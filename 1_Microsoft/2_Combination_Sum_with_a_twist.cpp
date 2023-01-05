class Solution
{
public:
    void func(vector<vector<int>> &ans, vector<int> &curr, int cnum, int k, int n)
    {
        if (n < 0 || curr.size() > k)
            return;
        if (n == 0 && curr.size() == k)
        {
            ans.push_back(curr);
            return;
        }
        for (int i = cnum; i <= 9; ++i)
        {
            curr.push_back(i);
            func(ans, curr, i + 1, k, n - i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> curr;
        vector<vector<int>> ans;
        func(ans, curr, 1, k, n);
        return ans;
    }
};