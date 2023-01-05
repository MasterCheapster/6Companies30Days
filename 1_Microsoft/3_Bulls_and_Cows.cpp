class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int b = 0, c = 0;
        vector<int> sec(10, 0);
        vector<int> gue(10, 0);
        if (secret.size() != guess.size() || secret.empty())
        {
            return "0A0B";
        }
        for (int i = 0; i < secret.size(); i++)
        {
            char c1 = secret[i];
            char c2 = guess[i];
            if (c1 == c2)
            {
                b++;
            }
            else
            {
                sec[c1 - '0']++;
                gue[c2 - '0']++;
            }
        }
        // Count the number of unpaired digits, and the less one is the cow number
        // sec[c1-'0']++; gue[c2-'0']++; is used to count digits (0~9) number which are not paired.
        // c += min(sec[i], gue[i]); 
        //for example, sec[1] =2, gue[1] =3, 
        //means there are 2 '1' in secret and 3 '1' in guess can not find paired one, 
        //then at least there are 2 '1' is in the wrong place.
        for (int i = 0; i < sec.size(); i++)
        {
            c += min(sec[i], gue[i]);
        }
        return to_string(b) + 'A' + to_string(c) + 'B';
    }
};