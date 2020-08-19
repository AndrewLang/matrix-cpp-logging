#include "logging/VsOutputLoggerProvider.h"
#include "logging/VsOutputLogger.h"
#include "logging/LogLevels.h"

namespace Logging
{
	VsOutputLoggerProvider::VsOutputLoggerProvider()
	{
	}
	
	VsOutputLoggerProvider::~VsOutputLoggerProvider()
	{
	}

	std::shared_ptr<ILogger> VsOutputLoggerProvider::createLogger(const std::string& name)
	{
		std::vector<std::shared_ptr<ILogLayout>> layouts;
		return std::make_shared<VsOutputLogger>(name, layouts, LogLevels::Default()->all());
	}
}