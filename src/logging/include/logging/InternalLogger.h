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
		InternalLogger(std::shared_ptr<ILoggerFactory> factory, std::string name);

		InternalLogger() = delete;

		InternalLogger(const InternalLogger &) = delete;

		InternalLogger& operator=(const InternalLogger&) = delete;

		~InternalLogger();

		bool isEnabled(std::shared_ptr<LogLevel> level) override;

		void addProvider(std::shared_ptr<ILoggerProvider> provider);

		virtual ILogger& log(LogMessage message) override;

	private:
		std::shared_ptr<ILoggerFactory> mFactory;

		std::vector<std::shared_ptr<ILogger>> mLoggers;

		void initialize();

	protected:
		
	};

}