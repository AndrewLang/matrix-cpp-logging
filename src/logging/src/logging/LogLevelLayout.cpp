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
		std::string name = message.getLevel()->getName();
		/*if (Strings::notNullOrEmpty(name))
		{
			std::stringstream stream;
			stream << LogLayout::BracketLeft << name << LogLayout::BracketRight;
			return stream.str();
		}*/
		return name;
	}
}