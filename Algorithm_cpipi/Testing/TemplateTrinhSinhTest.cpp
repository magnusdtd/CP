#include <bits/stdc++.h>
using namespace std;
// Ten chuong trinh
const string NAME = "template";
// So test kiem tra
const int NTEST = 100;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

long long random(long long min, long long max) {
    assert(min <= max);
    return min + rand() * 1LL * rand() % (max - min + 1);
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        
        // Code phan sinh test o day
        
        inp.close();
        // Neu dùng Linux thì "./" + Ten chuong trinh
        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());
        // Neu dung linux thi thay fc bang diff
        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
