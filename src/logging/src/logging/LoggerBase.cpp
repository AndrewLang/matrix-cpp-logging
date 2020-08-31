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
		return level->getValue() > miniLevel->getValue();
	}

	ILogger & LoggerBase::log(LogMessage message)
	{
		if (isEnabled(message.getLevel()))
		{
			std::vector<string> parts;
			for (auto& item : layouts)
			{
				parts.push_back(item->layout(message));
			}

			string content = Vectors::join(parts, "");

			write(content);
		}

		return *this;
	}

	std::vector<std::shared_ptr<ILogLayout>> LoggerBase::getLayouts()
	{
		return layouts;
	}

	std::shared_ptr<LogLevel> LoggerBase::getMiniLevel()
	{
		return miniLevel;
	}

}