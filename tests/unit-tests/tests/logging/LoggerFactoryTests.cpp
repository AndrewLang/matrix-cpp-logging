#include "pch.h"
#include "gtest/gtest.h"
#include "logging/ILogger.h"
#include "logging/LoggerFactory.h"
#include "logging/ILoggerFactory.h"
#include "logging/ConsoleLoggerProvider.h"
#include "logging/VsOutputLoggerProvider.h"
#include "logging/LogLevels.h"

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

	TEST(LoggerFactoryTests, CreateLoggerWithPointer)
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

	TEST(LoggerFactoryTests, CreateLoggersWithReference)
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

	TEST(LoggerFactoryTests, CreateLoggerWithConfiguration)
	{
		auto configuration = std::make_shared<Configuration>();

		auto consoleConfig = ConsoleLoggerConfig::defaultWithColor(); 
		
		auto vsConfig = std::make_shared<LoggerConfig>();
		vsConfig->isEnabled = true;
		vsConfig->type = LoggerConfigTypes::VsOutput;
		vsConfig->layout = "{timestamp} {level} {name}: {message}";

		configuration->addConfig(consoleConfig)
			.addConfig(vsConfig);


		auto factory = std::make_shared<LoggerFactory>();
		factory->configure(configuration);
		factory->useProvider<ConsoleLoggerProvider>()
			.useProvider<VsOutputLoggerProvider>();

		
		auto logger = factory->createLogger("jasoom");
		auto internalLogger = std::static_pointer_cast<InternalLogger>(logger);

		ASSERT_EQ("jasoom", logger->name);

		ASSERT_NE(nullptr, internalLogger);
		ASSERT_TRUE(internalLogger->isEnabled(LogLevels::Default()->debug()));
		ASSERT_EQ(2, internalLogger->getLoggers().size());

		logger->debug("This is Jasoom");
	}
}