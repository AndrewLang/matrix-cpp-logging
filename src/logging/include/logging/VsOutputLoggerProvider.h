#pragma once
#include "ILoggerProvider.h"

namespace Logging
{
	class VsOutputLoggerProvider : public ILoggerProvider
	{
	public:
		VsOutputLoggerProvider();

		~VsOutputLoggerProvider();

		std::shared_ptr<ILogger> createLogger(std::string name) override;
	};
}
