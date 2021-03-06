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
	
	operator bool(){return mpLibHandle != nullptr;}
	
	bool open(const tString &asPath) // TODO: load?
	{
		close();
		
#if KONBINI_PLATFORM == KONBINI_PLATFORM_WINDOWS
			mpLibHandle = LoadLibrary(asPath.c_str());
#else
			mpLibHandle = dlopen(asPath.c_str(), RTLD_NOW);
#endif
		
		return mpLibHandle ? true : false;
	};
	
	void *getexportfunc(const tString &asName) const
	{
		//assert(mpLibHandle);
		
		void *pFunc{nullptr};
		
#if KONBINI_PLATFORM == KONBINI_PLATFORM_WINDOWS
		pFunc = (void*)GetProcAddress(mpLibHandle, asName.c_str());
#else
		pFunc = dlsym(mpLibHandle, asName.c_str());
#endif
		
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

#if KONBINI_PLATFORM == KONBINI_PLATFORM_WINDOWS
			FreeLibrary(mpLibHandle);
#else
			dlclose(mpLibHandle);
#endif
	};
	
	tString msPath{""}; ///< Full path to the library
	tString msName{""}; ///< Name of library
	
	tLibHandle mpLibHandle{nullptr}; ///< Instance of the loaded library
};

}; // namespace konbini