#pragma once
#include <string>

namespace Logging
{
	class LogLevel
	{
	public:
		LogLevel(const std::string name, const int value);

		LogLevel(const LogLevel& level);

		LogLevel() = delete;

		~LogLevel();

		std::string getName();

		std::string getAlias();

		int getValue();

		LogLevel& setAlias(const std::string& value);

	private:
		std::string mName;
		std::string mAlias;
		int mValue;
	};

} // namespace Logging