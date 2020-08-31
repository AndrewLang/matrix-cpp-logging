#pragma once
#include <string>

namespace Logging
{
	class LogLevel
	{
	private:
		std::string name;
		std::string alias;
		int value;

	public:
		LogLevel(const std::string name, const int value);

		LogLevel(const LogLevel& level);

		LogLevel() = delete;

		~LogLevel();

		std::string getName();

		std::string getAlias();

		int getValue();

		LogLevel& setAlias(const std::string& value);
	};

} // namespace Logging