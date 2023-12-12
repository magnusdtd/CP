#include<iostream>
#include<stack>
#include<cstring> // ham memset
using namespace std;
const int maxx=100;
int n, m[maxx][maxx]; //m la ma tran ke bieu dien do thi (graph)
int u, v, num; // num la bac cua dinh u, v la cac dinh tro toi
int d[maxx], f[maxx]; // mang d chua thoi gian luot di, mang f chua thoi gian luot ve
int flag[maxx]; // mang danh dau dc dfs hay chua
int nowtime = 1;

void dfs(int u){
    //thoi gian ngan xep
    flag[u]=1;
    d[u] = nowtime++;
    for (int i=1; i<=n; i++){
        if ((flag[i]==0) && (m[u][i]==1)) {
            dfs(i);
        }
    }
    //thoi gian xep chong
    f[u]= nowtime++;

}

int main(){
    scanf("%d", &n);
    memset(m, 0, sizeof(m));
    memset(f, 0, sizeof(f));
    for (int i=1; i<=n; i++){
        scanf("%d %d", &u, &num);
        for (int j=1; j<=num; j++){
            scanf("%d", &v);
            m[u][v]=1;
        }
    }

    for (int i=1; i<=n; i++){
        if (flag[i] == 0){
            dfs(i);
        }
    }
    for (int i=1; i<=n; i++){
        printf("%d %d %d\n", i, d[i], f[i]);
    }


    return 0;
}