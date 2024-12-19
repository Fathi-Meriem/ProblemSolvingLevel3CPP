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
				cout << arr[i][j] << "\t";
			}
			else {
				cout << arr[i][j] << "\t";
			}
		}
		cout << endl;
	}
}
short MaxNumberInMatrix(int matrix[3][3], short rows, short columns) {
	short Max = matrix[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (matrix[i][j] > Max) {
				Max=matrix[i][j];
			}
		}
	}
	return Max;
}
short MinNumberInMatrix(int matrix[3][3], short rows, short columns) {
	short Min = matrix[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (matrix[i][j] < Min) {
				Min=matrix[i][j];
			}
		}
	}
	return Min;
}



int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];
	FillMatrixNumber(arr, 3, 3);
	PrintMatrix(arr, 3, 3);
	cout << "\n\n";
	cout << "The max number in matrix is: " << MaxNumberInMatrix(arr, 3, 3)<<"\n\n";
	cout << "The min number in matrix is: " << MinNumberInMatrix(arr, 3, 3) << "\n\n";
	system("pause>0");


}

