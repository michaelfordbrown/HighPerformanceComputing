// GetCPUName.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

string get_cpu_name()
{
	uint32_t data[4] = { 0 };

	_asm
	{
		/* 
		 * CPUID (CPU IDentification)
		 *
		 * EAX=0: Get vendor ID (including EAX=1: Get CPUID)
		 * This returns the CPU's manufacturer ID string – a twelve-character ASCII string stored in EBX, EDX, ECX (in that order). 
		 * The highest basic calling parameter (largest value that EAX can be set to before calling CPUID) is returned in EAX.
		 */
		cpuid;
		mov data[0], ebx;
		mov data[4], edx;
		mov data[8], ecx;
	}

	return string((const char*)data);
}

void getssesupport()
{
	int d, c;

	_asm
	{
		/*
		* CPUID (CPU IDentification)
		*
		* EAX=1: Processor Info and Feature Bits
		*/
		mov eax, 1;
		cpuid;
		mov d, edx;
		mov c, ecx;
	}

	if ((d & (1 << 26)) != 0)
		cout << "SSE2 is supported " << endl;

	if ((c & 1) != 0)
		cout << "SSE3 is supported " << endl;

	if ((c & (1 << 19)) != 0)
		cout << "SSE4.1 is supported " << endl;

	if ((c & (1 << 20)) != 0)
		cout << "SSE4.2 is supported " << endl;

}

void assember()
{
	cout << "CPU is " << get_cpu_name() << endl;
}	

int main()
{
	cout << "Get CPU Name" << endl;
	assember();

	cout << "Level of SSE Support for This Computer" << endl;
	getssesupport();

    return 0;
}

