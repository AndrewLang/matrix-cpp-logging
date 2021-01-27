#include "logging/ConsoleColorRender.h"
#include "common/MapExtensions.h"
#include "common/StringExtensions.h"
#include "common/VectorExtensions.h"

namespace Logging
{
	using std::string;

	std::map<std::string, std::string>ConsoleColorRenderer::knownStyles = {
		{"", ""},
		{"bold", "1"},
		{"dim", "2"},
		{"underline", "4"},
		{"blink", "5"},
		{"reverse", "7"},
		{"hidden", "8"},
	};

	ConsoleColorRenderer::ConsoleColorRenderer()
	{
	}

	ConsoleColorRenderer::~ConsoleColorRenderer()
	{
	}

	void ConsoleColorRenderer::initialize(std::shared_ptr<ConsoleLoggerConfig> loggerConfig)
	{
		mConfig = loggerConfig;
	}

	std::string ConsoleColorRenderer::render(const std::string& level, const std::string & text)
	{
		if (!Maps::contains<string, string>(mStyles, level))
		{
			auto consoleStyles = mConfig->styles;
			auto config = Vectors::firstOrDefault<ConsoleStyleConfig>(consoleStyles, [=](ConsoleStyleConfig x) {return x.level == level; });

			std::stringstream stream;

			stream << StyleEsc;
			
			if (Strings::notNullOrEmpty(config.foreColor))
			{
				stream << Color256Start << config.foreColor ;
			}
			if (Strings::notNullOrEmpty(config.backColor))
			{
				if (Strings::notNullOrEmpty(config.foreColor))
					stream << Separator;

				stream << Color256BgStart << config.backColor;
			}
			if (Strings::notNullOrEmpty(config.style))
			{
				std::vector<string> parts;
				for (auto& item : Strings::split(config.style, ','))
				{
					string style = Maps::get<string, string>(knownStyles, item);
					if (Strings::notNullOrEmpty(style))
						parts.push_back(style);
				}

				string result = Vectors::join(parts, ";");
				if (Strings::notNullOrEmpty(result))
				{
					if (Strings::notNullOrEmpty(config.foreColor) || Strings::notNullOrEmpty(config.backColor))
						stream << Separator;

					stream << result;
				}
			}

			stream << StyleEnd;

			mStyles[level] = stream.str();
		}

		string format = Maps::get<string, string>(mStyles, level);

		std::stringstream stream;
		stream << format << text << StyleEsc << StyleEnd;
		return stream.str();
	}
	
	std::shared_ptr<ConsoleLoggerConfig> ConsoleColorRenderer::getConfig()
	{
		return mConfig;
	}
}