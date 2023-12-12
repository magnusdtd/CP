/*Case 1:
4 5
0 0 1 0 0
1 0 0 0 0
0 0 0 1 0
0 0 0 1 0
Result1: 4
Case 2:
7 7
0 0 0 0 0 0 1
0 0 1 0 0 0 0
0 0 0 0 0 1 0
1 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
1 0 0 0 0 0 0
Result: 16*/

#include<iostream>
#include<algorithm>
using namespace std;
const int maxx = 1410;
int dp[maxx][maxx], G[maxx][maxx]; //Mảng dp chứa các 
// 0 tức là sạch, 1 là bị bẩn

int getLargestSquare(int H, int W){
    int maxWidth = 0;
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            dp[i][j] = (G[i][j] + 1)%2; // O trong bien thanh 1
            //maxWidth |= dp[i][j]; //Khong can dong nay cung dc ??
        }
    }
    for (int i=1; i<H; i++){
        for (int j=1; j<W; j++){
            if (G[i][j]){
                dp[i][j] = 0;
            } else {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1; // Cộng 1 để láy ô đang xem
                maxWidth = max(maxWidth, dp[i][j]);
            }
        }
    }
    return maxWidth*maxWidth;
}

int main(){
    int H, W;
    scanf("%d %d", &H, &W);
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            scanf("%d", &G[i][j]);
        }
    }
    printf("%d", getLargestSquare(H, W));
    return 0;
}