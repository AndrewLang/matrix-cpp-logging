
#include "pch.h"
#include "gtest/gtest.h"
#include "logging/LogLevelLayout.h"
#include "logging/LogMessage.h"
#include "Messages.h"

namespace Logging
{

	TEST(LogLevelLayoutTests, Constructor) {
		LogLevelLayout layout;
	}

	TEST(LogLevelLayoutTests, Layout) {
		LogLevelLayout layout;
		LogMessage msg = Messages::DebugMessage();
		auto content = layout.layout(msg);

		EXPECT_EQ("Debug", content);
	}
}