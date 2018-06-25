//
// RuntimeTimer_test.cpp
//
// Copyright (C) 2011-2018, Maurer & Treutner GmbH & Co. KG
//
// SPDX-License-Identifier: BSL-1.0
//

#include "pmeas/RuntimeTimer.h"


#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <thread>

using namespace pmeas;

class RuntimeTimer_Test : public testing::Test
{
public:
    virtual ~RuntimeTimer_Test() = default;

    virtual void SetUp() override
    {}

    virtual void TearDown() override
    {} 
};

TEST_F(RuntimeTimer_Test,TimeMeasurement)
{
    using namespace std::chrono_literals;
    const RuntimeTimer<std::chrono::steady_clock>::timeunit SLEEP_TIME{10ms};
    RuntimeTimer<std::chrono::steady_clock>::timeunit execTime;
    {
        RuntimeTimer<std::chrono::steady_clock> tm(execTime);
        std::this_thread::sleep_for(SLEEP_TIME);
    }
    ASSERT_TRUE(execTime >= SLEEP_TIME);
}