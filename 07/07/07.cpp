// 07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
void FillMatrixNumber(int arr[3][3], short rows, short columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			arr[i][j] = RandomNumber(1,10);
		}
		cout << endl;
	}
}
void PrintMatrix(int arr[3][3], short rows, short columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (arr[i][j] < 10) {
				cout << "0" << arr[i][j] << "\t";
			}
			else {
				cout << arr[i][j] << "\t";
			}
		}
		cout << endl;
	}
}
void MultiplyMatrix(int arr[3][3],int arr2[3][3],int arr3[3][3], short rows, short columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			arr3[i][j] = arr[i][j]*arr2[i][j];
		}
		
	}

}
int main()
{
	int arr[3][3],arr2[3][3],arrMultiple[3][3];
	FillMatrixNumber(arr, 3, 3);
	cout << "First Matrix: " << endl;
	PrintMatrix(arr, 3, 3);
	FillMatrixNumber(arr2, 3, 3);
	cout << "Second Matrix: " << endl ;
	PrintMatrix(arr2, 3, 3);
	MultiplyMatrix(arr, arr2,arrMultiple, 3, 3);
	cout << "Mutiple Matrix result : " << endl ;
	PrintMatrix(arrMultiple, 3, 3);
	system("pause>0");


}


