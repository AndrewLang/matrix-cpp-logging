#pragma once
#include "ILogger.h"
#include "LogLayout.h"


namespace Logging
{
	class LoggerBase :public ILogger
	{
	private:
		

	public:
		LoggerBase();

		LoggerBase(const std::string& loggerName, std::vector<std::shared_ptr<ILogLayout>> loggerLayouts, std::shared_ptr<LogLevel> loggerMiniLevel);
		
		~LoggerBase();

		bool isEnabled(std::shared_ptr<LogLevel> level) override;

		ILogger& log(LogMessage& message) override;

		std::vector<std::shared_ptr<ILogLayout>> getLayouts();

		std::shared_ptr<LogLevel> getMiniLevel();

	protected:
		std::shared_ptr<LogLevel> miniLevel;
		std::vector<std::shared_ptr<ILogLayout>> layouts;

		virtual void write(const std::string message) = 0;
	};

}