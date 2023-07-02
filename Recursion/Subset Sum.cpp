void helper(int idx, int sum, int n, vector<int>& num, vector<int>& ans)
{
	if(idx == n)
	{
		ans.push_back(sum);
		return;
	}

	sum += num[idx];
	helper(idx+1, sum,n, num, ans);
	sum -= num[idx];
	helper(idx+1, sum, n,num, ans);
}
vector<int> subsetSum(vector<int> &num){
	// Write your code here.
	int n = num.size();
	vector<int>ans;
	helper(0, 0, n, num, ans);
	sort(ans.begin(),ans.end());
	return ans;	
}
