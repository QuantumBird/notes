#include <bits/stdc++.h>
using namespace std;
template<typename T>
class List{
    T * lst;
    int len, maxlen;
    int allocater(){
        int tmp = maxlen * 2;
        T * tmplst = (T *)malloc(sizeof(T)*maxlen);
        if(tmplst == NULL) return 1;
        memcpy(tmplst, lst, len);
        free(lst);
        lst = tmplst;
        return 0;
    }
public:
    List();
    ~List();
    T * begin(){return &(lst[0]);}
    T * end(){return lst + len;}
    T & operator[](int idx);
    void push_back(T val);
    int size();
    T * find(const T & val);
    void insert(T * pos, T val);
    void remove(T * pos);
};

template<typename T>
List<T>::List(){
    lst = NULL;
    len = 0;
    maxlen = 8;
    assert(allocater() == 0);
}

template<typename T>
List<T>::~List(){
    free(lst);
}

template<typename T>
T & List<T>::operator[](int idx){
    return lst[idx];
}

template<typename T>
void List<T>::push_back(T val){
    if(len == maxlen)
        assert(allocater() == 0);
    lst[len ++] = val;
}

template<typename T>
int List<T>::size(){
    return len;
}

template<typename T>
T * List<T>::find(const T & val){
    for(int i = 0; i < len; i ++){
        if(lst[i] == val)
            return &(lst[i]);
    }
    return NULL;
}
template<typename T>
void List<T>::insert(T * pos, T val){
    assert(pos >= begin() && pos <= end());
    if(len == maxlen)
        assert(allocater() == 0);
    for(T * iter = end(); iter != pos; iter --)
        *iter = *(iter - 1);
    *pos = val;
    len ++;
}
template<typename T>
void List<T>::remove(T * pos){
    assert(begin() <= pos && pos < end());
    for(T * iter = pos; iter + 1 != end(); iter ++)
        *iter = *(iter + 1);
    len --;
}
int main(){
    List<int> a;
    cout<<a.size()<<endl;
    a.push_back(1);
    a[0] = 2;
    a.insert(a.begin(), 3);
    cout<<a[0]<<endl;
    return 0;
}


