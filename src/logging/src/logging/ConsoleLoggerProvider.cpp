#include "logging/ConsoleLoggerProvider.h"
#include "logging/ConsoleLogger.h"
#include "logging/LogLevels.h"

namespace Logging
{
	ConsoleLoggerProvider::ConsoleLoggerProvider()
	{
		configurationType = LoggerConfigTypes::Console;
	}

	ConsoleLoggerProvider::~ConsoleLoggerProvider()
	{
	}

	std::shared_ptr<ILogger> ConsoleLoggerProvider::createLogger(const std::string& name)
	{		
		auto layouts = getLayouts();
		
		return std::make_shared<ConsoleLogger>(name, layouts, LogLevels::Default()->all());
	}

}