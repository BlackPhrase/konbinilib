/*
 *	This file is part of konbinilib
 *	Copyright (C) 2017-2018 BlackPhrase
 */

/// @file
/// @brief RAII-styled shared lib handle class

#pragma once

//#include <cassert>

#include "types.hpp"
#include "noncopyable.hpp"

namespace konbini
{

#if KONBINI_PLATFORM == KONBINI_PLATFORM_WINDOWS
	using tLibHandle = HMODULE;
#else
	using tLibHandle = void*;
#endif

//shared_lib *LoadLib(const char *asPath);

class shared_lib : public noncopyable
{
public:
	shared_lib() : mpLibHandle(nullptr){}
	
	shared_lib(const tString &asPath) : msPath(asPath)
	{
		open(msPath);

		//assert(mpLibHandle);
	};
	
	virtual ~shared_lib(){close();} // TODO: why virtual?
	
	bool open(const tString &asPath) // TODO: load?
	{
		close();
		
		if constexpr(Platform == PlatformType::Windows)
			mpLibHandle = LoadLibrary(asPath.c_str());
		else
			mpLibHandle = dlopen(asPath.c_str(), RTLD_NOW);
		
		return mpLibHandle ? true : false;
	};
	
	void *getexportfunc(const tString &asName) const
	{
		//assert(mpLibHandle);
		
		void *pFunc{nullptr};
		
	if constexpr(Platform == PlatformType::Windows)
		pFunc = (void*)GetProcAddress(mpLibHandle, asName.c_str());
	else
		pFunc = dlsym(mpLibHandle, asName.c_str());
		
		return pFunc;
	};
	
	template<typename T>
	T getexportfunc(const tString &asName) const {return (T)getexportfunc(asName);}
	
	const tString &getpath() const {return msPath;}
	const tString &getname() const {return msName;}
private:
/*
	struct info
	{
		// info about the shared lib (name, handle, etc)
	};
*/

	void close() // TODO: unload? make public?
	{
		if(!mpLibHandle)
			return;

		if constexpr(Platform == PlatformType::Windows)
			FreeLibrary(mpLibHandle);
		else
			dlclose(mpLibHandle);
	};
	
	tString msPath{""}; ///< Full path to the library
	tString msName{""}; ///< Name of library
	
	tLibHandle mpLibHandle{nullptr}; ///< Instance of the loaded library
};

}; // namespace konbini