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
	class ConsoleStyleConfig
	{
	public:
		std::string level;
		std::string foreColor;
		std::string backColor;
		std::string style;

		ConsoleStyleConfig();
		ConsoleStyleConfig(const std::string& level, const std::string& foreColor, const std::string& backColor = "", const std::string& style = "");
	};

	///<summary>
	/// Configuration for console logger
	///</summary>
	class ConsoleLoggerConfig : public LoggerConfig
	{
	public:
		bool enableColor;
		std::vector<ConsoleStyleConfig> styles;

		ConsoleLoggerConfig();

		ConsoleLoggerConfig& addStyle(const std::string& level, const std::string& foreColor = "", const std::string& backColor = "", const std::string& style = "");

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