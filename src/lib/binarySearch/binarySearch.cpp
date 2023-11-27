#include "binarySeach.h"

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
