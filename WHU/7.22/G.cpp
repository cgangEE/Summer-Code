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

#define N 200
int i,j,k,m,n,l;
char s[N+10][N+10];
char c1[10], c2[10];
int plt[N+10][30], a[N+10], mins[N+10], g[N+10][30];
int r[N+10], c[N+10];
double d[N+10];
vi v;

bool cmp(int i, int j){
    if (a[i]!=a[j]) return a[i]>a[j];
    return mins[i]<mins[j];
}

bool cmp2(int i, int j){
    return d[i]>d[j];
}

void gao(){
    sort(all(v), cmp);
    rep(i, sz(v)){
        r[v[i]]=i+1;
        if (i && a[v[i]]==a[v[i-1]] && mins[v[i]]==mins[v[i-1]]) r[v[i]]=r[v[i-1]];
    }
    rep(ii, sz(v)){
        int i=v[ii];
        c[i]++;
        if (a[v[0]]!=0){
            double ai=2*sz(v)-2;
            double bi=sz(v)-2;
            d[i]+=1.*a[i]/a[v[0]]*ai/(r[i]+bi);
        }
    }
}

void init(){
    int len=0;
    scanf("%d\n", &n);
    repf(i, 1, n) gets(s[i]), checkmax(len, (int)strlen(s[i]));
    scanf("%d", &m);
    clr(c, 0), clr(d, 0);
    while (m--){
        v.clear();
        scanf("%d", &l);
        rep(i, l) scanf("%d", &k) ,v.pb(k);
        scanf("%d%d", &k, &l);
        clr(plt, 0), clr(g, 0), clr(mins, 0), clr(a, 0);
        while (l--){
            scanf("%d%s%d%s", &i, c1, &k, c2);
            j=c1[0]-'A';
            if (c2[0]=='+'){
                if (!g[i][j])
                    g[i][j]=1, mins[i]+=plt[i][j]*20+k, a[i]++;
            }
            else if (!g[i][j]) plt[i][j]++;
        }
        gao();
    }
    repf(i, 1, n){
         r[i]=i;
         if (c[i]) d[i]/=c[i];
        }
    sort(r+1, r+1+n, cmp2);
    repf(ii, 1, n){
        int i=r[ii];
        printf("%s ", s[i]);
        rep(x, len-strlen(s[i])) putchar(' ');

        printf("%.4lf\n", d[i]);
    }
}    
int main(){
    int tests;
    scanf("%d", &tests);
    rep(test, tests){
        if (test) puts("");
        init();
    }
    return 0;
}
