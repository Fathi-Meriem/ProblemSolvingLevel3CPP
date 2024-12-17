// 06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<iomanip>
using namespace std;
void FillMatrixNumber(int arr[3][3],short rows,short columns) {
	int counter = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			counter++;
			arr[i][j] = counter;
		}
		cout << endl;
	}
}
void PrintMatrixNumber(int arr[3][3], short rows, short columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << arr[i][j]<<"\t";
		}
		cout << endl;
	}
}
int main()
{
	int arr[3][3];
	FillMatrixNumber(arr,3,3);
	PrintMatrixNumber(arr,3,3);
}


