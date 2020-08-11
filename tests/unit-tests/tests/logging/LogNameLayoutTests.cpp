
#include "pch.h"
#include "gtest/gtest.h"
#include "logging/LogNameLayout.h"
#include "logging/LogMessage.h"
#include "Messages.h"

namespace Logging
{
	
	TEST(LogNameLayoutTests, Constructor) {
		LogNameLayout layout;
	}

	TEST(LogNameLayoutTests, Layout) {
		LogNameLayout layout;
		LogMessage msg = Messages::DebugMessage();
		auto content = layout.layout(msg);

		EXPECT_EQ("[Jasoom]", content);
	}
}