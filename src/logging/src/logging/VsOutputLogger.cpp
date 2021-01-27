#include "logging/VsOutputLogger.h"
#include "logging/VsOutput.h"
#include "common/StringExtensions.h"

namespace Logging
{
	VsOutputLogger::VsOutputLogger(const std::string& loggerName, std::vector<std::shared_ptr<ILogLayout>> loggerLayouts, std::shared_ptr<LogLevel> loggerMiniLevel)
		:LoggerBase(loggerName, loggerLayouts, loggerMiniLevel)
	{
		
	}
	   
	VsOutputLogger::~VsOutputLogger()
	{
	}

	void VsOutputLogger::write(const std::string message)
	{
		VsOutput::writeLine(message);
	}
}