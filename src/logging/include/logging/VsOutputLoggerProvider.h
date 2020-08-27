#pragma once
#include "BaseLoggerProvider.h"

namespace Logging
{
	class VsOutputLoggerProvider : public BaseLoggerProvider
	{
	public:
		VsOutputLoggerProvider();

		~VsOutputLoggerProvider();

		std::shared_ptr<ILogger> createLogger(const std::string& name) override;
	};
}
