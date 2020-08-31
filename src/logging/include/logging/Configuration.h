#pragma once
#include "LogLevel.h"
#include "LoggerConfig.h"

#include <vector>
#include <map>

namespace Logging
{
	class Configuration
	{
	public:
		Configuration();

		~Configuration();

		Configuration& addConfig(std::shared_ptr<LoggerConfig> configure);

		std::shared_ptr<LoggerConfig> getConfig(const std::string& type);

		template<class T>
		std::shared_ptr<T> get(const std::string& type)
		{
			auto context = getConfig(type);
			if (context != nullptr)
			{
				return std::static_pointer_cast<T>(context);
			}
			return nullptr;
		}

	private:
		std::map<std::string, std::shared_ptr<LoggerConfig>> configs;
	};


}