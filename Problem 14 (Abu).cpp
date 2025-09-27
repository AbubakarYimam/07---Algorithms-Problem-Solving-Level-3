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

bool areidentity(int arr[3][3], short Rows, short Cols) {
    int a = arr[0][0];
    for (short i = 0; i < Rows; i++) {

        for (short j = 0; j < Cols; j++) {
            if ((i == j && arr[i][j] != a) || (i != j && arr[i][j] != 0)) {
                return false;
            }
        }
    }
    return true;
}



int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3] = {3,0,0,0,3,0,0,0,3};
    // FillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "\n Matrix 1\n";
    PrintMatrix(arr, 3, 3);
    if (areidentity(arr, 3, 3)) {
        cout << "\n YES, Its scalar";
    }
    else {
        cout << "\n NO, Its not scalar";
    }
}

