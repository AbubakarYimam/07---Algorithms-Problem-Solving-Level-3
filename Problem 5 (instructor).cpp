#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib> // for rand, srand
#include <ctime>   // for time

using namespace std;

// Function to generate a random number between From and To
int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

// Fill matrix with random numbers
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

// Print matrix
void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            cout << setw(4) << arr[i][j];
        }
        cout << "\n";
    }
}

// Sum of a specific column
int ColSum(int arr[3][3], short Rows, short ColNumber) {
    int Sum = 0;
    for (short i = 0; i < Rows; i++) {
        Sum += arr[i][ColNumber];
    }
    return Sum;
}

// Store sums of all columns into a 1D array
void SumMatrixColsInArray(int arr[3][3], int arrSum[3], short Rows, short Cols) {
    for (short j = 0; j < Cols; j++) {
        arrSum[j] = ColSum(arr, Rows, j);
    }
}

// Print column sums array
void PrintColsSumArray(int arr[3], short length) {
    cout << "\nThe following are the sums of each column in the matrix:\n";
    for (short i = 0; i < length; i++) {
        cout << " Col " << i + 1 << " Sum = " << arr[i] << endl;
    }
}

int main() {
    // Seed random number generator
    srand((unsigned)time(NULL));

    int arr[3][3];
    int arrSum[3];

    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "\nThe following is a 3x3 random matrix:\n";
    PrintMatrix(arr, 3, 3);

    SumMatrixColsInArray(arr, arrSum, 3, 3);

    PrintColsSumArray(arrSum, 3);

    system("pause>0");
    return 0;
}
