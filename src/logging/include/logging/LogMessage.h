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
        std::shared_ptr<LogLevel> mLevel;
        int mIndent;

    public:
        LogMessage(std::shared_ptr<LogLevel> level, const std::string& name, const std::string& message, const std::string& timestamp, const int intent = 0);
        LogMessage() = delete;
        ~LogMessage();

        std::string getName();
        std::string getMessage();
        std::string getTimmestamp();
        std::shared_ptr<LogLevel> getLevel();
        int getIndent();
    };

} // namespace Logging