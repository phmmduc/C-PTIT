#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--)
    {
        stack<int> st;
        int n;
        cin>>n;
        vector<int> a(n),r(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&a[i]>=st.top())
                st.pop();
            if(st.empty())
                r[i]=-1;
            else r[i]=st.top();
            st.push(a[i]);
        }
        for(int i=0;i<n;i++)
            cout<<r[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}