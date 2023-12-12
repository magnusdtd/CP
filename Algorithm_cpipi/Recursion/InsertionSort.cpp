/*6
5 2 4 6 1 3
Result:
5 2 4 6 1 3
2 5 4 6 1 3
2 4 5 6 1 3
2 4 5 6 1 3
1 2 4 5 6 3
1 2 3 4 5 6*/

#include<iostream>
using namespace std;

void printArray(int a[], int n){
    for (int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insertSort(int a[], int n){
    for (int i=1; i<n; i++){
        int j=i-1;
        int v = a[i];
        while (j >= 0 && a[j] > v){
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = v;
        printArray(a, n);
    }
}

int main(){
    int n=0, a[110];
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    printArray(a, n);
    insertSort(a, n);
    return 0;
}