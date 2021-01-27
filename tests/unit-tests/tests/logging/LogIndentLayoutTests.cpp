
#include "pch.h"
#include "gtest/gtest.h"
#include "logging/LogIndentLayout.h"
#include "logging/LogMessage.h"
#include "Messages.h"

namespace Logging
{
	using namespace Tests;
	TEST(LogIndentLayoutTests, Constructor) {
		LogIndentLayout layout;
	}

	TEST(LogIndentLayoutTests, Layout) {
		LogIndentLayout layout;
		LogMessage msg = Messages::DebugMessage();
		auto content = layout.layout(msg);

		EXPECT_EQ("	", content);
	}
}