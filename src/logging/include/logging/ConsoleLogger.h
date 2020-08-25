#pragma once
#include "LoggerBase.h"

namespace Logging
{
	class ConsoleLogger :public LoggerBase
	{
	public:
		ConsoleLogger();
		ConsoleLogger(const std::string& loggerName, std::vector<std::shared_ptr<ILogLayout>> loggerLayouts, std::shared_ptr<LogLevel> loggerMiniLevel);
		ConsoleLogger(const ConsoleLogger& logger);

		~ConsoleLogger();
	private:
		

	protected:
		virtual void write(std::string message) override;
	};

}