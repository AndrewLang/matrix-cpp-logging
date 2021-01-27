#pragma once
#include "ILoggerProvider.h"

namespace Logging
{
	class BaseLoggerProvider : public ILoggerProvider
	{
	public:		
		void configure(std::shared_ptr<LoggerContext> context) override;

	protected:	
		std::shared_ptr<LoggerContext> getContext();

		std::shared_ptr<LoggerConfig> getConfig(const std::string& type = "");

		std::vector<std::shared_ptr<ILogLayout>> getLayouts(std::shared_ptr<LoggerConfig> configure);

		std::string getConfigurationType();

		void setConfigurationType(const std::string value);

		template<class T>
		std::shared_ptr<T> getConfiguration(const std::string& type = "")
		{
			auto configure = getConfig(type);
			if (configure)
			{
				return std::static_pointer_cast<T>(configure);
			}
			return nullptr;
		}

	private:
		std::shared_ptr<LoggerContext> mContext;
		std::string mConfigurationType;
	};
}