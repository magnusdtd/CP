/*5
1 2 3 4 5
3 2 4 1 5
Result: 3 4 2 5 1*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> pre, in, post;
int pos;
int n, k;

void reconstruction(int left, int right){
    if (left >= right) return;
    int root = pre[pos++];
    int m = distance(in.begin(), find(in.begin(), in.end(), root));

    reconstruction(left, m);
    reconstruction(m+1, right);

    post.push_back(root);
}

void solve(){
    pos = 0;
    reconstruction(0, pre.size());
    for (int i=0; i<n; i++){
        printf("%d%c", post[i], (i == n -1) ? '\n': ' '); // Dấu '' thì được còn dau "" thì không
    }
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", &k);
        pre.push_back(k);
    }
    for (int i=0; i<n; i++){
        scanf("%d", &k);
        in.push_back(k);
    }
    solve();
    return 0;
}