string kthPermutation(int n, int k) {
    // Write your code here.
    int fact = 1;
    string ans;
    vector<int> v;
    for(int i = 1; i < n; i++)
    {
        fact *= i;
        v.push_back(i);
    }

    v.push_back(n);
    k--;
    while(true)
    {
        ans.push_back(v[k/fact] + '0');
        v.erase(v.begin()+k/fact);
        if(v.empty()) break;
        k %= fact;
        fact /= v.size();
    }

    return ans;
}

