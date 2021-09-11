#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int main(){
    int n,a[50],cnt=0,f;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        if(a[i]!=i+1){
            cnt++;
        }
    }
    if(cnt==0||cnt==2){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}