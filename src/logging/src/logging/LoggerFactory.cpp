#include "logging/LoggerFactory.h"

namespace Logging
{	
	LoggerFactory::LoggerFactory()
	{
		
	}

	LoggerFactory::~LoggerFactory()
	{
		mProviders.clear();
		loggers.clear();
	}

	std::shared_ptr<ILogger> LoggerFactory::createLogger(const std::string& name)
	{
		auto finder = loggers.find(name);

		if (finder == loggers.end()) 
		{
			auto factory = shared_from_this();

			auto logger = std::make_shared<InternalLogger>(factory, name);

			loggers.insert(std::make_pair(name, logger));

			return logger;
		}
		else
		{
			return finder->second;
		}
	}

	void LoggerFactory::addProvider(std::shared_ptr<ILoggerProvider> provider)
	{
		if (provider)
		{
			provider->configure(context);
			mProviders.push_back(provider);

			for (auto &pair : loggers)
			{
				pair.second->addProvider(provider);
			}
		}
	}

	std::vector<std::shared_ptr<ILoggerProvider>> LoggerFactory::getProviders()
	{
		return mProviders;
	}

	ILoggerFactory & LoggerFactory::configure(std::shared_ptr<Configuration> configuration)
	{
		if (configuration)
		{
			auto layoutRepo = std::make_shared<LogLayoutRepository>();
			layoutRepo->initialize();

			context = std::make_shared<LoggerContext>();
			context->factory = shared_from_this();
			context->layoutRepo = layoutRepo;
			context->configuration = configuration;
		}

		return *this;
	}

	std::shared_ptr<LoggerContext> LoggerFactory::getContext()
	{
		return context;
	}
}