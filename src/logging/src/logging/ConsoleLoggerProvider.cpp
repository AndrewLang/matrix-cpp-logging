#include "logging/ConsoleLoggerProvider.h"
#include "logging/ConsoleLogger.h"

namespace Logging
{
	ConsoleLoggerProvider::ConsoleLoggerProvider()
	{
	}
	
	ConsoleLoggerProvider::~ConsoleLoggerProvider()
	{
	}

	std::shared_ptr<ILogger> ConsoleLoggerProvider::createLogger(std::string name)
	{
		return std::make_shared<ConsoleLogger>(name);
	}

}