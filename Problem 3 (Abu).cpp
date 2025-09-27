#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>   // for time()
#include <cstdlib> // for rand(), srand()

using namespace std;

// Function to generate a random number between From and To
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

// Print a matrix
void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            cout << setw(3) << arr[i][j] << "   ";
        }
        cout << "\n";
    }
}

// Calculate the sum of a given row
int RowSum(int arr[3][3], short RowNumber, short Cols) {
    int Sum = 0;
    for (short j = 0; j < Cols; j++) {
        Sum += arr[RowNumber][j];
    }
    return Sum;
}

// Store the sum of each row in a 1D array
void SumMatrixRowsInArray(int arr[3][3], int arrSum[3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        arrSum[i] = RowSum(arr, i, Cols);
    }
}

// Print the sum of each row
void PrintRowsSumArray(int arr[3], short Rows) {
    cout << "\nThe following are the sums of each row in the matrix:\n";
    for (short i = 0; i < Rows; i++) {
        cout << " Row " << i + 1 << " Sum = " << arr[i] << endl;
    }
}

int main() {
    // Seed the random number generator
    srand((unsigned)time(NULL));

    int arr[3][3];
    int arrSum[3];

    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "\nThe following is a 3x3 random matrix:\n";
    PrintMatrix(arr, 3, 3);

    SumMatrixRowsInArray(arr, arrSum, 3, 3);

    PrintRowsSumArray(arrSum, 3);

    system("pause>0");
    return 0;
}
