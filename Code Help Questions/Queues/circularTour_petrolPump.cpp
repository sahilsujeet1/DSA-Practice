// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int balance = 0;
       int deficit = 0;
       int start = 0;
       
       for(int i=0; i<n; i++) {
           balance += p[i].petrol - p[i].distance;
           
           if(balance < 0) {
               deficit += balance;
               start = i+1;
               balance = 0;
           }
        }
        
        if(deficit + balance >= 0) {
            return start;
        } else {
            return -1;
        }
    }
};

int main()
{
    int n;
    cin>>n;
    petrolPump p[n];
    for(int i=0;i<n;i++)
        cin>>p[i].petrol>>p[i].distance;
    Solution obj;
    cout<<obj.tour(p,n)<<endl;

    // 4 4 6 6 5 7 3 4 5    Test case input
}
