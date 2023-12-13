#include "linearSearch.h"

template <typename T>
int linearSearch(T arr[], int n, T x) {

	for (int i = 0; i < n; ++i) {

		if (arr[i] == x)
			return i;

	}

	return -1;

}

template int linearSearch<std::string>(std::string arr[], int n, std::string x);
template int linearSearch<int>(int arr[], int n, int x);
template int linearSearch<float>(float arr[], int n, float x);
template int linearSearch<long long>(long long arr[], int n, long long x);