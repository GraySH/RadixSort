//============================================================================
// Name        : RadixSort_main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void radixSort(int arr[], int arraySize, int maxDigit)
{
	const int BUCKETSIZE = 10;

	//bucket size is digit size, each vector has queue to save more than one number to the bucket.
	vector< queue<int> > bucket;
	bucket.reserve(BUCKETSIZE);

	int radix;
	int divFact = 1;

	//initialize bucket, need nine digit for sorting number.
	for(int i = 0; i < BUCKETSIZE ; i++)
	{
		queue<int> tempQueue;
		bucket.push_back(tempQueue);
	}

	//extract digits from numbers, loop for digits of number
	for(int pos = 0; pos < maxDigit; pos++)
	{
		//do it for number of items in arr[]
		for(int arrayItemNum = 0; arrayItemNum < arraySize; arrayItemNum++)
		{
			//extract Nth digit
			radix = (arr[arrayItemNum] / divFact) % 10;

			//save the number to bucket by radix
			bucket[radix].push(arr[arrayItemNum]);
		}

		//read from bucket and save it to arr[]
		int arrayIndex = 0;
		for(unsigned int i = 0; i < bucket.size(); i++)
		{
			while( bucket[i].empty() != true )
			{
				//arr[arrayIndex++] = *iter->front();
				arr[arrayIndex++] = bucket[i].front();
				bucket[i].pop();
			}
		}

		//increase divFact to get next digit of the number
		divFact *= 10;
	}
}


int main()
{
	int arr[] = {123, 224, 232, 122, 100, 199, 478, 589, 77};

	int arrSize = sizeof(arr) / sizeof(int);

	radixSort(arr, arrSize, 3);

	for(int i = 0; i < arrSize; i++)
		cout <<  arr[i] << " ";
	cout << endl;

	return 0;
}
