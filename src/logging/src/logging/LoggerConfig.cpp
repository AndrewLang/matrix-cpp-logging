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
		configure->level = LogLevels::Default()->all();

		configure->addStyle(LogLevels::Debug)
			.addStyle(LogLevels::Info, "47")
			.addStyle(LogLevels::Warn, "226")
			.addStyle(LogLevels::Error, "124", "", "bold")
			.addStyle(LogLevels::Fatal, "226", "124", "underline")
			;
		return configure;
	}

	FileLoggerConfig::FileLoggerConfig()
	{
		type = LoggerConfigTypes::File;
	}
}