#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n,two[31],ans=0,cnt;
    vector<int> a,b;
    two[0]=1;
    for(int i=1;i<31;i++){
        two[i]=two[i-1]*2;
    }
    scanf("%d",&n);
    a.resize(n);
    b.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    for(int i=30;i>=1;i--){
        cnt=0;
        for(int j=0;j<n;j++){
            a[j]%=two[i];
            b[j]%=two[i];
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int k=0;k<n;k++){
            decltype(b)::iterator it1 = std::lower_bound(b.begin(), b.end(), two[i-1]-a[k]);
            decltype(b)::iterator it2 = std::lower_bound(b.begin(), b.end(), 2*two[i-1]-a[k]);
            decltype(b)::iterator it3 = std::lower_bound(b.begin(), b.end(), 3*two[i-1]-a[k]);
            cnt+=it2-it1+b.end()-it3;
        }
        if(cnt%2){
            ans+=two[i-1];
        }
    }
    printf("%d\n",ans);
}