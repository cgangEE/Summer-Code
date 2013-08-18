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
#include <deque>
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
    int i, x, y;
};
bool x(const P& a, const P& b){
    if (a.x!=b.x) return a.x>b.x;
    return a.y>b.y;
}

bool y(const P& a,const P &b){
    if (a.y!=b.y) return a.y<b.y;
    return a.x<b.x;
}


int i,j,k,m,n,l;
P a[N+10];
bool v[N+10];

int main(){
    while (~scanf("%d%d%d", &n, &m, &l)){
        rep(i, n) scanf("%d%d", &a[i].x, &a[i].y), a[i].i=i;
        sort(a, a+n, y);
        clr(v, 0);
        vi ans;
        rep(i, m-l) ans.pb(a[i].i), v[a[i].i]=1;
        sort(a, a+n, x);
        rep(i, l) if (!v[a[i].i]) ans.pb(a[i].i);
        rep(i, sz(ans)){
            if (i) putchar(' ');
            printf("%d" ,ans[i]+1);
        }
        putchar('\n');
    }
    return 0;
}
