#include <iostream>
#include "task1.h"
#include <cmath>
#include <cstdlib>
using namespace std;


void push_back(unsigned int *&arr, int &size, const unsigned int value) {
	unsigned int *new_arr = new unsigned int[size + 1];
	for (int i = 0; i < size; i++)
	{
		new_arr[i] = arr[i];
	}
	new_arr[size] = value;
	delete[] arr;
	arr = new_arr;
	size++;
}
void prost(unsigned int *&arr, unsigned int &size2, const unsigned int vol) {
	unsigned int vol2 = vol;
	int iter = 0;
	unsigned int *a = new unsigned int[vol2];

	for (unsigned int i = 0; i < vol2; ++i)
	{
		a[i] = i + 1;
	}
	for (unsigned int i = 1; i < vol2; ++i)
	{
		if (a[i])
		{
			push_back(arr, iter, a[i]);
			size2++;

			for (unsigned int j = a[i] * a[i]; j <= vol2; j += a[i])
			{
				a[j - 1] = 0;
			}
		}
	}
	delete[] a;
	//arr[0] = 1;
}
unsigned long findValue(unsigned int min, unsigned int max) {
	unsigned int i = 0;
	unsigned int *arr = new unsigned int[0];
	prost(arr, i, max);
	const unsigned int v = max - min + 1;
	unsigned long res = 1;
	unsigned int *arr1 = new unsigned int[v];
	for (unsigned int ia = 0; ia < v; ia++) {
		arr1[ia] = min + ia;
	}
	bool test = false;
	for (int ia = 0; ia <= i; ia++) // primes 
	{
		for (unsigned int io = 0; io < v; io++) // min -> max
		{
			if (arr1[io] % arr[ia] == 0) {
				arr1[io] /= arr[ia];

				test = true;
			}
		}

		if (test) {
			res *= arr[ia];
			test = false;
			//ia = 0;
			ia--;
		}
	}
	return res;
}