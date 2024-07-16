#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin() , a.end());
        long long start = 0 , end = 0;
        long long mind = LLONG_MAX;
        for (long long i = 0; i+m-1 < n; i++) {
            long long diff = a[i+m-1] - a[i];
            if (mind > diff) {
                mind = diff;
                start = i;
                end = i+m-1;
            }
        }
        return a[end] - a[start];
    
    }   
};
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
