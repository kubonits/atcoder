#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    long c,d,l,r,ans=0;
    l=140;
    r=170;
    scanf("%ld %ld",&c,&d);
    while(l<=d){
        if(c<r&&d>l){
            ans+=min(r,d)-max(l,c);
        }
        l*=2;
        r*=2;
    }
    printf("%ld\n",ans);
}