#include <chrono>
#include <iostream>
#include <future>

using namespace std::chrono_literals;

int main()
{
    std::cout << "Future Demo" << std::endl;

    auto result = std::async(std::launch::async, [](int i) {
        std::this_thread::sleep_for(1s);
        return i * i;
    },
                             3);
    std::cout << "Result: i*i =" << result.get() << std::endl;

    auto expresult = std::async(std::launch::async, [](int i) {
        std::this_thread::sleep_for(1s);
        if (i == 0)
            throw std::runtime_error("Division by zero");
        return 1 / i;
    },
                                0);
    try
    {
        std::cout << "Result: 1/i = " << expresult.get() << std::endl;
    }
    catch (...)
    {
        std::cout << "Exception caught when accessing result." << std::endl;
    }
}
