#pragma once
#include "ILogger.h"
#include "LogLayout.h"
#include "LoggerConfig.h"

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

		virtual void configure(std::shared_ptr<LoggerConfig> loggerConfig);

		std::vector<std::shared_ptr<ILogLayout>> getLayouts();

		std::shared_ptr<LogLevel> getMiniLevel();

	protected:
		std::shared_ptr<LoggerConfig> rawConfig;
		std::shared_ptr<LogLevel> miniLevel;
		std::vector<std::shared_ptr<ILogLayout>> layouts;		
		std::string  layoutFormat;
		bool enabled = true;
		

		virtual void write(const std::string message) = 0;

		virtual std::string preWrite(LogMessage& message, const std::string& text);
	};

}