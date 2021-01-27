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

	std::shared_ptr<ILogger> LoggerFactory::createLogger(const std::string& name)
	{
		auto finder = mLoggers.find(name);

		if (finder == mLoggers.end()) 
		{
			auto factory = shared_from_this();

			auto logger = std::make_shared<InternalLogger>(factory, name);

			mLoggers.insert(std::make_pair(name, logger));

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
			provider->configure(mContext);
			mProviders.push_back(provider);

			for (auto &pair : mLoggers)
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

			mContext = std::make_shared<LoggerContext>();
			mContext->factory = shared_from_this();
			mContext->layoutRepo = layoutRepo;
			mContext->configuration = configuration;
		}

		return *this;
	}

	std::shared_ptr<LoggerContext> LoggerFactory::getContext()
	{
		return mContext;
	}
}