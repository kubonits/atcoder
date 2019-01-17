#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,c,l[100000],ans=0,le,r;
    scanf("%d %d",&n,&c);
    for(int i=0;i<n;i++){
        scanf("%d",&l[i]);
    }
    sort(l,l+n);
    le=0;
    r=n-1;
    while(le<=r){
        if(l[le]+l[r]+1<=c){
            le++;
            r--;
        }
        else{
            r--;
        }
        ans++;
    }
    printf("%d\n",ans);
}