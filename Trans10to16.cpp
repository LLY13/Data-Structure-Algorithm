// Trans10to16.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>



int main()
{
	int i = 0;
	// create a hnum to store a hexadecimal number
	char hnum[10];
	// create a reminder(re) to store reminder
	int re;
	// enter a init decimal num and store  number divided by 16
	int num = 100001;
	// the algorithm to transform
	while (num != 0) {
		re = num % 16;
		if (re < 10) {
			//ASC||  0-9  +  48    -> '0'-'9'
			re = re + 48;
		}
		else
		{
			//   10 - 15    ->  'A'  - 'F' 
			re = re + 55;
		}
		hnum[i++] = re;
		num = num / 16;
	}
	//print reverse
	for (int j = i - 1; j >= 0; j--) {
		printf("%c", hnum[j]);
	}
	
	system("pause");
	return 0;
}

