#include "logging/LoggerConfig.h"
#include "common/MapExtensions.h"

namespace Logging
{

	ConsoleLoggerConfig::ConsoleLoggerConfig()
	{
		type = LoggerConfigTypes::Console;
	}

	FileLoggerConfig::FileLoggerConfig()
	{
		type = LoggerConfigTypes::File;
	}
}