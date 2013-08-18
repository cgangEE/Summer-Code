#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>

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
#define N 100000

struct E{
    int x, y, c, i;
    bool operator <(const E&e)const{ return c<e.c; }
};

template<int SZ>
class UFS{
    int f[SZ+10];
public:
    void clear(){ rep(i, SZ+10) f[i]=i; }
    int find(int i){
        if (f[i]==i) return i;
        return f[i]=find(f[i]);
    }
    void unions(int i, int j){
        i=find(i), j=find(j);
        f[i]=j;
    }
};

int i,j,k,m,n,l;
long long p;
E e[N+10];
UFS<N> ufs;
bool v[N+10];

int main(){
    bool first=true;
    while (~scanf("%d%d%lld", &n, &m, &p)){
        if (first) first=0;
        else putchar('\n');
        
        repf(i, 1, m) 
            scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].c), e[i].i=i;
        sort(e+1, e+1+m);
        ufs.clear(), clr(v, 0); 
        int tot=0;
   
        repd(i, m, 1){
            if (ufs.find(e[i].x)!=ufs.find(e[i].y)){
                ufs.unions(e[i].x, e[i].y);
                v[i]=1;
                if (++tot==n-1) break;
            }
        }
        vector<int> ans;
        
        repf(i, 1, m) if (!v[i] && p>=e[i].c)
            ans.push_back(e[i].i), p-=e[i].c;
            
        sort(all(ans));
        printf("%d\n", sz(ans));
        rep(i, sz(ans)){
            if (i) putchar(' ');
            printf("%d", ans[i]);
        }
        putchar('\n');
    }
    return 0;
}
