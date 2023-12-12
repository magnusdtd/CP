// 1 3 0
// 4 2 5
// 7 8 6
// Results:
// 4


#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<string>

using namespace std;
const int row = 3;
const int maxx = 9;

struct Puzzle {
    int f[maxx]; //Chứa vị trí các mảnh ghép của puzzle
    int space; //Chứa vị trí của số 0
    string path; //Chứa đường dẫn tới kết quả đúng
    bool operator < (const Puzzle &p) const { //Phép so sánh hai puzzle
        for (int i=0; i<maxx; i++){
            if (f[i] != p.f[i]) return f[i] > p.f[i];
        }
        return false;
    } 
};

const int dx[4] = {-1, 0, 1, 0}; //dx, dy là giá trị của ô chứa 0 thay đổi thế nào khi up, down, left, right
const int dy[4] = {0, -1, 0, 1};
const char dir[4] = {'u', 'l', 'd', 'r'};

bool isTarget(Puzzle p){
    for (int i=0; i<maxx;i++){
        if (p.f[i] != (i+1)){
            return false;
        }
    }
}
/*
Hàm isTarget sẽ kiểm tra xem đã đưa về kết quả đúng chưa
1 2 3
4 5 6
7 8 0
*/
string bfs(Puzzle s){
    queue<Puzzle> Q;
    map<Puzzle, bool> V;
    Puzzle u, v;
    s.path = "";
    Q.push(s);
    V[s] = true;

    while (!Q.empty()){
        u = Q.front();
        Q.pop();
        if (isTarget(u)){
            return u.path;
        }
        int sx = u.space / row; //Tọa độ x của ô 0
        int sy = u.space % row; // Tọa độ y của ô 0
        for (int r=0; r<4; r++){ // Kiểm tra các ô xung quanh có trống hay không
            int tx = sx + dx[r];
            int ty = sy + dy[r];
            if (tx < 0 || ty < 0 || tx>= row || ty >= row) continue; //Loại các trường hợp 
            v = u;
            v.space = tx * row + ty;
            swap(v.f[u.space], v.f[v.space]); // Đổi vị trí với ô đang trống
            if (!V[v]){
                V[v] = true;
                v.path += dir[r];
                Q.push(v);
            }
        }
    }
    return "unsolveable";
}

int main(){
    Puzzle in;
    for (int i=0; i<maxx; i++){
        scanf("%d", &in.f[i]);
        if (in.f[i] == 0){
            in.f[i] = maxx;
            in.space = i;
        }
    }
    string ans = bfs(in);
    printf("%d", ans.size());

    return 0;
}