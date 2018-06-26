#include <iostream>

#include <thread>
#include <chrono>

using namespace std::chrono_literals;

int main()
{
    std::cout<<"Thread and Task Demo"<<std::endl;

    std::string name="Peter";

    std::thread myThread([name=std::move(name)](/*std::string &&name*/)
        {
            std::cout<<name<<" from thread"<<std::endl;
            std::this_thread::sleep_for(1000ms);
            std::cout<<"finished"<<std::endl;
        }/*,std::move(name)*/
    );
    myThread.detach();
    std::this_thread::sleep_for(1ms);
    std::cout<<"from main: "<<name<<std::endl;
    std::this_thread::sleep_for(10ms);
    // myThread.join();
}
