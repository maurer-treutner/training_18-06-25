#include <chrono>
#include <functional>
#include <future>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

int main()
{
    std::cout << "Thread and Task Demo" << std::endl;

    std::packaged_task<int(int)> myTask([](int i) {
        std::cout << "Task started" << std::endl;
        std::this_thread::sleep_for(500ms);
        return i * i;
    });
    auto myResult = myTask.get_future();
    std::cout << "Future assigned, starting task in next step" << std::endl;
    myTask(7);
    std::this_thread::yield();
    while (myResult.wait_for(100ms) == std::future_status::timeout)
    {
        std::cout << ".";
        std::cout.flush();
    }
    std::cout << "Result = " << myResult.get() << std::endl;
}
