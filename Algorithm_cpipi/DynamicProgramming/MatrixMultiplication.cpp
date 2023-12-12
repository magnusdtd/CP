/*6
30 35
35 15
15 5
5 10
10 20
20 25
Result: 
15125*/

#include<iostream>
#include<algorithm>
using namespace std;
const int maxx=110;

int main(){
    int m[maxx][maxx], p[maxx], n=0;
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        scanf("%d %d", &p[i-1], &p[i]);
    }
    for (int i=1; i<=n; i++) m[i][i] = 0;

    for (int l=2; l<= n; l++){
        for (int i=1; i<=n - l + 1; i++){
            int j = i + l -1; //Có thể thay vòng l bằng đk if i<j 
            m[i][j] = INT_MAX;
            for (int k=i; k<= j - 1; k++){
                m[i][j] = min(m[i][j], m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]);
            }
        }
    }
    printf("%d", m[1][n]);
    return 0;
}