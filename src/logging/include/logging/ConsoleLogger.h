#pragma once
#include "LoggerBase.h"
#include "LoggerConfig.h"
#include "ConsoleColorRender.h"

namespace Logging
{
	class ConsoleLogger :public LoggerBase
	{
	public:
		ConsoleLogger();
		ConsoleLogger(const std::string& loggerName, std::vector<std::shared_ptr<ILogLayout>> loggerLayouts, std::shared_ptr<LogLevel> loggerMiniLevel);
		ConsoleLogger(const ConsoleLogger& logger);

		~ConsoleLogger();

		void configure(std::shared_ptr<ConsoleLoggerConfig> loggerConfig);

	private:
		std::shared_ptr<ConsoleLoggerConfig> loggerConfig;
		std::shared_ptr<ConsoleColorRenderer> renderer;

	protected:
		virtual void write(std::string message) override;

		virtual std::string preWrite(LogMessage& message, const std::string& text) override;
	};

}