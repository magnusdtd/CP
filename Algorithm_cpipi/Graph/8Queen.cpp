/*2
2 2
5 3
Result:
......Q.
Q.......
..Q.....
.......Q
.....Q..
...Q....
.Q......
....Q...*/

#include<iostream>
#include<cassert>
using namespace std;
#define N 8
#define FREE -1
#define NOT_FREE 1

bool X[N][N];
int row[N], col[N], dpos[2*N-1], dneg[2*N-1];

void initialize(){
    for (int i=0; i<N; i++) {
        row[i] = FREE;
        col[i] = FREE;
    }
    for (int i=0; i<2*N-1; i++){
        dpos[i] = FREE;
        dneg[i] = FREE;
    }
}

void printBoard(){  //Mỗi dòng có một lần printBoard()
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (X[i][j]){
                if (row[i] != j) return;
            }
        }
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            printf("%s", (row[i] == j) ? "Q" : ".");
        }
        printf("\n");
    }
}

void Recursion(int i){  //i là dòng, j là cột
    if (i==N){
        printBoard();
        return;
    } else {
        for (int j=0; j<N; j++){
            if ((NOT_FREE == col[j]) || (NOT_FREE == dpos[i+j]) || (NOT_FREE == dneg[i-j+N-1])){
                continue;
            }
            //Ô thỏa mãn thì:
            row[i] = j;
            col[j] = NOT_FREE;
            dpos[i+j] = NOT_FREE;
            dneg[i-j+N-1] = NOT_FREE;

            Recursion(i+1);

            row[i] = col[j] = dpos[i+j] = dneg[i-j+N-1] = FREE;
        }
    }
}

int main(){
    initialize();
    for (int i=0; i<N;i++){
        for (int j=0; j<N; j++){
            X[i][j] = false;
        }
    }

    int n=0, r=0, c=0;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d %d", &r, &c);
        X[r][c] = true;
    }

    Recursion(0);
    return 0;
}