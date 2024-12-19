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


bool CompareTypicalMatrix(int matrix1[3][3], int matrix2[3][3], short rows, short columns) {
	bool result=true;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (matrix1[i][j] != matrix2[i][j]) {
				result = false;
			}
		}
	}
	return result;
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3], arr2[3][3];
	int sum = 0;
	bool result;
	FillMatrixNumber(arr, 3, 3);
	FillMatrixNumber(arr2, 3, 3);
	cout << "First Matrix: " << endl;
	PrintMatrix(arr, 3, 3);
	cout << "Second Matrix: " << endl;
	PrintMatrix(arr2, 3, 3);
	cout << "\n\n";
	if (CompareTypicalMatrix(arr,arr2,3,3)) {
		cout << " Typical Matrix";
	}
	else cout << "Not typical Matrix\n";
	system("pause>0");


}
