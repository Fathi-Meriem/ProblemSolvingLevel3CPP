
#include <iostream>
#include<cstdlib>
#include <iomanip>
using namespace std;
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
void FillArray(int arr[3][3], short rows, short columns) {
    for (short i= 0; i < rows; i++) {
        for (short j = 0; j < columns; j++) {
            arr[i][j] = RandomNumber(1, 110);
          }
    }
}
void PrintMatrix(int arr[3][3],short rows,short columns) {
   
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < columns; j++) {
            cout << setw(3) << arr[i][j]<<"\t";
        }
        cout << endl;
    }
}


int main()
{
  srand((unsigned)time(NULL));
  int arr[3][3];
  FillArray(arr, 3, 3);
  cout << "the Matrix 3*3" << endl;
  PrintMatrix(arr, 3, 3);
  system("pause");
 
}

