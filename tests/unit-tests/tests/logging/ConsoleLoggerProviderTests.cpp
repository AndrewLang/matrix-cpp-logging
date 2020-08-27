#include "pch.h"
#include "gtest/gtest.h"
#include "logging/ConsoleLoggerProvider.h"
#include "logging/ILogger.h"

namespace Logging
{
	TEST(ConsoleLoggerProviderTests, Constructor) {
		ConsoleLoggerProvider provider;
	}
	TEST(ConsoleLoggerProviderTests, CreateLogger)
	{
		ConsoleLoggerProvider provider;
		auto logger = provider.createLogger("test");
				
		ASSERT_EQ("test", logger->name);
	}

	TEST(ConsoleLoggerProviderTests, CreateLoggerWithConfiguration)
	{
		auto configuration = std::make_shared<Configuration>();
		
		auto config = std::make_shared<ConsoleLoggerConfig>();
		config->enableColor = true;
		config->isEnabled = true;
		config->type = "console";
		config->layout = "{{date}} {{name}}: {{message}}";

		configuration->addConfig(config);

		ConsoleLoggerProvider provider;
		provider.configure(configuration);

		auto logger = provider.createLogger("jasoom");
		ASSERT_EQ("jasoom", logger->name);

		logger->debug("Hellow Jasoom");

	}
}