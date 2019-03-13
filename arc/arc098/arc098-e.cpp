#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n,ans=1000000000,k,q,a[2000],x;
    vector<int> v1,v2;
    scanf("%d %d %d",&n,&k,&q);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        v2.clear();
        v1.clear();
        for(int j=0;j<n;j++){
            if(a[j]<a[i]){
                sort(v1.begin(),v1.end());
                x=(int)v1.size();
                for(int l=0;l<=x-k;l++){
                    v2.push_back(v1[l]);
                }
                v1.clear();
            }
            else{
                v1.push_back(a[j]);
            }
            if(j==n-1){
                sort(v1.begin(),v1.end());
                x=(int)v1.size();
                for(int l=0;l<=x-k;l++){
                    v2.push_back(v1[l]);
                }
                v1.clear();
            }
        }
        if(v2.size()>=q){
            sort(v2.begin(),v2.end());
            ans=min(ans,v2[q-1]-v2[0]);
        }
    }
    printf("%d\n",ans);
}