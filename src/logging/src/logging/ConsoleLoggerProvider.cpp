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
		auto config = getConfig();
		auto layouts = getLayouts(config);
		
		return std::make_shared<ConsoleLogger>(name, layouts, config->level);
	}

}