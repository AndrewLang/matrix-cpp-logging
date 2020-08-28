#include "logging/LoggerFactory.h"

namespace Logging
{
	
	LoggerFactory::LoggerFactory()
	{
		
	}

	LoggerFactory::~LoggerFactory()
	{
		mProviders.clear();
		mLoggers.clear();
	}

	std::shared_ptr<ILogger> LoggerFactory::createLogger(std::string name)
	{
		auto finder = mLoggers.find(name);

		if (finder == mLoggers.end()) 
		{
			auto pointer = shared_from_this();

			auto loggerPtr = std::make_shared<InternalLogger>(pointer, name);

			mLoggers.insert(std::make_pair(name, loggerPtr));

			return loggerPtr;
		}
		else
		{
			return finder->second;
		}
	}

	void LoggerFactory::addProvider(std::shared_ptr<ILoggerProvider> provider)
	{
		provider->configure(context);
		mProviders.push_back(provider);

		for (auto &pair : mLoggers)
		{
			pair.second->addProvider(provider);
		}
	}

	std::vector<std::shared_ptr<ILoggerProvider>> LoggerFactory::getProviders()
	{
		return mProviders;
	}
	ILoggerFactory & LoggerFactory::configure(std::shared_ptr<Configuration> configuration)
	{
		auto layoutRepo = std::make_shared<LogLayoutRepository>();
		layoutRepo->initialize();

		context = std::make_shared<LoggerContext>();
		context->factory = shared_from_this();
		context->layoutRepo = layoutRepo;
		context->configuration = configuration;

		return *this;
	}
	std::shared_ptr<LoggerContext> LoggerFactory::getContext()
	{
		return context;
	}
}