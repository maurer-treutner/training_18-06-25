#include <thread>
#include <atomic>
#include <iostream>
#include <vector>

struct AtomicCounter
{
    std::atomic<long> value; // Atomic value will work
    // long value; // Non atomic value will meet race condition results

    AtomicCounter() : value(0) {}

    void increment()
    {
        ++value;
    }

    void decrement()
    {
        --value;
    }

    int get()
    {
        return value;
    }
};

int main()
{
    AtomicCounter counter;

    std::vector<std::thread> threads;
    for (int i = 0; i < 100; ++i)
    {
        threads.push_back(std::thread([&counter]() {
            for (int i = 0; i < 50000; ++i)
            {
                counter.increment();
            }
        }));
    }

    for (auto &thread : threads)
    {
        thread.join();
    }

    std::cout << counter.get() << std::endl;

    return 0;
}