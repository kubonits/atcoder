#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define mod 1000000007
using namespace std;
int main(){
    int n,k,sl[51],sr[51],v[50],ans=-1000000000,sum,l,r;
    vector<int> vl[51],vr[51];
    scanf("%d %d",&n,&k);
    sl[0]=sr[0]=0;
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
        sl[i+1]=sl[i]+v[i];
        vl[i+1]=vl[i];
        if(v[i]<0){
            vl[i+1].push_back(v[i]);
        }
    }
    for(int i=0;i<n;i++){
        vr[i+1]=vr[i];
        sr[i+1]=sr[i]+v[n-1-i];
        if(v[n-1-i]<0){
            vr[i+1].push_back(v[n-1-i]);
        }
    }
    for(int i=1;i<=n;i++){
        if(vr[i].size()!=0){
            sort(vr[i].begin(),vr[i].end());
        }
        if(vl[i].size()!=0){
            sort(vl[i].begin(),vl[i].end());
        }
    }
    for(int i=0;i<=min(n,k);i++){
        for(int j=0;i+j<=min(n,k);j++){
            sum=sl[i]+sr[j];
            int x=k-(i+j);
            l=r=0;
            while(x&&(l<vl[i].size()||r<vr[j].size())){
                if(r==vr[j].size()){
                    sum-=vl[i][l];
                    l++;
                    x--;
                }
                else if(l==vl[i].size()){
                    sum-=vr[j][r];
                    r++;
                    x--;
                }
                else if(vl[i][l]<vr[j][r]){
                    sum-=vl[i][l];
                    l++;
                    x--;
                }
                else{
                    sum-=vr[j][r];
                    r++;
                    x--;
                }
            }
            ans=max(ans,sum);
        }
    }
    printf("%d\n",ans);
}