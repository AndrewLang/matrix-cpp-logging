#pragma once
#include <memory>
#include <string>
#include <vector>

#include "Configuration.h"

namespace Logging
{
	class ILogger;

	class ILoggerProvider;

	class ILoggerFactory
	{
	public:
        virtual ~ILoggerFactory() = default;

		virtual std::shared_ptr<ILogger> createLogger(const std::string& name) = 0;

		virtual void addProvider(std::shared_ptr<ILoggerProvider> provider) = 0;

		virtual std::vector<std::shared_ptr<ILoggerProvider>> getProviders() = 0;

		virtual ILoggerFactory& configure(std::shared_ptr<Configuration> configure) = 0;

		

		template<class TKey, class ... TArgs>
		ILoggerFactory& useProvider(TArgs... args)
		{
			addProvider(std::make_shared<TKey>(args...));
			return *this;
		}

    protected:
        ILoggerFactory() = default;
	};
}