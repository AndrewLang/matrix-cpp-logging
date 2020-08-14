#include "logging/LogNoneLayout.h"

#include "common/StringExtensions.h"

namespace Logging
{

	LogNoneLayout::LogNoneLayout()
	{
	}

	LogNoneLayout::~LogNoneLayout()
	{
	}

	std::string LogNoneLayout::layout(const LogMessage & message)
	{
		return Strings::Empty;
	}
}