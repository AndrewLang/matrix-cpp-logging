#include "logging/LogTextLayout.h"

#include "common/StringExtensions.h"

namespace Logging
{

	LogTextLayout::LogTextLayout()
	{
	}

	LogTextLayout::LogTextLayout(const std::string& text)
		:mContent(text)
	{
	}

	LogTextLayout::~LogTextLayout()
	{
	}

	std::string LogTextLayout::layout(const LogMessage & message)
	{
		return mContent;
	}
}