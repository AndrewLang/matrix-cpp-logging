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

	///<summary>
	/// Configuration for a logger
	///</summary>
	class LoggerConfig
	{
	public:
		bool isEnabled;
		std::string type;
		std::string layout;
		std::shared_ptr<LogLevel> level;
	};

	///<summary>
	/// Configuration for color setting in console logger
	///</summary>
	class ColorConfig
	{
	public:
		std::string level;
		std::string foreColor;
		std::string backColor;

		ColorConfig();
		ColorConfig(const std::string& level, const std::string& foreColor, const std::string& backColor = "");
	};

	///<summary>
	/// Configuration for console logger
	///</summary>
	class ConsoleLoggerConfig : public LoggerConfig
	{
	public:
		bool enableColor;
		std::vector<ColorConfig> colors;

		ConsoleLoggerConfig();

		ConsoleLoggerConfig& addColor(const std::string& level, const std::string& foreColor = "", const std::string& backColor = "");

		static std::shared_ptr<ConsoleLoggerConfig> default();

		static std::shared_ptr<ConsoleLoggerConfig> defaultWithColor();
	private:

	};


	///<summary>
	/// Configuration for file logger
	///</summary>
	class FileLoggerConfig : public LoggerConfig
	{
	public:
		std::string filename;

		FileLoggerConfig();
	};

}