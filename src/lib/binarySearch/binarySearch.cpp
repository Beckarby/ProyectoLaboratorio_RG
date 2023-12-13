#include "binarySearch.h"

template<typename T>
int binarySearch(T arr[], int n, T x)
{
	int start = 0;
	int end = n-1;
	while(start<=end)
	{
		int mid = (start+end)/2;
		if(arr[mid]==x)	
			return mid;
		else if(arr[mid]<x)	
			start = mid + 1;
		else	
			end = mid - 1;
	}
	return -1;
}


template int binarySearch<std::string>(std::string arr[], int n, std::string x);
template int binarySearch<int>(int arr[], int n, int x);
template int binarySearch<float>(float arr[], int n, float x);
template int binarySearch<long long>(long long arr[], int n, long long x);