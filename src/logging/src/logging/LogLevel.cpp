#include "logging/LogLevel.h"

namespace Logging
{
	LogLevel::LogLevel(const std::string name, const int value)
		:mName(name), mValue(value)
	{
	}

	LogLevel::~LogLevel()
	{
	}

	std::string LogLevel::getName() 
	{
		return mName;
	}

	int LogLevel::getValue()
	{
		return mValue;
	}
} // namespace Logging