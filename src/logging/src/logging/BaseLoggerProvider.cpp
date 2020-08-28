#include "logging/BaseLoggerProvider.h"

namespace Logging
{
	void BaseLoggerProvider::configure(std::shared_ptr<LoggerContext> loggerContext)
	{
		context = loggerContext;
	}
}