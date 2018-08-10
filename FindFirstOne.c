/*
* @author @vaishaknair
* @date 09/08/2018
*/

#include<stdio.h>
#include<math.h>

int getFirstOnesIndex(int *array, int startIndex, int endIndex);

int probeCount = 0;

int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};


int main() {
	printf("Index of first 1: %d\n", getFirstOnesIndex(arr, 0, (sizeof(arr) / sizeof(int)) - 1));
	printf("Probe count: %d\n", probeCount);
}


int getFirstOnesIndex(int *array, int startIndex, int endIndex) {
	int mid = ceil((startIndex + endIndex) / 2.0);
	printf("Start index = %d End index = %d Mid = %d\n", startIndex, endIndex, mid);
	if (startIndex == endIndex) {
		probeCount++;
		if(array[startIndex] == 0) {
			
			return startIndex + 1;		
		}	
		else {
			return startIndex;
		}
	}

	probeCount++;
	if(array[mid] == 0) {
		if(mid == endIndex) {// Absence of this piece was resulting in stack overflow in the previous version.
			endIndex = mid+1;
		}
		return getFirstOnesIndex(array, mid+1, endIndex);		
	}	
	else {
		return getFirstOnesIndex(array, startIndex, mid-1);
	}
}
