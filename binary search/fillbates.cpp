#include<bits/stdc++.h>
using namespace std;
 
vector<vector<int> > vvi;
string c; string q;
 
int main() {
 
    vvi.resize(256);
    cin >> c; int Q;
    for(int i = 0; i < c.size(); i++) {
        vvi[c[i]].push_back(i);
    }
    scanf("%d", &Q);
    for(int i = 0; i < Q; i++) {
        cin >> q;
        int ind = -1, a = 0; bool fin = true;
        for(int j = 0; j < q.size(); j++) {
            vector<int>::iterator low = upper_bound(vvi[q[j]].begin(), vvi[q[j]].end(), ind);
            ind = low - vvi[q[j]].begin();
            if(low == vvi[q[j]].end()) fin = false;
            ind = vvi[q[j]][ind];
            if(j == 0) a = ind;
        }
 
        if(fin) {
            printf("Matched %d %d\n", a, ind);
        } else printf("Not matched\n");
    }
 
    return 0;
}