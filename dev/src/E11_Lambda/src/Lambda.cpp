#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <map>
#include <memory>


template <typename Product,typename ...Args>
std::unique_ptr<Product> createProduct(Args ...args)
{
    return std::make_unique<Product>(args...);
}


class DemoLambda
{
public:
    void doSmth()
    {
        std::cout<<"DemoLambda::doSmth() called"<<std::endl;
    }

    auto getCallback()
    {
        return [this](){doSmth();};
    }
};



class EventHandler
{
public:
    enum struct Event{E1,E2,E3};

    void dispatch(Event e, std::string data)
    {
        const std::map<Event,std::function<void (std::string)>> dispatchMap{
            std::make_pair(Event::E1,[this](std::string s){processE1(s);}),
            std::make_pair(Event::E2,[this](std::string s){processE2(s);}),
            std::make_pair(Event::E3,[this](std::string s){processE3(s);})           
        };
        auto fc = dispatchMap.find(e);
        if (fc!=dispatchMap.end())
        {
            fc->second(data);
        }
        else
        {
            throw std::runtime_error("Event not supported");
        }
    }

protected:
    void processE1(std::string data)
    {}

    void processE2(std::string data)
    {}

    void processE3(std::string data)
    {}


};


auto getCall()
{
    std::string name="Hugo";
    return [name = std::move(name)]()
    {
        std::cout<<name<<" called!"<<std::endl;
    };
}

auto getLambdas(std::vector<std::string> &&names)
{
    std::vector<std::function<void()>> lambdas;
    for ( auto &name : names )
    {
        lambdas.emplace_back([name=std::move(name)](){
            std::cout<<"Hello, "<<name<<std::endl;
        }
        );
    }
    return lambdas;
}

int main()
{
    std::cout<<"Lambda Demo"<<std::endl;

    std::string name = "Peter";

    auto myLambda = [&name](){
    
        std::cout<<name<<" has been called."<<std::endl;
    
    };

    name = "Horst";

    myLambda();

    auto testCall = getCall();
    
    for (auto i=0; i<10; i++)
    {
        testCall();
    }

    std::vector<std::string> names {"Willy","Herbert","Angela","Hillary"};
    auto testLambdas = getLambdas(std::move(names));
    for (auto & l : testLambdas)
    {
        l();
    }

    DemoLambda myDemo;
    auto cb = myDemo.getCallback();
    cb();
}
