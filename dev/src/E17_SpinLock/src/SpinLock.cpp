#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

class SpinLock
{
  public:
    SpinLock() = default;
    SpinLock(SpinLock &) = delete;

    void lock()
    {
        while (_lock.test_and_set(std::memory_order_relaxed))
        {
        }
    }

    void unlock()
    {
        _lock.clear(std::memory_order_release);
    }

  private:
    std::atomic_flag _lock = ATOMIC_FLAG_INIT;
};

int main(int argc, char *argv[])
{
    int count = 0;
    std::vector<std::thread> threads;
    SpinLock lck;
    for (int i = 0; i < 100; ++i)
    {
        threads.push_back(std::thread([&count, &lck]() {
            for (int j = 0; j < 50000; j++)
            {
                lck.lock();
                count++;
                lck.unlock();
            }
        }));
    }

    for (auto &thread : threads)
    {
        thread.join();
    }

    std::cout << count << std::endl;
}