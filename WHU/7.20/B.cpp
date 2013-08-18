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

#define N 65

int i,j,k,m,mm,n,l;
unsigned long long f[N+10][N+10];
int g[N+10][N+10];
bool v[N+10];
stack<int> ss[N+10];



void gao(int n, int m, int x, int y){
    if (n==1){
        int k=ss[x].top(); ss[x].pop(); 
        printf("move %d from %d to %d", k, x, y);
        if (ss[y].size()) printf(" atop %d", ss[y].top());
        putchar('\n');
        ss[y].push(k);
        return;
    }
    int k=g[n][m], i=-1;
    repf(j, 1, mm) if (j!=x && j!=y && !v[j]){
        i=j; break;
    }
    gao(k, m, x, i);
    v[i]=1;
    gao(n-k, m-1, x, y);
    v[i]=0;
    gao(k, m, i, y);
}

int main(){
    int tests;
    scanf("%d", &tests);
    rep(test, tests){
        if (test) puts("");
        scanf("%d%d", &n, &m);
        clr(f, -1);
        repf(j, 1, m) f[1][j]=1;
    
        repf(i, 2, n) repf(j, 3, m) repf(k, 1, i-1)
            if (f[i-k][j-1]!=-1 && f[k][j]!=-1)
                if (f[i][j]==-1 || f[i][j]>f[i-k][j-1]+2*f[k][j])
                    f[i][j]=f[i-k][j-1]+2*f[k][j], g[i][j]=k;
        
        repf(i, 1, n) while (ss[i].size()) ss[i].pop();
        repd(i, n, 1) ss[1].push(i);
        clr(v, 0);
        mm=m;
        cout<<f[n][m]<<endl;
        gao(n, m, 1, m);

    }   
    return 0;
}
