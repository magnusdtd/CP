#include<iostream>
using namespace std;
typedef long long LL;

LL modExpo(LL x, LL y, LL m){
    if (y==0){
        return 1;
    } else if (y &1 == 0){
        return modExpo(x*x, y/2, m);
    } else{
        return ((x%m)* modExpo(x*x, (y-1)/2, m) ) %m;
    }
}

int main(){
    LL x=0, y=0, m=0;
    cin>> x >> y >>m;
    LL ans = modExpo(x, y, m);
    cout<< ans<< endl;
    return 0;
}