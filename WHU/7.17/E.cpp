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
#define M (1<<5)
#define N 100

int i,j,k,m,l,e;
char s[N+10];

struct bigNum{
    static const ll L=100;
    int it[L+10];
    bigNum(){
        clr(it, 0), it[0]=1;
    }
    bigNum(int n){
        clr(it, 0);
        while (n){
            it[++it[0]]=n%1000000000;
            n/=1000000000;
        }
        if (!it[0]) it[0]=1;
    }
    bigNum(char *s){
        clr(it, 0), it[0]=1;
        int n=strlen(s), k=1;
        repd(i, n-1, 0){
            it[it[0]]+=(s[i]-'0')*k;
            if (k==100000000) k=1, it[0]++;
            else k*=10;
        }
    }
    void init(char *s){
        clr(it, 0), it[0]=1;
        int n=strlen(s), k=1;
        repd(i, n-1, 0){
            it[it[0]]+=(s[i]-'0')*k;
            if (k==100000000) k=1, it[0]++;
            else k*=10;
        }
    }
    bigNum operator -(const bigNum & b)const{
        bigNum ret;
        ret.it[0]=it[0];
        repf(i, 1, ret.it[0]){
            ret.it[i]+=it[i]-b.it[i];
            if (ret.it[i]<0)
                ret.it[i]+=1000000000, ret.it[i+1]--;
        }
        while (ret.it[0]>1 && ret.it[ret.it[0]]==0) ret.it[0]--;
        return ret;
    }
    void div(const int &k){
        int rem=0;
        repd(i, it[0], 1){
            rem=rem*1000000000+it[i];
            it[i]=rem/k;
            rem%=k;
        }
        while (it[0]>1 && it[it[0]]==0) it[0]--;
    }
    bool isZero(){
        if (it[0]==1 && it[1]==0) return true;
        return false;
    }
    void out(){
        bool first=true;
        repd(i, it[0], 1){
            int k=it[i], w=100000000;
            while (w){
                int j=k/w;
                
                if (j==0){
                     if (i!=it[0] || !first) putchar('0');
                }
                else printf("%d", j), first=false;
                k%=w, w/=10;
            }

        }
        putchar('\n');
    }
};

struct Mat{
    Mat(){}
    ll it[M][M], MOD, n;
    void init(int _n, int _m){n=_n, MOD=_m, clr(it, 0);}
    Mat(int n, int m):n(n), MOD(m){clr(it, 0);}
    Mat operator * (const Mat & a){
        Mat ret(n, MOD);
        rep(i,n) rep(j,n) rep(k, n)
            ret.it[i][j]=(ret.it[i][j]+it[i][k]*a.it[k][j]%MOD)%MOD;
        return ret;
    }
    void out(){
        rep(i, n){
            rep(j, n) cout<<it[i][j]<<' ';
            cout<<endl;
        }
    }
};

inline int g(int i, int j){
    int w=m-1;
    int k=i&j, l=(i^w)&(j^w);
    if ((k&(k<<1)) || (k&(k>>1)) || (l&(l<<1)) || (l&(l>>1))) return 0;
    return 1;
}


bigNum n, one(1);
int x[M+10][M+10], c[M+10][M+10], ans[M+10][M+10];

int solve(){
    scanf("%s%d%d", s, &m, &e), m=1<<m;

    clr(ans, 0);
    rep(i, m) rep(j, m) x[i][j]=g(i,j);
    rep(i, m) ans[i][i]=1;
    n.init(s);
    n=n-one;
    
    while (!n.isZero()){
        if (n.it[1]%2==1){
            clr(c, 0);
            rep(i, m) rep(j, m) rep(k, m) c[i][j]=(c[i][j]+ans[i][k]*x[k][j])%e;
            memcpy(ans, c, sizeof(c));
        }

        clr(c, 0);
        rep(i, m) rep(j, m) rep(k, m) c[i][j]=(c[i][j]+x[i][k]*x[k][j])%e;
        memcpy(x, c, sizeof(c));
        n.div(2);
    }

    int ret=0;
    rep(i, m) rep(j, m) ret=(ret+ans[i][j])%e;
    return ret;
}

int main(){
int tests;
scanf("%d", &tests);
rep(test, tests){
if (test) puts("");
        printf("%d\n", solve());
}
    
    return 0;
}
