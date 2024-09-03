#include <iostream>
#include <vector>
#include "cmath"
#include <algorithm>

using namespace std;

void printAscending(int n){
    if (n == 0){
        cout << 0 << " ";
        return;
    }
    printAscending(n - 1);
    cout << n << " ";
}


void printDescending(int n){
    if (n == 0){
        cout << 0 << " ";
        return;
    }
    cout << n << " ";
    printDescending(n - 1);
}



int main(){
    printAscending(10); // 0 1 2 3 4 5 6 7 8 9 10
    cout << endl;
    printDescending(10); // 10 9 8 7 6 5 4 3 2 1 0
}
