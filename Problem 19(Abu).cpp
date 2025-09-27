#include <iostream>
#include <iomanip>
using namespace std;

int randnum(int from, int to) {
    return rand() % (to - from + 1) + from;
}

void fillmat(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3;j++) {
            arr[i][j] = randnum(1, 20);
        }
    }
}

void printmat(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3;j++) {
            printf(" %02d ", arr[i][j]);
        }
        cout << "\n";
    }
}

void isBIGorSMALL(int arr[3][3]) {
    int smallnum, bignum;
    smallnum = arr[0][0];
    bignum = arr[0][0];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3;j++) {
            if (bignum < arr[i][j]) {
                bignum = arr[i][j];
            }
            else if  (smallnum > arr[i][j]) {
                smallnum = arr[i][j];
            }
        }
    }
    cout << "The biggest is  " << bignum<<endl;
    cout << "The smallest is  " << smallnum << endl;
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3];
    fillmat(arr);
    printmat(arr);
    isBIGorSMALL(arr);
}
