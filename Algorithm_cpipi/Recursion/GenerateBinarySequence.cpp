#include<iostream>
using namespace std;

main() {
    int n=0;
    cin >>n;
    for (int i=0; i<(1<<n); i++){
        for (int j=0; j<n; j++){
            cout << ((i>>j) & 1) <<" ";
        }
        cout<< "\n";
    }
    

    return 0;
}