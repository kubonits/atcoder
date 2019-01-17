#include<cstdio>
using namespace std;
int main(){
    long n,a[100000],sum=0,d[100000],k;
    scanf("%ld",&n);
    for(long i=0;i<n;i++){
        scanf("%ld",&a[i]);
        sum+=a[i];
    }
    if(sum%(n*(n+1)/2)){
        printf("NO\n");
        return 0;
    }
    k=sum/(n*(n+1)/2);
    for(long i=0;i<n;i++){
        d[i]=a[i]-a[(i+1)%n]+k;
    }
    sum=0;
    for(long i=0;i<n;i++){
        if(d[i]%n||d[i]<0){
            printf("NO\n");
            return 0;
        }
        else{
            sum+=d[i];
        }
    }
    if(sum==n*k){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}