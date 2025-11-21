### **Problem: Count occurrences of a number in a sorted array**

#### **Problem Statement**

একটি **সর্টেড (sorted)** ইন্টিজার অ্যারে `arr` দেওয়া হবে, যাতে ডুপ্লিকেট উপাদান থাকতে পারে। এছাড়াও একটি ইন্টিজার `x` দেওয়া হবে।

কাজ হলো `arr`-এ `x` সংখ্যাটি **মোট কতবার (count)** এসেছে, তা খুঁজে বের করা।

**Example:**
*   `arr = [1, 2, 2, 2, 3, 4]`, `x = 2`
    *   **Result:** `3` (কারণ 2 তিনবার এসেছে)

*   `arr = [5, 7, 7, 8, 8, 10]`, `x = 8`
    *   **Result:** `2`

*   `arr = [5, 7, 7, 8, 8, 10]`, `x = 6`
    *   **Result:** `0`

#### **Core Idea**

যেহেতু অ্যারেটি সর্টেড, `x`-এর সব occurrence একসাথে একটি ব্লক হিসেবে থাকবে। যেমন: `[..., 1, 2, 2, 2, 3, ...]`।

`x`-এর মোট সংখ্যা বের করার জন্য, আমাদের শুধু দুটি জিনিস জানতে হবে:
1.  **`x`-এর প্রথম occurrence-এর ইনডেক্স (`first_index`)।**
2.  **`x`-এর শেষ occurrence-এর ইনডেক্স (`last_index`)।**

যদি আমরা এই দুটি ইনডেক্স পেয়ে যাই, তাহলে মোট occurrence হবে:
`count = last_index - first_index + 1`

সুতরাং, এই সমস্যাটি আসলে "Find First and Last Position" সমস্যারই একটি রূপ।

---

### **Approach 1: Brute Force (Linear Scan)**

এটি সবচেয়ে সহজবোধ্য পদ্ধতি, যেখানে আমরা বাইনারি সার্চ ব্যবহার করি না।

#### **Algorithm:**
1.  একটি `count` ভেরিয়েবল `0` দিয়ে শুরু করো।
2.  অ্যারের শুরু থেকে শেষ পর্যন্ত একটি `for` লুপ চালাও।
3.  যদি `arr[i] == x` হয়, `count`-কে `1` বাড়াও।
4.  লুপ শেষে `count` রিটার্ন করো।

#### **C++ Code:**
```cpp

int countOccurrences_brute_force(const vector<int>& arr, int x) {
    int count = 0;
    for (int num : arr) {
        if (num == x) {
            count++;
        }
    }
    return count;
}
```

#### **Complexity Analysis:**
*   **Time Complexity: O(N)** - আমরা পুরো অ্যারেটি একবার ট্র্যাভার্স করি।
*   **Space Complexity: O(1)**।

**Verdict:** এটি কাজ করে, কিন্তু এটি অ্যারের "সর্টেড" হওয়ার বৈশিষ্ট্যকে কাজে লাগায় না। ইন্টারভিউয়ার আপনাকে O(log N) সমাধানের জন্য বলবেন।

---

### **Approach 2: Using Two Binary Searches (Optimal Solution)**

এটিই সেরা এবং ইন্টারভিউয়ের জন্য উপযুক্ত সমাধান। আমরা দুটি ভিন্ন বাইনারি সার্চ ব্যবহার করে প্রথম এবং শেষ occurrence খুঁজে বের করব।

#### **Algorithm:**
1.  **Find First Occurrence:**
    *   "Find First Occurrence" এর জন্য একটি বাইনারি সার্চ ফাংশন (`findFirst`) ইমপ্লিমেন্ট করো।
    *   এই ফাংশনটি `x`-এর `lower_bound` খুঁজে বের করে এবং চেক করে যে সেই ইনডেক্সের মান `x`-এর সমান কি না।
2.  **Find Last Occurrence:**
    *   "Find Last Occurrence" এর জন্য আরেকটি বাইনারি সার্চ ফাংশন (`findLast`) ইমপ্লিমেন্ট করো।
