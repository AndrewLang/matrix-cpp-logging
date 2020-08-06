#include "pch.h"
#include "gtest/gtest.h"
#include "logging/LogLevel.h"

namespace Logging
{
    TEST(LogLevelTests, Constructor) {
        LogLevel level("jasoom", 99);

        EXPECT_EQ("jasoom", level.getName());
        EXPECT_EQ(99, level.getValue());
    }
}