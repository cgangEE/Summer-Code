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

#define N 5000

int i,j,k,m,n,l;
int f[10][10][N+10], g[10][10][N+10];

vi gao(int m){
    vi a;
    while (m) a.pb(m%10), m/=10;
    if (sz(a)==0) a.pb(0);
    return a;
}

int gao(){
    vi a=gao(m), b=gao(n);
    int k=0;
    rep(i, sz(b)) k+=b[i]*(1<<i);

    int ret=0;
    repd(i, sz(a)-1, 0){
            repf(j, 0, a[i]-1) 
                ret+=g[i+1][j][k];
        if (i==0) ret+=g[i+1][a[i]][k];
        k-=(1<<i)*a[i];
        if (k<0) break;
    }
    return ret;
}

int main(){
    f[0][0][0]=1;
    

    repf(i, 1, 9)
        repf(j, 0, 9){
            repf(k, (1<<i-1)*j, N){
                repf(l, 0, 9)
                    f[i][j][k]+=f[i-1][l][k-(1<<i-1)*j];
                if (k) g[i][j][k]=g[i][j][k-1];
                g[i][j][k]+=f[i][j][k];
            }
        }


    int ts;
    scanf("%d", &ts);
    repf(te, 1, ts){
        scanf("%d%d", &n, &m);
        printf("Case #%d: %d\n", te, gao());
    }
    return 0;
}


