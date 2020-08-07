#pragma once
#include "ILogger.h"
#include "LogLevelConverter.h"


namespace Logging
{
	class LoggerBase :public ILogger
	{
	public:
		LoggerBase();

		~LoggerBase();

		bool isEnabled(LogLevelEnum level) override;

		ILogger& debug(std::string message) override;

		ILogger& trace(std::string message) override;

		ILogger& info(std::string message) override;

		ILogger& warning(std::string message) override;

		ILogger& error(std::string message) override;

		ILogger& fatal(std::string message) override;

	protected:
		std::string format(LogLevelEnum level, std::string message, int eveintId = 0, std::exception* exception = nullptr, TextFormatter formatter = TextFormatter::DefaultTextFormatter());

		LogLevelConverter mConverter;

		std::string wrapText(std::string value);
	};

}