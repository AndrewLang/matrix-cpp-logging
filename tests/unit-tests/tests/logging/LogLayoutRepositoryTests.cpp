
#include "pch.h"
#include "gtest/gtest.h"
#include "logging/LogLayoutRepository.h"
#include "logging/LogNameLayout.h"
#include "logging/LogLevelLayout.h"

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
		EXPECT_NE(nullptr, repo.get(LayoutNames::None));
		EXPECT_NE(nullptr, repo.get("jasoom"));
	}


	TEST(LogLayoutRepositoryTests, AddGetCreator) {
		LogLayoutRepository repo;

		repo.add("name", []() { return std::make_shared<LogNameLayout>(); })
			.add("level", []() {return std::make_shared<LogLevelLayout>(); } );

		auto nameLayout = repo.get("name");
		EXPECT_NE(nullptr, nameLayout);

		auto levelLayout = repo.get("level");
		EXPECT_NE(nullptr, levelLayout);

		EXPECT_EQ(nullptr, repo.get("jasoom"));
	}
}