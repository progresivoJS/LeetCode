# Bit Manipulation

### 191. Number of 1 Bits

#### Solution

```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int p = 1;
        int count = 0;
        while (n != 0) {
            if (n & p == 1) count++;
            n = n >> 1;
        }
        return count;
    }
};
```

#### Better Solution

```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            count++;
            n = n & (n - 1);
        }
        return count;
    }
};
```



### 476. Number Complement

#### Solution

```c++
class Solution {
public:
    int findComplement(int num) {
        int ret = 0;
        int part = 1;
        while (num != 0) {
            if ((num & 1) == 0) ret += part;
            num = num >> 1;
            part *= 2;
        }
        return ret;
    }
};
```

#### Better Solution

```c++
class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = ~0;
        while (num & mask) mask <<= 1;
        return ~(mask | num);
    }
};
```

