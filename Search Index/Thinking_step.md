### **Problem 1: Search Insert Position (Implement Lower Bound)**

#### **Problem Statement**

একটি **সর্টেড** ইন্টিজার অ্যারে `nums` এবং একটি ইন্টিজার `target` দেওয়া হবে।
*   যদি `target` অ্যারেতে পাওয়া যায়, তবে তার ইনডেক্স রিটার্ন করো।
*   যদি `target` পাওয়া না যায়, তবে সেই ইনডেক্সটি রিটার্ন করো যেখানে `target`-কে ঢোকালে (insert করলে) অ্যারেটি সর্টেড থাকবে।

**Example:**
*   `nums = [1, 3, 5, 6]`, `target = 5` -> **2** (কারণ `nums[2] == 5`)
*   `nums = [1, 3, 5, 6]`, `target = 2` -> **1** (কারণ 2-কে ইনডেক্স 1-এ ঢোকালে অ্যারেটি `[1, 2, 3, 5, 6]` হবে)
*   `nums = [1, 3, 5, 6]`, `target = 7` -> **4** (কারণ 7-কে ইনডেক্স 4-এ ঢোকাতে হবে)

#### **Core Idea**

এই সমস্যাটি আসলে আমাদের বলছে: **"অ্যারেতে `target`-এর সমান বা তার চেয়ে বড় প্রথম উপাদানটির ইনডেক্স খুঁজে বের করো।"** এই ধারণাটিই কম্পিউটার সায়েন্সে **Lower Bound** নামে পরিচিত।

`lower_bound(array, target)` = অ্যারেতে সেই প্রথম ইনডেক্স `i` যেখানে `array[i] >= target`।

আমরা বাইনারি সার্চ ব্যবহার করে এই "প্রথম occurrence" টি খুঁজব। আমাদের লক্ষ্য হলো সার্চ স্পেসকে এমনভাবে ছোট করা যাতে আমরা ধীরে ধীরে আমাদের কাঙ্ক্ষিত ইনডেক্সের দিকে এগোতে পারি।

---

### **Approach 1: Iterative Binary Search (Optimal)**

এটি `lower_bound` ইমপ্লিমেন্ট করার জন্য স্ট্যান্ডার্ড এবং সেরা পদ্ধতি।

#### **Algorithm:**
1.  **Initialization:**
    *   `low = 0`, `high = arr.size() - 1`।
    *   `ans = arr.size()`। এটি আমাদের ডিফল্ট উত্তর। যদি `target` অ্যারের সব উপাদানের চেয়ে বড় হয়, তবে লুপ শেষে এই মানটিই রিটার্ন হবে।
2.  **Loop:** `while (low <= high)` লুপটি চালাও।
3.  **Find Middle:** `mid = low + (high - low) / 2`।
4.  **Comparison:**
    *   **যদি `arr[mid] >= target` হয়:**
        *   `ans = mid` (এটি একটি সম্ভাব্য উত্তর, সংরক্ষণ করো)।
        *   `high = mid - 1` (আরও ভালো উত্তরের জন্য বামে খোঁজো)।
    *   **যদি `arr[mid] < target` হয়:**
        *   `low = mid + 1` (ডানে খোঁজো)।
5.  **Result:** লুপ শেষে, `ans` রিটার্ন করো।

#### **C++ Code:**
```cpp
#include<bits/stdc++.h>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int ans = nums.size(); // Default answer if target is larger than all elements

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= target) {
            ans = mid; // This is a potential answer
            high = mid - 1; // Look for a better (smaller index) answer on the left
        } else {
            low = mid + 1;  // The answer must be on the right
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 3, 5, 6};
    cout << "Target 5: Index " << searchInsert(nums, 5) << endl; // Expected: 2
    cout << "Target 2: Index " << searchInsert(nums, 2) << endl; // Expected: 1
    cout << "Target 7: Index " << searchInsert(nums, 7) << endl; // Expected: 4
    cout << "Target 0: Index " << searchInsert(nums, 0) << endl; // Expected: 0
    return 0;
}
```

