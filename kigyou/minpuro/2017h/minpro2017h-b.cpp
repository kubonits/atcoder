#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int a[100000],b[100000],n,m,k,mid,l,r,cnt,x,y;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    sort(a,a+n);
    sort(b,b+m);
    l=0;
    r=1000000000;
    while(l<=r){
        mid=(l+r)/2;
        x=y=0;
        cnt=0;
        while(x<n&&y<m){
            if(abs(a[x]-b[y])<=mid){
                cnt++;
                x++;
                y++;
            }
            else if(a[x]<b[y]){
                x++;
            }
            else{
                y++;
            }
        }
        if(cnt>=k){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    printf("%d\n",l);
}