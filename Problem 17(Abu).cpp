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
            arr[i][j] = RandomNumber(1, 10);
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

bool isExist(int arr[3][3], int a) {
   
    for (short i = 0; i < 3; i++) {
        for (short j = 0; j < 3; j++) {
            if (arr[i][j] == a) {
                return true;
            }
        }
    }
    return false;
}


int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3], a;
    FillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "\n Matrix 1\n";
    PrintMatrix(arr, 3, 3);
    cout << "\n\nEnter a Number you want to find ";
    cin >> a;
    if (isExist(arr, a)) {
        cout << "YES it exist";
   }
    else {
        cout << "NO it not exist";
    }

}

