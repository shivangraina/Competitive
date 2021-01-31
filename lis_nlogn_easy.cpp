#include <iostream>
#include <vector>
#include <algorithm>
# define ll long long
using namespace std;
# define inf 1000000000

int main() {
  ll t;
  cin >> t;
  while(t--){
	int n;
	cin >> n;
  vector<int> a(n);
        
	for (int i = 0; i < n; i++) {
	 cin>>a[i];
	}
	vector<int> d(n+1,inf);
	for (int i = 0; i < n; i++) {
		*lower_bound(d.begin(), d.end(), a[i]) = a[i];
	}
	for (int i = 0; i <= n; i++) {
		if (d[i] == inf) {
			cout <<i << endl;
			break;
		}
        }
  }
}
