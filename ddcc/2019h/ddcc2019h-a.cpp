#include<cstdio>
#include<algorithm>
using namespace std;
int n,l[100000],r[100000];
double sum[100001],a[100001],k=0.0,ans=100000.0;
char s[100001];
int main(){
    scanf("%d",&n);
    scanf("%s",s);
    sum[0]=0;
    a[0]=0;
    l[0]=0;
    for(int i=0;i<n;i++){
        if(s[i]=='-'){
            sum[i+1]=sum[i]+1.0;
            k=0;
        }
        else{
            sum[i+1]=sum[i]+(double)(1/(2+k));
            k+=1.0;
        }
        a[i+1]=a[i]+(double)(1.0/(2.0+(double)i));
    }
    for(int i=1;i<n;i++){
        if(s[i-1]=='-'){
            l[i]=i;
        }
        else{
            l[i]=l[i-1];
        }
    }
    r[n-1]=n-1;
    for(int i=n-2;i>=0;i--){
        if(s[i+1]=='-'){
            r[i]=i;
        }
        else{
            r[i]=r[i+1];
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]=='-'){
            ans=min(ans,sum[n]-sum[r[i]+1]+sum[l[i]]+a[r[i]-l[i]+1]);
        }
    }
    printf("%f\n",ans);
}