#include "pch.h"
#include "gtest/gtest.h"
#include "logging/VsOutputLoggerProvider.h"
#include "logging/ILogger.h"
#include "logging/LogLevels.h"
#include "logging/LoggerFactory.h"

namespace Logging
{
	TEST(VsOutputLoggerProviderTests, Constructor) 
	{
		VsOutputLoggerProvider provider;
	}

	TEST(VsOutputLoggerProviderTests, CreateLogger) {
		auto configuration = std::make_shared<Configuration>();

		auto consoleConfig = std::make_shared<LoggerConfig>();
		consoleConfig->type = LoggerConfigTypes::VsOutput;
		consoleConfig->isEnabled = true;
		consoleConfig->level = LogLevels::Default()->info();
		consoleConfig->layout = "{date} {name}: {message}";

		configuration->addConfig(consoleConfig);

		auto factory = std::make_shared<LoggerFactory>();
		factory->configure(configuration);


		VsOutputLoggerProvider provider;
		provider.configure(factory->getContext());

		auto logger = provider.createLogger("test");

		EXPECT_EQ("test", logger->name);
	}
}