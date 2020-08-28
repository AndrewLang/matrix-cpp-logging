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

		template<class T>
		std::shared_ptr<T> get(const std::string& type)
		{
			auto context = getConfig(type);
			if (context != nullptr)
			{
				return std::static_pointer_cast<T>(context);
			}
			return nullptr;
		}

	private:
		std::map<std::string, std::shared_ptr<LoggerConfig>> configs;
	};


}