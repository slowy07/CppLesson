## best time to buy and sell stock (easy)


**solution 1**
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = INT_MAX, ans = 0;
        for (int p : prices) {
            minVal = min(minVal, p);
            ans = max(ans, p - minVal);
        }
        return ans;
    }
};
```
**solution 2**
```cpp
class Solution {
public:
    int maxProfit(vector<int>& A) {
        int buy = INT_MIN, sell = 0;
        for (int n : A) {
            buy = max(buy, -n);
            sell = max(sell, buy + n);
        }
        return sell;
    }
};
```
