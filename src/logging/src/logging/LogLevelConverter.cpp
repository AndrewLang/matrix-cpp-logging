#include "logging/LogLevelConverter.h"

namespace Logging
{
	LogLevelConverter::LogLevelConverter()
	{
		mValues[LogLevelEnum::Trace] = "Trace";
		mValues[LogLevelEnum::Debug] = "Debug";
		mValues[LogLevelEnum::Information] = "Information";
		mValues[LogLevelEnum::Warning] = "Warning";
		mValues[LogLevelEnum::Error] = "Error";
		mValues[LogLevelEnum::Fatal] = "Fatal";
		mValues[LogLevelEnum::None] = "None";
	}

	LogLevelConverter::~LogLevelConverter()
	{
		mValues.clear();
	}

	std::string LogLevelConverter::toString(LogLevelEnum level)
	{
		auto iterator = mValues.find(level);
		if (iterator != mValues.end())
		{
			return iterator->second;
		}
		return "";
	}
}
