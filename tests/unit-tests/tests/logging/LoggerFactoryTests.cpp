#include "pch.h"
#include "gtest/gtest.h"
#include "logging/ILogger.h"
#include "logging/LoggerFactory.h"
#include "logging/ILoggerFactory.h"
#include "logging/ConsoleLoggerProvider.h"

#include <vector>


namespace Logging
{
	TEST(LoggerFactoryTests, Constructor)
	{
		auto factory = std::make_shared<LoggerFactory>();
	}
	TEST(LoggerFactoryTests, AddProvider)
	{
		LoggerFactory factory;

		auto provider = std::make_shared<ConsoleLoggerProvider>();

		factory.addProvider(provider);

		auto providers = factory.getProviders();

		ASSERT_EQ(1, providers.size());
	}
	TEST(LoggerFactoryTests, AddGenericProvider)
	{
		LoggerFactory factory;

		factory.useProvider<ConsoleLoggerProvider>();

		auto providers = factory.getProviders();

		ASSERT_EQ(1, providers.size());
	}

	TEST(LoggerFactoryTests, CreateLoggerByPointer)
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

		auto logger = factory->createLogger("test");

		ASSERT_EQ("test", logger->name);
	}
	TEST(LoggerFactoryTests, CreateLoggerByInstance)
	{
		EXPECT_ANY_THROW(
			{

				/*
				LoggerFactory implemented shared_from_this, so it needs create a shared pointer to
				LoggerFactory first, otherwise there will be a bad weak ptr exception
				*/
				LoggerFactory factory;

				factory.useProvider<ConsoleLoggerProvider>();

				auto logger = factory.createLogger("test");

				ASSERT_EQ("test", logger->name);
			}
		);

	}

}