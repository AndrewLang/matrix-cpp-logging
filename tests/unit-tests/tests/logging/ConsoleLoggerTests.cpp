#include "pch.h"
#include "gtest/gtest.h"
#include "logging/ConsoleLogger.h"
#include "logging/LogLevels.h"

namespace Logging
{	
	ConsoleLogger createLogger(const std::string & name = "test") {
		std::vector<std::shared_ptr<ILogLayout>> layouts;
		ConsoleLogger logger(name, layouts, LogLevels::Default()-> all());

		return logger;
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
			.warning("This is warning message");
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
}