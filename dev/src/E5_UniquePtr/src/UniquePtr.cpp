#include <iostream>
#include <memory>

auto square(const std::unique_ptr<int> &val)
{
	return (*val)*(*val);
}

auto kill_square(std::unique_ptr<int> &&ptr) // ownership goes to function
{
	auto p = std::move(ptr);
	return (*p)*(*p);
}

int main(int argc, char *argv[])
{     
	std::cout << "std::unique_ptr Demo" << std::endl;

	auto myNum = std::make_unique<int>(42);
	std::cout << "*myNum = "<<*myNum<<std::endl;
	std::cout << "square(myNum) = "<<square(myNum)<<std::endl; 
	std::cout << "kill_square(myNum) = "<<kill_square(std::move(myNum))<<std::endl;

	if (myNum)
	{
		std::cout<<"myNum ist true"<<std::endl;
	}

}