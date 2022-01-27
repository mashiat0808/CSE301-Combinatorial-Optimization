#include <bits/stdc++.h>
using namespace std;

int main()
{   
    freopen("activityselectioninput.txt", "r", stdin);
    int i;
    int n;
    cin >> n;
    int temp[n];
    int starttime[n], finishtime[n];
    for (int i = 0; i < n; i++)
    {
        cin >> starttime[i] >> finishtime[i];
    }
    pair<int, int> activity[n];

    for(int i = 0; i < n; i++)
    {
        activity[i].second = starttime[i];
        activity[i].first = finishtime[i];
    }
    sort(activity, activity + n);
    for(i=0; i<n; i++)
    {
        finishtime[i] = activity[i].first;
        starttime[i] = activity[i].second;
    }
    for(int i=0;i<n;i++)
    {
        temp[i]=-1;
    }
    int j=0;
    temp[0]=0;
    for(int i=1;i<n;i++)
    {
        if(starttime[i]>=finishtime[temp[j]])
        {
            temp[++j]=i;
            
        }
    }

    for(int i=0;i<n;i++)
    {
        if(temp[i]!=-1)
        {
            cout<<temp[i]<<" "<<endl;
        }
    }

}