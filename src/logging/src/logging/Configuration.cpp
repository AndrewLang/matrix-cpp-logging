#include "logging/Configuration.h"
#include "common/MapExtensions.h"

namespace Logging
{
	Configuration::Configuration()
	{
	}

	Configuration::~Configuration()
	{
	}
	Configuration & Configuration::addConfig(std::shared_ptr<LoggerConfig> configure)
	{
		configs[configure->type] = configure;
		return *this;
	}
	std::shared_ptr<LoggerConfig> Configuration::getConfig(const std::string & type)
	{
		return Maps::get<std::string, std::shared_ptr<LoggerConfig>>(configs, type);		
	}
}