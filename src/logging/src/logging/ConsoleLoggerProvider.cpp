 #include "logging/ConsoleLoggerProvider.h"
#include "logging/ConsoleLogger.h"
#include "logging/LogLevels.h"

namespace Logging
{
	ConsoleLoggerProvider::ConsoleLoggerProvider()
	{
	}

	ConsoleLoggerProvider::~ConsoleLoggerProvider()
	{
	}

	std::shared_ptr<ILogger> ConsoleLoggerProvider::createLogger(const std::string& name)
	{
		std::vector<std::shared_ptr<ILogLayout>> layouts;
		return std::make_shared<ConsoleLogger>(name, layouts, LogLevels::Default()->all());
	}

}