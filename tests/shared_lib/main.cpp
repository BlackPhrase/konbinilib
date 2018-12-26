#include <cstdlib>
#include <iostream>

#include "konbini/shared_lib.hpp"

using fnGetStubAPI = bool (*)();

int failed(const std::string &msg)
{
	std::cout << msg << std::endl;
	std::cin.get();
	return EXIT_FAILURE;
};

int main(int argc, char **argv)
{
	konbini::shared_lib StubLib("stublib");
	
	if(!StubLib)
		return failed("Failed to load the stub library!");
	
	auto pfnGetStubAPI{StubLib.getexportfunc<fnGetStubAPI>("GetStubAPI")};
	
	if(!pfnGetStubAPI)
		return failed("Failed to get the \"GetStubAPI\" export!");
	
	if(pfnGetStubAPI())
		std::cout << "\"GetStubAPI\" returns true!" << std::endl;
	else
		std::cout << "\"GetStubAPI\" returns false!" << std::endl;
	
	std::cin.get();
	return EXIT_SUCCESS;
};