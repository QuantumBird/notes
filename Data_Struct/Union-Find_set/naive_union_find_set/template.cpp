#include <iostream>
using namespace std;
const int maxn = 1e5 + 1;
int fhr[maxn];

void makeSet(int size){
    for(int i = 0; i < size; i ++)
        fhr[i] = i;
}

int find(int x){
    if(x != fhr[x])
        fhr[x] = find(fhr[x]);
    return fhr[x];
}

void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y)
        fhr[x] = y;
}




