// MergingArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>

int main()
{
	// two ordered array
	int array1[] = { 2,3,4,5,7,8,9,10};
	int array2[] = { 4,6,7,9};
	// get length of array
	int length1 = sizeof(array1) / sizeof(array1[0]);
	int length2 = sizeof(array2) / sizeof(array2[0]);
	//set new array
	int *newarray = (int *)malloc((length1 + length2) * sizeof(int));
	int i = 0, j = 0, m = 0;
	// add number into newarray until an array comes to end 
	while (i < length1 && j <length2 ) {
		if (array1[i] < array2[j]) {
			newarray[m] = array1[i];
			i++;
		}
		else if (array1[i] > array2[j]) {
			newarray[m] = array2[j];
			j++;
		}
		else {
			newarray[m] = array1[i];
			i++;
			j++;
		}
		m++;
	}
	//if there is one array not come to end, continuing looping to end
	while (i < length1) {
		newarray[m] = array1[i];
		i++;
		m++;
	}
	while (j < length2) {
		newarray[m] = array2[j];
		j++;
		m++;
	}
	//print
	for (int i = 0; i < m; i++) {
		printf("%d", newarray[i]);
	}
	system("pause");
    return 0;
}

