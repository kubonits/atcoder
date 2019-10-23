#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#define mod 1000000007
using namespace std;
int main(){
    int n,p[20],ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    for(int i=1;i<n-1;i++){
        if(p[i]==p[i-1]||p[i]==p[i+1]||(p[i]>p[i-1]&&p[i]<p[i+1])||(p[i]<p[i-1]&&p[i]>p[i+1])){
            ans++;
        }
    }
    printf("%d\n",ans);
}