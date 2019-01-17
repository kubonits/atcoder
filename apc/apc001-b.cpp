#include<cstdio>
using namespace std;
int main(){
    long a[10000],b[10000],as=0,bs=0,n,sa=0,sb=0;
    scanf("%ld",&n);
    for(int i=0;i<n;i++){
        scanf("%ld",&a[i]);
        as+=a[i];
    }
    for(int i=0;i<n;i++){
        scanf("%ld",&b[i]);
        bs+=b[i];
        if(a[i]>b[i]){
            sa+=a[i]-b[i];
        }
        else{
            sb+=(b[i]-a[i])/2+(b[i]-a[i])%2;
        }
    }
    if(as>bs||bs-as<sa||(bs-as)<sb){
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
}