3.  **Calculate Count:**
    *   `first = findFirst(arr, x)`।
    *   যদি `first == -1` হয়, তার মানে `x` অ্যারেতে নেই। `0` রিটার্ন করো।
    *   `last = findLast(arr, x)`।
    *   `count = last - first + 1` রিটার্ন করো।

#### **C++ Code (Full Implementation):**
```cpp
// Function to find the first occurrence of x
int findFirst(const vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int first = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            first = mid;
            high = mid - 1; // Look for more on the left
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return first;
}

// Function to find the last occurrence of x
int findLast(const vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int last = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            last = mid;
            low = mid + 1; // Look for more on the right
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return last;
}

int countOccurrences(const vector<int>& arr, int x) {
    int first = findFirst(arr, x);
    if (first == -1) {
        return 0; // Element not found
    }
    int last = findLast(arr, x);
    return last - first + 1;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4};
    int x = 2;
    cout << "Count of " << x << " is: " << countOccurrences(arr, x) << endl; // Expected: 3
    return 0;
}
```

---

### **Approach 3: Using STL `lower_bound` and `upper_bound` (CP-Style)**

এটি Competitive Programming-এ সবচেয়ে দ্রুত এবং সংক্ষিপ্ত পদ্ধতি।

#### **Core Idea:**
*   `lower_bound(arr, x)`: `x`-এর সমান বা তার চেয়ে বড় **প্রথম** উপাদানের ইটারেটর দেয়। এটি `first_occurrence`-এর ইটারেটর।
*   `upper_bound(arr, x)`: `x`-এর চেয়ে **বড়** **প্রথম** উপাদানের ইটারেটর দেয়। এটি `last_occurrence`-এর ঠিক পরের উপাদানের ইটারেটর।
*   সুতরাং, `x`-এর মোট সংখ্যা হবে এই দুটি ইটারেটরের মধ্যে দূরত্বের সমান।

#### **C++ Code (STL):**
```cpp

int countOccurrences_stl(const vector<int>& arr, int x) {
    auto first_it = lower_bound(arr.begin(), arr.end(), x);
    
    // Check if the element is not present
    if (first_it == arr.end() || *first_it != x) {
        return 0;
    }

    auto last_it = upper_bound(arr.begin(), arr.end(), x);

    // The distance between these two iterators is the count
    return distance(first_it, last_it);
}
```

#### **Complexity Analysis (For Optimal Approaches):**
*   **Time Complexity: O(log N)** - দুটি বাইনারি সার্চ (`lower_bound` এবং `upper_bound`) এর জন্য।
*   **Space Complexity: O(1)** - কোনো অতিরিক্ত স্পেস ব্যবহার করা হয়নি।

---

### **Summary of Approaches**

| Approach (পদ্ধতি) | Time Complexity | Space Complexity | Verdict (উপসংহার) |
| :--- | :--- | :--- | :--- |
| **Linear Scan** | O(N) | O(1) | সহজবোধ্য কিন্তু অদক্ষ। সর্টেড হওয়ার সুবিধা নেয় না। |
| **Two Binary Searches** | **O(log N)** | **O(1)** | **সর্বোত্তম সমাধান (ম্যানুয়াল ইমপ্লিমেন্টেশন)।** ইন্টারভিউয়ের জন্য আদর্শ। |
| **STL `lower/upper_bound`**| **O(log N)** | **O(1)** | **সর্বোত্তম সমাধান (CP-স্টাইল)।** সংক্ষিপ্ত, দ্রুত এবং নির্ভুল। |

**ইন্টারভিউয়ের জন্য সেরা পছন্দ:**
**Two Binary Searches** পদ্ধতিটি বিস্তারিতভাবে ব্যাখ্যা করা। প্রথমে `findFirst` এর লজিক, তারপর `findLast` এর লজিক, এবং শেষে কীভাবে দুটিকে একত্রিত করে উত্তর বের করা যায় তা দেখানো উচিত। এরপর, তুমি অতিরিক্ত হিসেবে উল্লেখ করতে পারো যে এই কাজটি C++ STL-এর `lower_bound` এবং `upper_bound` ব্যবহার করে আরও সংক্ষিপ্তভাবে করা যায়। এটি তোমার জ্ঞানের গভীরতা প্রমাণ করবে।