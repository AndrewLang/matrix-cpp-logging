
#pragma once
#include <string>

#include "LogLevel.h"

namespace Logging
{
    class LogMessage
    {
    private:
        std::string mName;
        std::string mMessage;
        std::string mTimestamp;
        LogLevel mLevel;
        int mIndent;

    public:
        LogMessage(const LogLevel& level, const std::string& name, const std::string& message, const std::string& timestamp);
        LogMessage() = delete;
        ~LogMessage();

        std::string getName();
    };

} // namespace Logging