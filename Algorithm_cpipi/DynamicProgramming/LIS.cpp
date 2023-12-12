////LIS: Day so con tang co do dai lon nhat O(n)=nlogn
//5
//5
//1
//3
//2
//4
//Result 1: 3
//8
//4
//1
//6
//2
//8
//5
//7
//3
//Result 2: 4

#include<iostream>
#include<algorithm>
using namespace std;

int dp[110000];
int a[110000];

int main(){
    int n=0;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        dp[i] = INT_MAX;
    }
    for (int i=0; i<n; i++) scanf("%d", &a[i]);

    for (int i=0; i<n; i++){
        *lower_bound(dp, dp+n, a[i]) = a[i];
    }
    printf("%d", lower_bound(dp, dp+n, INT_MAX) -dp);
    return 0;
}

//Ham lower_bond() se tra ve con tro den vi tri phan tu dau tien co gia tri lon hon hoac bang gia tri chi dinh
//Neu k tim thay, ham tra ve con tro cuoi cung trong mang
