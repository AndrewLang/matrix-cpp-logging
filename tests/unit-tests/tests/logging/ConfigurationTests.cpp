#include "pch.h"
#include "gtest/gtest.h"
#include "logging/Configuration.h"
#include "logging/LogLevels.h"

namespace Logging
{
	std::shared_ptr<LoggerConfig> createConfig() {
		auto configure = std::make_shared<LoggerConfig>();
		configure->isEnabled = true;
		configure->type = "jasoom";
		configure->level = LogLevels::Default()->info();


		return configure;
	}
	TEST(ConfigurationTests, Constructor) {
		Configuration configure;
	}

	TEST(ConfigurationTests, AddGetConfig) {
		Configuration configuration;

		auto configure = createConfig();
		configuration.addConfig(configure);

		auto actual = configuration.getConfig("jasoom");

		EXPECT_NE(nullptr, actual);

		EXPECT_EQ("jasoom", actual->type);
		EXPECT_EQ("Info", actual->level->getName());
		EXPECT_TRUE(actual->isEnabled);

	}

	TEST(ConfigurationTests, GetConfig) {
		Configuration configuration;

		auto configure = std::make_shared<ConsoleLoggerConfig>(); 
		configure->type = "console";
		configure->level = LogLevels::Default()->info();
		configure->isEnabled = true;
		configure->enableColor = true;
		configuration.addConfig(configure);

		auto actual = configuration.get<ConsoleLoggerConfig>("console");

		EXPECT_NE(nullptr, actual);

		EXPECT_EQ("console", actual->type);
		EXPECT_EQ("Info", actual->level->getName());
		EXPECT_TRUE(actual->isEnabled);
		EXPECT_TRUE(actual->enableColor);
		EXPECT_EQ(0, actual->styles.size());

	}
}