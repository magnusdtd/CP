#include<iostream>
using namespace std;
int i=0;

void HanoiTower(int n, char start, char spare, char finish){
    if (n ==1 ){
        printf("Move disk form %c to %c\n", start, finish);
        i++;
        return;
    } else {
        HanoiTower(n-1, start, finish, spare);
        HanoiTower(1, start, spare, finish);
        HanoiTower(n-1, spare, start, spare);
    }
}

int main(){
    int n=0;
    printf("Enter you n: ");
    scanf("%d", n);

    HanoiTower(n, '1', '2', '3');
    printf("Total number of moves = %d", i);
    return 0;
}
