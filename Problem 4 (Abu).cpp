#include <iostream>
#include <iomanip>
#include<cstdlib>
#include <ctime>

using namespace std;

int randnum(int from, int to) {
    return rand() % (to - from + 1) + from;
}

void read(int arr[3][3]) {
    for (int i = 0; i < 3;i++) {
        for (int j = 0; j < 3;j++) {
            arr[i][j] = randnum(1, 100);
        }
    }
}
void print(int arr[3][3]) {
    for (int i = 0; i < 3;i++) {
        for (int j = 0; j < 3;j++) {
            cout <<arr[i][j]<<setw(5)<<"   ";
        }
        cout << endl;
    }
}
int sumcol (int a[3], int i, int arr[3][3]) {
    int sum = 0;
    for (int t = 0; t < 3; t++) {
        sum += arr[t][i];
    }
    return sum;
}
void printsum(int a[3], int j, int arr[3][3]) {
    for (int i=0;i < j;i++) {
        cout << "sum[" << i + 1 << "]" << sumcol(a,i,arr )<< endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3], a[3];
    read(arr);
    print(arr);
    printsum(a, 3, arr);
    
}