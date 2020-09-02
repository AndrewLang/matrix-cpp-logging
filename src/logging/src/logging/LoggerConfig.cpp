#include "logging/LoggerConfig.h"
#include "logging/LogLevels.h"
#include "common/MapExtensions.h"

namespace Logging
{
	ConsoleStyleConfig::ConsoleStyleConfig()
	{
	}

	ConsoleStyleConfig::ConsoleStyleConfig(const std::string & level, const std::string & foreColor, const std::string & backColor, const std::string& style)
		:level(level), foreColor(foreColor), backColor(backColor), style(style)
	{
	}

	ConsoleLoggerConfig::ConsoleLoggerConfig()
	{
		type = LoggerConfigTypes::Console;
		enableColor = false;
	}

	ConsoleLoggerConfig & ConsoleLoggerConfig::addStyle(const std::string & level, const std::string & foreColor, const std::string & backColor, const std::string& style)
	{
		ConsoleStyleConfig configure(level, foreColor, backColor, style);
		styles.push_back(configure);

		return *this;
	}

	std::shared_ptr<ConsoleLoggerConfig> ConsoleLoggerConfig::default()
	{
		auto configure = std::make_shared<ConsoleLoggerConfig>();

		return configure;
	}

	std::shared_ptr<ConsoleLoggerConfig> ConsoleLoggerConfig::defaultWithColor()
	{
		auto configure = std::make_shared<ConsoleLoggerConfig>();
		configure->enableColor = true;

		configure->addStyle(LogLevels::Default()->debug()->getName())
			.addStyle(LogLevels::Default()->info()->getName(), "green")
			.addStyle(LogLevels::Default()->warn()->getName(), "yellow")
			.addStyle(LogLevels::Default()->error()->getName(), "purple")
			.addStyle(LogLevels::Default()->fatal()->getName(), "red")
			;
		return configure;
	}

	FileLoggerConfig::FileLoggerConfig()
	{
		type = LoggerConfigTypes::File;
	}
}