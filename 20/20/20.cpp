#include <iostream>
#include<iomanip>
#include<cstdlib>
#include < vector>
using namespace std;
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

bool IsPalindromMatrix(int matrix[3][3], short rows, short columns) {
	for (int i = 0; i < rows; i++) {
	for (int j = 0; j < columns/2; j++) {
		if(matrix[i][j] != matrix[i][columns-j-1]) {
			return false;
	  }
	}
	}
	return true;
}
void PrintResults(int matrix[3][3], short rows, short columns) {
	if (IsPalindromMatrix(matrix, 3, 3)) {
		cout << "Is a Palindrome Matrix";
	}
	else {
		cout << "Is Not a Palindrome Matrix ";
	}
}



int main()
{
	srand((unsigned)time(NULL));
	int matrix1[3][3] = { {1,2,1},{5,5,5},{7,3,7} };
	int matrix2[3][3] = { {1,2,1},{5,5,5},{7,3,7} };
	PrintMatrix(matrix1, 3, 3);
	cout << "\n\n";
	PrintResults(matrix1, 3, 3);
	cout << endl;
	PrintMatrix(matrix2, 3, 3); 
	cout << "\n\n";
	PrintResults(matrix2, 3, 3);
	cout << endl;
	system("pause>0");


}

