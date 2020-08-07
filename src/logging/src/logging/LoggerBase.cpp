#include "logging/LoggerBase.h"

namespace Logging
{
	using std::string;


	LoggerBase::LoggerBase()
	{
	}


	LoggerBase::~LoggerBase()
	{
	}

	bool Logging::LoggerBase::isEnabled(LogLevelEnum level)
	{
		return true;
	}

	ILogger & LoggerBase::debug(std::string message)
	{
		log(LogLevelEnum::Debug, message);
		return *this;
	}

	ILogger & LoggerBase::trace(std::string message)
	{
		log(LogLevelEnum::Trace, message);
		return *this;
	}

	ILogger & LoggerBase::info(std::string message)
	{
		log(LogLevelEnum::Information, message);
		return *this;
	}

	ILogger & LoggerBase::warning(std::string message)
	{
		log(LogLevelEnum::Warning, message);
		return *this;
	}

	ILogger & LoggerBase::error(std::string message)
	{
		log(LogLevelEnum::Error, message);
		return *this;
	}

	ILogger & LoggerBase::fatal(std::string message)
	{
		log(LogLevelEnum::Fatal, message);
		return *this;
	}
	
	std::string LoggerBase::format(LogLevelEnum level, std::string message, int eveintId, std::exception* exception, TextFormatter formatter)
	{
		string levelText = level == LogLevelEnum::None ?
			"" : wrapText(mConverter.toString(level));

		if (exception)
		{
			return formatter.format(levelText, message, exception->what());
		}
		return formatter.format(levelText, message);
	}

	string LoggerBase::wrapText(string value)
	{
		return "[" + value + "]";
	}
}