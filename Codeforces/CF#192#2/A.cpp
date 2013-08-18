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
#define N 10

int i,j,k,m,n,l;
char a[N+10][N+10];
bool v[N*3];
int ans;

int main(){
    while (~scanf("%d%d", &n, &m)){
        clr(v, 0);
        rep(i, n) rep(j, m){
            a[i][j]=getchar();
            while (a[i][j]!='S' && a[i][j]!='.') a[i][j]=getchar();
            if (a[i][j]=='S') v[i]=v[n+j]=1;
        }
        ans=0;

        rep(i, n) if (!v[i]) rep(j, m) if (a[i][j]=='.')
            ans++, a[i][j]=' ';
        rep(j, m) if (!v[j+n]) rep(i, n) if (a[i][j]=='.')
            ans++, a[i][j]=' ';
            
        cout<<ans<<endl;
    }
    return 0;
}
