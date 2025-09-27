#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib> // rand, srand
#include <ctime>   // time()

using namespace std;

// Function to generate a random number
int RandomNumber(int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Fill a 3x3 matrix with random numbers
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

// Print the matrix
void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            cout << setw(4) << arr[i][j];
        }
        cout << "\n";
    }
}

// Calculate the sum of a given column
int ColSum(int arr[3][3], short Rows, short ColNumber) {
    int Sum = 0;
    for (short i = 0; i < Rows; i++) {
        Sum += arr[i][ColNumber];
    }
    return Sum;
}

// Print sum of each column
void PrintEachColSum(int arr[3][3], short Rows, short Cols) {
    cout << "\nThe following are the sums of each column in the matrix:\n";
    for (short j = 0; j < Cols; j++) {
        cout << " Col " << j + 1 << " Sum = " << ColSum(arr, Rows, j) << endl;
    }
}

int main() {
    // Seed the random number generator
    srand((unsigned)time(NULL));

    int arr[3][3];

    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "\nThe following is a 3x3 random matrix:\n";
    PrintMatrix(arr, 3, 3);

    PrintEachColSum(arr, 3, 3);

    system("pause>0");
    return 0;
}
