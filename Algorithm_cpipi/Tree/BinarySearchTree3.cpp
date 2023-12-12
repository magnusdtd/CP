/*18
insert 8
insert 2
insert 3
insert 7
insert 22
insert 1
find 1
find 2
find 3
find 4
find 5
find 6
find 7
find 8
print
delete 3
delete 7
print
//Result:
yes
yes
yes
no
no
no
yes
yes
1 2 3 7 8 22
8 2 1 3 7 22
1 2 8 22
8 2 1 22*/

#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 1024;

struct Node {
    int data;
    Node *parent, *left, *right;
};
//Khoi tao cay nhi phan NULL
Node* root = NULL;
typedef Node* TREE;

void PreorderTreeWalk(Node* root){
    if (root != NULL) {
        printf("%d ", root->data);
        PreorderTreeWalk(root->left);
        PreorderTreeWalk(root->right);
    }
}

void InorderTreeWalk(Node* root){
    if (root != NULL) {
        PreorderTreeWalk(root->left);
        printf("%d ", root->data);
        PreorderTreeWalk(root->right);
    }
}

void insert(int value){
    Node *y = NULL, *x = root;
    Node *z = new Node();
    z -> data = value;
    z -> left = z -> right = NULL;

    // �i tu goc x xuong
    while (x != NULL){
        y = x;
        if (z -> data < x -> data){
            x = x ->left;
        } else{
            x = x ->right;
        }
    }
    z->parent = y;
    //B?t d?u n?i z v?i cha c?a n�, n?i cha v?i n�
    //Tru?ng h?p gi� tr? ch�n v�o l� g?c
    if (y==NULL){
        root = z;
    } else {
        if (z->data < y->data){
            y->left = z;
        } else {
            y -> right = z;
        }
    }
}

Node* find(Node* x, int value){
    while (x != NULL && value != x->data){
        if (value <x->data){
            x = x->left;
        } else {
            x = x->right;
        }
    }
    return x;
}

void searchStandFor(Node* p, Node* q) {
    if (q->left != NULL){
        searchStandFor(p, q->left);
    } else {
        p->data = q->data;
        p = q;
        q = q->right;
    }
}

void deleteNode(Node* x, int value) {
    //Trường hợp đơn giản nhất
    if (x == NULL) return;
    //Tìm vị trí của node cần xóa
    if (x->data > value) {
        return deleteNode(x->left, value);
    } else if (x->data < value) {
        return deleteNode(root->right, value);
    } else {
        //Đã tìm thấy vị trí node cần xóa
        //Trường hợp node chỉ 1 con
        Node* p = x;
        if (x->left == NULL){
            x = x ->right;
        } else if (x -> right == NULL){
            x = x -> left;
        } else {    //Trường hợp có cả 2 con
            Node* q = x->right;
            searchStandFor(p, q);
        }
        delete p;
    }
}

int main(){
    int n, value;
    char s[200];
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%s", &s);
        if (s[0] == 'i') {	//insert
            scanf("%d", &value);
            insert(value);
        } else if (s[0] == 'f') { //find
            scanf("%d", &value);
            Node* temp = find(root, value);
            if (temp == NULL) printf("no\n");
            else if (temp->data == value) printf("yes\n");
        } else if (s[0] == 'd') { //delete
            scanf("%d", &value);
            deleteNode(root, value);    
        }else { //print
            InorderTreeWalk(root);
            printf("\n");
            PreorderTreeWalk(root);
            printf("\n");
        }
    }
    return 0;
}
