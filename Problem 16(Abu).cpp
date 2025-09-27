#include <iostream>
#include <iomanip>
#include <cstdlib>  // for rand(), srand()
#include <ctime>    // for time()

using namespace std;

// Function to generate a random number between From and To
int RandomNumber(int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Fill matrix with random numbers
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            arr[i][j] = RandomNumber(0, 10);
        }
    }
}

// Print matrix
void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            cout << setw(3) << arr[i][j] << "   ";
        }
        cout << "\n";
    }
}

int isSpare(int arr[3][3]) {
    int s = 0;
    for (short i = 0; i < 3; i++) {
        for (short j = 0; j < 3; j++) {
            if (arr[i][j] == 0) {
                s++;
            }
        }
        cout << "\n";
    }
    return (s>4);
}


int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3]={0,0,0,2,2,0,0,0,0}, a;
  //  FillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "\n Matrix 1\n";
    PrintMatrix(arr, 3, 3);
    if (isSpare(arr)) {
        cout << "\nYES , It is SPARE  ";
    }
    else {
        cout << "\nNO, IT IS NOT SPARE ";
    }

}

