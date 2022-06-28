// Two Pointer Approach - TC: O(n)  SC: O(1)
// --------------------------------------------

// Let's generate some clue that how we will reach to our answer.
// The first and the most important thing that we can observe here is by looking a constraint i.e All the given revisions in /// version1 and version2 can be stored in a 32-bit integer.
// It gives us a clue that for comparing some numbers we have open option.
// Question asks us to compare versions of two different strings by traversing left to right. And versions are present between
// dots of strings.
// So, Finally we can think of is, We will start generating every possible number present in between dots of both the strings
// and simply compare those two numbers and on the basis of that comparison we will return our answer.
// For doing this we will use our two pointer approach.
// See below how it works.

// Suppose our strings given to us is s1 = "1.1.0.3.5.06" and s2 = "1.1.0.00003.5.00005"

// s1 = "1.1.0.3.5.06"                       s2 = "1.1.0.00003.5.00005"
//        ↑                                         ↑
// 	   For the first dot number generated from s1 is, number1 = 1 &
// 	   For the first dot number generated from s2 is, number2 = 1
// 	   Since both them are equal, so we can't comment anything,
// 	   therefore we will move further

// s1 = "1.1.0.3.5.06"                       s2 = "1.1.0.00003.5.00005"
//          ↑                                         ↑
// 		 For the second dot number generated from s1 is, number1 = 1 &
// 	     For the second dot number generated from s2 is, number2 = 1
// 	     Since both them also equal, so we can not comment anything,
// 	     therefore we will move further

// s1 = "1.1.0.3.5.06"                       s2 = "1.1.0.00003.5.00005"
//            ↑                                         ↑
// 		   For the third dot number generated from s1 is, number1 = 0 &
// 	       For the third dot number generated from s2 is, number2 = 0
// 	       Since both again equal, so we can not comment anything,
// 	       therefore we will move further

// s1 = "1.1.0.3.5.06"                       s2 = "1.1.0.00003.5.00005"
//              ↑                                             ↑
// 			 For the fourth dot number generated from s1 is, number1 = 3 &
// 	         For the fourth dot number generated from s2 is, number2 = 00003
// 			 One Important thing is to observe here is,
// 			 no matter how many leading zeroes are their, if numbers are same then we will proceed further
// 	         Since both again equal, so we can not comment anything,
// 	         therefore we will move further

// s1 = "1.1.0.3.5.06"                       s2 = "1.1.0.00003.5.00005"
//                ↑                                             ↑
// 			   For the fifth dot number generated from s1 is, number1 = 5 &
// 	           For the fifth dot number generated from s2 is, number2 = 5
// 			   Since both again equal, so we can not comment anything,
// 			   therefore we will move further

// s1 = "1.1.0.3.5.06 "                       s2 = "1.1.0.00003.5.00005 "
//                    ↑                                                 ↑
// 				   And lastly number generated from s1 is, number1 = 06 &
// 				   number generated from s1 is, number2  = 00005
// 				   since number1 > number2 , therefore we will return 1 as our answer.

// Therefore, Our answer should be 1.

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int i = 0, j = 0, n1 = version1.size(), n2 = version2.size(), num1 = 0, num2 = 0;
        while (i < n1 || j < n2)
        {
            while (i < n1 && version1[i] != '.')
            {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            while (j < n2 && version2[j] != '.')
            {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            if (num1 > num2)
            {
                return 1;
            }
            if (num1 < num2)
            {
                return -1;
            }
            i++;
            j++;
            num1 = 0;
            num2 = 0;
        }
        return 0;
    }
};