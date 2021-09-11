#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<set>
#include<map>
using namespace std;

int main(){
    int n,ans=1;
    char s[100010];
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            ans++;
        }
    }
    printf("%d\n",ans);
}