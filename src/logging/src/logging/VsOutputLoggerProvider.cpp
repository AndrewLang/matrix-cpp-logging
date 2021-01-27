#include "logging/VsOutputLoggerProvider.h"
#include "logging/VsOutputLogger.h"
#include "logging/LogLevels.h"

namespace Logging
{
	VsOutputLoggerProvider::VsOutputLoggerProvider()
	{
		setConfigurationType(LoggerConfigTypes::VsOutput);
	}

	VsOutputLoggerProvider::~VsOutputLoggerProvider()
	{
	}

	std::shared_ptr<ILogger> VsOutputLoggerProvider::createLogger(const std::string& name)
	{
		auto configure = getConfig();
		auto layouts = getLayouts(configure);
		return std::make_shared<VsOutputLogger>(name, layouts, configure->level);
	}
}