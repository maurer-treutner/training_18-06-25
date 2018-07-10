#include <iostream>
#include <memory>

void usePtr(const std::shared_ptr<int> &val)
{
	std::cout << "usePtr Ptr use count:" << val.use_count() << std::endl;
}

void duplicatePtr(std::shared_ptr<int> val)
{
	std::cout << "duplicatePtr Ptr use count:" << val.use_count() << std::endl;
}

void movePtr(std::shared_ptr<int> &&val)
{
	auto localPtr = std::move(val);
	std::cout << "movePtr Ptr use count:" << localPtr.use_count() << std::endl;
}

int main(int argc, char *argv[])
{
	std::cout << "std::shared_ptr Demo" << std::endl;
	auto myPtr = std::make_shared<int>(42);
	usePtr(myPtr);
	std::cout << "Ptr use count after use: " << myPtr.use_count() << std::endl;
	duplicatePtr(myPtr);
	std::cout << "Ptr use count after diplicate: " << myPtr.use_count() << std::endl;
	movePtr(std::move(myPtr));
	std::cout << "Ptr use count after move: " << myPtr.use_count() << std::endl;
}