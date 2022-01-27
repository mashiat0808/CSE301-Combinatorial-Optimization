#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int n, storage;
    
    freopen("knapsackinput.txt", "r", stdin);
    scanf("%d %d", &n, &storage);
    int profit[n], weight[n], profbywe[n];
    pair<int, int> ks[n];
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &profit[i], &weight[i]);
        profbywe[i] = profit[i] / weight[i];
        ks[i].first = profbywe[i];
      
        ks[i].second = weight[i];
    }

    sort(ks, ks + n);
    for(int i=0; i<n; i++)
    {
        profbywe[i]=ks[i].first;
        weight[i]=ks[i].second;
    }
    
   
    int max_profit = 0;
    int cur_weight = 0;
    int i=n-1;
    for(int i=n-1; storage!=0; i--)
    {
        if(storage>=weight[i])
        {
           max_profit=max_profit+weight[i]*profbywe[i];
           storage=storage-weight[i];
        }
        else 
        {
           max_profit= max_profit+ storage*profbywe[i];
            storage=0;
        }
       
    }

    printf(" the maximum possible profit is %d   ", max_profit);
    return 0;
}