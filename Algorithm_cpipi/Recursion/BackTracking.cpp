#include <iostream>
using namespace std;
int n = 3;
int a[3];
void show(){
    for(int i = 0; i<n; i++){
        cout<<a[i];
    }
    cout<<"\n";
}
 
 
void moPhong_Backtracking(){
    int k = 0;
    for(int i = 0; i<= 1; i++)
    {
        a[k] = i;
        k = 1;
        for(int i1 = 0; i1 <= 1; i1++){
            a[k] = i1;
            k = 2;
            for(int i2 = 0; i2 <= 1; i2++){
                a[k] = i2;
                show();
            }
            k=1;
        }
        k = 0;
    }
}
 
int main()
{
    moPhong_Backtracking();
}