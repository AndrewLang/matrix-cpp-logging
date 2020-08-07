#pragma once
#include "LoggerBase.h"


namespace Logging
{
	class VsOutputLogger :public LoggerBase
	{
	public:
		VsOutputLogger() = delete;

		VsOutputLogger(const std::string & name);

		VsOutputLogger(const VsOutputLogger& logger);

		~VsOutputLogger();


		ILogger& log(LogLevelEnum level, std::string message, int eveintId, std::exception* exception, TextFormatter formatter) override;

	};

}