#pragma once
#include "LoggerConfig.h"

#include <map>

namespace Logging
{
	class ConsoleColorRenderer
	{
	public:
		ConsoleColorRenderer();
		~ConsoleColorRenderer();

		void initialize(std::shared_ptr<ConsoleLoggerConfig> configure);

		std::string render(const std::string& level,const std::string& text);

		std::shared_ptr<ConsoleLoggerConfig> getConfig();

	private:
		std::shared_ptr<ConsoleLoggerConfig> mConfig;
		std::map<std::string, std::string> mStyles;

		static constexpr const char* StyleEsc = "\033[";
		static constexpr const char* StyleEnd = "m";
		static constexpr const char* Color256Start = "38;5;";
		static constexpr const char* Color256BgStart = "48;5;";
		static constexpr const char* Color256End = "";
		static constexpr const char* Separator = ";";

		static std::map<std::string, std::string> knownStyles;
	};

}