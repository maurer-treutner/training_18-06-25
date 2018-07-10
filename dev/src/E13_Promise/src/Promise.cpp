#include <chrono>
#include <iostream>
#include <future>
#include <thread>

using namespace std::chrono_literals;

int main()
{
    std::promise<int> res_prom;
    auto res = res_prom.get_future();
    auto myThread = std::thread([](std::promise<int> &&p) {
        std::this_thread::sleep_for(500ms);
        p.set_value(42);
        std::this_thread::sleep_for(500ms);
        std::cout << "Thread done." << std::endl;
    },
                                std::move(res_prom));
    std::cout << "Result: " << res.get() << std::endl;
    myThread.join();
    std::cout << "Program exiting." << std::endl;
}
