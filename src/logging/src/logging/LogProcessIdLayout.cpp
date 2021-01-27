#include "logging/LogProcessIdLayout.h"
#include "common/StringExtensions.h"


namespace Logging
{
	using namespace std;

	LogProcessIdLayout::LogProcessIdLayout(const std::string prefix)
		: mPrefix(prefix)
	{
	}

	LogProcessIdLayout::~LogProcessIdLayout()
	{
	}

	std::string LogProcessIdLayout::layout(const LogMessage & message)
	{
		return Consts::Empty;
	}

	std::string LogProcessIdLayout::getPrefix()
	{
		return mPrefix;
	}

	void LogProcessIdLayout::setPrefix(const std::string value)
	{
		mPrefix = value;
	}
}