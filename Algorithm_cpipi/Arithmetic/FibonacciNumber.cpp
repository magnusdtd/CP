#include<iostream>
#include<cstring>
using namespace std;

int dp[50];

int fib(int n){
    if (n == 0 || n == 1) return dp[n] = 1;
    if ( dp[n] != -1) return dp[n];
    return dp[n] = fib(n-1) + fib(n-2);
}

int main(){
    int n=0;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    printf("%d\n", fib(n));
    return 0;
}