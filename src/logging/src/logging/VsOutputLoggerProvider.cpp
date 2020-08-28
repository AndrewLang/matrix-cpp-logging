#include "logging/VsOutputLoggerProvider.h"
#include "logging/VsOutputLogger.h"
#include "logging/LogLevels.h"

namespace Logging
{
	VsOutputLoggerProvider::VsOutputLoggerProvider()
	{
		configurationType = LoggerConfigTypes::VsOutput;
	}
	
	VsOutputLoggerProvider::~VsOutputLoggerProvider()
	{
	}

	std::shared_ptr<ILogger> VsOutputLoggerProvider::createLogger(const std::string& name)
	{
		auto config = getConfig();
		auto layouts = getLayouts(config);
		return std::make_shared<VsOutputLogger>(name, layouts, config->level);
	}
}