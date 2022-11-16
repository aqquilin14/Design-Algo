#include <bits/stdc++.h>
using namespace std;
int knapSack(int W, int wt[], int val[], int n)
{
int i, w;
vector<vector<int>> K(n + 1, vector<int>(W + 1));
for(i = 0; i <= n; i++)
{
for(w = 0; w <= W; w++)
{
if (i == 0 || w == 0)
K[i][w] = 0;
else if (wt[i - 1] <= w)
K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
else
K[i][w] = K[i - 1][w];
cout<<K[i][w]<<" ";
}
cout<<endl;
}
return K[n][W];}
int main()
{
int n,w;
cout<<"Enter the number of Items:"<<endl;
cin>>n;
cout<<"Enter the capacity of Knapsack:"<<endl;
cin>>w;
int val[n],wt[n];
cout<<"Enter the values of Profits:"<<endl;
for(int i=0;i<n;i++){
cin>>val[i]; }
cout<<"Enter the values of Weights:"<<endl;
for(int i=0;i<n;i++){
cin>>wt[i];
}
cout<<"Maximum profit can be obtained is: " << knapSack(w, wt, val, n);
return 0;
}


/*
Output:
Enter the number of Items:
4
Enter the capacity of Knapsack:
8
Enter the values of Profits:
1 2 5 6
Enter the values of Weights:
2 3 4 5
0 0 0 0 0 0 0 0 0
0 0 1 1 1 1 1 1 1
0 0 1 2 2 3 3 3 3
0 0 1 2 5 5 6 7 7
0 0 1 2 5 6 6 7 8
8
*/