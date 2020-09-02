#include "pch.h"
#include "gtest/gtest.h"
#include "logging/ConsoleLogger.h"
#include "logging/LogLevels.h"
#include "logging/LogLayoutRepository.h"

#if defined(_WIN32)
#include <Windows.h>
#endif

namespace Logging
{
	ConsoleLogger createLogger(const std::string & name = "test") {
		LogLayoutRepository repo;
		repo.initialize();

		auto layouts = repo.parse("{timestamp} {level} {name}: {message}");

		ConsoleLogger logger(name, layouts, LogLevels::Default()->all());

		return logger;
	}

	void writeLine(const std::string& line)
	{
		std::cout << line << std::endl;
	}

	TEST(ConsoleLoggerTests, Constructor) {
		auto logger = createLogger();

		EXPECT_EQ("test", logger.name);
	}

	TEST(ConsoleLoggerTests, LogMessage) {
		ConsoleLogger logger = createLogger();

		EXPECT_EQ("test", logger.name);

		logger.debug("Output message to VS output window.")
			.error("This is an error message")
			.fatal("This is fatal message")
			.info("This is info message")
			.warn("This is warning message");
	}

	TEST(ConsoleLoggerTests, LogMessageWithFormatter) {
		ConsoleLogger logger = createLogger();

		EXPECT_EQ("test", logger.name);

	}

	TEST(ConsoleLoggerTests, LogMessageWithName) {
		std::vector<std::shared_ptr<ILogLayout>> layouts;
		std::shared_ptr<ILogger> logger = std::make_shared<ConsoleLogger>("test", layouts, LogLevels::Default()->all());


		EXPECT_EQ("test", logger->name);

		logger->info("title", "1. this is a test")
			.info("title", "2. this is a test")
			.info("title", "3. this is a test")
			.info("title", "4. this is a test");
	}

	TEST(ConsoleLoggerTests, LogWithStyleSetting) {
		auto config = ConsoleLoggerConfig::defaultWithColor();
		auto logger = createLogger();
		logger.configure(config);

		logger.debug("Jasoom debug")
			.info("Jasoom info")
			.warn("Jasoom warn")
			.error("Jasoom error")
			.fatal("Jasoom fatal");
	}
	TEST(ConsoleLoggerTests, ColorfulPrototype) {
#if defined(_WIN32)
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD consoleMode;
		GetConsoleMode(hConsole, &consoleMode);
		consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

		if (!SetConsoleMode(hConsole, consoleMode))
		{
			std::cout << "Enable color console error: " << GetLastError() << std::endl;
		}
		else
		{
			std::cout << "Enable console coloring." << std::endl;
		}
#endif	

		// foreground styles
		std::cout << std::endl << "Foreground 256 color" << std::endl;
		for (int i = 0; i <= 256; i++) {
			std::cout << "\033[38;5;" << i << "m" << "Color: " << i << "\033[0m" << "\t";

			if (i > 0 && (i + 1) % 5 == 0)
				std::cout << std::endl;
		}
		std::cout << std::endl;

		// background styles
		std::cout << std::endl << "Background 256 color" << std::endl;
		for (int i = 0; i <= 256; i++) {
			std::cout << "\033[48;5;" << i << "m" << "Color: " << i << "\033[0m" << "\t";

			if (i > 0 && (i + 1) % 5 == 0)
				std::cout << std::endl;
		}
		std::cout << std::endl;

		// styles
		writeLine("");
		writeLine("Styles");

		writeLine( "\033[1m Bold text \033[0m" );
		writeLine( "\033[2m Dim text \033[0m" );
		writeLine( "\033[4m Underline text \033[0m" );
		writeLine( "\033[5m Blink text \033[0m" );
		writeLine( "\033[7m Inverted text \033[0m" );
		writeLine( "\033[8m Hidden text (not supported on windows)\033[0m" );



		writeLine("");
		writeLine("Combine Styles");
		writeLine("");
		writeLine("\033[38;5;245;48;5;4;1;4;7m Combined styles with 256 colors, bold, underline\033[0m");
		writeLine("\033[38;5;245;48;5;24m Combined styles with 256 colors\033[0m");
		writeLine("\033[38;5;46;48;5;234;1m Combined styles with 256 colors\033[0m");
		writeLine("\033[38;5;226;48;5;198;4m Combined styles with 256 colors\033[0m");
		writeLine("\033[38;5;166;48;5;232;1;4m Combined styles with 256 colors\033[0m");
		writeLine("\033[38;5;196;7m Combined styles with 256 colors\033[0m");

		writeLine("");
		writeLine("\x1B[mJasoom\x1B[m");
		writeLine("\x1B[38;5;46mJasoom\x1B[m");
		writeLine("\x1B[38;5;226mJasoom\x1B[m");
		writeLine("\x1B[38;5;226;48;5;124;1mJasoom\x1B[m");
		writeLine("\x1B[38;5;124;1;4mJasoom\x1B[m");
	}

}