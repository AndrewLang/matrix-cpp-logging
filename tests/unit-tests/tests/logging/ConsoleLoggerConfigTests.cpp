#include "pch.h"
#include "gtest/gtest.h"
#include "logging/LoggerConfig.h"
#include "logging/LogLevels.h"
#include "common/VectorExtensions.h"

namespace Logging
{
	TEST(ColorConfigTests, Constructor)
	{
		ConsoleStyleConfig configure;
	}

	TEST(ColorConfigTests, ConstructorWithValues)
	{
		ConsoleStyleConfig configure("Debug", "red", "yellow", "bold" );

		EXPECT_EQ("Debug", configure.level);
		EXPECT_EQ("red", configure.foreColor);
		EXPECT_EQ("yellow", configure.backColor);
		EXPECT_EQ("bold", configure.style);
	}

	TEST(ConsoleLoggerConfigTests, Constructor)
	{
		ConsoleLoggerConfig configure;
	}

	TEST(ConsoleLoggerConfigTests, AddColors)
	{
		ConsoleLoggerConfig configure;

		configure.addStyle("Debug")
			.addStyle("Error", "red", "yellow", "bold")
			;

		EXPECT_EQ(2, configure.styles.size());
		EXPECT_EQ("Debug", configure.styles[0].level);
		EXPECT_EQ("", configure.styles[0].foreColor);
		EXPECT_EQ("", configure.styles[0].backColor);

		EXPECT_EQ("Error", configure.styles[1].level);
		EXPECT_EQ("red", configure.styles[1].foreColor);
		EXPECT_EQ("yellow", configure.styles[1].backColor);
		EXPECT_EQ("bold", configure.styles[1].style);
	}

	TEST(ConsoleLoggerConfigTests, DefaultConfig)
	{
		auto configure = ConsoleLoggerConfig::default();
		EXPECT_FALSE(configure->enableColor);
	}

	TEST(ConsoleLoggerConfigTests, DefaultConfigWithColor)
	{
		auto config = ConsoleLoggerConfig::defaultWithColor();

		EXPECT_TRUE(config->enableColor);

		auto actual = Vectors::firstOrDefault<ConsoleStyleConfig>(config->styles, [](ConsoleStyleConfig x) {return x.level == LogLevels::Debug; });
		EXPECT_EQ("", actual.foreColor);
		EXPECT_EQ("", actual.backColor);
		EXPECT_EQ("", actual.style);

		actual = Vectors::firstOrDefault<ConsoleStyleConfig>(config->styles, [](ConsoleStyleConfig x) {return x.level == LogLevels::Info; });
		EXPECT_EQ("47", actual.foreColor);
		EXPECT_EQ("", actual.backColor);
		EXPECT_EQ("", actual.style);

		actual = Vectors::firstOrDefault<ConsoleStyleConfig>(config->styles, [](ConsoleStyleConfig x) {return x.level == LogLevels::Warn; });
		EXPECT_EQ("226", actual.foreColor);
		EXPECT_EQ("", actual.backColor);
		EXPECT_EQ("", actual.style);

		actual = Vectors::firstOrDefault<ConsoleStyleConfig>(config->styles, [](ConsoleStyleConfig x) {return x.level == LogLevels::Error; });
		EXPECT_EQ("124", actual.foreColor);
		EXPECT_EQ("", actual.backColor);
		EXPECT_EQ("bold", actual.style);

		actual = Vectors::firstOrDefault<ConsoleStyleConfig>(config->styles, [](ConsoleStyleConfig x) {return x.level == LogLevels::Fatal; });
		EXPECT_EQ("226", actual.foreColor);
		EXPECT_EQ("124", actual.backColor);
		EXPECT_EQ("underline", actual.style);
	}
}