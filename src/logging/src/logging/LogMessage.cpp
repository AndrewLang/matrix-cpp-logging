#include "logging/LogMessage.h"
#include "logging/LogLevels.h"
#include "common/StringExtensions.h"

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

    std::string LogMessage::getName() const
    {
        return mName;
    }
    std::string LogMessage::getMessage() const
    {
        return mMessage;
    }
    std::string LogMessage::getTimmestamp() const
    {
        return mTimestamp;
    }
    std::shared_ptr<LogLevel> LogMessage::getLevel() const
    {
        return mLevel;
    }
    int LogMessage::getIndent() const
    {
        return mIndent;
    }

	LogMessage LogMessage::debug(const std::string & name, const std::string & message, const std::string & timestamp, const int indent)
	{
		std::string time = timestamp;
		if (Strings::isNullOrEmpty(time))
			time = Strings::getTimestamp();

		LogMessage msg(LogLevels::Default()->debug(), name, message, time, indent);
		return msg;
	}

	LogMessage LogMessage::info(const std::string & name, const std::string & message, const std::string & timestamp, const int indent)
	{
		std::string time = timestamp;
		if (Strings::isNullOrEmpty(time))
			time = Strings::getTimestamp();

		LogMessage msg(LogLevels::Default()->info(), name, message, time, indent);
		return msg;
	}

	LogMessage LogMessage::warn(const std::string & name, const std::string & message, const std::string & timestamp, const int indent)
	{
		std::string time = timestamp;
		if (Strings::isNullOrEmpty(time))
			time = Strings::getTimestamp();

		LogMessage msg(LogLevels::Default()->warn(), name, message, time, indent);
		return msg;
	}

	LogMessage LogMessage::error(const std::string & name, const std::string & message, const std::string & timestamp, const int indent)
	{
		std::string time = timestamp;
		if (Strings::isNullOrEmpty(time))
			time = Strings::getTimestamp();


		LogMessage msg(LogLevels::Default()->error(), name, message, time, indent);
		return msg;
	}

	LogMessage LogMessage::fatal(const std::string & name, const std::string & message, const std::string & timestamp, const int indent)
	{
		std::string time = timestamp;
		if (Strings::isNullOrEmpty(time))
			time = Strings::getTimestamp();


		LogMessage msg(LogLevels::Default()->fatal(), name, message, time, indent);
		return msg;
	}


    

} // namespace Logging