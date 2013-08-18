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
#define N 100

int i,j,k,m,n,l;
int r[N+10], c[N+10];

void solve(){
    k=l=0;
    repf(i, 1, n){
        if (r[i]) k++; 
        if (c[i]) l++;
    }
    if (k==n){
        repf(i, 1, n) printf("%d %d\n", i, r[i]);
        return;
    }
    if (l==n){
        repf(i, 1, n) printf("%d %d\n", c[i], i);
        return;
    }
    puts("-1");
}

int main(){
    while (~scanf("%d", &n)){
        clr(r, 0), clr(c, 0);
        repf(i, 1, n) repf(j, 1, n){
            char ch=getchar();
            while (ch!='E' && ch!='.') ch=getchar();
            if (ch=='.') r[i]=j, c[j]=i;
        }
        solve();

    }
    return 0;
}
