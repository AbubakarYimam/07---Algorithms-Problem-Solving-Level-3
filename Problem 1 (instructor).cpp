#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()

using namespace std;

// Function to generate a random number between From and To
int RandomNumber(int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Fill a matrix with random numbers
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            arr[i][j] = RandomNumber(1, 100); // numbers between 1 and 100
        }
    }
}

// Print the matrix in a formatted way
void PrintMatrix(int arr[3][3], short Rows, short Cols) {

    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            cout <<  arr[i][j] << setw(10);
        }
        cout << "\n";
    }
}

int main() {
    // Seeds the random number generator in C++
    srand((unsigned)time(NULL));

    int arr[3][3];

    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "\nThe following is a 3x3 random matrix:\n\n";
    PrintMatrix(arr, 3, 3);

    system("pause>0");  // Windows only, remove if on Linux/Mac
    return 0;
}
