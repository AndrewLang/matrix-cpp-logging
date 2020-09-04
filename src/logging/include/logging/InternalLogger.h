#pragma once

#include "ILogger.h"
#include "ILoggerFactory.h"
#include "ILoggerProvider.h"

#include <memory>
#include <string>

namespace Logging
{
	class InternalLogger : public ILogger
	{
	public:
		InternalLogger(std::shared_ptr<ILoggerFactory> factory, const std::string& name);

		InternalLogger() = delete;

		InternalLogger(const InternalLogger &) = delete;

		InternalLogger& operator=(const InternalLogger&) = delete;

		~InternalLogger();

		bool isEnabled(std::shared_ptr<LogLevel> level) override;

		void addProvider(std::shared_ptr<ILoggerProvider> provider);

		virtual ILogger& log(LogMessage& message) override;

		std::vector<std::shared_ptr<ILogger>> getLoggers();

	private:
		std::shared_ptr<ILoggerFactory> factory;

		std::vector<std::shared_ptr<ILogger>> loggers;

		void initialize();

	protected:
		
	};

}