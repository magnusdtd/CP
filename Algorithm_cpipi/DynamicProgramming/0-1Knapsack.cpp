// 4 5
// 4 2
// 5 2
// 2 1
// 8 3
// Result:
// 13


#include<iostream>
#include<algorithm>
#include<vector>
#define NMAX 105
#define WMAX 10005
#define DIAGONAL 1
#define TOP 0
using namespace std;

struct Item {
    int value, weight;
};

int N, W;
Item items[NMAX+1];
int C[NMAX+1][NMAX+1], G[NMAX+1][NMAX+1];
//G là mảng chứa đường chéo

void compute(int &maxValue, vector<int> &selection){
    //Cho hang va cot dau tien cua mang C gia tri 0
    for (int w=0; w<=W; w++){
        C[0][w] = 0;
        G[0][w] = DIAGONAL;
    }

    for (int i=0; i<=N; i++) C[i][0]=0;

    for (int i=1; i<=N; i++){
        for (int w=1; i<=W; w++){
            C[i][w] = C[i-1][w];
            G[i][w] = TOP;
            if (items[i].weight > w) continue;
            if (items[i].value + C[i-1][w - items[i].weight] > C[i-1][w]){
                C[i][w] = items[i].value + C[i-1][w - items[i].weight];
                G[i][w] = DIAGONAL;
            }
        }
    }

    maxValue = C[N][W];

    // Truy vết ngược lại các item tạo ra đc maxValue
    selection.clear();
    for (int i= N, w= W; i>=1; i--){
        if (G[i][w] == DIAGONAL){
            selection.push_back(i);
            w-=items[i].weight;
        }
    }

    reverse(selection.begin(), selection.end());
}

int main(){
    int maxValue;
    vector<int> selection;
    scanf("%d %d", &N, &W);
    for (int i=1; i<=N; i++){
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    compute(maxValue, selection);
    printf("%d", maxValue);
    return 0;
}