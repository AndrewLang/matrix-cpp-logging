#include "logging/BaseLoggerProvider.h"
#include "common/StringExtensions.h"

namespace Logging
{
	void BaseLoggerProvider::configure(std::shared_ptr<LoggerContext> loggerContext)
	{
		mContext = loggerContext;
	}

	std::shared_ptr<LoggerContext> BaseLoggerProvider::getContext()
	{
		return mContext;
	}

	std::shared_ptr<LoggerConfig> BaseLoggerProvider::getConfig(const std::string & type)
	{
		std::shared_ptr<LoggerConfig> configure;
		std::vector<std::shared_ptr<ILogLayout>> layouts;
		std::string configType = type;

		if (Strings::isNullOrEmpty(type))
			configType = mConfigurationType;

		if (Strings::notNullOrEmpty(configType))
		{
			configure = mContext->configuration->getConfig(configType);
		}

		return configure;
	}

	std::vector<std::shared_ptr<ILogLayout>> BaseLoggerProvider::getLayouts(std::shared_ptr<LoggerConfig> configure)
	{
		std::vector<std::shared_ptr<ILogLayout>> layouts;

		if (configure != nullptr)
			layouts = mContext->layoutRepo->parse(configure->layout);

		return layouts;
	}
	std::string BaseLoggerProvider::getConfigurationType()
	{
		return mConfigurationType;
	}
	void BaseLoggerProvider::setConfigurationType(const std::string value)
	{
		mConfigurationType = value;
	}
}