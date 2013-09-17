#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int pre[512345];
bool hash[512345];
int ans[512345];
int cas;
int n;
int top;

int main(){
    scanf("%d",&cas);
    for(int ca = 0 ; ca < cas; ca++){
        if(ca != 0) puts("");
        memset(hash,true,sizeof(hash));
        top = -1;
        
        scanf("%d",&n);
        for(int i = 2 ; i <= n ; i++)
            scanf("%d",&pre[i]);
        
        for(int i = n ;i > 1 ; i--){
            if(hash[i] && hash[pre[i]]){
                ans[++top] = i;
                hash[pre[i]] = false;
            }
        }  
        printf("%d000\n",top+1);
        for(int i = top ; i >= 0 ; i--){
            if(i == 0) printf("%d\n",ans[i]);
            else printf("%d ",ans[i]);
        }
    }
    return 0;
}
