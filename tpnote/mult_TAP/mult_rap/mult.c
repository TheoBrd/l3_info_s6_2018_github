
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int lengthOfInt(int num){
	int length = 0;
	while(num!=0){
		num = num/10;
		length++;
	}
	return length;
}
int multiply(int x, int y){
	if(x<10) return x*y;
	int n = lengthOfInt(x);

	int tmpx = x;
	int tmpy = y;

	int x_plus, x_less, y_plus, y_less;
	x_less = x_plus = y_less = y_plus = 0;

	for(int i=0; i<n/2; ++i){
		x_less = x_less + (tmpx%10)*pow(10,i);
		y_less = y_less + (tmpy%10)*pow(10,i);
		tmpy = tmpy/10;
		tmpx = tmpx/10;
	}

	for(int i=0; i<n/2; ++i){
		x_plus = x_plus + tmpx%10*pow(10,i);
		y_plus = y_plus + tmpy%10*pow(10,i);
		tmpy = tmpy/10;
		tmpx = tmpx/10;
	}

	int p1 = multiply(x_plus, y_plus);
	int p2 = multiply(x_plus, y_less);
	int p3 = multiply(x_less, y_plus);
	int p4 = multiply(x_less, y_less);
	int a = p2 + p3;

	return p1*pow(10,n)+a*pow(10,n/2)+p4;
}
int main(void){
    int x = 1234;
    int y = 9876;
    printf("%d * %d = %d \nYou should get 12186984 !\n", x, y, multiply(x, y));
    return 0;
}
