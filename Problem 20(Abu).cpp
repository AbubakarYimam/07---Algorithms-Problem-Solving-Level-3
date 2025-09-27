#include <iostream>
#include <iomanip>
using namespace std;

void printmat(int arr[3][3]) {
    for (int i = 0; i < 3;i++) {
        for (int j = 0; j < 3;j++) {
            cout << setw(3) << arr[i][j];
        }
        cout << "\n";
    }
}

bool ispalinder(int arr[3][3]) {
    for (int i = 0;i < 3;i++) {
        if (arr[i][0] != arr[i][2]) {
            return false;
        }
    }
    
      return true;
}
int main()
{
    int arr[3][3] = { {1,2,1},{3,4,3},{5,6,5} };
    printmat(arr);
    if (ispalinder(arr)) {
        cout << "\n YES, it's palnidomor";
    }
    else {
        cout << "\n NO, it's not palnidor";
    }
}
