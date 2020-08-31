#include "logging/LogLevelLayout.h"

#include "common/StringExtensions.h"

namespace Logging
{

	LogLevelLayout::LogLevelLayout()
	{
	}

	LogLevelLayout::~LogLevelLayout()
	{
	}

	std::string LogLevelLayout::layout(const LogMessage & message)
	{
		return message.getLevel()->getName();
	}
}