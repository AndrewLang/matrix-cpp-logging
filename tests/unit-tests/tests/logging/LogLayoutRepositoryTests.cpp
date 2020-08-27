
#include "pch.h"
#include "gtest/gtest.h"
#include "logging/LogLayoutRepository.h"
#include "logging/LogNameLayout.h"
#include "logging/LogLevelLayout.h"
#include "logging/LogLevels.h"

namespace Logging
{

	TEST(LogLayoutRepositoryTests, Constructor) {
		LogLayoutRepository repo;
	}

	TEST(LogLayoutRepositoryTests, Initialize) {
		LogLayoutRepository repo;
		repo.initialize();

		EXPECT_NE(nullptr, repo.get(LayoutNames::Name));
		EXPECT_NE(nullptr, repo.get(LayoutNames::Level));
		EXPECT_NE(nullptr, repo.get(LayoutNames::Timestamp));
		EXPECT_NE(nullptr, repo.get(LayoutNames::Message));
		EXPECT_NE(nullptr, repo.get(LayoutNames::Indent));
		EXPECT_NE(nullptr, repo.get(LayoutNames::ThreadId));
		EXPECT_NE(nullptr, repo.get(LayoutNames::ProcessId));
		EXPECT_NE(nullptr, repo.get(LayoutNames::Text));
		EXPECT_NE(nullptr, repo.get(LayoutNames::None));

		EXPECT_EQ(nullptr, repo.get("jasoom"));
	}


	TEST(LogLayoutRepositoryTests, AddGetCreator) {
		LogLayoutRepository repo;

		repo.add("name", []() { return std::make_shared<LogNameLayout>(); })
			.add("level", []() {return std::make_shared<LogLevelLayout>(); });

		auto nameLayout = repo.get("name");
		EXPECT_NE(nullptr, nameLayout);

		auto levelLayout = repo.get("level");
		EXPECT_NE(nullptr, levelLayout);

		EXPECT_EQ(nullptr, repo.get("jasoom"));
	}

	TEST(LogLayoutRepositoryTests, ParseFromFormatString)
	{
		LogLayoutRepository repo;
		repo.initialize();

		LogMessage message(LogLevels::Default()->debug(), "jasoom", "I come from jasoom", "08-07-2020 10:10:10");

		std::string format = "{timestamp} {level} {name}: {message}";


		auto actual = repo.parse(format);

		EXPECT_EQ(7, actual.size());
		EXPECT_EQ("08-07-2020 10:10:10", actual[0]->layout(message));
		EXPECT_EQ(" ", actual[1]->layout(message));
		EXPECT_EQ("Debug", actual[2]->layout(message));
		EXPECT_EQ(" ", actual[3]->layout(message));
		EXPECT_EQ("jasoom", actual[4]->layout(message));
		EXPECT_EQ(": ", actual[5]->layout(message));
		EXPECT_EQ("I come from jasoom", actual[6]->layout(message));

		format = "{timestamp} [{level}] [{name}]: {message}";
		actual = repo.parse(format);
		EXPECT_EQ(" [", actual[1]->layout(message));
		EXPECT_EQ("] [", actual[3]->layout(message));
		EXPECT_EQ("]: ", actual[5]->layout(message));
	}

	TEST(LogLayoutRepositoryTests, ParseFromEmptyString)
	{
		LogLayoutRepository repo;
		repo.initialize();

		std::string format = "";

		auto actual = repo.parse(format);
		EXPECT_EQ(0, actual.size());
	}
}