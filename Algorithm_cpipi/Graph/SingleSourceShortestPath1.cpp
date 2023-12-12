/*5
0 3 3 1 2 3 1 2
1 2 0 2 3 4
2 3 0 3 3 1 4 1
3 4 2 1 0 1 1 4 4 3
4 2 2 1 3 3
Result:
0 0
1 2
2 2
3 1
4 3*/

#include<iostream>
#include<cstring>
using namespace std;
static const int MAXX=100;
static const int oo = 1 << 20;
int n, M[MAXX][MAXX];
int flag[MAXX];

void dijkstra(){
    int minv = oo;
    int d[MAXX];
    // mảng d chứa số đỉnh ít nhất phải đi qua để đến đc đỉnh thứ i xuất phát từ
    memset(flag, 0, sizeof(flag));
    for (int i=0; i<n; i++){
        d[i] = oo;
    }

    d[0]=0;
    while(true){
        minv=oo;
        int u=-1;
        for (int i=0; i<n; i++){
            if (minv > d[i] && flag[i] != 1){
                u = i;
                minv = d[i];
            }
        }
        if (u == -1) break;

        flag[u]=1;
        for (int v=0; v<n; v++){
            if (flag[v] != 1 && M[u][v] != oo){
                if (d[v] > d[u] + M[u][v]){
                    d[v] = d[u] + M[u][v]; // Phần khác biệt so với Prim
                }
            }
        }
    }
    for (int i=0; i<n; i++){
        printf("%d %d\n", i, (d[i] == oo) ? -1: d[i]);
    }  
}

int main(){

    scanf("%d", &n);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            M[i][j] = oo;
        }
    } 
    int k=0, c=0, u=0, v=0;
    //u là tên đỉnh, k là bậc của đỉnh u, v đỉnh nối với u, c là trọng số của cạnh uv
    for (int i=0; i<n; i++){
        scanf("%d %d", &u, &k);
        for (int j=0; j<k; j++){
            scanf("%d %d", &v, &c);
            M[u][v] = c;
        }
    }
    dijkstra();
    return 0;
}