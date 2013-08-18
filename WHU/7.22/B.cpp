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
#define N 10000

struct P{
    int i, j;
    P(){}
    P(int i, int j):i(i),j(j){}
};

int i,j,k,m,n,l;
int low[N+10], dfn[N+10], dfs_clock;
vp a[N+10];
vi ans;

void dfs(int i, int fa){
    dfn[i]=low[i]=++dfs_clock;
    rep(k, sz(a[i])){
        int j=a[i][k].j;
        if (a[i][k].i==fa) continue;
        if (!dfn[j]){
            dfs(j, a[i][k].i);
            if (low[j]>dfn[i]) ans.pb(a[i][k].i);
            checkmin(low[i], low[j]);
        }
        else 
            checkmin(low[i], dfn[j]);
    }
}

int main(){
    int tests;
    scanf("%d", &tests);
    rep(test, tests){
        scanf("%d%d", &n, &m);
        repf(i, 1, n) a[i].clear();
        repf(i, 1, m){
            scanf("%d%d", &j, &k);
            a[j].pb(P(i,k)), a[k].pb(P(i,j));
        }
        dfs_clock=0, ans.clear();
        clr(dfn, 0);
        repf(i, 1, n) 
            if (dfn[i]==0) dfs(i, 0);
        
        if (test) puts("");
        printf("%d\n", sz(ans));
        sort(all(ans));
        rep(i, sz(ans)){
            if (i) putchar(' ');
            printf("%d", ans[i]);
        }
        if (sz(ans)) putchar('\n');
    }
    return 0;
}
