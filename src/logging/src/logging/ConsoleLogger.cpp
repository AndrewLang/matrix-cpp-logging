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

	void ConsoleLogger::configure(std::shared_ptr<ConsoleLoggerConfig> config)
	{
		loggerConfig = config;

		if (loggerConfig && loggerConfig->enableColor)
		{
			renderer = std::make_shared<ConsoleColorRenderer>();
			renderer->initialize(loggerConfig);
		}
	}

	void ConsoleLogger::write(std::string message)
	{
		cout << message << endl;
	}

	std::string ConsoleLogger::preWrite(LogMessage & message, const std::string & text)
	{
		if (loggerConfig && loggerConfig->enableColor)
		{
			return renderer->render(message.getLevel()->getName(), text);
		}
		else
		{
			return text;
		}
	}

}