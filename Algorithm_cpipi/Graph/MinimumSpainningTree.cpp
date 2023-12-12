/*Case 1:
5
-1 2 3 1 -1
2 -1 -1 4 -1
3 -1 -1 1 1
1 4 1 -1 3
-1 -1 1 3 -1
Result: 5
Case 2:
7
-1 8 12 3 -1 -1 -1
8 -1 -1 -1 -1 -1 -1
12 -1 -1 -1 -1 -1 -1
3 -1 -1 -1 7 23 -1
-1 -1 -1 7 -1 -2 -1
-1 -1 -1 23 -2 -1 -1
-1 -1 -1 -1 -1 -1 -1
Result2: 28
Case 3:
7
-1 7 -1 5 -1 -1 -1
7 -1 8 9 7 -1 -1
-1 8 -1 -1 5 -1 -1
5 9 -1 -1 15 6 -1
-1 7 5 15 -1 8 9
-1 -1 -1 6 8 -1 11
-1 -1 -1 -1 9 11 -1
Result3: 39*/

//Sử dụng thuật toán Prim
#include<iostream>
#include<cstring>
using namespace std;

const int maxx = 1010;
const int INF = 1 << 30;
int n, m[maxx][maxx];
int u, v;
int flag[maxx];

int Prim(){

    int d[maxx], p[maxx]; 
    //Mảng d để lưu cạnh kề với đỉnh đang xét MST, mảng p để ghi MST.
    for (int i=0; i<n; i++){
        d[i]= INF;
        p[i]=-1;
    }
    //Thuật toán này mặc định đỉnh bắt đầu là đỉnh 0
    d[0]=0;
    while (true){
        int minv = INF;
        u = -1;
        //So sanh các cạnh để chọn ra 
        for (int i=0; i<n; i++){
            if ((minv > d[i]) && (flag[i] == 0)){
                u=i;
                minv = d[i];
            }
        }

        if (u==-1) break;
        //Mảng đã được lưu vào trên MST sẽ được đánh dấu
        flag[u] = 1;
        // Cập nhật cạnh nhỏ nhất giữa hai điểm chưa truy cập và điểm đã truy cập
        for (int v=0; v<n; v++){
            if ((flag[v] == 0) && (m[u][v] != INF)){
                if (d[v] > m[u][v]){
                    d[v] = m[u][v];
                    p[v] = u;
                }
            }
        }
    }
    //Tính tổng của các MST đã được ghi MST
    int ans=0;
    for (int i=0; i<n; i++){
        if (p[i] != -1){
            ans += m[i][p[i]];
        }
    }
    return ans;
}


int main(){
    memset(flag, 0, sizeof(flag));
    scanf("%d", &n);

    for (int i=0; i<n; i++){    //Duyet ma tran ke
        for (int j=0; j<n; j++){
            scanf("%d", &m[i][j]);
            if (m[i][j] == -1){
                m[i][j] = INF;
            }
        }
    }

    printf("%d", Prim());
    return 0;
}