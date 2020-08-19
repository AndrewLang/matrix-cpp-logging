#pragma once
#include "ILoggerProvider.h"

namespace Logging
{
	class ConsoleLoggerProvider : public ILoggerProvider
	{
	public:
		ConsoleLoggerProvider();
		~ConsoleLoggerProvider();

		std::shared_ptr<ILogger> createLogger(const std::string& name) override;
	};	
}