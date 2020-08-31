#include "logging/LogLevel.h"

namespace Logging
{
	LogLevel::LogLevel(const std::string levelName, const int value)
		:name(levelName), value(value)
	{
	}

	LogLevel::LogLevel(const LogLevel& level) 
	{
		name = level.name;
		value = level.value;
	}

	LogLevel::~LogLevel()
	{
	}

	std::string LogLevel::getName() 
	{
		return name;
	}

	std::string LogLevel::getAlias()
	{
		return alias;
	}

	int LogLevel::getValue()
	{
		return value;
	}

	LogLevel & LogLevel::setAlias(const std::string& value)
	{
		alias = value;
		return *this;
	}

} // namespace Logging