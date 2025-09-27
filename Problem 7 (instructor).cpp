#include <iostream>
#include <string>
using namespace std;

// Fill matrix with ordered numbers (1,2,3,...)
void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Cols) {
    short Counter = 0;
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            Counter++;
            arr[i][j] = Counter;
        }
    }
}

// Print matrix
void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            cout << " " << arr[i][j] << "\t";
        }
        cout << "\n";
    }
}

// Transpose matrix
void TransposeMatrix(int arr[3][3], int arrTransposed[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            arrTransposed[j][i] = arr[i][j];  // swapped indices
        }
    }
}

int main() {
    int arr[3][3], arrTransposed[3][3];

    FillMatrixWithOrderedNumbers(arr, 3, 3);

    cout << "\nThe following is a 3x3 ordered matrix:\n";
    PrintMatrix(arr, 3, 3);

    TransposeMatrix(arr, arrTransposed, 3, 3);

    cout << "\nThe following is the transposed matrix:\n";
    PrintMatrix(arrTransposed, 3, 3);

    system("pause>0");
    return 0;
}
