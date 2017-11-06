// SIMD Examples.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

void 	vectorarithmatic()
{
	float f1[] = { 1.f, 2.f, 3.f, 4.f };
	float f2[] = { 5.f, 4.f, 3.f, 2.f };

	float result[4] = { 0.f };

	_asm
	{
		/*
		 * MOVUPS - Move Unaligned Packed Single-Precision Floating-Point Values
		 */
		movups xmm1, f1;
		movups xmm2, f2;

		/*
		 * MULPS - Multiply Packed Single-Precision Floating-Point Values
		 */
		mulps xmm1, xmm2;

		movups result, xmm1;
	}

	/* Write  result */
	for (int i = 0; i < 4; i++)
	{
		cout << result[i] << "\t";
	}
	cout << endl;
}

int main()
{
	vectorarithmatic();
    return 0;
}

