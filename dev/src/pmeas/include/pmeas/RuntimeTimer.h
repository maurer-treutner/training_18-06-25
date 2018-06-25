//
// PerformanceTimer.h
//
// Copyright (C) 2011-2018, Maurer & Treutner GmbH & Co. KG
//
// SPDX-License-Identifier: BSL-1.0
//

#ifndef __PMEAS_RUNTIMETIMER_H__
#define __PMEAS_RUNTIMETIMER_H__

#include <chrono>

namespace pmeas
{
/**
 * RuntimeTimer is a scoped timer to measure the runtime
 * of a code block.
 */
template <typename clock=std::chrono::steady_clock>
class RuntimeTimer
{
public:
    using timeunit = std::chrono::nanoseconds;
    /**
     * @brief Create a RuntimeTimer storing the measured runtime in duration
     * 
     * @param duration  Shall be defined in outer scope
     */
    RuntimeTimer(timeunit &duration):
        _duration(duration),
        _startTime(clock::now())
    {}
    
    /**
     * @brief Stores the measured time in duration
     */
    ~RuntimeTimer()
    {
        _duration = std::chrono::duration_cast<timeunit>(clock::now() - _startTime);
        // std::cout<<"Test: "<<_duration.count()<<std::endl;
    }

public:
    decltype(clock::now()) _startTime;
    timeunit& _duration;
};

} // namespace pmeas

#endif // __PMEAS_RUNTIMETIMER_H__