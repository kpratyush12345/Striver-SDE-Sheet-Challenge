// TC: O(n)  SC: O(1)
// ---------------------
// 1. Start traversing the provided string(str)
// 2. Skip all the leading white spaces. eg: " -123456" --> "-123456"
// 3. Check for sign cases(+-). eg: "-123456". If +, then set the variable(boolean) isNegative to true and if it's -, set
// isNegative to false
// 4. Iterate over the next remaining characters and keep adding them in result by converting the digits(in character form) to
// integer form. eg: "-123456" --> -123456, until the non-digit character is found.
// NOTE: Logic is implemented in such a way that after performing above 3 steps, if it finds characters(English letters
// (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.') before the digit character, it will give output as 0(zero)
// eg: "abc-123456" --> 0 and if it finds characters(English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-',
// and '.') after the digit characters, it will return the number eg: "-123456abc" --> -123456

// result > (Integer.MAX_VALUE / 10) means:
// Suppose,
// result = 214748365(9 digits)
// Integer.MAX_VALUE = 2147483647(10 digits) and Integer.MAX_VALUE / 10 = 214748364(9 digits)
// Here, it is clearly evident that result > Integer.MAX_VALUE / 10( i.e. 214748365 > 214748364) and if we try to add even 0
// (zero) in result 214748365(9 digits), the number will become 2147483650(10 digits) which is obviously greater than 2147483647
// (Integer.MAX_VALUE which is of 10 digits). So even before adding 0(zero) or any other digit, we return the Integer.MAX_VALUE
// or Integer.MIN_VALUE, according to the sign case, in order to avoid integer overflow.

// And, result == (Integer.MAX_VALUE / 10) && digit > 7 means:
// Suppose,
// result = 214748364(9 digits), and
// Integer.MAX_VALUE / 10 = 214748364(9 digits)
// Now, if the result is equal to the Integer.MAX_VALUE / 10 (214748364 == 214748364) and the digit is greater than 7 i.e. digit
// > 7 and if we try to add 8(assume the digit greater than 7 to be 8) to the result, then the number will become 2147483648(10
// digits), which will result in integer overflow. So, even before adding the digit which is greater than 7, we return the
// Integer.MAX_VALUE or Integer.MIN_VALUE, according to the sign case, to avoid integer overflow.

class Solution
{
public:
    int myAtoi(string s)
    {

        // helper variables
        int res = 0;
        int i = 0;
        int sign = 1;

        while (i < s.size() && s[i] == ' ')
            i++; // ignore leading white space

        if (s[i] == '-' || s[i] == '+') // check if number positve or negative
        {
            sign = s[i] == '-' ? -1 : 1;
            i++;
        }
        // now iterate across digits if any
        // should only be in range 0-9
        while (i < s.length() && (s[i] >= '0' && s[i] <= '9')) // traverse string till nondigit not found or string ends
        {
            int digit = (s[i] - '0') * sign;
            if (sign == 1 && (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > INT_MAX % 10)))
                return INT_MAX; // check for overflow
            if (sign == -1 && (res < INT_MIN / 10 || (res == INT_MIN / 10 && digit < INT_MIN % 10)))
                return INT_MIN; // check for underflow

            res = res * 10 + digit; // update res
            i++;
        }

        return res;
    }
};