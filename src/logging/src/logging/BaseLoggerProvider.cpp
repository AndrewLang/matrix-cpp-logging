#include "logging/BaseLoggerProvider.h"
#include "common/StringExtensions.h"

namespace Logging
{
	void BaseLoggerProvider::configure(std::shared_ptr<LoggerContext> loggerContext)
	{
		context = loggerContext;
	}

	std::shared_ptr<LoggerConfig> BaseLoggerProvider::getConfig(const std::string & type)
	{
		std::shared_ptr<LoggerConfig> config;
		std::vector<std::shared_ptr<ILogLayout>> layouts;
		std::string configType = type;

		if (Strings::isNullOrEmpty(type))
			configType = configurationType;

		if (Strings::notNullOrEmpty(configType))
		{
			config = context->configuration->getConfig(configType);
		}

		return config;
	}

	std::vector<std::shared_ptr<ILogLayout>> BaseLoggerProvider::getLayouts(std::shared_ptr<LoggerConfig> config)
	{
		std::vector<std::shared_ptr<ILogLayout>> layouts;

		if (config != nullptr)
			layouts = context->layoutRepo->parse(config->layout);

		return layouts;
	}
}