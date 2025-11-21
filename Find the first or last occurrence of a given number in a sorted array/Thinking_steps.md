
### **Problem: Find the first or last occurrence of a given number in a sorted array**

#### **Problem Statement (সমস্যাটা কী?)**

একটি **সর্টেড (sorted)** ইন্টিজার অ্যারে `arr` দেওয়া হবে, যাতে ডুপ্লিকেট উপাদান থাকতে পারে। এছাড়াও একটি ইন্টিজার `x` দেওয়া হবে।

কাজ হলো `arr`-এ `x`-এর **প্রথম (first)** এবং **শেষ (last)** occurrence-এর ইনডেক্স খুঁজে বের করা।

যদি `x` অ্যারেতে না থাকে, তবে উভয় ইনডেক্স `-1` হবে।

**Example:**
*   `arr = [1, 2, 2, 2, 3, 4]`, `x = 2`
    *   **First Occurrence:** ইনডেক্স `1`
    *   **Last Occurrence:** ইনডেক্স `3`
    *   **Result:** `{1, 3}`

*   `arr = [5, 7, 7, 8, 8, 10]`, `x = 8`
    *   **Result:** `{3, 4}`

*   `arr = [5, 7, 7, 8, 8, 10]`, `x = 6`
    *   **Result:** `{-1, -1}`

#### **Core Idea**

এই সমস্যাটিকে দুটি পৃথক সমস্যায় ভাগ করা যেতে পারে:
1.  **Find the First Occurrence of `x`:** এটি `x`-এর **Lower Bound** খুঁজে বের করার সমান। আমরা সেই প্রথম ইনডেক্সটি খুঁজছি যেখানে `arr[i] >= x`। যদি `arr[ans] == x` হয়, তবে `ans`-ই হলো প্রথম occurrence।
2.  **Find the Last Occurrence of `x`:** এটি `x`-এর **Upper Bound**-এর ধারণার সাথে ঘনিষ্ঠভাবে সম্পর্কিত। আমরা সেই শেষ ইনডেক্সটি খুঁজছি যেখানে `arr[i] <= x`।

আমরা দুটি ভিন্ন বাইনারি সার্চ চালিয়ে এই দুটি ইনডেক্স বের করতে পারি।

---

### **Part 1: Finding the First Occurrence**

এটি "Implement Lower Bound" সমস্যার প্রায় হুবহু নকল।

#### **Algorithm (First Occurrence):**
1.  **Initialization:** `low = 0`, `high = n - 1`। `first = -1`।
2.  **Loop:** `while (low <= high)`।
3.  **Find Middle:** `mid = low + (high - low) / 2`।
4.  **Comparison:**
    *   **যদি `arr[mid] == x` হয়:**
        *   `mid` একটি সম্ভাব্য উত্তর। `first = mid`।
        *   যেহেতু আমরা **প্রথম** occurrence খুঁজছি, আমাদের আরও বাম দিকে খুঁজতে হবে। `high = mid - 1`।
    *   **যদি `arr[mid] < x` হয়:** `low = mid + 1` (ডানে খোঁজো)।
    *   **যদি `arr[mid] > x` হয়:** `high = mid - 1` (বামে খোঁজো)।
5.  **Result:** লুপ শেষে, `first` রিটার্ন করো।

#### **C++ Code (First Occurrence):**
```cpp
int findFirst(const vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int first = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            first = mid;
            high = mid - 1; // Look for more occurrences on the left
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return first;
}
```

---

### **Part 2: Finding the Last Occurrence**

এই যুক্তিটি "Floor" খুঁজে বের করার মতো, কিন্তু এখানে আমরা `arr[mid] == x` এর উপর ফোকাস করি।

#### **Algorithm (Last Occurrence):**
1.  **Initialization:** `low = 0`, `high = n - 1`। `last = -1`।
2.  **Loop:** `while (low <= high)`।
3.  **Find Middle:** `mid = low + (high - low) / 2`।
4.  **Comparison:**
    *   **যদি `arr[mid] == x` হয়:**
        *   `mid` একটি সম্ভাব্য উত্তর। `last = mid`।
        *   যেহেতু আমরা **শেষ** occurrence খুঁজছি, আমাদের আরও ডান দিকে খুঁজতে হবে। `low = mid + 1`।
    *   **যদি `arr[mid] < x` হয়:** `low = mid + 1` (ডানে খোঁজো)।
    *   **যদি `arr[mid] > x` হয়:** `high = mid - 1` (বামে খোঁজো)।
