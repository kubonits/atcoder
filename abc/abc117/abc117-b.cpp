#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,l[10],sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&l[i]);
    }
    sort(l,l+n);
    for(int i=0;i<n-1;i++){
        sum+=l[i];
    }
    if(sum>l[n-1]){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}