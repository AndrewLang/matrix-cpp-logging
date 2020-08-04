#pragma once
#include <memory>
#include <string>

namespace Logging
{
	class ILogger;

	class ILoggerProvider
	{
	public:
		virtual std::shared_ptr<ILogger> createLogger(std::string name) = 0;
	};

}