#include<bits/stdc++.h>
using namespace std;
double knapsack(vector<pair<double,int>>v,int w,int n){
double ans=0;
for(int i=0;i<n;i++){
if(w>v[i].second){
ans+=(v[i].first*v[i].second);
w-=v[i].second;
}
else{
ans+=w*v[i].first;
w=0;
}
}
return ans;
}
int main(){
int n,w;
cout<<"Enter the number of Items:"<<endl;
cin>>n;
cout<<"Enter the capacity of Knapsack:"<<endl;
cin>>w;
vector<int>profit(n),weight(n);
cout<<"Enter the values of Profits:"<<endl;
for(int i=0;i<n;i++){
cin>>profit[i];
}
cout<<"Enter the values of Weights:"<<endl;
for(int i=0;i<n;i++){
cin>>weight[i];
}
vector<pair<double,int>>profitperwt(n);
for(int i=0;i<n;i++){
profitperwt[i]={(profit[i]/(float)weight[i]),weight[i]};
}
sort(profitperwt.begin(),profitperwt.end());
reverse(profitperwt.begin(),profitperwt.end());
cout<<"Maximum possible Profit :: "<<knapsack(profitperwt,w,n);
return 0;
}