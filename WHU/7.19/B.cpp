#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <ctime>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define N 30000

int e;

struct Mat{
    int it[2][2];
    void input(){ rep(i, 2) rep(j, 2) scanf("%d", &it[i][j]);}
    void out(){
        rep(i, 2){
            rep(j, 2){
                if (j) putchar(' ');
                printf("%d", it[i][j]);
            }
            putchar('\n');
        }
    }
    Mat operator *(const Mat &m)const{
        Mat ret;
        rep(i, 2) rep(j, 2){
            ret.it[i][j]=0;
            rep(k, 2) 
                ret.it[i][j]=(ret.it[i][j]+it[i][k]*m.it[k][j]%e)%e;
        }
        return ret;
    }
};

#define lson i*2, x, z
#define rson i*2+1, z+1, y

template <int SZ>
class SegTree{
    Mat a[SZ*4+10];
public:
    void build(int i, int x, int y){
        if (x==y){
            a[i].input();
            return;
        }
        int z=mid(x, y);
        build(lson), build(rson);
        a[i]=a[i*2]*a[i*2+1];
    }
    Mat query(int i, int x, int y, int l, int r){
        if (x==l && y==r) return a[i];
        int z=mid(x, y);
        if (r<=z) return query(lson, l, r);
        else if (l>z) return query(rson, l, r);
        else return query(lson, l, z) * query(rson, z+1, r);
    }
};

int i,j,k,m,n,l;
SegTree<N> st;

int main(){
    bool jk=0;
    while (~scanf("%d%d%d", &e, &n, &m)){
        st.build(1, 1, n);
        while (m--){
            scanf("%d%d", &i, &j);
            if (jk) puts("");
            else jk=1;
            st.query(1, 1, n, i, j).out();
        }
    }
    return 0;
}
