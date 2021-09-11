#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<set>
#include<map>
using namespace std;

int main(){
    int n,l[2001],ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&l[i]);
    }
    sort(l,l+n);
    l[n]=100000;
    for(int i=1;i<n-1;i++){
        int left=0,right=i+1;
        for(left=0;left<i;left++){
            while(l[right]<l[i]+l[left]){
                right++;
            }
            ans+=right-i-1;
        }
    }
    printf("%d\n",ans);
}