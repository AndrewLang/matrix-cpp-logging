#include "logging/LogMessage.h"

namespace Logging
{
    LogMessage::LogMessage(const LogLevel & level, const std::string & name, const std::string & message, const std::string & timestamp)
        : mLevel(level), mName(name), mMessage(message), mTimestamp(timestamp)
    {
    }

    LogMessage::~LogMessage()
    {
    }

    std::string LogMessage::getName()
    {
        return mName;
    }
} // namespace Logging