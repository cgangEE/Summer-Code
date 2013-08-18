#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <ctime>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef long long ll;
template <class T> void checkmax(T &t, T x){if (x > t) t = x;}
template <class T> void checkmin(T &t, T x){if (x < t) t = x;}
template <class T> void _checkmax(T &t, T x){if (t == -1 || x > t) t = x;}
template <class T> void _checkmin(T &t, T x){if (t == -1 || x < t) t = x;}
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it = (v).begin(); it != (v).end(); it++)
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 100000

struct P{
    int x, y, i;
    void input(){ scanf("%d%d", &x, &y); }
    bool operator <(const P&p)const{ if (x!=p.x) return x<p.x; return y<p.y; }
};

int i,j,k,m,n,l;
P a[N+10];
int g[N+10], f[N+10];
vi b, ans;

int find(int k){
    int x=0, y=sz(b)-1;
    while (x!=y){
        int z=mid(x+1, y);
        if (a[b[z]].y<k) x=z;
        else y=z-1;
    }
    return b[x];
}

void gao(int i){
    if (!i) return;
    ans.pb(a[i].i);
    gao(g[i]);
}

void solve(){
    scanf("%d", &n);
    repf(i, 1, n) a[i].input(), a[i].i=i; 
    sort(a+1, a+1+n), a[0].y=INT_MIN;
    b.clear(), b.pb(0); 
    int x=1;
    repf(i, 1, n){
        g[i]=find(a[i].y), f[i]=f[g[i]]+1;
        if (a[i].x!=a[i+1].x){
            repf(j, x, i) if (f[j]==sz(b)) b.pb(j);
            else if (a[j].y<a[b[f[j]]].y) b[f[j]]=j;
            x=i+1;
        }
    }
    
    ans.clear();
    repd(i, n, 1) if (f[i]==sz(b)-1){
        gao(i); break;
    }
    
    printf("%d\n", sz(ans));
    rep(i, sz(ans)){
        if (i) putchar(' ');
        printf("%d", ans[i]);
    }
    printf("\n");
}

int main(){
    int tests;
    scanf("%d", &tests);
    rep(test, tests){
        if (test) puts("");
        solve();
    }
	return 0;
}


