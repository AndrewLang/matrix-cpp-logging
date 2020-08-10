#include "logging/LogLevel.h"

namespace Logging
{
	LogLevel::LogLevel(const std::string name, const int value)
		:mName(name), mValue(value)
	{
	}

	LogLevel::LogLevel(const LogLevel& level) 
	{
		mName = level.mName;
		mValue = level.mValue;
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

	LogLevel & LogLevel::setAlias(const std::string value)
	{
		mAlias = value;
		return *this;
	}

} // namespace Logging