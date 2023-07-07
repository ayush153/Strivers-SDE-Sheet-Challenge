 int largestRectangle(vector < int > & heights) {
   // Write your code here.
   int ans = 0;
   heights.push_back(0);
   vector<int> idx;

    for(int i = 0; i < heights.size(); i++)
  	{
      while(idx.size() > 0 && heights[idx.back()] >= heights[i])
       {
          int a = heights[idx.back()];
          idx.pop_back();

          int b = idx.size() > 0 ? idx.back() : -1;
          if(a * (i-b-1) > ans)
              ans = a * (i-b-1);
       }
       idx.push_back(i);
    }    
  return ans;
 }
