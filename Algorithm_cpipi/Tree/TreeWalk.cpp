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
Preorder
0 1 2 3 4 5 6 7 8 
Inorder
2 1 3 0 6 5 7 4 8
Postorder
2 3 1 6 7 5 8 4 0*/

#include<iostream>
using namespace std;
const int MAX = 100005;
const int NIL = -1;

struct Node {
    int parent, left, right;
};
Node Tree[MAX];

void PreorderTreeWalk(int u){
    if (u==NIL) return;
    printf("%d ", u);
    PreorderTreeWalk(Tree[u].left);
    PreorderTreeWalk(Tree[u].right);
}

void InorderTreeWalk(int u){
    if (u==NIL) return;
    InorderTreeWalk(Tree[u].left);
    printf("%d ", u);
    InorderTreeWalk(Tree[u].right);
}

void PostorderTreeWalk(int u){
    if (u==NIL) return;
    PostorderTreeWalk(Tree[u].left);
    PostorderTreeWalk(Tree[u].right);
    printf("%d ", u);
}

int main(){
    int n=0;
    int u, l, r, root;
    scanf("%d", &n);

    for (int i=0; i<n; i++) Tree[i].parent = Tree[i].left = Tree[i].right = NIL;

    for (int i=0; i<n; i++){
        scanf("%d %d %d", &u, &l, &r);
        Tree[u].left = l;
        Tree[u].right = r;
        Tree[l].parent = u;
        Tree[r].parent = u;
    }

    for (int i=0; i<n; i++){
        if (Tree[i].parent == NIL){
            root = i;
        }
    }

    printf("Preorder\n");
    PreorderTreeWalk(root);
    printf("\nInorder\n");
    InorderTreeWalk(root);
    printf("\nPostorder\n");
    PostorderTreeWalk(root);

    return 0;
}