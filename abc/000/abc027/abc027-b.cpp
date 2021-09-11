#include<cstdio>
using namespace std;
int main(){
    int n,a[100],sum=0,b,ans=0,cnt;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    if(sum%n){
        printf("-1\n");
        return 0;
    }
    b=sum/n;
    sum=0;
    cnt=0;
    for(int i=0;i<n;i++){
        cnt++;
        sum+=a[i];
        if(sum%cnt==0&&sum/cnt==b){
            cnt=0;
            sum=0;
        }
        else{
            ans++;
        }
    }
    printf("%d\n",ans);
}