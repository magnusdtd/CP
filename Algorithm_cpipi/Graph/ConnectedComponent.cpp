/*10 9
0 1
0 2
3 4
5 7
5 6
6 7
6 8
7 8
8 9
3
0 1
5 9
1 3
Result:
yes
yes
no*/

#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
using namespace std;
const int maxx=100010;

int m, n; //n la so dinh, m la so quan he cua cac dinh
int u, num, v;
int flag[maxx];
int color[maxx];
vector<int> G[maxx];

int c=1;

void dfs(int i){ //duyet dfs den cac phan tu moi lien he (tuc la cung mau)
    stack<int> s;
    s.push(i);
    color[i]=c;
    while (!s.empty())
    {
        int u= s.top(); s.pop();
        int len= G[u].size();
        for (int i=0; i< len; i++){
            int v= G[u][i];
            if (flag[v]==0){
                color[v]=c;
                flag[v]=1;
                s.push(v);
            }
        }
    }
}
int main(){
    int q;
    memset(flag, 0, sizeof(flag));
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++){
        scanf("%d %d", &u, &v);
        //Thiet lap moi quan he hai chieu cho u, v
        G[u].push_back(v);  // Mới lần đầu tiên thấy cái này
        G[v].push_back(u);  // Tương tự ma trận kề
    }

    for (int i=0; i<n; i++){
        if (flag[i]== 0){
            dfs(i);
            c++;
        }
    }
    
    scanf("%d", &q);
    for (int i=0; i<q; i++){
        scanf("%d %d", &u, &v);
        if (color[u] == color[v]){
            printf("yes\n");
        } else printf("no\n");
    }

    return 0;
}