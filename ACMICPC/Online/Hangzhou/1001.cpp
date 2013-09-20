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
#define N 1000

struct P{
    int to, w, idx;
    P(){}
    P(int to, int w, int idx):to(to),w(w),idx(idx){}
};

int i,j,k,m,n,l;
vp a[N+10];
int pre[N+10], low[N+10];
int dfs_clock, ans;
bool v[N*N+10];

void dfs(int i){
    pre[i]=low[i]=++dfs_clock;
    rep(k, sz(a[i])){

        if (v[a[i][k].idx]) continue;
        v[a[i][k].idx]=1;

        int j=a[i][k].to;

        if (!pre[j]){
            dfs(j), checkmin(low[i], low[j]);
            if (low[j]>pre[i]){
                   _checkmin(ans, a[i][k].w);
            }
        }
        else if (pre[j]<pre[i])
            checkmin(low[i], pre[j]);
    }
}

void find_bridge(){
    clr(v, 0), clr(pre, 0), dfs_clock=0;
    int k=0;
    repf(i, 1, n) if (!pre[i]){
           dfs(i);
        k++;
    }
    if (k>1) ans=0;
    else if (ans==0) ans=1;
}

int main(){
    while (~scanf("%d%d", &n, &m) && n+m){
        repf(i, 1, n) a[i].clear();
        rep(i, m) scanf("%d%d%d", &j, &k, &l),
            a[j].pb(P(k, l, i)), a[k].pb(P(j, l, i));
        ans=-1;
        find_bridge();
        printf("%d\n", ans);
    }
    return 0;
}
