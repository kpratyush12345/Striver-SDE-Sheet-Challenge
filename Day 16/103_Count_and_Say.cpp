// TC: O(n)  SC: O(1)
// -------------------
// 1
// 11
// 21
// 1211
// 111221
// 312211
// 13112221
// its a recursive function to find a string with a similar type of pattern for n times

// lets understand with an example n=6
// we start from n=1
// question says we have the string "1"
// now, for second iteration n=2 and s="1" get from previous iteration
// we have the string s="1" , in which we can count how many times the first character i.e. the frequency of the character (that
// is one) is present store both frequency and character in the temporary string res ("11") where first character is frequency
// and second is the character itself so the iteration shifts to next

// now , n=3 we have s="11"
// so repeat the process extract first character count the consecutive frequence and store it in a variable i.e count=2 , update
// the string res("21") and shifted to the next iteration

// for n=4 ,we have s="21"
// count the first character which is '2' we have one time update the string res="12" (here we can say we have 2 one times ) now
// count the second character '1' which we have only one time so add it to string res="12" + "11" and go to next iteration

// n=5, and s="1211"
// count first character '1' we have one times --> update res=res+"11"
// second character '2' we have one times -->update res=res+"12"
// third character '1' we have two times --> update res=res+"21"

// so, final answer is s="111221"
// so i guess you got the drill so calculate yourself for n=6,7 etc...

string countAndSay(int n)
{
    if (n == 1)
        return "1";
    string s = countAndSay(n - 1);
    string res = "";
    char ch = s[0];
    int count = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (ch == s[i])
            count++;
        else
        {
            res += to_string(count);
            res += ch;
            ch = s[i];
            count = 1;
        }
    }
    res += to_string(count);
    res += ch;
    return res;
}