5.  **Result:** লুপ শেষে, `last` রিটার্ন করো।

#### **C++ Code (Last Occurrence):**
```cpp
int findLast(const vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int last = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            last = mid;
            low = mid + 1; // Look for more occurrences on the right
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return last;
}
```

---

### **Putting It All Together**

```cpp
#include <iostream>
#include <vector>

// (findFirst এবং findLast ফাংশনগুলো উপরে দেওয়া আছে)

vector<int> findFirstAndLastPosition(const vector<int>& arr, int x) {
    int first = findFirst(arr, x);
    if (first == -1) { // যদি প্রথমটিই না পাওয়া যায়, তবে শেষটিও থাকবে না
        return {-1, -1};
    }
    int last = findLast(arr, x);
    return {first, last};
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4};
    int x = 2;
    vector<int> result = findFirstAndLastPosition(arr, x);
    cout << "For x = " << x << ", First: " << result[0] << ", Last: " << result[1] << endl;
    return 0;
}
```

### **Alternative: Using Lower Bound and Upper Bound**

এটি একটি আরও সংক্ষিপ্ত এবং মার্জিত সমাধান, বিশেষ করে STL ব্যবহার করলে।
*   **First Occurrence:** `x`-এর `lower_bound` সরাসরি প্রথম occurrence-এর ইনডেক্স দেয়।
*   **Last Occurrence:** `x`-এর `upper_bound` `x`-এর চেয়ে বড় প্রথম উপাদানটির ইনডেক্স দেয়। তার ঠিক আগের ইনডেক্সটিই হবে `x`-এর শেষ occurrence।

#### **C++ Code (using STL `lower_bound` & `upper_bound`):**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

vector<int> findFirstAndLastPosition_stl(const vector<int>& arr, int x) {
    // Find the first occurrence (lower bound)
    auto first_it = lower_bound(arr.begin(), arr.end(), x);
    
    // Check if the element was found
    if (first_it == arr.end() || *first_it != x) {
        return {-1, -1};
    }

    // Find the last occurrence
    auto last_it = upper_bound(arr.begin(), arr.end(), x);
    
    int first_idx = distance(arr.begin(), first_it);
    int last_idx = distance(arr.begin(), last_it) - 1;
    
    return {first_idx, last_idx};
}
```

#### **Complexity Analysis (For All Optimal Approaches):**
*   **Time Complexity: O(log N)** - আমরা দুটি ভিন্ন বাইনারি সার্চ চালাই, যার প্রতিটির কমপ্লেক্সিটি O(log N)। মোট: `O(log N) + O(log N) = O(log N)`।
*   **Space Complexity: O(1)** - কোনো অতিরিক্ত স্পেস ব্যবহার করা হয়নি।

---

### **Competitive Programming (CP) vs LeetCode Perspective**

*   **LeetCode/Interview:** তোমাকে `findFirst` এবং `findLast` ফাংশন দুটি **নিজে থেকে ইমপ্লিমেন্ট** করতে বলা হবে। বাইনারি সার্চের লজিকটি (বিশেষ করে, ম্যাচ পাওয়ার পর `low` বা `high`-কে কোন দিকে সরাতে হবে) পরিষ্কারভাবে ব্যাখ্যা করাটা খুবই গুরুত্বপূর্ণ।
*   **CP:** প্রতিযোগিতামূলক প্রোগ্রামিংয়ে, গতি এবং নির্ভুলতার জন্য প্রায় সবাই **STL-এর `lower_bound` এবং `upper_bound`** ব্যবহার করবে। `count = upper_bound(x) - lower_bound(x)` এই সূত্রটি একটি নির্দিষ্ট সংখ্যার occurrence গণনা করার জন্য একটি খুবই সাধারণ প্যাটার্ন।

