#include "linearSearch.h"

template <typename T>
int linearSearch(T arr[], int n, T x) {

	for (int i = 0; i < n; ++i) {

		if (arr[i] == x)
			return i;

	}

	return -1;

}