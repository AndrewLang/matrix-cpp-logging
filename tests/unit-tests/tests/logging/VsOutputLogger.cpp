#include "pch.h"
#include "gtest/gtest.h"
#include "logging/VsOutputLogger.h"
#include "logging/LogLevels.h"
#include "logging/LogLayoutRepository.h"

#include <memory>

namespace Logging
{
	VsOutputLogger createLogger() {
		auto layoutRepo = std::make_shared<LogLayoutRepository>();
		layoutRepo->initialize();
		auto layouts = layoutRepo->parse("{timestamp} [{level}] [{name}]: {message}");

		VsOutputLogger logger("test", layouts, LogLevels::Default()->all());

		return logger;
	}

	TEST(VsOutputLoggerTests, Constructor)
	{
		VsOutputLogger logger = createLogger();

		EXPECT_EQ("test", logger.name);
	}

	TEST(VsOutputLoggerTests, LogMessages)
	{
		VsOutputLogger logger = createLogger();

		EXPECT_EQ("test", logger.name);

		logger.debug("this is debug")
			.error("this is error")
			.fatal("this is fatal")
			.info("this is info")			
			.warn("this is warning");
	}

	TEST(VsOutputLoggerTests, LogWithGroup)
	{
		VsOutputLogger logger = createLogger();

		EXPECT_EQ("test", logger.name);

		logger			
			.debug("this is debug")
			.error("this is error")
			.fatal("this is fatal")
			.info("this is info")
			.warn("this is warning")
			;
	}

	TEST(VsOutputLoggerTests, LogMessageWithName) {
		std::vector<std::shared_ptr<ILogLayout>> layouts;
		std::shared_ptr<ILogger> logger = std::make_shared<VsOutputLogger>("test", layouts, LogLevels::Default()->all());


		EXPECT_EQ("test", logger->name);

		logger->info("Iron man", "1. this is a test")
			.info("Spider man", "2. this is a test")
			.info("Caption American", "3. this is a test")
			.info("Hulk", "4. this is a test");
	}
}