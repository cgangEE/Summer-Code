#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <ctime>
using namespace std;
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a)
#define sz(a) ((int)(a).size())

int i,j,k,m,n,l;

int main(){
    while (~scanf("%d", &n)){
        rep(i, n){
            rep(j, n){
                if (j) putchar(' ');
                printf("%d", i>j?0:10);
            }
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}
