//Day ki tu con chung cua hai chuoi co do dai lon nhat
//3
//abcbdab
//bdcaba
//abc
//abc
//abc
//bc
//Result:
//4
//3
//2

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxx=1010;
int dp[maxx][maxx];

int LCS(char s1[], char s2[]){
    int m = strlen(s1), n = strlen(s2);
    for (int i=1; i<=m; i++){
        dp[i][0] = 0;
    }
    for (int i=1; i<=n; i++){
        dp[0][i] = 0;
    }
    for (int i=1; i<=m; i++){
        for (int j = 1; j<=n; j++){
            if (s1[i] == s2[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main(){
    int n=0;
    char s1[maxx], s2[maxx];
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%s %s", &s1, &s2);
        printf("%d\n", LCS(s1, s2));
    }
    return 0;
}
