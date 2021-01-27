
#include "logging/LogTimestampLayout.h"

#include "common/StringExtensions.h"

namespace Logging 
{
    LogTimestampLayout::LogTimestampLayout()
    {
    }

    LogTimestampLayout::~LogTimestampLayout()
    {
    }

	std::string LogTimestampLayout::layout(const LogMessage & message)
	{
		std::string timestamp = message.getTimmestamp();
		if (Strings::notNullOrEmpty(timestamp))
		{
			return timestamp;
		}
		return Consts::Empty;
	}
}