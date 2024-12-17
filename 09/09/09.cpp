// 09.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
			arr[i][j] = RandomNumber(1, 10);
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

void PrintMidlleRow(int arr[3][3], short rows, short columns) {
	   int i = rows / 2;
		for (int j = 0; j < columns; j++) {
			if (arr[i][j] < 10) {
				cout << "0" << arr[i][j] << "   ";
			}
			else {
				cout << arr[i][j] << "   ";
			}
		}
}
void PrintMidlleCol(int arr[3][3], short rows, short columns) {
	int j = rows / 2;
	for (int i= 0; i < columns; i++) {
		if (arr[i][j] < 10) {
			cout << "0" << arr[i][j] << "   ";
		}
		else {
			cout << arr[i][j] << "   ";
		}
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];
	FillMatrixNumber(arr, 3, 3);
	cout << "First Matrix: " << endl;
	PrintMatrix(arr, 3, 3);
	cout << "\n\n";
	cout << "The midlle row" << endl;
	PrintMidlleRow(arr, 3, 3);
	cout << "\n\n";
	cout << "The midlle col" << endl;
	PrintMidlleCol(arr, 3, 3);
	system("pause>0");


}


