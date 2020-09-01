#include "logging/LoggerConfig.h"
#include "logging/LogLevels.h"
#include "common/MapExtensions.h"

namespace Logging
{
	ColorConfig::ColorConfig()
	{
	}

	ColorConfig::ColorConfig(const std::string & level, const std::string & foreColor, const std::string & backColor)
		:level(level), foreColor(foreColor), backColor(backColor)
	{
	}

	ConsoleLoggerConfig::ConsoleLoggerConfig()
	{
		type = LoggerConfigTypes::Console;
		enableColor = false;
	}

	ConsoleLoggerConfig & ConsoleLoggerConfig::addColor(const std::string & level, const std::string & foreColor, const std::string & backColor)
	{
		ColorConfig config(level, foreColor, backColor);
		colors.push_back(config);

		return *this;
	}

	std::shared_ptr<ConsoleLoggerConfig> ConsoleLoggerConfig::default()
	{
		auto config = std::make_shared<ConsoleLoggerConfig>();

		return config;
	}

	std::shared_ptr<ConsoleLoggerConfig> ConsoleLoggerConfig::defaultWithColor()
	{
		auto config = std::make_shared<ConsoleLoggerConfig>();
		config->enableColor = true;

		config->addColor(LogLevels::Default()->debug()->getName())
			.addColor(LogLevels::Default()->info()->getName(), "green")
			.addColor(LogLevels::Default()->warn()->getName(), "yellow")
			.addColor(LogLevels::Default()->error()->getName(), "purple")
			.addColor(LogLevels::Default()->fatal()->getName(), "red")
			;
		return config;
	}

	FileLoggerConfig::FileLoggerConfig()
	{
		type = LoggerConfigTypes::File;
	}
}