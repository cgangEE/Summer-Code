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
#define clr(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define N 500000

int i,j,k,m,n,l;
int f[N+1000];
bool v[N+1000];

void solve(){
    scanf("%d", &n);
    repf(i, 2, n) scanf("%d", &f[i]);
    clr(v, 0); 
    vi ans;
    repd(i, n, 2) if (!v[i] && !v[f[i]]){
        ans.pb(i);
        v[f[i]]=v[i]=1;
    }
    printf("%d\n", sz(ans)*1000);
    repd(i, sz(ans)-1, 0){
        if (i!=sz(ans)-1) putchar(' ');
        printf("%d", ans[i]);
    }
    putchar('\n');
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
