// Reverseanarray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>

int* reverse(int array[]) {
	//j indicate number from last
	int j = 9;
	for (int i = 0; i < 5; i++) {
		// change position of i and j(9-i)
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		j--;
	}
	return array;
}

int main()
{
	// init a array
	int array[] = { 1,2,3,4,5,6,7,8,9,0 };
	reverse(array);
	// print array
	printf("reversed array is : ");
	for (int i = 0; i < 10; i++) {
		printf("%d  ", array[i]);
	}
	system("pause");
    return 0;
}

