#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 1;
int ufs[maxn];
bool mark[maxn];
void init(int size){
    for(int i = 0; i < size; i ++){
        ufs[i] = i;
        mark[i] = false;
    }
}

int findf(int x){
    if(x != ufs[x])
        ufs[x] = findf(ufs[x]);
    return ufs[x];
}

void merge(int a, int b){
    a = findf(a);
    b = findf(b);
    if(a != b){
        ufs[a] = b;
    }
}

bool same(int a, int b){
    a = findf(a);
    b = findf(b);
    return a == b;
}

int main(){
    int n, m, kase = 0;
    //ios::sync_with_stdio(false);
    while(scanf("%d%d", &n, &m), n || m){
        init(n + 1);
        int ans = n;
        while(m --){
            int a, b;
            //cin>>a>>b;
            scanf("%d%d", &a, &b);
            if(! same(a, b)){
                ans --;
                merge(a, b);
            }
        }
        //cout<<"Case "<<++kase<<":"<<ans<<endl;
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}


