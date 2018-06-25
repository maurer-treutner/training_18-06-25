//
// RuntimeMeasurement
//
// Copyright (C) 2011-2018, Maurer & Treutner GmbH & Co. KG
//
// SPDX-License-Identifier: BSL-1.0
//

#ifndef __PMEAS_RUNTIMEMEASUREMENT_H__
#define __PMEAS_RUNTIMEMEASUREMENT_H__

#include <algorithm>
#include <chrono>
#include <functional>
#include <numeric>
#include <ostream>
#include <vector>

#include "RuntimeTimer.h"

namespace pmeas
{

/**
 * @brief RuntimeMeasurement allows the measurement of runtime of
 *      code given as lambda functions
 */
template <typename clock=std::chrono::steady_clock>
class RuntimeMeasurement
{
public:
    using timeunit = typename RuntimeTimer<clock>::timeunit;

    RuntimeMeasurement(int repeatCount):
        _repeatCount(repeatCount)
    {}

    void operator () (std::function<void(timeunit&)> fun)
    {
        std::vector<timeunit> timeMeasurements;
        timeMeasurements.reserve(_repeatCount);
        for (int i=0;i<_repeatCount;i++)
        {
            timeunit time;
            fun(time);
            timeMeasurements.emplace_back(time);
        }
        int idx=0;
        _totalTime = std::accumulate(timeMeasurements.begin(),timeMeasurements.end(),timeunit{0});
        _averageTime = _totalTime / timeMeasurements.size();
        auto maxIt = std::max_element(timeMeasurements.begin(),timeMeasurements.end());
        auto minIt = std::min_element(timeMeasurements.begin(),timeMeasurements.end());
        _maxTime = *maxIt;
        _minTime = *minIt;
    }

    auto totalTime() const
    {
        return _totalTime;
    }

    auto averageTime() const
    {
        return _averageTime;
    }

    auto maxTime() const
    {
        return _maxTime;
    }

    auto minTime() const
    {
        return _minTime;
    }

    void printResult(std::ostream &os,std::string testname)
    {
        os<<"min:"<<_minTime.count()<<"\t"
            <<"av: "<<_averageTime.count()<<"\t"
            <<"max: "<<_maxTime.count()<<"\t"
            <<"total:"<<_totalTime.count()<<"\t"
            <<"rep:"<<_repeatCount<<"\t"
            <<testname<<std::endl;
    }

    static void printEmptyFunctionResult(std::ostream &os,int repeatCount)
    {
        RuntimeMeasurement<clock> rtm(repeatCount);
        rtm([](timeunit &tm){
            RuntimeTimer<clock> timer(tm);
        });
        rtm.printResult(os,"Empty Funtion");
    }

private:
    int _repeatCount;
    timeunit _totalTime {0};
    timeunit _averageTime {0};
    timeunit _maxTime{0};
    timeunit _minTime{0};
    double _sigma{0.};
};

} // namespace pmeas

#endif // __PMEAS_RUNTIMEMEASUREMENT_H__