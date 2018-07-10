#include <iostream>
#include <memory>

void duplicatePtr(std::weak_ptr<int> val)
{
	std::cout << "duplicatePtr Ptr use count: " << val.use_count() << std::endl;
	std::cout << "             Ptr expired: " << val.expired() << std::endl;
}

int main(int argc, char *argv[])
{
	std::cout << "std::weak_ptr Demo" << std::endl;

	auto mySPtr = std::make_shared<int>(42);
	std::weak_ptr<int> myWPtr(mySPtr);
	duplicatePtr(myWPtr);
	auto sp = myWPtr.lock();
	std::cout << "myWPtr use count: " << myWPtr.use_count() << std::endl;
	mySPtr = nullptr;
	std::cout << "myWPtr use count: " << myWPtr.use_count() << std::endl;
	sp = nullptr;
	std::cout << "myWPtr use count: " << myWPtr.use_count() << std::endl;
}