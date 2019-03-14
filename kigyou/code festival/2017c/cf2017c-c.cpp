#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int main(){
    char s[100010];
    int n,ll,rr,ans=0;
    //vector<char> l(100000),r(100000);
    scanf("%s",s);
    n=strlen(s);
    ll=0;
    rr=n-1;
    while(ll<rr){
        if(s[ll]==s[rr]){
            ll++;
            rr--;
        }
        else if(s[ll]=='x'){
            ll++;
            ans++;
        }
        else if(s[rr]=='x'){
            rr--;
            ans++;
        }
        else{
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n",ans);
}