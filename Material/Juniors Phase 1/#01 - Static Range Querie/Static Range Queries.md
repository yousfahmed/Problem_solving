# Week #1 - Static Range Queries

## 1- Thinking Techniques Tips:

#### important videos :

- Approaching Problem Statement: [video](https://youtu.be/fd0Ebfa_mJ0)

- Tips and Tricks in Algorithms: [video](https://youtu.be/-jE3_O9Dpps)

- On papers Not on PC : [video](https://youtu.be/olcmPKZNqnM)

---

## 2- Complexity of algorithms

- what is Complexity : [video](https://youtu.be/sHhVsGQz9MI)

- Problem Constraints : [video](https://youtu.be/6Fx8T_NBA7Q)

- Another video : [video](https://www.youtube.com/watch?v=hYalOGs1_Og)

#### Extra notes:

- The following picture (from a book called Competitive Programming 3 by Steven Halim) shows a rough estimation of the worst complexity of an algorithm that can be used for a problem of a given size.

![Image](../Images/TimeComplexity.png)

- An easier way to get a rough estimation of whether an algorithm will pass for a given problem size or not, is simply to substitute with the problem's limits in the upper-bound function of your algorithm.  
  For example, if your algorithm is O(N^2), and N (which is the array size for example) in this problem is up to 1000. Then you can substitute N with 1000 in the N^2 equation, which will give you 1000000.  
  If the number you get from this substitution is <= 10^8, then "most probably" your solution will not exceed the time limit for most of the problems (which is about 2 seconds).

#### Problems:

#### you can check the Tutorial section for each problem, Don't ask about the solutions

1. http://codeforces.com/problemset/problem/268/A
2. https://codeforces.com/contest/1612/problem/A
3. https://codeforces.com/contest/1520/problem/A
4. https://codeforces.com/problemset/problem/1478/B
5. https://codeforces.com/contest/1475/problem/B
6. https://codeforces.com/contest/1426/problem/A

---

## 3- Frequency array

- Frequency array : [video](https://youtu.be/kQGTjql8WjI)

#### Extra notes:

- The usage of frequency arrays has its limitations. Remember that you need an array whose size is equal to the value of the largest integer in the original array. Which means that you can't use a frequency array if the values in the original array can be up to 10^9 for example.  
  In most cases, you can use frequency arrays safely for values up to 10^7. However, in some websites like Codeforces, you will be given the amount of memory available for your program, which you can use to calculate (roughly) the maximum size of a frequency array that you can use.

- You can use a frequency array to sort an array in O(M) time ([Counting Sort](https://www.geeksforgeeks.org/counting-sort/)), where M is the value of the largest integer in the array. Which could be much more efficient than merge sort (which runs in O(NlogN)) (we will discuss it later) in cases where the array size is large but the values inside the array are bounded with a small number.

#### we already create a sheet in the codeforces group that discuss this topic

#### Another problems:

1. http://codeforces.com/problemset/problem/767/A

---

## 4- Prefix sum

- Prefix sum : [video](https://www.youtube.com/watch?v=hqOqr6vFPp8)
- Another video : [video](https://youtu.be/fQwD4-FxQBU)

#### Extra notes:

- In many cases, you don't need the original array after you build the prefix_sum array. In these cases, it's better to "transform" your original array into a prefix_sum array, instead of creating a separate array for the prefix sum.  
  Suppose that you have a zero-indexed array `A` that you want to compute a prefix sum for, then you can write:

```c
for(int i = 1; i < n; i++)  A[i] += A[i-1];
```

After this line, you can use the array `A` as a prefix_sum array. This is more memory-efficient and even faster to write.

- Remember that the sum of elements in A[L:R] = prefix_sum[R] - prefix_sum[L-1] (for L != 0).  
  While the sum of elements in A[0:R] = prefix_sum[R]

Therefore, working with 1-indexed arrays (if you have N integers for example, the first of them will be A[1] and the last will be A[N], instead of A[0] and A[N-1]) can make your life easier, as you don't have to check whether `L` is equal to zero or not before you answer the query (which results in a shorter code).  
So if you are going to input the array (of size N) and want to make a prefix array for it write:

```c
int arr[N+1];

for(int i = 1; i <= N; i++)
      cin >> arr[i];

int prefix[N+1];
prefix[0]=0;
for(int i = 1; i <= N; i++)
      prefix[i] = arr[i] + prefix[i-1];
```

This assumes that prefix_sum[0] = 0, which is the case by default for global variables.  
Now, the sum of elements in A[L:R] = prefix_sum[R] - prefix_sum[L-1] (for any `1 <= L <= R <= N`).

- You can use prefix sum for multi-dimensional arrays. Here is a [video](https://youtu.be/hqOqr6vFPp8?t=465) that
  demonstrates how this could be done for 2D arrays.  
  You can apply the same concept to 3D arrays, but it will be a little bit tedious.

#### we already create a sheet in the codeforces group that discuss this topic

---

## 7- Update Range

- Prefix sum : [video](https://youtu.be/vF78qRAAyx4)

#### Extra notes:

- Some people use the terms "Prefix sum" and "Partial sum" interchangeably.

- Feel free to skip this note:  
  The situation we faced in the video is that we wanted to added some constant value x to all the array elements in the range [l,r].  
  A harder problem would be to add x to a[l], x+k to a[l+1], x+2k to a[l+2], ... where k and x are given constants.  
  Fortunately, there is an efficient solution for this task, which I will not explain here. However, here is my implementation for it if you want to have a look.

```cpp
typedef long long ll;

const int MAX = 1000000+9;   //Maximum array size
int a[MAX];
ll inst[MAX], perm[MAX];

///a[l] += x, a[l+1] += x+k, a[l+2] += x+2k, ...
void updateRange(int x, int k, int l, int r)
{
    inst[l] += x;
    perm[l+1] += k;
    perm[r+1] -= k;
    inst[r+1] -= x + (ll)(r-l)*k;
}

///Accumulate the values in the range [l, r] inclusive.
void acc(int l, int r)
{
    ll val = 0, inc = 0;
    for(int i = l; i <= r; i++)
    {
        val += inst[i];
        inc += perm[i];
        val += inc;

        a[i] = val;
    }
}
```

#### Problems:

1. http://codeforces.com/problemset/problem/834/B

---
