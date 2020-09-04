#include "logging/LoggerBase.h"
#include "logging/LogLevels.h"
#include "common/VectorExtensions.h"

namespace Logging
{
	using std::string;

	LoggerBase::LoggerBase()
	{

	}

	LoggerBase::LoggerBase(const std::string& loggerName, std::vector<std::shared_ptr<ILogLayout>> loggerLayouts, std::shared_ptr<LogLevel> loggerMiniLevel)
	{
		name = loggerName;
		layouts = loggerLayouts;
		miniLevel = loggerMiniLevel ? loggerMiniLevel: LogLevels::Default()->all();		
	}
	   
	LoggerBase::~LoggerBase()
	{
	}

	bool Logging::LoggerBase::isEnabled(std::shared_ptr<LogLevel> level)
	{
		if (!miniLevel)
			return true;

		return level->getValue() > miniLevel->getValue();
	}

	ILogger & LoggerBase::log(LogMessage& message)
	{
		if (enabled && isEnabled(message.getLevel()))
		{
			std::vector<string> parts;
			for (auto& item : layouts)
			{
				parts.push_back(item->layout(message));
			}

			string content = preWrite(message, Vectors::join(parts, ""));
						
			write(content);
		}

		return *this;
	}

	void LoggerBase::configure(std::shared_ptr<LoggerConfig> loggerConfig)
	{
		rawConfig = loggerConfig;
		if (rawConfig)
		{
			enabled = rawConfig->isEnabled;
			miniLevel = rawConfig->level;
			layoutFormat = rawConfig->layout;
		}
	}

	std::vector<std::shared_ptr<ILogLayout>> LoggerBase::getLayouts()
	{
		return layouts;
	}

	std::shared_ptr<LogLevel> LoggerBase::getMiniLevel()
	{
		return miniLevel;
	}

	std::string LoggerBase::preWrite(LogMessage & message, const std::string & text)
	{
		return text;
	}

}