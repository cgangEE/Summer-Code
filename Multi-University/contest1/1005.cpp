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
template <class T> void checkmax(T &t, T x){if (x>t) t=x; }
template <class T> void checkmin(T &t, T x){if (x<t) t=x; }
template <class T> void _checkmax(T &t, T x){if (t==-1 || x>t) t=x; }
template <class T> void _checkmin(T &t, T x){if (t==-1 || x<t) t=x; }
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it=(v).begin(); it!=(v).end(); it++)
#define clr(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 100000

int i,j,k,m,n,l;
int a[N+10], u[N+10], v[N+10];
int g[N+10], f[N+10];
int r[N+10], s[N+10];

int gaoF(int i){
    int x=1, y=u[0];
    while (x!=y){
        int z=mid(x+1, y);
        if (u[z]<=a[i]) x=z;
        else y=z-1;
    }
    if (u[0]==x) u[++u[0]]=a[i];  
    else checkmin(u[x+1], a[i]);
    if (u[x]==a[i]) r[x+1]=r[x]+1;
    else r[x+1]=1;
    f[i]=x;
    return r[x+1];
}

int gaoG(int i){
    int x=1, y=v[0];
    while (x!=y){
        int z=mid(x, y+1);
        if (v[z]>=a[i]) x=z;
        else y=z-1;
    }
    if (v[0]==x) v[++v[0]]=a[i];
    else checkmax(v[x+1], a[i]);
    if (v[x]==a[i]) s[x+1]=s[x]+1;
    else s[x+1]=1;
    g[i]=x;
    return s[x+1];
}

int main(){
    int tests;
    scanf("%d", &tests);
    while (tests--){
        scanf("%d", &n);
        repf(i, 1, n) scanf("%d", &a[i]);
        clr(u, 0), clr(v, 0);
        u[0]=v[0]=1, u[1]=INT_MIN, v[1]=INT_MAX;

        int ans=0;
        repd(i, n, 1){
            j=gaoF(i), k=gaoG(i);
            checkmax(ans, f[i]+g[i]-min(j, k));
        }
        printf("%d\n", ans);
    }
    return 0;
}
