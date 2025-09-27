#include <iostream>
using namespace std;

int rand(int from, int to) {

    return rand() % (to - from + 1) + to;

}

void write() {
    for (int i = 0; i <= 3;i++) {
        for (int j = 0; j <= 3; j++) {
            cout << rand(1, 1000) << "  ";
        }
        cout << endl;
    }
}

int main()
{
    
    write();

}
