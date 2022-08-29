#include<cstdio>
#include<algorithm>
#include<vector>
#define MAX_N 100001
typedef long long ll;
using namespace std;

const int DAT_SIZE = (1<<18)-1;

int n,q;
int A[MAX_N];

ll data[DAT_SIZE],datb[DAT_SIZE];

void add(int a,int b,int x,int k,int l,int r){
    if(a<=l&&r<=b){
        data[k]+=x;
    }
    else if(l<b&&a<r){
        datb[k]+=(min(b,r)-max(a,l))*x;
        add(a,b,x,k*2+1,l,(l+r)/2);
        add(a,b,x,k*2+2,(l+r)/2,r);
    }
}

ll sum(int a,int b,int k,int l,int r){
    if(b<=l||r<=a){
        return 0;
    }
    else if(a<=l&&r<=b){
        return data[k]*(r-l)+datb[k];
    }
    else{
        ll res=(min(b,r)-max(a,l))*data[k];
        res+=sum(a,b,k*2+1,l,(l+r)/2);
        res+=sum(a,b,k*2+2,(l+r)/2,r);
        return res;
    }
}
int main(){
    int m,l,r,ans,sumv[MAX_N]={};
    vector<int> v[MAX_N];
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++){
        scanf("%d %d",&l,&r);
        v[r-l+1].push_back(l);
    }
    for(int i=n;i>=1;i--){
        sumv[i]=sumv[i+1]+v[i].size();
    }
    for(int i=1;i<=n;i++){
        ans=sumv[i];
        for(int j=i;j<=n;j+=i){
            ans+=sum(j,j+1,0,0,n+1);
        }
        for(int j=0;j<v[i].size();j++){
            add(v[i][j],v[i][j]+i,1,0,0,n+1);
        }
        printf("%d\n",ans);
    }
}