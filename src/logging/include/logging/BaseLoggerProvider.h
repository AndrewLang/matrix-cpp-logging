#pragma once
#include "ILoggerProvider.h"

namespace Logging
{
	class BaseLoggerProvider : public ILoggerProvider
	{
	public:		
		void configure(std::shared_ptr<LoggerContext> context) override;

	protected:
		std::shared_ptr<LoggerContext> context;
		std::string configurationType;
		
		std::shared_ptr<LoggerConfig> getConfig(const std::string& type = "");

		std::vector<std::shared_ptr<ILogLayout>> getLayouts(std::shared_ptr<LoggerConfig> config);
	};
}