#include <iostream>
#include <iomanip>   // for setw
#include <cstdlib>   // for rand, srand
#include <ctime>     // for time
using namespace std;

// Function to generate a random number in range [From, To]
int RandomNumber(int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Fill matrix with random numbers
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
            cout << setw(3) << arr[i][j] << "   ";
        }
        cout << "\n";
    }
}

// Calculate sum of a row
int RowSum(int arr[3][3], short RowNumber, short Cols) {
    int Sum = 0;
    for (short j = 0; j < Cols; j++) {
        Sum += arr[RowNumber][j];
    }
    return Sum;
}

// Print sum of each row
void PrintEachRowSum(int arr[3][3], short Rows, short Cols) {
    cout << "\nThe following are the sum of each row in the matrix:\n";
    for (short i = 0; i < Rows; i++) {
        cout << " Row " << i + 1 << " Sum = " << RowSum(arr, i, Cols) << endl;
    }
}

int main() {
    // Seed random number generator
    srand((unsigned)time(NULL));

    int arr[3][3];

    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "\nThe following is a 3x3 random matrix:\n";
    PrintMatrix(arr, 3, 3);

    PrintEachRowSum(arr, 3, 3);

    system("pause>0");
    return 0;
}