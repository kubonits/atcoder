#include<cstdio>
#include<vector>
#include<utility>
using namespace std;

int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

int main(){
    int n,k,a[200000],g,flag;
    vector<pair<int ,long> > v;
    long ans=0;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        g=gcd(k,a[i]);
        flag=1;
        for(int j=0;j<v.size();j++){
            if(v[j].first==g){
                v[j].second++;
                flag=0;
                break;
            }
        }
        if(flag){
            v.push_back(make_pair(g,1));
        }
    }
    for(int i=0;i<v.size();i++){
        for(int j=i;j<v.size();j++){
            if(k==gcd(k,v[i].first*v[j].first)){
                if(i!=j){
                    ans+=v[i].second*v[j].second;
                }
                else{
                    ans+=v[i].second*(v[j].second-1)/2;
                }
            }
        }
    }
    printf("%ld\n",ans);
}