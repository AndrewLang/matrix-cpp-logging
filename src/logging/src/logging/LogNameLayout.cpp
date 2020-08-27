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
		std::string name = message.getName();
		/*if (Strings::notNullOrEmpty(name))
		{
			std::stringstream stream;
			stream << LogLayout::BracketLeft << name << LogLayout::BracketRight;
			return stream.str();			
		}*/
		return name;
	}
}