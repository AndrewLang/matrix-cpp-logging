#pragma once
#include "ILoggerProvider.h"

namespace Logging
{
	class BaseLoggerProvider : public ILoggerProvider
	{
	public:		
		void configure(std::shared_ptr<Configuration> configuration) override;

	protected:
		std::shared_ptr<Configuration> config;
	};
}