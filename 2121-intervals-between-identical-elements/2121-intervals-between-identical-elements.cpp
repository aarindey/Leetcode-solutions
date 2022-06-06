class Solution {
public:
    #define ll long long int
    ll abbs(ll x)
    {
        return abs(x);
    }
    vector<long long> getDistances(vector<int>& arr) {
     map<ll,vector<ll>> mp;
        ll n=arr.size();
        for(ll i=n-1;i>=0;i--)
        {
            mp[arr[i]].push_back(i);
        }
        vector<ll> ans(n);
        for(auto pr:mp)
        {
            vector<ll> v=pr.second;
            ll total=accumulate(v.begin(),v.end(),(ll)0);
            ll pre=0;
            ll n2=v.size();
            ll res=0;
            for(ll i=0;i<n2;i++)
            {
                res=abs(i*v[i]-pre)+abs((total-pre-v[i])-(n2-i-1)*v[i]);
                pre+=v[i];
                ans[v[i]]=res;
            }
        }
        return ans;
    }
};