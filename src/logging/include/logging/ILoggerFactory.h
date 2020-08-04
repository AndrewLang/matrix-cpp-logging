#pragma once
#include <memory>
#include <string>
#include <vector>

namespace Logging
{
	class ILogger;

	class ILoggerProvider;

	class ILoggerFactory
	{
	public:
		virtual std::shared_ptr<ILogger> createLogger(std::string name) = 0;

		virtual void addProvider(std::shared_ptr<ILoggerProvider> provider) = 0;

		virtual std::vector<std::shared_ptr<ILoggerProvider>> getProviders() = 0;

		template<class TKey, class ... TArgs>
		ILoggerFactory& useProvider(TArgs... args)
		{
			addProvider(std::make_shared<TKey>(args...));
			return *this;
		}
	};
}