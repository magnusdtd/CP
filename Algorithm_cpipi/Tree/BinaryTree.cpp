/*9
0 1 4
1 2 3
2 -1 -1
3 -1 -1
4 5 8
5 6 7
6 -1 -1
7 -1 -1
8 -1 -1
Result:
node 0: parent = -1, sibling = -1, degree = 2, depth = 0, height = 3, root
node 1: parent = 0, sibling = 4, degree = 2, depth = 1, height = 1, internal node
node 2: parent = 1, sibling = 3, degree = 0, depth = 2, height = 0, leaf
node 3: parent = 1, sibling = 2, degree = 0, depth = 2, height = 0, leaf
node 4: parent = 0, sibling = 1, degree = 2, depth = 1, height = 2, internal node
node 5: parent = 4, sibling = 8, degree = 2, depth = 2, height = 1, internal node
node 6: parent = 5, sibling = 7, degree = 0, depth = 3, height = 0, leaf
node 7: parent = 5, sibling = 6, degree = 0, depth = 3, height = 0, leaf
node 8: parent = 4, sibling = 5, degree = 0, depth = 2, height = 0, leaf*/

#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 100005;
const int NIL = -1;

struct Node {
    int parent, left, right;
};
Node Tree[MAX];
int n, Depth[MAX], Height[MAX];

int getDegree(int u){
    int deg = 0;
    if (Tree[u].left != NIL) deg++;
    if (Tree[u].right != NIL) deg++;
    return deg;
}

void setDepth(int u, int depth){
    if (u == NIL) return;
    Depth[u] = depth;
    setDepth(Tree[u].left, depth + 1);
    setDepth(Tree[u].right, depth + 1);
}

int setHeight(int u){
    int h1 = 0, h2 = 0;
    if (Tree[u].left != NIL) h1 = setHeight(Tree[u].left) + 1;
    if (Tree[u].right != NIL) h2 = setHeight(Tree[u].right) + 1;
    return Height[u] = max(h1, h2);
}

int getSibling(int u) {
    if (Tree[u].parent == NIL){
        return -1;
    } 
    if (Tree[Tree[u].parent].left != u && Tree[Tree[u].parent].left != NIL){
        return Tree[Tree[u].parent].left;
    }
    if (Tree[Tree[u].parent].right != u && Tree[Tree[u].parent].right != NIL){
        return Tree[Tree[u].parent].right;
    }
}

void print(int u){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", u, Tree[u].parent, getSibling(u), getDegree(u), Depth[u], Height[u]);

    if (Tree[u].parent == NIL){
        printf("root\n");
    } else if ((Tree[u].left != NIL) || (Tree[u].right != NIL)) {
        printf("internal node\n");
    } else {
        printf("leaf\n");
    }
}

int main() {
    scanf("%d", &n);
    int u, l, r, root;

    for (int i=0; i<n; i++) Tree[i].parent = Tree[i].left = Tree[i].right = NIL;

    for (int i=0; i<n; i++){
        scanf("%d %d %d", &u, &l, &r);
        Tree[u].left = l;
        Tree[u].right = r;
        Tree[l].parent = u;
        Tree[r].parent = u;
    }

    for (int i=0; i<n; i++){
        if (Tree[i].parent == NIL) root = i;
    }

    setHeight(root);
    setDepth(root, 0);
    for (int i=0; i<n; i++) print(i);

    return 0;
}