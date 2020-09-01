#include "pch.h"
#include "gtest/gtest.h"
#include "logging/LoggerConfig.h"


namespace Logging
{
	TEST(ColorConfigTests, Constructor)
	{
		ColorConfig config;
	}

	TEST(ColorConfigTests, ConstructorWithValues)
	{
		ColorConfig config("Debug", "red", "yellow" );

		EXPECT_EQ("Debug", config.level);
		EXPECT_EQ("red", config.foreColor);
		EXPECT_EQ("yellow", config.backColor);
	}

	TEST(ConsoleLoggerConfigTests, Constructor)
	{
		ConsoleLoggerConfig config;
	}

	TEST(ConsoleLoggerConfigTests, AddColors)
	{
		ConsoleLoggerConfig config;

		config.addColor("Debug")
			.addColor("Error", "red", "yellow")
			;

		EXPECT_EQ(2, config.colors.size());
		EXPECT_EQ("Debug", config.colors[0].level);
		EXPECT_EQ("", config.colors[0].foreColor);
		EXPECT_EQ("", config.colors[0].backColor);

		EXPECT_EQ("Error", config.colors[1].level);
		EXPECT_EQ("red", config.colors[1].foreColor);
		EXPECT_EQ("yellow", config.colors[1].backColor);
	}

	TEST(ConsoleLoggerConfigTests, DefaultConfig)
	{
		auto config = ConsoleLoggerConfig::default();
		EXPECT_FALSE(config->enableColor);
	}

	TEST(ConsoleLoggerConfigTests, DefaultConfigWithColor)
	{
		auto config = ConsoleLoggerConfig::defaultWithColor();

		EXPECT_TRUE(config->enableColor);
	}
}