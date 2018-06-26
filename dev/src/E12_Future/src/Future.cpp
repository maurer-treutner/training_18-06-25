#include <iostream>
#include <future>
#include <chrono>

using namespace std::chrono_literals;

int main()
{
    std::cout<<"Future Demo"<<std::endl;

    int myNum = 3;
    auto result = std::async(std::launch::async,
        [](int val){
            std::this_thread::sleep_for(1000ms);
            return val*val;
        },myNum);
    while(result.wait_for(100ms)!=std::future_status::ready)
    {
        std::cout<<".";
        std::cout.flush();
    }
    std::cout<<std::endl;
    std::cout<<myNum<<" -> "<<result.get()<<std::endl;
    
}
