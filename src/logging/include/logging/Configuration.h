#pragma once
#include "LogLevel.h"

#include <vector>
#include <map>

namespace Logging
{
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
	private:

	};

	class FileLoggerConfig : public LoggerConfig
	{
	public:
		std::string filename;

	};


	class Configuration
	{
	public:
		Configuration();

		~Configuration();

		Configuration& addConfig(std::shared_ptr<LoggerConfig> configure);

		std::shared_ptr<LoggerConfig> getConfig(const std::string& type);
	private:
		std::map<std::string, std::shared_ptr<LoggerConfig>> configs;
	};


}