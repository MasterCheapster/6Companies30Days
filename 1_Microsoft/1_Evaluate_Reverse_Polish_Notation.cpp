class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        int n = tokens.size();
        string t = tokens.back();
        tokens.pop_back();
        if (t != "+" && t != "*" && t != "-" && t != "/")
        {
            return stoi(t);
        }
        else
        {
            long long b = evalRPN(tokens);
            long long a = evalRPN(tokens);
            if (t == "+")
                return a + b;
            else if (t == "-")
                return a - b;
            else if (t == "*")
                return a * b;
            else
                return a / b;
        }
    }
};