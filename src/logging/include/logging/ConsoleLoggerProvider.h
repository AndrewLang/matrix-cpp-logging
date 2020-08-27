#pragma once
#include "ILoggerProvider.h"
#include "BaseLoggerProvider.h"

namespace Logging
{
	class ConsoleLoggerProvider : public BaseLoggerProvider
	{
	public:
		ConsoleLoggerProvider();

		~ConsoleLoggerProvider();

		std::shared_ptr<ILogger> createLogger(const std::string& name) override;

	private:
		
	};	
}