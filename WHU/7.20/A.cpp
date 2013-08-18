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
typedef vector<int> vi;
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
#define foreach(it, v) for (iter(V) it=(v).begin(); it!=(v).end(); ++it)
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator

#define Z 26
#define N 60
#define K 1000

struct bigNum{
    static const int L=100;
    int it[L+10];
    bigNum(){ clr(it,0), it[0]=1; }
    bigNum(int n){
        clr(it, 0);
        while (n) it[++it[0]]=n%10, n/=10;
        if (!it[0]) it[0]=1;
    }
    bigNum operator +(const bigNum &b)const{
        bigNum ret;
        ret.it[0]=max(it[0], b.it[0])+1;
        repf(i, 1, ret.it[0])
            ret.it[i]+=it[i]+b.it[i],
            ret.it[i+1]+=ret.it[i]/10,
            ret.it[i]%=10;
        while (ret.it[0]>1 && ret.it[ret.it[0]]==0) ret.it[0]--;
        return ret;
    }
    void out(){
        repd(i, it[0], 1) printf("%d", it[i]);
        putchar('\n');
    }
};

int i,j,k,m,n,l;
int z, kk, st,ed;
char str[Z+10];
int f[K+10][Z+10], g[K+10][Z+10], e[K+10][Z+10];
vi ved;
bigNum dp[N+10][K+10], ZERO;

int dfs(int i, int j){
    if (e[i][j]==0){
        if (g[i][j]==0){
            e[i][j]=f[i][j];
        }
        else{
            e[i][j]=-1;
            e[i][j]=dfs(f[i][j], j);
        }
    }
    return e[i][j];
}

int main(){
    int tests;
    scanf("%d", &tests);
    rep(test, tests){
        if (test) puts("");
        scanf("%s", str), z=strlen(str);
        scanf("%d%d%d", &kk, &st, &ed), ved.clear();
        rep(i, ed) scanf("%d", &k), ved.pb(k);
        repf(i, 1, kk) repf(j, 1, z) scanf("%d", &f[i][j]);
        repf(i, 1, kk) repf(j, 1, z) scanf("%d", &g[i][j]);
        scanf("%d", &n);
        clr(e, 0);
        
        repf(j, 1, z) repf(i, 1, kk) if (e[i][j]==0) dfs(i, j);
          
        repf(i, 0, n) repf(j, 1, kk) dp[i][j]=ZERO;
        dp[0][st]=bigNum(1);
        
        
        repf(i, 1, n) repf(j, 1, kk) {
            if (dp[i-1][j].it[0]<=1 && dp[i-1][j].it[1]==0) continue;
        repf(k, 1, z)
            if (e[j][k]>0)
                dp[i][e[j][k]]=dp[i][e[j][k]]+dp[i-1][j];
        }
        bigNum ans(0);
        rep(i, ed) ans=ans+dp[n][ved[i]];
        ans.out();
    }   
    return 0;
}
