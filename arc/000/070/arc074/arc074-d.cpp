#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int n;
long a[300000],ans=0,sum1[300000]={},sum2[300000]={};
priority_queue<long, vector<long>,greater<long> > q1;
priority_queue<long> q2;
int main(){
    scanf("%d",&n);
    for(int i=0;i<3*n;i++){
        scanf("%ld",&a[i]);
        if(i<n){
            q1.push(a[i]);
            sum1[n-1]+=a[i];
        }
        else if(i>=2*n){
            q2.push(a[i]);
            sum2[2*n]+=a[i];
        }
    }
    for(int i=n;i<2*n;i++){
        sum1[i]=sum1[i-1];
        if(q1.top()<a[i]){
            sum1[i]-=q1.top();
            sum1[i]+=a[i];
            q1.push(a[i]);
            q1.pop();
        }
    }
    for(int i=2*n-1;i>=n;i--){
        sum2[i]=sum2[i+1];
        if(q2.top()>a[i]){
            sum2[i]-=q2.top();
            sum2[i]+=a[i];
            q2.push(a[i]);
            q2.pop();
        }
    }
    ans=-100000000000000;
    for(int i=n-1;i<2*n;i++){
        ans=max(ans,sum1[i]-sum2[i+1]);
    }
    printf("%ld\n",ans);
}