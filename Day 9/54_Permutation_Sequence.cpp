// Brute Force - TC: O(N! * N) +O(N! Log N!)  SC: O(N)
// ----------------------------------------------------
// The extreme naive solution is to generate all the possible permutations of the given sequence.  This is achieved using
// recursion and every permutation generated is stored in some other data structure (here we have used a vector). Finally,
// we sort the data structure in which we have stored all the sequences and return the Kth sequence from it.

class Solution
{
public:
    void solve(string &s, int index, vector<string> &res)
    {
        if (index == s.size())
        {
            res.push_back(s);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            swap(s[i], s[index]);
            solve(s, index + 1, res);
            swap(s[i], s[index]);
        }
    }

    string getPermutation(int n, int k)
    {
        string s;
        vector<string> res;
        for (int i = 1; i <= n; i++)
        {
            s.push_back(i + '0');
        }
        solve(s, 0, res);
        sort(res.begin(), res.end());
        auto it = res.begin() + (k - 1);
        return *it;
    }
};

// Optimal Solution - TC : O(N^2)  SC: O(N)
// -----------------------------------------
// Since this is a permutation we can assume that there are four positions that need to be filled using the four numbers of
// the sequence. First, we need to decide which number is to be placed at the first index. Once the number at the first index
// is decided we have three more positions and three more numbers.  Now the problem is shorter. We can repeat the technique
// that was used previously until all the positions are filled.

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> numbers;
        for (int i = 1; i < n; i++)
        {
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans = "";
        k = k - 1;
        while (true)
        {
            ans = ans + to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + k / fact);
            if (numbers.size() == 0)
            {
                break;
            }

            k = k % fact;
            fact = fact / numbers.size();
        }
        return ans;
    }
};