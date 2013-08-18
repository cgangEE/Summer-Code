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
const ll M=1000000007;

int i,j,k,m,n,l;
ll aa[100];

ll pow(ll a, int b, int m){ 
    ll ret=1;
    int k=1;
    while (b){ 
        if (b&1)
             ret=(ret*aa[k])%m;
        b >>= 1; 
        k++;
    } 
    return ret; 
}

int main(){
    int tests;
    scanf("%d", &tests);
    aa[1]=2;
    repf(i, 2, 60) aa[i]=(aa[i-1]*aa[i-1])%M;
    while (tests--){
        scanf("%d%d", &n, &k);
        if (k>n || k<1) puts("0");
        else
     	printf("%I64d\n", 
         k==n?1:k==n-1?pow(2, n-k, M): pow(2, n-k-2, M)*(n-k+3)%M );
    }
    return 0;
}
