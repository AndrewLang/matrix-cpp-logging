#include "logging/InternalLogger.h"


namespace Logging
{
	InternalLogger::InternalLogger(std::shared_ptr<ILoggerFactory> factory, std::string loggerName)
		: mFactory(factory)
	{
		name = loggerName;
		initialize();
	}
	
	InternalLogger::~InternalLogger()
	{
		mLoggers.clear();
	}

	/*ILogger & InternalLogger::log(LogLevelEnum level, std::string message, int eveintId, std::exception* exception, TextFormatter formatter)
	{
		std::vector<std::exception> exceptions;
		for (auto logger : mLoggers)
		{
			try
			{
				logger->log(level, message, eveintId, exception, formatter);
			}
			catch (const std::exception& ex)
			{
				exceptions.push_back(ex);
			}
		}

		if (exceptions.size() > 0)
		{
			throw std::runtime_error("An error occurred while writing to logger(s).");
		}

		return *this;
	}*/

	bool InternalLogger::isEnabled(std::shared_ptr<LogLevel> level)
	{
		for (auto logger : mLoggers)
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
		mLoggers.push_back(logger);
	}

	ILogger & InternalLogger::log(LogMessage message)
	{
		// TODO: insert return statement here
		return *this;
	}

	void InternalLogger::initialize()
	{
		auto providers = mFactory->getProviders();
		for (auto provider : providers)
		{
			mLoggers.push_back(provider->createLogger(name));
		}
	}

}