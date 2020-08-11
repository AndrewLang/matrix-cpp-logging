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

        std::string getName() const;
        std::string getMessage() const;
        std::string getTimmestamp() const;
        std::shared_ptr<LogLevel> getLevel() const;
        int getIndent() const;

		// return LogMessage instance because optimization of modern c++
		/*
		create debug level message 
		*/
        static LogMessage debug(const std::string& name, const std::string& message, const std::string& timestamp, const int indent);

		static LogMessage info(const std::string& name, const std::string& message, const std::string& timestamp, const int indent);

		static LogMessage warn(const std::string& name, const std::string& message, const std::string& timestamp, const int indent);

		static LogMessage error(const std::string& name, const std::string& message, const std::string& timestamp, const int indent);

		static LogMessage fatal(const std::string& name, const std::string& message, const std::string& timestamp, const int indent);
    };

} // namespace Logging