#### **Dry Run (`nums = [1, 3, 5, 6]`, `target = 2`)**

| `low` | `high` | `mid` | `nums[mid]` | Condition (`nums[mid] >= 2`) | Action | `ans` |
|---|---|---|---|---|---|---|
| 0 | 3 | 1 | 3 | `3 >= 2` -> True | `ans = 1`, `high = 0` | 1 |
| 0 | 0 | 0 | 1 | `1 >= 2` -> False | `low = 1` | 1 |
| 1 | 0 | - | - | `low <= high` -> False | **Loop Ends** | - |

**Result:** `ans = 1`।

#### **Complexity Analysis:**
*   **Time Complexity: O(log N)** - বাইনারি সার্চের Ideal Time Complexity
*   **Space Complexity: O(1)** - কোনো অতিরিক্ত স্পেস ব্যবহার করা হয়নি।

---

### **Competitive Programming (CP) vs LeetCode Perspective**

**LeetCode/Interview Perspective:**
*   **Fundamental Skill:** `lower_bound` এবং `upper_bound` নিজে থেকে ইমপ্লিমেন্ট করতে পারা একটি অপরিহার্য বাইনারি সার্চ দক্ষতা। ইন্টারভিউতে,  প্রায় সবসময় এই লজিকটি নিজে লিখতে বলা হবে, STL ব্যবহার করার পরিবর্তে।
*   **Clarity:**কোড কতটা পরিষ্কার এবং  `ans`, `low`, `high` এর আপডেটগুলো সঠিকভাবে ব্যাখ্যা করতে পারছ কি না, তার উপর জোর দেওয়া হবে।

**Competitive Programming (CP) Perspective:**
*   **STL is Standard:** CP-তে, `lower_bound` এর জন্য প্রায় ১০০% ক্ষেত্রেই `lower_bound` ব্যবহার করা হয়। এটি দ্রুত, নির্ভুল এবং পরীক্ষিত।
    ```cpp
    #include <bits/stdc++.h>
    
    // ...
    auto it = lower_bound(nums.begin(), nums.end(), target);
    int index = distance(nums.begin(), it);
    ```
*   **Why Learn Manual Implementation?:** "Binary Search on Answer" প্যাটার্নে, তোমাকে সবসময় একটি কাস্টম বাইনারি সার্চ লিখতে হবে। `lower_bound`-এর এই ইমপ্লিমেন্টেশনটি সেই প্যাটার্নের ভিত্তি তৈরি করে।

---

### **Related Practice Problems**

#### **LeetCode**
1.  **LeetCode 704. Binary Search (Easy):** ক্লাসিক বাইনারি সার্চের সরাসরি ইমপ্লিমেন্টেশন। ([Link](https://leetcode.com/problems/binary-search/))
2.  **LeetCode 34. Find First and Last Position of Element in Sorted Array (Medium):** `lower_bound` এবং `upper_bound`-এর ধারণা ব্যবহার করে সমাধান করা হয়। ([Link](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/))
3.  **LeetCode 278. First Bad Version (Easy):** `lower_bound` of `true` খুঁজে বের করার একটি ক্লাসিক "Binary Search on Answer" উদাহরণ। ([Link](https://leetcode.com/problems/first-bad-version/))

#### **Codeforces**
1.  **Codeforces EDU: Binary Search Step 1 - Problem C: Closest to the Right:** এটি `lower_bound`-এর সরাসরি অনুশীলনের জন্য চমৎকার। ([Link](https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/C))
2.  **Codeforces: 706B - Interesting drink (Rating: 1400):** সর্টিং + `upper_bound` ব্যবহার করে অনেকগুলো কোয়েরি দক্ষতার সাথে হ্যান্ডেল করা। ([Link](https://codeforces.com/problemset/problem/706/B))