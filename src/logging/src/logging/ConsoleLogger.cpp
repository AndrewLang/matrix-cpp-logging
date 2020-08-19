#include "logging/ConsoleLogger.h"

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

namespace Logging
{
	ConsoleLogger::ConsoleLogger()	
	{

	}

	ConsoleLogger::ConsoleLogger(const std::string& loggerName, std::vector<std::shared_ptr<ILogLayout>> loggerLayouts, std::shared_ptr<LogLevel> loggerMiniLevel)
		:LoggerBase(loggerName, loggerLayouts, loggerMiniLevel)
	{

	}

	ConsoleLogger::ConsoleLogger(const ConsoleLogger& logger)
	{
		name = logger.name;
		layouts = logger.layouts;
		miniLevel = logger.miniLevel;
	}
	
	ConsoleLogger::~ConsoleLogger()
	{
		
	}

	void ConsoleLogger::write(std::string message)
	{
		cout << message << endl;
	}
	
}