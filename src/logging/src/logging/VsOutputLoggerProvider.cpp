#include "logging/VsOutputLoggerProvider.h"
#include "logging/VsOutputLogger.h"

namespace Logging
{
	VsOutputLoggerProvider::VsOutputLoggerProvider()
	{
	}
	
	VsOutputLoggerProvider::~VsOutputLoggerProvider()
	{
	}

	std::shared_ptr<ILogger> VsOutputLoggerProvider::createLogger(std::string name)
	{
		return std::make_shared<VsOutputLogger>(name);
	}
}