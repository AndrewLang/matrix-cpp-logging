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

		std::string toString(LogLevelEnum level);

	private:	

		std::map<LogLevelEnum, std::string> mValues;
	};

}
