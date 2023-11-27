#include "quicksort.h"


template <typename T>
int partition(T arr[], int start, int end){
	
	int pivot = end;
	int j = start;
	for(int i=start;i<end;++i){
		if(arr[i]<arr[pivot]){
			swap(arr[i],arr[j]);
			++j;
		}
	}
	swap(arr[j],arr[pivot]);
	return j;
	
}

template <typename T>
void quicksort(T arr[], int start, int end ){

	if(start<end){
		int p = partition(arr,start,end);
        quicksort(arr,start,p-1);
        quicksort(arr,p+1,end);
	}
	
}