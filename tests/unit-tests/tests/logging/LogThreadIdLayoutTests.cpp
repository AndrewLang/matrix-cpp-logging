
#include "pch.h"
#include "gtest/gtest.h"
#include "logging/LogThreadIdLayout.h"
#include "logging/LogMessage.h"
#include "Messages.h"

namespace Logging
{
	using namespace std;
	using namespace Tests;

	TEST(LogThreadIdLayoutTests, Constructor) {
		LogThreadIdLayout layout;
	}

	TEST(LogThreadIdLayoutTests, Layout) {
		LogThreadIdLayout layout;
		LogMessage msg = Messages::DebugMessage();
		auto content = layout.layout(msg);
		
		std::cout << content << std::endl;
	}
}