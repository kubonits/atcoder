#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;

int main(){
    int n,a[200001],flag[200001]={};
    vector<int> v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=n;i>=1;i--){
        int cnt=0;
        for(int j=i;j<=n;j+=i){
            cnt+=flag[j];
        }
        if(cnt%2!=a[i]){
            flag[i]=1;
            v.push_back(i);
        }
    }
    if(!v.empty()){
        sort(v.begin(),v.end());
    }
    printf("%ld\n",v.size());
    for(int i=0;i<v.size();i++){
        printf("%d ",v[i]);
    }
    if(!v.empty()){
        printf("\n");
    }
}