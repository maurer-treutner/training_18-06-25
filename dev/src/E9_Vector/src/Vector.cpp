#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>
#include <vector>
#include <memory>

bool isOdd(int i)
{
    return (i%2);
}

int main(int argc,char *argv[])
{
    std::vector<int> numbers {1,2,3,4,5,6,7,8,9,10};

    for(auto num : numbers)
    {
        std::cout<<"num = "<<num<<std::endl;
    }

    std::vector<std::unique_ptr<int>> pnumbers;
    for (auto num : numbers)
    {
        pnumbers.emplace_back(std::make_unique<int>(num*num));
    }

    for (const auto &pnum : pnumbers)
    {
        std::cout<<"pnum ="<<*pnum<<std::endl;
    }

    std::deque<int> dnumbers;

    // std::copy(numbers.begin(),numbers.end(),std::front_inserter(dnumbers));
    /*
    std::copy_if(numbers.begin(),numbers.end(),std::front_inserter(dnumbers),
        [](int v){
            return (v%2);
        });
    */
    /*
    auto copyCond = [](int v){
            return (v%2);
        };
    
    std::copy_if(numbers.begin(),numbers.end(),std::front_inserter(dnumbers),copyCond);
    */
    std::copy_if(numbers.begin(),numbers.end(),std::front_inserter(dnumbers),isOdd);

    std::copy(dnumbers.begin(),dnumbers.end(),
              std::ostream_iterator<int>(std::cout));

    

}