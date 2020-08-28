#include "pch.h"
#include "gtest/gtest.h"
#include "logging/ConsoleLoggerProvider.h"
#include "logging/ILogger.h"
#include "logging/LoggerFactory.h"
#include "logging/LogLevels.h"

namespace Logging
{
	TEST(ConsoleLoggerProviderTests, Constructor) 
	{
		ConsoleLoggerProvider provider;
	}
	TEST(ConsoleLoggerProviderTests, CreateLogger)
	{
		auto configuration = std::make_shared<Configuration>();
		auto factory = std::make_shared<LoggerFactory>();
		factory->configure(configuration);

		factory->useProvider<ConsoleLoggerProvider>();

		auto consoleConfig = std::make_shared<ConsoleLoggerConfig>();
		consoleConfig->enableColor = true;
		consoleConfig->isEnabled = true;
		consoleConfig->type = LoggerConfigTypes::Console;
		consoleConfig->layout = "{{date}} {{name}}: {{message}}";

		configuration->addConfig(consoleConfig);

		ConsoleLoggerProvider provider;
		provider.configure(factory->getContext());

		auto logger = provider.createLogger("test");
				
		ASSERT_EQ("test", logger->name);
	}

	TEST(ConsoleLoggerProviderTests, CreateLoggerWithConfiguration)
	{
		auto factory = std::make_shared<LoggerFactory>();
		auto configuration = std::make_shared<Configuration>();
		
		auto consoleConfig = std::make_shared<ConsoleLoggerConfig>();
		consoleConfig->enableColor = true;
		consoleConfig->isEnabled = true;
		consoleConfig->type = LoggerConfigTypes::Console;
		consoleConfig->level = LogLevels::Default()->info();
		consoleConfig->layout = "{{date}} {{name}}: {{message}}";

		configuration->addConfig(consoleConfig);

		factory->configure(configuration);
		
		ConsoleLoggerProvider provider;
		provider.configure(factory->getContext());

		auto logger = provider.createLogger("jasoom");
		ASSERT_EQ("jasoom", logger->name);

		logger->debug("Hellow Jasoom");

	}
}