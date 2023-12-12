/*13
0 3 1 4 10
1 2 2 3
2 0
3 0
4 3 5 6 7
5 0
6 0
7 2 8 9
8 0
9 0
10 2 11 12
11 0
12 0
Result:
node 0: parent = -1, depth = 0, root, [1, 4, 10]
node 1: parent = 0, depth = 1, internal node, [2, 3]
node 2: parent = 1, depth = 2, leaf, []
node 3: parent = 1, depth = 2, leaf, []
node 4: parent = 0, depth = 1, internal node, [5, 6, 7]
node 5: parent = 4, depth = 2, leaf, []
node 6: parent = 4, depth = 2, leaf, []
node 7: parent = 4, depth = 2, internal node, [8, 9]
node 8: parent = 7, depth = 3, leaf, []
node 9: parent = 7, depth = 3, leaf, []
node 10: parent = 0, depth = 1, internal node, [11, 12]
node 11: parent = 10, depth = 2, leaf, []
node 12: parent = 10, depth = 2, leaf, []*/

#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 100005;
const int NIL = -1;

struct Node {
    int p, l, r;
};
Node Tree[MAX];
int n, Depth[MAX];

void print(int u){
    printf("node %d: ", u);
    printf("parent = %d, ", Tree[u].p);
    printf("depth = %d, ", Depth[u]);

    if (Tree[u].p == NIL){
        printf("root, ");
    } else if (Tree[u].l == NIL){
        printf("leaf, ");
    } else printf("internal node, ");

    printf("[");
    int c = Tree[u].l;
    while (c != NIL){
        printf("%d", c);
        if (Tree[c].r != NIL){
            printf(", ");
        }
        c = Tree[c].r;
    }
    printf("]\n");
}

void rec(int u, int depth){ //Thiết lập độ sâu
    Depth[u] = depth;
    if (Tree[u].r != NIL) rec(Tree[u].r, depth);
    if (Tree[u].l != NIL) rec(Tree[u].l, depth + 1);
}

int main(){
    int n=0;
    scanf("%d", &n);

    for (int i=0; i<n; i++){
        Tree[i].p = Tree[i].l = Tree[i].r = NIL; 
    }
    int v, num, c, l, root;
    for (int i=0; i<n; i++){
        scanf("%d %d", &v, &num);
        for (int j=0; j<num; j++){
            scanf("%d", &c);

            if (j==0) Tree[v].l = c;
            else Tree[l].r = c;
            l = c;
            Tree[c].p = v;
        }
    }

    for (int i=0; i<n; i++){ //Tạo gốc
        if (Tree[i].p == NIL) root = i;
    }
    rec(root, 0);
    for (int i=0; i<n; i++) print(i);

    return 0;
}