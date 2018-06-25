//
// RuntimeTimer_test.cpp
//
// Copyright (C) 2011-2018, Maurer & Treutner GmbH & Co. KG
//
// SPDX-License-Identifier: BSL-1.0
//

#include "pmeas/RuntimeMeasurement.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <thread>
#include <iostream>

using namespace pmeas;

class RuntimeMeasurement_Test : public testing::Test
{
public:
    virtual ~RuntimeMeasurement_Test() = default;

    virtual void SetUp() override
    {}

    virtual void TearDown() override
    {}    
};

TEST_F(RuntimeMeasurement_Test,TestBracketOperator)
{
    using clock = std::chrono::steady_clock;
    using namespace std::chrono_literals;
    RuntimeMeasurement<clock> rtm(100);
    RuntimeTimer<clock>::timeunit measuredDuration;
    {
        RuntimeTimer<clock> tm(measuredDuration);
        rtm([](RuntimeMeasurement<clock>::timeunit &tm){
            RuntimeTimer<std::chrono::steady_clock> timer(tm);
            std::this_thread::sleep_for(1ms);
         });
    }
    ASSERT_GE(measuredDuration,rtm.totalTime());
    ASSERT_GE(rtm.totalTime(),100ms);
    ASSERT_GE(rtm.minTime(),1ms);
    ASSERT_GE(rtm.averageTime(),rtm.minTime());
    ASSERT_GE(rtm.maxTime(),rtm.averageTime());
    ASSERT_GT(rtm.totalTime(),rtm.maxTime());
}

TEST_F(RuntimeMeasurement_Test,Test2ndMeasurement)
{
    using clock = std::chrono::steady_clock;
    using namespace std::chrono_literals;
    RuntimeMeasurement<clock> rtm(100);
    rtm([](auto &tm){
        RuntimeTimer<clock> timer(tm);
        std::this_thread::sleep_for(500us);
    });
    // rtm.printResult(std::cout,"Test1");
    ASSERT_GT(rtm.minTime(),500us);
    rtm([](auto &tm){
        RuntimeTimer<clock> timer(tm);
        std::this_thread::sleep_for(5ms);
    });
    ASSERT_GT(rtm.minTime(),5ms);
    // rtm.printResult(std::cout,"Test1");
    ASSERT_TRUE(true);
}
