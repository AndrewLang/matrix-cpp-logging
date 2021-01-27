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
		mName = loggerName;
		mLayouts = loggerLayouts;
		mMiniLevel = loggerMiniLevel ? loggerMiniLevel: LogLevels::Default()->all();		
	}
	   
	LoggerBase::~LoggerBase()
	{
	}

	bool Logging::LoggerBase::isEnabled(std::shared_ptr<LogLevel> level)
	{
		if (!mMiniLevel)
			return true;

		return level->getValue() > mMiniLevel->getValue();
	}

	ILogger & LoggerBase::log(LogMessage& message)
	{
		if (mEnabled && isEnabled(message.getLevel()))
		{
			std::vector<string> parts;
			for (auto& item : mLayouts)
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
			mEnabled = rawConfig->isEnabled;
			mMiniLevel = rawConfig->level;
			mLayoutFormat = rawConfig->layout;
		}
	}

	std::vector<std::shared_ptr<ILogLayout>> LoggerBase::getLayouts()
	{
		return mLayouts;
	}

	std::shared_ptr<LogLevel> LoggerBase::getMiniLevel()
	{
		return mMiniLevel;
	}

	std::string LoggerBase::preWrite(LogMessage & message, const std::string & text)
	{
		return text;
	}

	std::string LoggerBase::getName()
	{
		return mName;
	}

	void LoggerBase::setName(const std::string value)
	{
		mName = value;
	}
}