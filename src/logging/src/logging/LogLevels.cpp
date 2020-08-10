#include "logging/LogLevels.h"
#include "common/MapExtensions.h"
#include "common/StringExtensions.h"


namespace Logging
{
	LogLevels::LogLevels()
	{
		initialize();
	}
	LogLevels::~LogLevels()
	{
		mLevels.clear();
	}
	void LogLevels::initialize()
	{
		add(All, 0)
			.add(Debug, 1000)
			.add(Info, 2000)
			.add(Warn, 3000)
			.add(Error, 4000)
			.add(Fatal, 5000)
			.add(None, 99999);

	}
	
	std::shared_ptr<LogLevel> LogLevels::all()
	{
		return Maps::get<std::string, std::shared_ptr<LogLevel>>(mLevels, All);
	}

	std::shared_ptr<LogLevel> LogLevels::debug()
	{
		return Maps::get<std::string, std::shared_ptr<LogLevel>>(mLevels, Debug);
	}

	std::shared_ptr<LogLevel> LogLevels::info()
	{
		return Maps::get<std::string, std::shared_ptr<LogLevel>>(mLevels, Info);
	}

	std::shared_ptr<LogLevel> LogLevels::warn()
	{
		return Maps::get<std::string, std::shared_ptr<LogLevel>>(mLevels, Warn);
	}

	std::shared_ptr<LogLevel> LogLevels::error()
	{
		return Maps::get<std::string, std::shared_ptr<LogLevel>>(mLevels, Error);
	}

	std::shared_ptr<LogLevel> LogLevels::fatal()
	{
		return Maps::get<std::string, std::shared_ptr<LogLevel>>(mLevels, Fatal);
	}

	std::shared_ptr<LogLevel> LogLevels::none()
	{
		return Maps::get<std::string, std::shared_ptr<LogLevel>>(mLevels, None);
	}

	LogLevels & LogLevels::add(const std::string name, const int value)
	{
		if (!Strings::isNullOrEmpty(name)) {
			mLevels[name] = std::make_shared<LogLevel>(name, value);
		}
		return *this;
	}
}