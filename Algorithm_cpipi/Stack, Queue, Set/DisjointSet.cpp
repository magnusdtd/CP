/*5 12
0 1 4
0 2 3
1 1 2
1 3 4
1 1 4
1 3 2
0 1 3
1 2 4
1 3 0
0 0 4
1 0 2
1 3 0
Result:
0
0
1
1
1
0
1
1*/

#include<iostream>
#include<vector>
using namespace std;

class DisjointSet {
public:
    vector<int> rank, p;
    DisjointSet(int n){
        rank.resize(n, 0);
        p.resize(n, 0);
        for (int i=0; i<n; i++){
            makeSet(i);
        }
    }
    
    void makeSet(int i){
        p[i] = i;
        rank[i] = 0;
    }
    void unite(int x, int y){
        link(findSet(x), findSet(y));
    }
    bool same(int x, int y){
        return (findSet(x) == findSet(y)) ? true : false;
    }

    void link(int x, int y){
        if (rank[x] > rank[y]){
            p[y] = x;
        } else{
            p[x] = y;
            if (rank[x] == rank[y]){
                rank[y]++;            }
        }
    }

    int findSet(int x){
        if (x != p[x]){
            p[x] = findSet(p[x]);
        }
        return p[x];    
    }
};

int main(){
    int n=0, q=0, t=0, x=0, y=0;
    scanf("%d %d", &n, &q);
    DisjointSet ds  = DisjointSet(n);
    for (int i=0; i<q; i++){
        scanf("%d %d %d", &t, &x, &y);
        if (t==0){
            ds.unite(x, y);
        } else {
            printf("%d\n", ds.same(x, y) ? 1 : 0);
        }
    }
    return 0;
}