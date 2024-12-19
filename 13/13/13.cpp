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
			arr[i][j] = RandomNumber(0, 1);
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
bool CompareIdentityMatrix(int matrix[3][3],short rows,short columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (i == j && matrix[i][j] != 1) {
					return false;
				}
			else if (i!=j && matrix[i][j] != 0) {
					return false;
				}
			}
		}
	return true;
	}


int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];
	bool result;
	FillMatrixNumber(arr, 3, 3);
	PrintMatrix(arr, 3, 3);
	cout << "\n\n";
	if (CompareIdentityMatrix(arr, 3, 3)) {
		cout << " Matrix is identity";
	}
	else cout << "Matrix is not identity \n";
	system("pause>0");


}
