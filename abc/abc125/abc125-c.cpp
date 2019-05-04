#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;

int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

int main(){
    int n,ans=0,a[100000],b[1000],x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(i/1000){
            b[i%1000]=gcd(b[i%1000],a[i]);
        }
        else{
            b[i%1000]=a[i];
        }
    }
    for(int i=0;i<n;i++){
        x=0;
        for(int j=i%1000;j<n;j+=1000){
            if(i/1000!=j/1000){
                if(x){
                    x=gcd(x,a[j]);
                }
                else{
                    x=a[j];
                }
            }
        }
        for(int j=0;j<min(1000,n);j++){
            if(i%1000!=j%1000){
                if(x){
                    x=gcd(x,b[j]);
                }
                else{
                    x=b[j];
                }
            }
        }
        ans=max(x,ans);
    }
    printf("%d\n",ans);
}