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
		auto config = std::make_shared<ConsoleLoggerConfig>();
		config->level = LogLevels::Default()->all();
		config->type = LoggerConfigTypes::Console;
		config->layout = "{timestamp} {level} {name}: {message}";

		return config;
	}

	std::shared_ptr<ConsoleLoggerConfig> ConsoleLoggerConfig::defaultWithColor()
	{
		auto config = std::make_shared<ConsoleLoggerConfig>();
		config->enableColor = true;
		config->isEnabled = true;
		config->level = LogLevels::Default()->all();
		config->type = LoggerConfigTypes::Console;
		config->layout = "{timestamp} {level} {name}: {message}";

		config->addStyle(LogLevels::Debug)
			.addStyle(LogLevels::Info, "47")
			.addStyle(LogLevels::Warn, "226")
			.addStyle(LogLevels::Error, "124", "", "bold")
			.addStyle(LogLevels::Fatal, "226", "124", "underline")
			;
		return config;
	}

	FileLoggerConfig::FileLoggerConfig()
	{
		type = LoggerConfigTypes::File;
	}
}