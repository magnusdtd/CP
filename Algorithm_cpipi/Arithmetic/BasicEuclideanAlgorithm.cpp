#include<iostream>
using namespace std;


int gcd(int a, int b){
    if (b==0){
        return a;
    }
    return gcd(b, a%b);
}

int lcm(int a, int b){
    return (a*b)/gcd(a, b);
    }


int main(){
    int a, b;
    cout<< "Enter your a and b: "<<endl;
    cin>> a >> b;
    int ans1=gcd(a, b);
    int ans2= lcm(a, b);
    cout<<"GCD of a and b: "<< ans1 <<"\n";
    cout<<"LCM of a and b: "<< ans2;
    return 0;
}