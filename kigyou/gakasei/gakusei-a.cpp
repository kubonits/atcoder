#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<utility>
#include<deque>
using namespace std;
#define MOD 1000000007
typedef long long ll;

int main(){
    int m,d,ans=0;
    scanf("%d %d",&m,&d);
    for(int i=1;i<=m;i++){
        for(int j=22;j<=d;j++){
            int a=j%10;
            int b=j/10;
            if(a>=2&&a*b==i){
                ans++;
            }
        }
    }
    printf("%d\n",ans);
}