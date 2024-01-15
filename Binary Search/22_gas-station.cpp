#include<bits/stdc++.h>
using namespace std;

// Brute approach 

double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int>howMany(n-1,0);
    for(int gasStation = 1; gasStation <= k; gasStation++)
    {
        long double maxSection = -1;
        int maxIndex = -1;
        for(int i=0;i<n-1;i++)
        {
            long double difference = arr[i+1] - arr[i];
            long double sectionLength = difference / ((long double)howMany[i]+1);
            if(sectionLength>maxSection)
            {
                maxSection = sectionLength;
                maxIndex = i;
            }
        }
        howMany[maxIndex]++;
    }

    long double maxAns = -1;
    for(int i=0 ; i<n-1 ; i++)
    {
        long double difference = arr[i+1] - arr[i];
        long double sectionLength = difference / ((long double)howMany[i]+1);
        maxAns = max(maxAns,sectionLength);
    }
    return maxAns;
}

// Better approach using Priority Queue

double minimiseMaxDistance_1(vector<int>&arr , int k)
{
    int n = arr.size();
    vector<int>howMany(n-1,0);
    priority_queue<pair<long double , int>>pq;
    for(int i=0;i<n-1;i++)
    {
        pq.push({arr[i+1]-arr[i],i});
    }
    for(int gasStation = 1;gasStation<=k;gasStation++)
    {
        auto tp = pq.top();
        pq.pop();
        int secInd = tp.second;
        howMany[secInd]++;
        long double initialDifference = arr[secInd+1]-arr[secInd];
        long double newSection = initialDifference / ((long double)howMany[secInd]+1);
        pq.push({newSection,secInd});
    }
    return pq.top().first;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance_1(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}