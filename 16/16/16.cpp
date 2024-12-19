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
			arr[i][j] = RandomNumber(0, 10);
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
//bool IsSparseMatrix(int matrix[3][3], short rows, short columns) {
//	bool result = false;
//	short counterZero = 0, counterNonZero=0;
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < columns; j++) {
//			if (matrix[i][j] == 0) {
//				counterZero++;
//			}
//			else counterNonZero++;
//		}
//	}
//	if (counterZero >= counterNonZero) {
//		result = true;
//	}
//	return result;
//}
short CountNumberInMatrix(int matrix[3][3], short rows, short columns, short N) {
	short counter = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (matrix[i][j] == N) {
				counter++;
			}
		}
	}
	return counter;
}
bool IsSparseMatrix(int matrix[3][3], short rows, short columns) {
	short MatrixSize = rows * columns;
	return (CountNumberInMatrix(matrix, 3, 3, 0) >= (MatrixSize / 2));
}



int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3] = { {1,4,4} ,{1,2,0},{0,0,3} };
	//FillMatrixNumber(arr, 3, 3);
	PrintMatrix(arr, 3, 3);
	cout << "\n\n";
	if (IsSparseMatrix(arr, 3, 3)) {
		cout << "The matrix is sparse\n";
	}
	else { cout << "The matrix is not sparse\n"; }
	system("pause>0");


}

