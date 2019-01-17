#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n;
    long a,b,ans=0,maxa=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        if(maxa<a){
            maxa=a;
            ans=a+b;
        }
    }
    printf("%ld\n",ans);
}