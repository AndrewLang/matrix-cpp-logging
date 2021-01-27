#include "logging/LogProcessIdLayout.h"
#include "common/StringExtensions.h"


namespace Logging
{
	using namespace std;

	LogProcessIdLayout::LogProcessIdLayout(const std::string prefix)
		: prefix(prefix)
	{
	}

	LogProcessIdLayout::~LogProcessIdLayout()
	{
	}

	std::string LogProcessIdLayout::layout(const LogMessage & message)
	{
		return Consts::Empty;
	}
}