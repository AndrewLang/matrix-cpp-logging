#include "logging/LogLevel.h"

namespace Logging
{
	LogLevel::LogLevel(const std::string levelName, const int value)
		:mName(levelName)
		, mValue(value)
	{
	}

	LogLevel::LogLevel(const LogLevel& level) 
	{
		mName = level.mName;
		mValue = level.mValue;
		mAlias = level.mAlias;
	}

	LogLevel::~LogLevel()
	{
	}

	std::string LogLevel::getName() 
	{
		return mName;
	}

	std::string LogLevel::getAlias()
	{
		return mAlias;
	}

	int LogLevel::getValue()
	{
		return mValue;
	}

	LogLevel & LogLevel::setAlias(const std::string& value)
	{
		mAlias = value;
		return *this;
	}

} // namespace Logging