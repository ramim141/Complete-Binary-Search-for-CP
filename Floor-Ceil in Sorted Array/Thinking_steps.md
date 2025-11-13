### **Problem: Floor and Ceil in a Sorted Array**

#### **Problem Statement**

একটি **সর্টেড** ইন্টিজার অ্যারে `arr` এবং একটি ইন্টিজার `x` দেওয়া হবে।
1.  **Floor of x:** `arr`-এর মধ্যে `x`-এর চেয়ে **ছোট বা সমান** (`<= x`) সবচেয়ে বড় সংখ্যাটি খুঁজে বের করো। যদি এমন কোনো সংখ্যা না থাকে, `-1` রিটার্ন করো।
2.  **Ceil of x:** `arr`-এর মধ্যে `x`-এর চেয়ে **বড় বা সমান** (`>= x`) সবচেয়ে ছোট সংখ্যাটি খুঁজে বের করো। যদি এমন কোনো সংখ্যা না থাকে, `-1` রিটার্ন করো।

**Example (`arr = [3, 4, 4, 7, 8, 10]`)**
*   `x = 5`:
    *   **Floor:** 5-এর চেয়ে ছোট বা সমান সবচেয়ে বড় সংখ্যা হলো `4`।
    *   **Ceil:** 5-এর চেয়ে বড় বা সমান সবচেয়ে ছোট সংখ্যা হলো `7`।
*   `x = 8`:
    *   **Floor:** `8`।
    *   **Ceil:** `8`।

#### **Core Idea**

*   **Ceil:** এটি আসলে "Lower Bound" খুঁজে বের করার মতোই। আমরা অ্যারেতে সেই প্রথম উপাদানটি খুঁজছি যা `x`-এর চেয়ে বড় বা সমান (`>= x`)।
*   **Floor:** এটি Ceil-এর ঠিক উল্টো। আমরা অ্যারেতে সেই শেষ উপাদানটি খুঁজছি যা `x`-এর চেয়ে ছোট বা সমান (`<= x`)।

---

### **Approach 1: Finding the Ceil of x**

#### **Algorithm (Binary Search Algorithm):**
1.  **Initialization:** `low = 0`, `high = n - 1`। `ans = -1` (ডিফল্ট উত্তর)।
2.  **Loop:** `while (low <= high)`।
3.  **Find Middle:** `mid = low + (high - low) / 2`।
4.  **Comparison:** `arr[mid]`-কে `x`-এর সাথে তুলনা করো:
    *   **যদি `arr[mid] >= x` হয়:**
        *   `arr[mid]` একটি সম্ভাব্য উত্তর হতে পারে। `ans = arr[mid]` সংরক্ষণ করো।
        *   যেহেতু আমরা সবচেয়ে ছোট (`smallest`) সংখ্যাটি খুঁজছি যা `>= x`, তাই আমাদের আরও ভালো উত্তরের জন্য **বাম দিকে** খুঁজতে হবে। `high = mid - 1`।
    *   **যদি `arr[mid] < x` হয়:**
        *   আমাদের **ডান দিকে** খুঁজতে হবে। `low = mid + 1`।
5.  **Result:** লুপ শেষে, `ans` রিটার্ন করো।

#### **C++ Code (Ceil):**
```cpp
#include <bits/stdc++.h>
using namespace std;

int findCeil(const vector<int>& arr, int x) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x) {
            ans = arr[mid]; // This is a potential answer
            high = mid - 1; // Look for a smaller value on the left
        } else {
            low = mid + 1;  // Answer must be on the right
        }
    }
    return ans;
}
```

---

### **Approach 2: Finding the Floor of x**

