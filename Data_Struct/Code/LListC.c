#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct List{
    ElemType * lst;
    int len;
    int maxlen;
} List;

List * initList(int max_length){
    List * ans = (List *)malloc(sizeof(List));
    if(ans == NULL) return NULL;
    ans -> lst = (ElemType *)malloc(sizeof(ElemType) * max_length);
    if(ans -> lst == NULL) return NULL;
    ans -> len = 0;
    ans -> maxlen = max_length;
    return ans;
}

void  destoryList(List * lt){
    free(lt ->  lst);
    free(lt);
}

ElemType getItem(List * lt, int idx){
    return (lt -> lst)[idx];
}

int find(List * lt, ElemType val){
    for(int i = 0; i < lt -> len; i ++)
        if((lt -> lst)[i] == val)
            return i;
    return -1;
}

int push_back(List * lt, ElemType val){
    if(lt -> len == lt -> maxlen) return 1;
    (lt -> lst)[(lt -> len) ++] = val;
    return 0;
}

int insert(List * lt, int idx, ElemType val){
    for(int i = lt -> len; i > idx; i --)
        (lt -> lst)[i - 1] = (lt -> lst)[i];
    (lt -> lst)[idx] = val;
    lt -> len ++;
    return 0;
}

int remove(List * lt, int idx, ElemType val){
    for(int i = idx; i < lt -> len - 1; i ++)
        (lt -> lst)[i] = (lt -> lst)[i + 1];
    lt -> len --;
}

int main(){
    List * lt = initList(10);
    for(int i = 0; i < 5; i ++)
        push_back(lt, i);
    for(int i = 0; i < 5; i ++)
        printf("%d ", getItem(lt, i));
    printf("\n");
    return 0;
}

