#include "logging/LogMessage.h"
#include "logging/LogLevels.h"

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

	LogMessage LogMessage::debug(const std::string & name, const std::string & message, const std::string & timestamp, const int indent)
	{
		LogMessage msg(LogLevels::Default()->debug(), name, message, timestamp, indent);
		return msg;
	}

	LogMessage LogMessage::info(const std::string & name, const std::string & message, const std::string & timestamp, const int indent)
	{
		LogMessage msg(LogLevels::Default()->info(), name, message, timestamp, indent);
		return msg;
	}

	LogMessage LogMessage::warn(const std::string & name, const std::string & message, const std::string & timestamp, const int indent)
	{
		LogMessage msg(LogLevels::Default()->warn(), name, message, timestamp, indent);
		return msg;
	}

	LogMessage LogMessage::error(const std::string & name, const std::string & message, const std::string & timestamp, const int indent)
	{
		LogMessage msg(LogLevels::Default()->error(), name, message, timestamp, indent);
		return msg;
	}

	LogMessage LogMessage::fatal(const std::string & name, const std::string & message, const std::string & timestamp, const int indent)
	{
		LogMessage msg(LogLevels::Default()->fatal(), name, message, timestamp, indent);
		return msg;
	}


    

} // namespace Logging