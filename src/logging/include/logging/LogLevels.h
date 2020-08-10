#pragma once

#include <map>
#include "LogLevel.h"

namespace Logging
{
	class LogLevels
	{
	private:
		static constexpr const char* All = "All";
		static constexpr const char* Debug = "Debug";
		static constexpr const char* Info = "Info";
		static constexpr const char* Warn = "Warn";
		static constexpr const char* Error = "Error";
		static constexpr const char* Fatal = "Fatal";
		static constexpr const char* None = "None";
		
		std::map<std::string, std::shared_ptr<LogLevel>> mLevels;

		
		void initialize();
	public:

		LogLevels();

		LogLevels(LogLevels const& instance) = delete;

		LogLevels& operator = (LogLevels  const& instance) = delete;
		
		~LogLevels();

		static std::shared_ptr<LogLevels> Default()
		{
			static std::shared_ptr<LogLevels> instance = std::make_shared<LogLevels>();
			// (new LogLevels());
			return instance;
		}

		std::shared_ptr<LogLevel> all();
		std::shared_ptr<LogLevel> debug();
		std::shared_ptr<LogLevel> info();
		std::shared_ptr<LogLevel> warn();
		std::shared_ptr<LogLevel> error();
		std::shared_ptr<LogLevel> fatal();
		std::shared_ptr<LogLevel> none();

		LogLevels& add(const std::string name, const int value);
	};
}
