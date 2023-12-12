/*10
insert 30
insert 88
insert 12
insert 1
insert 20
find 12
insert 17
insert 25
find 16
print
Result:
yes
no
1 12 17 20 25 30 88
30 12 1 20 17 25 88*/

#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 1024;
const int NIL = -1;

struct Node {
    int key;
    Node *parent, *left, *right;
};
Node *root;

void PreorderTreeWalk(Node *u){
    if (u == NULL) return;
    printf("%d ", u->key);
    PreorderTreeWalk(u->left);
    PreorderTreeWalk(u->right);
}

void InorderTreeWalk(Node *u){
    if (u == NULL) return;
    InorderTreeWalk(u->left);
    printf("%d ", u->key);
    InorderTreeWalk(u->right);
}

void insert(int value){
    Node *y = NULL, *x = root;
    Node *z = new Node();
    z -> key = value;
    z -> left = z -> right = NULL;

    // Đi từ gốc x xuống 
    while (x != NULL){
        y = x;
        if (z -> key < x -> key){
            x = x ->left;
        } else{
            x = x ->right;
        }
    }
    z->parent = y;
    //Bắt đầu nối z với cha của nó, nối cha với nó
    //Trường hợp giá trị chèn vào là gốc
    if (y==NULL){
        root = z;
    } else {
        if (z->key < y->key){
            y->left = z;
        } else {
            y -> right = z;
        }
    }
}

Node* find(Node* x, int value){
    while (x != NULL && value != x->key){
        if (value < x->key){
            x = x->left;
        } else {
            x = x->right;
        }
    }
    return x;
}

int main(){
    int n, value;
    char s[200];
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%s", &s);
        if (s[0] == 'i') {
            scanf("%d", &value);
            insert(value);
        } else if (s[0] == 'f') {
            scanf("%d", &value);
            Node* temp = find(root, value);
            if (temp == NULL) printf("no\n");
            else if (temp->key == value) printf("yes\n");
        } else {
            InorderTreeWalk(root);
            printf("\n");
            PreorderTreeWalk(root);
            printf("\n");
        }
    }
    return 0;
}