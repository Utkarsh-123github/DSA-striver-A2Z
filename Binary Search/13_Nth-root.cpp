#include<bits/stdc++.h>
using namespace std;

// Yaha pe humlogpower function banane ke jagh powerChecker function, overflow conditions ko na laane ke liye kr rhe kyuki waise bhi hume Binary search me bass check krne se matlab hai power ke value ka koi jarurat nhi hai

int powerChecker(int mid , int n , int num)
{
    // In this function we'll return 1 if ans == num 
    // return 0 if ans<num
    // return 2 if ans>num
    long long ans = 1;
    for(int i=1;i<=n;i++){
        ans = ans*mid;
        if(ans>num) return 2;
    }
    if(ans == num) return 1;
    return 0;
}

int NthRoot(int n,int num)
{
    int low = 1, high = num;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        int powerCheck = powerChecker(mid , n , num);
        if(powerCheck == 1)return mid;
        else if(powerCheck == 2){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

int main()
{
    int num;
    cin>>num;
    int power;
    cin>>power;
    cout<<NthRoot(power,num)<<endl;
    return 0;
}

