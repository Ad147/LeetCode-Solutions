// LeetCode728-selfDividingNumbers.cpp
// Ad147
// Init: 19Jan02

/* -----------------------------------------------------------------------------

A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

Also, a self-dividing number is not allowed to contain the digit zero.

Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.

Example 1:

```
Input: 
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
```

Note:

- The boundaries of each input argument are 1 <= left <= right <= 10000.

----------------------------------------------------------------------------- */

#include <vector>

// solution --------------------------------------------------------------------

// Runtime: 4 ms, faster than 65.11% of C++ online submissions for Self Dividing Numbers.
// `final`: Many 0 ms submissions have similar code with this.

class Solution
{
  public:
    std::vector<int> selfDividingNumbers(int left, int right)
    {
        std::vector<int> ret;
        for (int i = left; i <= right; ++i)
        {
            bool flag = true;
            for (int temp = i, d = temp % 10; temp != 0; temp /= 10, d = temp % 10)
            {
                if (d == 0 || i % d)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ret.push_back(i);
        }

        return ret;
    }
};
