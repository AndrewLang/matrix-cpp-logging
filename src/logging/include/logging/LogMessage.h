#pragma once
#include <string>
#include <memory>

#include "LogLevel.h"

namespace Logging
{
    class LogMessage
    {
    private:
        std::string name;
        std::string message;
        std::string timestamp;
        std::shared_ptr<LogLevel> level;
        int indent;

    public:
        LogMessage(std::shared_ptr<LogLevel> logLevel, const std::string& loggerName, const std::string& messageBody, const std::string& timestamp, const int intent = 0);
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
        static LogMessage debug(const std::string& name, const std::string& message, const std::string& timestamp = "", const int indent = 0);

		static LogMessage info(const std::string& name, const std::string& message, const std::string& timestamp = "", const int indent = 0);

		static LogMessage warn(const std::string& name, const std::string& message, const std::string& timestamp = "", const int indent = 0);

		static LogMessage error(const std::string& name, const std::string& message, const std::string& timestamp = "", const int indent = 0);

		static LogMessage fatal(const std::string& name, const std::string& message, const std::string& timestamp = "", const int indent = 0);
    };

} // namespace Logging