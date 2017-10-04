// Lab_3_Var_6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define N 16
int arr[N];

void inputArray(){
	for (unsigned i = 0; i < N; i++)
		arr[i] = rand() % 100;
}

void printArray(){
	for (unsigned i = 0; i < N; i++)
		cout << " " << arr[i] << endl;
}

void sortByBatcher(){
	unsigned p = N;
	while (p>0){
		unsigned q = N, r = 0, d = p;
		bool b = 0;
		do{
			unsigned nTo = N - d;
			for (unsigned i = 0; i < nTo; i++)
			if ((i&p) == r){
				if (arr[i]>arr[i + d]){
					unsigned temp = arr[i];
					arr[i] = arr[i + d];
					arr[i + d] = temp;
				}
			}
			b = (q != p);
			if (b){
				d = q - p;
				q >>= 1;
				r = p;
			}
		} while (b);
		p >>= 1;
	}
}

int main(){
	inputArray();
	printArray();
	sortByBatcher();
	cout << "  Sorted array:\n";
	printArray();
	system("pause");
	return 0;
}

