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

int i,j,k,m,n,l;
vi a[N+10];
int now, d[N+10];

void dfs(int i, int len, int fa, int &ret){
    d[i]=len;
    if (d[i]>d[ret]) ret=i;
    rep(k, sz(a[i])){
        int j=a[i][k];
        if (j!=fa) dfs(j, len+1, i, ret);
    }
}

int main(){
    int tests;
    scanf("%d", &tests);
    while (tests--){
        scanf("%d%d", &n, &m);
        repf(i, 1, n) a[i].clear();
        
        rep(xx, n-1) scanf("%d%d", &i, &j), a[i].pb(j), a[j].pb(i);
        int first=1, second=1;
        clr(d, 0), dfs(1, 1, 0, first);
        clr(d, 0), dfs(first, 1, 0, second);
        while (m--){
            scanf("%d", &k);
            if (k<=d[second]) printf("%d\n", k-1);
            else printf("%d\n", d[second]-1+(k-d[second])*2);
        }
    }
    return 0;
}
