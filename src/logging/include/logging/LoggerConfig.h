#pragma once
#include "LogLevel.h"

#include <vector>
#include <map>

namespace Logging
{
	class LoggerConfigTypes
	{
	public:
		static constexpr const char* Console = "console";
		static constexpr const char* File = "file";
		static constexpr const char* VsOutput = "vsoutput";
	};

	class LoggerConfig
	{
	public:
		bool isEnabled;
		std::string type;
		std::string layout;
		std::shared_ptr<LogLevel> level;
	};

	class ColorConfig
	{
	public:
		std::string level;
		std::string foreColor;
		std::string backColor;
	};

	class ConsoleLoggerConfig : public LoggerConfig
	{
	public:
		bool enableColor;
		std::vector<ColorConfig> colors;

		ConsoleLoggerConfig();
	private:

	};

	class FileLoggerConfig : public LoggerConfig
	{
	public:
		std::string filename;

		FileLoggerConfig();
	};

}