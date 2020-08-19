#pragma once
#include "LoggerBase.h"


namespace Logging
{
	class VsOutputLogger :public LoggerBase
	{
	public:
		VsOutputLogger() = delete;

		VsOutputLogger(const std::string& loggerName, std::vector<std::shared_ptr<ILogLayout>> loggerLayouts, std::shared_ptr<LogLevel> loggerMiniLevel);

		~VsOutputLogger();


		// ILogger& log(LogLevelEnum level, std::string message, int eveintId, std::exception* exception, TextFormatter formatter) override;

	protected:
		virtual void write(std::string message) override;
	};

}