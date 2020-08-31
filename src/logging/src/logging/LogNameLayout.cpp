#include "logging/LogNameLayout.h"

#include "common/StringExtensions.h"

namespace Logging
{

	LogNameLayout::LogNameLayout()
	{
	}

	LogNameLayout::~LogNameLayout()
	{
	}

	std::string LogNameLayout::layout(const LogMessage & message)
	{
		return	message.getName();
	}
}