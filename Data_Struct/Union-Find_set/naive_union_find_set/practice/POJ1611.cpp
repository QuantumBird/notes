#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXN 30010 
int sum[MAXN];    //集合总数
int ufs[MAXN];    //并查集

void Init(int n)    //初始化
{
    int i;
    for(i=0;i<n;i++){
        ufs[i] = i;
        sum[i] = 1;
    }
}

int GetRoot(int a)    //获得a的根节点。路径压缩
{
    if(ufs[a]!=a){    //没找到根节点
        ufs[a] = GetRoot(ufs[a]);
    }
    return ufs[a];
}

void Merge(int a,int b)    //合并a和b的集合
{
    int x = GetRoot(a);
    int y = GetRoot(b);
    if(x!=y){
        ufs[y] = x;
        sum[x] += sum[y];
    }
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0 && m==0) break;
        Init(n);    //初始化并查集
        while(m--){    //读入m行
            int t,one,two;
            scanf("%d",&t);    //每一行有t个数需要输入
            scanf("%d",&one);
            t--;
            while(t--){
                scanf("%d",&two);
                Merge(one,two);    //合并集合
            }
        }
        printf("%d\n",sum[GetRoot(0)]);
    }
    return 0;
}

