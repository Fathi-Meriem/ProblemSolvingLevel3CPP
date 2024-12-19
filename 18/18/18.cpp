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
bool IsNumberInVecor(vector <int> &vNumbers, short N) {
	for (int &Number : vNumbers) {
		if (Number == N)
			return true;
	}
	return false;
}
void FindIntersectedNumbersInMatrix(int matrix1[3][3], int matrix2[3][3],short rows, short columns, vector <int>& vNumbers) {
        for (int i = 0; i < rows;i++) {
		for (int j = 0; j < columns;j++ ) {
			if (FindNumberInMatrix(matrix1, rows, columns, matrix2[i][j]) && !IsNumberInVecor(vNumbers,matrix2[i][j])){
				vNumbers.push_back(matrix2[i][j]);
		    } 			
		}
	    }
}
void PrintIntersectedEelements(vector <int> vNumbers) {

	for (int &Number : vNumbers) {
		cout << Number<<"  ";
		
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };
	int matrix2[3][3] = { {5,80,90},{22,77,1},{10,8,33} };
	vector <int> vNumbers;
	PrintMatrix(matrix1, 3, 3);
	cout << "\n\n";
	PrintMatrix(matrix2, 3, 3);
	cout << "\n\n";
	FindIntersectedNumbersInMatrix(matrix1, matrix2, 3, 3, vNumbers);
	PrintIntersectedEelements(vNumbers);
	system("pause>0");


}

