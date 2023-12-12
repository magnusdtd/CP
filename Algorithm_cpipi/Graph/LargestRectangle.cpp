/*4 5
0 0 1 0 0
1 0 0 0 0
0 0 0 1 0
0 0 0 1 0
Result:
6*/

#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
const int maxx = 1410;

int H=0, W=0;
int C[maxx][maxx], T[maxx][maxx];

struct Rectangle {
    int height, pos;
};

int getLargestRectangle(int size, int height[]){
    stack<Rectangle> S;
    int maxv = 0;
    height[size] =0;

    for (int i=0; i<=size; i++){ //Duyệt theo hàng ngang
        Rectangle rect;
        rect.height = height[i];
        rect.pos = i;

        if (S.empty()){
            S.push(rect);
        } else if (S.top().height < rect.height) {
            S.push(rect);
        } else if (S.top().height > rect.height) {
                int target = i;
                while (!S.empty() && S.top().height >= rect.height ){
                    Rectangle pre = S.top();
                    S.pop();
                    int area = pre.height*(i - pre.pos);
                    maxv = max(maxv, area);
                    target = pre.pos;
                }
                rect.pos = target;
                S.push(rect);
        }   
    }
    return maxv;
}

int solve() {
    //Duyệt theo chiều dọc
    for (int j=0; j<W; j++){
        for (int i=0; i<H; i++){
            if (C[i][j]){
                T[i][j] = 0;
            } else {
                T[i][j] = (i > 0) ? T[i-1][j] + 1 : 1;
            }
        }
    }

    int maxv = 0;
    for (int i=0; i<H; i++){
        maxv = max(maxv, getLargestRectangle(W, T[i]));
    }
    return maxv;
}

int main(){
    scanf("%d %d", &H, &W);
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            scanf("%d", &C[i][j]);
        }
    }
    printf("%d", solve());
    return 0;
}