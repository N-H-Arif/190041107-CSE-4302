#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b=0,even[5],i;
    set<int>odd;
    vector<int>merged(10);

    for(i=1; i<=10; i++)
    {
        if(i%2==0)
        {
            even[b]=i;
            b++;
        }
        else
        {
            odd.insert(i);
        }
    }

    merge(even, even+5, odd.begin(), odd.end(), merged.begin());
    cout << "Merged : ";
    for (i = 0; i < merged.size(); i++)
    {
        cout << merged[i] << " ";
    }
    cout<<endl;
    return 0;
}
