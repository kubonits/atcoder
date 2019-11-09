#include<cstdio>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n,l,r,ans=0;
    pair<int,int> left[100000],right[100000];
    vector<pair<int,int> > v1,v2;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&l,&r);
        v1.push_back({l,r});
        v2.push_back({r,l});
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    left[0]={v1[0].first,v1[0].second};
    for(int i=1;i<n;i++){
        left[i].first=max(left[i-1].first,v1[i].first);
        left[i].second=min(left[i-1].second,v1[i].second);
    }
    right[n-1]={v1[n-1].first,v1[n-1].second};
    for(int i=n-2;i>=0;i--){
        right[i].first=max(right[i+1].first,v1[i].first);
        right[i].second=min(right[i+1].second,v1[i].second);
    }
    for(int i=1;i<n;i++){
        int x=0;
        if(left[i-1].first<=left[i-1].second){
            x+=left[i-1].second-left[i-1].first+1;
        }
        if(right[i].first<=right[i].second){
            x+=right[i].second-right[i].first+1;
        }
        ans=max(ans,x);
    }
    for(int i=1;i<n-1;i++){
        int x=0;
        if(max(left[i-1].first,right[i+1].first)<=min(left[i-1].second,right[i+1].second)){
            x+=min(left[i-1].second,right[i+1].second)-max(left[i-1].first,right[i+1].first)+1;
        }
        x+=v1[i].second-v1[i].first+1;
        ans=max(ans,x);
    }
    left[0]={v2[0].second,v2[0].first};
    for(int i=1;i<n;i++){
        left[i].first=max(left[i-1].first,v2[i].second);
        left[i].second=min(left[i-1].second,v2[i].first);
    }
    right[n-1]={v2[n-1].second,v2[n-1].first};
    for(int i=n-2;i>=0;i--){
        right[i].first=max(right[i+1].first,v2[i].second);
        right[i].second=min(right[i+1].second,v2[i].first);
    }
    for(int i=1;i<n;i++){
        int x=0;
        if(left[i-1].first<=left[i-1].second){
            x+=left[i-1].second-left[i-1].first+1;
        }
        if(right[i].first<=right[i].second){
            x+=right[i].second-right[i].first+1;
        }
        ans=max(ans,x);
    }
    printf("%d\n",ans);
}