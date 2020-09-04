#include "logging/InternalLogger.h"


namespace Logging
{
	InternalLogger::InternalLogger(std::shared_ptr<ILoggerFactory> factory, const std::string& loggerName)
		: factory(factory)
	{
		name = loggerName;
		initialize();
	}
	
	InternalLogger::~InternalLogger()
	{
		loggers.clear();
	}
	
	bool InternalLogger::isEnabled(std::shared_ptr<LogLevel> level)
	{
		for (auto& logger : loggers)
		{
			if (logger->isEnabled(level))
			{
				return true;
			}
		}
		return false;
	}
		
	void InternalLogger::addProvider(std::shared_ptr<ILoggerProvider> provider)
	{
		auto logger = provider->createLogger(name);
		loggers.push_back(logger);
	}

	ILogger & InternalLogger::log(LogMessage& message)
	{
		for (auto& logger : loggers)
		{
			logger->log(message);
		}
		return *this;
	}

	std::vector<std::shared_ptr<ILogger>> InternalLogger::getLoggers()
	{
		return loggers;
	}

	void InternalLogger::initialize()
	{
		auto providers = factory->getProviders();
		for (auto& provider : providers)
		{
			loggers.push_back(provider->createLogger(name));
		}
	}

}