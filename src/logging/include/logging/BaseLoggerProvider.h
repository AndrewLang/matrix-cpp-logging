#pragma once
#include "ILoggerProvider.h"

namespace Logging
{
	class BaseLoggerProvider : public ILoggerProvider
	{
	public:		
		void configure(std::shared_ptr<LoggerContext> context) override;

	protected:
		std::shared_ptr<LoggerContext> context;
	};
}