#include "logging/LogThreadIdLayout.h"
#include "common/StringExtensions.h"
#include <thread>

namespace Logging
{

	LogThreadIdLayout::LogThreadIdLayout(const std::string prefix)
		: mPrefix(prefix)
	{
		
	}

	LogThreadIdLayout::~LogThreadIdLayout()
	{
	}

	std::string LogThreadIdLayout::layout(const LogMessage & message)
	{
		auto id = std::this_thread::get_id();
		std::stringstream stream;
		stream << mPrefix << id;
		return stream.str();
	}

	std::string LogThreadIdLayout::getPrefix()
	{
		return mPrefix;
	}

	void LogThreadIdLayout::setPrefix(const std::string value)
	{
		mPrefix = value;
	}
}