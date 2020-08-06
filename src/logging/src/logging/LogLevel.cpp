#include "logging/LogLevel.h"

namespace Logging
{

	LogLevel::LogLevel(const std::string name, const int value)
		:name(name), value(value)
	{
	}

	LogLevel::~LogLevel()
	{
	}
} // namespace Logging