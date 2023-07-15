vector<int> stringMatch(string text, string pattern) {
	// Write your code here.
	int d = 256;
	int q = 101;
	int i, j, t = 0, p = 0;
	int h = 1;
	vector<int> ans;

	for (i = 0; i < pattern.size() - 1; i++)
		h = (h * d) % q;

	for (i = 0; i < pattern.size(); i++)
	{
		p = (p * d + pattern[i]) % q;
		t = (t * d + text[i]) % q;
	}

	for (int i = 0; i <= text.size() - pattern.size(); i++) 
	{
		if (t == p)
		{
			for (j = 0; j < pattern.size(); j++)
			{
				if (pattern[j] != text[i + j])
					break;
			}
			if (j == pattern.size())
				ans.push_back(i+1);
		}

		if (i < text.size() - pattern.size())
		{
			t = (d * (t - text[i] * h) + text[i + pattern.size()]) % q;
			if (t < 0)
				t = t + q;
		}
	}
	return ans;
}

