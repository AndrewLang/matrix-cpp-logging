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

	protected:
		virtual void write(std::string message) override;
	};

}