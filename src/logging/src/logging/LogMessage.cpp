#include "logging/LogMessage.h"

namespace Logging
{

	LogMessage::LogMessage(std::shared_ptr<LogLevel> level, const std::string & name, const std::string & message, const std::string & timestamp, const int indent)
		: mName(name), mMessage(message), mTimestamp(timestamp), mIndent(indent)
	{
		mLevel = level;
	}

	LogMessage::~LogMessage()
    {
    }

    std::string LogMessage::getName()
    {
        return mName;
    }
    std::string LogMessage::getMessage()
    {
        return mMessage;
    }
    std::string LogMessage::getTimmestamp()
    {
        return mTimestamp;
    }
    std::shared_ptr<LogLevel> LogMessage::getLevel()
    {
        return mLevel;
    }
    int LogMessage::getIndent()
    {
        return mIndent;
    }
} // namespace Logging