#include <iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}
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
bool FindNumberInMatrix(int matrix[3][3], short rows, short columns, short N) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (matrix[i][j] == N) {
				return true;
			}
		}
	}
	return false;
}



int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];
	int N = ReadPositiveNumber("Please enter the number to find in matrix: \n");
	FillMatrixNumber(arr, 3, 3);
	PrintMatrix(arr, 3, 3);
	cout << "\n\n";
	if (FindNumberInMatrix(arr,3,3,N)) {
		cout << "Yes is there! " << "\n\n";
	}
	else {
		cout << " No is  not there!" << "\n\n";
	}
	system("pause>0");


}

