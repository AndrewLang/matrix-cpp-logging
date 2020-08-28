#include "logging/BaseLoggerProvider.h"
#include "common/StringExtensions.h"

namespace Logging
{
	void BaseLoggerProvider::configure(std::shared_ptr<LoggerContext> loggerContext)
	{
		context = loggerContext;
	}
	std::vector<std::shared_ptr<ILogLayout>> BaseLoggerProvider::getLayouts(const std::string & type)
	{
		std::vector<std::shared_ptr<ILogLayout>> layouts;
		std::string configType = type;

		if (Strings::isNullOrEmpty(type))
			configType = configurationType;

		if (Strings::notNullOrEmpty(configType))
		{
			auto config = context->configuration->getConfig(configType);
			if (config != nullptr)
				layouts = context->layoutRepo->parse(config->layout);
		}

		return layouts;
	}
}