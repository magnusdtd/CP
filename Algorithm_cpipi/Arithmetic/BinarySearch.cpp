#include<iostream>
#include<vector>

using namespace std;

int binarySearch(vector<int> v, int l, int r, int key)
{
    while (r-l > 1) {
        int m = l + (r-l)/2;
        if (v[m] >= key) r = m;
        else l = m;
    }
    return r;
}


int main ()
{
    int key;
    cin >> key;
    
    vector<int> vc={1, 5, 7, 8, 9, 10};
    int n=6;
    cout << binarySearch(vc, -1, n-1, key) << endl;
    
    return 0;
}