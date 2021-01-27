#pragma once
#include <memory>
#include <string>

#include "Configuration.h"
#include "LoggerContext.h"

namespace Logging
{
	class ILogger;

	class ILoggerProvider
	{
	public:
		virtual ~ILoggerProvider() = default;

		virtual void configure(std::shared_ptr<LoggerContext> context) = 0;

		virtual std::shared_ptr<ILogger> createLogger(const std::string& name) = 0;

	protected:
		ILoggerProvider() = default;
	};

}