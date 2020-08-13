#include "logging/LogMessageLayout.h"

#include "common/StringExtensions.h"

namespace Logging
{

	LogMessageLayout::LogMessageLayout()
	{
	}

	LogMessageLayout::~LogMessageLayout()
	{
	}

	std::string LogMessageLayout::layout(const LogMessage & message)
	{
		return message.getMessage();
	}
}