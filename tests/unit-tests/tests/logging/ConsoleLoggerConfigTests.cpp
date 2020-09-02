#include "pch.h"
#include "gtest/gtest.h"
#include "logging/LoggerConfig.h"


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
		auto configure = ConsoleLoggerConfig::defaultWithColor();

		EXPECT_TRUE(configure->enableColor);
	}
}