#include<iostream>
#include<algorithm>
#include<queue>
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

#include<vector>
using namespace std;
static const int MAXX = 10000;
static const int oo = 1 << 20;

int n;
vector<pair<int, int>> adj[MAXX];

void dijkstra(){
    priority_queue<pair<int, int>> PQ;
    int d[MAXX], flag[MAXX];
    for (int i=0; i<n; i++){
        d[i] = oo;
        flag[i] = 0;
    }
    d[0] = 0;
    PQ.push(make_pair(0, 0));

    while (!PQ.empty()){
        pair<int, int> f = PQ.top();
        PQ.pop();
        int u = f.second;
        flag[u] = 1;

        if (d[u] < f.first*(-1)) continue;
        
        for (int j=0; j < adj[u].size(); j++){
            int v = adj[u][j].first;
            if (flag[v] != 1 && d[v] > d[u] + adj[u][j].second){
                d[v] = d[u] + adj[u][j].second;
                PQ.push(make_pair(d[v]*(-1), v));
            }
        }
    }

    for (int i=0; i<n; i++){
        printf("%d %d\n", i, (d[i] == oo) ? -1 : d[i]);
    }

}

int main(){
    int u, k, v, c;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d %d", &u, &k);
        for (int j=0; j<n; j++){
            scanf("%d %d", &v, &c);
            adj[u].push_back(make_pair(v, c));
        }
    }
    dijkstra();
    return 0;
}