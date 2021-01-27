#include "logging/LogIndentLayout.h"

#include "common/StringExtensions.h"

namespace Logging
{

	LogIndentLayout::LogIndentLayout()
	{
	}

	LogIndentLayout::~LogIndentLayout()
	{
	}

	std::string LogIndentLayout::layout(const LogMessage & message)
	{
		int indent = message.getIndent();
		if (indent > 0)
		{
			std::stringstream stream;
			for (int i = 0; i < indent; i++)
			{
				stream << Indent;
			}			
			return stream.str();
		}
		return Consts::Empty;
	}
}