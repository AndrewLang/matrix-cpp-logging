#pragma once
#include <string>
#include <map>

#include "ILogger.h"

namespace Logging
{
	class LogLevelConverter
	{
	public:
		LogLevelConverter();

		~LogLevelConverter();

		std::string toString(LogLevel level);

	private:	

		std::map<LogLevel, std::string> mValues;
	};

}
