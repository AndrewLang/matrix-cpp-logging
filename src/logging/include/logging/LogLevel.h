#pragma once
#include <string>

namespace Logging
{
	class LogLevel
	{
	private:
		std::string mName;
		std::string mAlias;
		int mValue;

	public:
		LogLevel(const std::string name, const int value);

		LogLevel(const LogLevel& level);

		LogLevel() = delete;

		~LogLevel();

		std::string getName();

		int getValue();

		LogLevel& setAlias(const std::string value);
	};

} // namespace Logging