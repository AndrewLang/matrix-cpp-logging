
#include "pch.h"
#include "gtest/gtest.h"
#include "logging/LogMessageLayout.h"
#include "logging/LogMessage.h"
#include "Messages.h"

namespace Logging
{
	using namespace Tests;
	TEST(LogMessageLayoutTests, Constructor) {
		LogMessageLayout layout;
	}

	TEST(LogMessageLayoutTests, Layout) {
		LogMessageLayout layout;
		LogMessage msg = Messages::DebugMessage();
		auto content = layout.layout(msg);

		EXPECT_EQ("I come from Jasoom", content);
	}
}