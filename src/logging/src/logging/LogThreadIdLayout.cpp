#include "logging/LogThreadIdLayout.h"
#include "common/StringExtensions.h"
#include <thread>

namespace Logging
{

	LogThreadIdLayout::LogThreadIdLayout(const std::string prefix)
		: prefix(prefix)
	{
		
	}

	LogThreadIdLayout::~LogThreadIdLayout()
	{
	}

	std::string LogThreadIdLayout::layout(const LogMessage & message)
	{
		auto id = std::this_thread::get_id();
		std::stringstream stream;
		stream << prefix << id;
		return stream.str();
	}
}