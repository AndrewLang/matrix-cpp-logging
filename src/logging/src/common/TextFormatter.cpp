#include "common/TextFormatter.h"

namespace Logging
{
	TextFormatter & TextFormatter::DefaultTextFormatter()
	{
		static TextFormatter formatter;
		return formatter;
	}

	TextFormatter::TextFormatter(std::string separatorString)
		:separator(separatorString)
	{
	}
}