// Version sẽ không có phần truy cập về các giá trị đã tạo ra nó
// 4 5
// 4 2
// 5 2
// 2 1
// 8 3
// Result:
// 13

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 1 << 30;
const int maxx = 10010;

int dp[maxx], s[maxx];
int w[maxx], v[maxx];
int main(){
    int n, W;
    scanf("%d %d", &n, &W);
    memset(dp, 0, sizeof(dp));
    memset(s, 0, sizeof(s));

    for (int i=1; i<=n; i++){
        scanf("%d %d", &v[i], &w[i]);
        s[i] = s[i-1] + w[i]; // ??
    }
    for (int i=1; i<=n; i++){
        int b = max(w[i], W - s[n] + s[i-1]);   //??
        for (int j = W; j >= b; j--){
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    printf("%d\n", dp[W]);
    return 0;
}