// Using Stack - TC: O(n)  SC: O(n)
// -----------------------------------
// Skip the spaces and push the word in stack and lastly pop and store the elements in a string.

class Solution
{
public:
    string reverseWords(string s)
    {
        if (s.size() == 0)
            return s;
        stack<string> stack;
        string result;
        for (int i = 0; i < s.size(); i++)
        {
            string word;
            if (s[i] == ' ')
                continue; // skip spaces
            while (i < s.size() && s[i] != ' ')
            { // store continuous letters into word
                word += s[i];
                i++;
            }
            stack.push(word); // push word to the stack
        }
        while (!stack.empty())
        {
            result += stack.top();
            stack.pop();
            if (!stack.empty())
                result += " ";
        }
        return result;
    }
};

// Two Pointer Approach - TC: O(n)  SC: O(1)
// ------------------------------------------
// 1. Reverse whole string.
// 2. Again maintain two indices i and j for starting and ending of word, Twist is this time i will not point to starting of word  but instead to the first leading space, Reason for the same is when we will call reverse on i..j, It will brinng word in the front and spaces to the back, In this way we will make all space to the trailing ones.
// 3. One more thing is we will rev(i,j) when i==0. Reason is in this there might not be a single space, For other cases it is
// clearly mentioned that there will be at least 1 space b/w words.

class Solution
{
public:
    void rev(string &s, int l, int r)
    {
        while (l < r)
            swap(s[l++], s[r--]);
    }
    string reverseWords(string s)
    {
        int i, j, n = s.length();
        i = 0;

        rev(s, 0, n - 1);
        while (i < n)
        {

            // Remove leading spaces
            j = i;
            while (j < n && s[j] == ' ')
                j++;

            int cnt = 0;

            while (j < n && s[j] != ' ')
            {
                j++;
                cnt++;
            }

            if (j > n)
                break;
            j--;

            if (i == 0)
                rev(s, i, j);
            else
                rev(s, i + 1, j);

            if (cnt == 0)
                i = j + 1;
            else
                i = i + cnt;
        }

        j = n - 1;
        while (j >= 0 && s[j] == ' ')
        {
            j--;
            s.pop_back();
        }
        return s;
    }
};