#### **Algorithm (Binary Search Algorithm):**
1.  **Initialization:** `low = 0`, `high = n - 1`। `ans = -1`।
2.  **Loop:** `while (low <= high)`।
3.  **Find Middle:** `mid = low + (high - low) / 2`।
4.  **Comparison:** `arr[mid]`-কে `x`-এর সাথে তুলনা করো:
    *   **যদি `arr[mid] <= x` হয়:**
        *   `arr[mid]` একটি সম্ভাব্য উত্তর হতে পারে। `ans = arr[mid]` সংরক্ষণ করো।
        *   যেহেতু আমরা সবচেয়ে বড় (`largest`) সংখ্যাটি খুঁজছি যা `<= x`, তাই আমাদের আরও ভালো উত্তরের জন্য **ডান দিকে** খুঁজতে হবে। `low = mid + 1`।
    *   **যদি `arr[mid] > x` হয়:**
        *   আমাদের **বাম দিকে** খুঁজতে হবে। `high = mid - 1`।
5.  **Result:** লুপ শেষে, `ans` রিটার্ন করো।

#### **C++ Code (Floor):**
```cpp
#include <bits/stdc++.h>
using namespace std;

int findFloor(const vector<int>& arr, int x) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= x) {
            ans = arr[mid]; // This is a potential answer
            low = mid + 1;  // Look for a larger value on the right
        } else {
            high = mid - 1; // Answer must be on the left
        }
    }
    return ans;
}
```

#### **Complexity Analysis (For Both):**
*   **Time Complexity: O(log N)**
*   **Space Complexity: O(1)**

---

### **Competitive Programming (CP) vs LeetCode Perspective**

**LeetCode/Interview Perspective:**
*   **Emphasis on Implementation:** তোমাকে অবশ্যই বাইনারি সার্চের এই দুটি ভেরিয়েশন (`>=` এবং `<=`) নিজে থেকে ইমপ্লিমেন্ট করতে জানতে হবে। `ans` ভেরিয়েবলটি কখন এবং কেন আপডেট হচ্ছে, এবং `low`/`high` পয়েন্টার কোন দিকে যাচ্ছে—এই যুক্তিটি পরিষ্কারভাবে ব্যাখ্যা করাটা খুবই গুরুত্বপূর্ণ।

**Competitive Programming (CP) Perspective:**
*   **STL is King:** CP-তে, এই কাজগুলো করার জন্য C++ STL-এর `lower_bound` এবং `upper_bound` ফাংশনগুলোই প্রায় সবসময় ব্যবহৃত হয়।
    *   **Ceil:** `ceil` খুঁজে বের করা `lower_bound` এর সরাসরি প্রয়োগ।
        ```cpp
        auto it = lower_bound(arr.begin(), arr.end(), x);
        if (it == arr.end()) return -1; // Ceil নেই
        return *it;
        ```
    *   **Floor:** `floor` খুঁজে বের করা `upper_bound` এর একটি চতুর প্রয়োগ। `upper_bound(x)` `x`-এর চেয়ে বড় প্রথম উপাদানটি খুঁজে দেয়। তার ঠিক আগের উপাদানটিই হবে `floor`।
        ```cpp
        auto it = upper_bound(arr.begin(), arr.end(), x);
        if (it == arr.begin()) return -1; // Floor নেই
        return *(--it);
        ```

---

### **Related Practice Problems**

#### **LeetCode**
1.  **LeetCode 34. Find First and Last Position of Element in Sorted Array (Medium):** `lower_bound` (first position) এবং `upper_bound` (last position-এর জন্য) এর ধারণা ব্যবহার করে। ([Link](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/))
2.  **LeetCode 744. Find Smallest Letter Greater Than Target (Easy):** এটি `upper_bound` এর একটি সরাসরি এবং সহজ সংস্করণ। ([Link](https://leetcode.com/problems/find-smallest-letter-greater-than-target/))

#### **Codeforces**
1.  **Codeforces EDU: Binary Search Step 1 - Problem B: Closest to the Left:** এটি "Floor" খুঁজে বের করার একটি সরাসরি অনুশীলন। ([Link](https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B))
2.  **Codeforces EDU: Binary Search Step 1 - Problem C: Closest to the Right:** এটি "Ceil" খুঁজে বের করার একটি সরাসরি অনুশীলন। ([Link](https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/C))