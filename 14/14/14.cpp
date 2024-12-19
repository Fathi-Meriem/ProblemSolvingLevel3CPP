#include <iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
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
bool CheckScalarMatrix(int matrix[3][3], short rows, short columns) {
	int N=matrix[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (i == j && matrix[i][j] != N) {
				return false;
			}
			else if (i != j && matrix[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}


int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3] = { {9,0,0},{0,9,0},{0,0,9} };
	PrintMatrix(arr, 3, 3);
	cout << "\n\n";
	if (CheckScalarMatrix(arr, 3, 3)) {
		cout << " Matrix is scalar";
	}
	else cout << "Matrix is not scalar \n";
	system("pause>0");


}
