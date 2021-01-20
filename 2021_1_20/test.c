#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>
#pragma warning(disable:4996)
//LeetCode217
int Cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}
bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize <= 1)
        return false;
    else {
        qsort(nums, numsSize, sizeof(int), Cmp);
        for (int i = 0; i < numsSize - 1; i++) {
            if (nums[i] == nums[i + 1])
                return true;
        }
    }
    return false;
}
//Leetcode925
bool isLongPressedName(char* name, char* typed) {
    int n = strlen(name);
    int m = strlen(typed);
    int i = 0, j = 0;
    while (j < m) {
        if (i < n && name[i] == typed[j]) {//一样则同时后移
            i++;
            j++;
        }
        else if (j > 0 && typed[j] == typed[j - 1]) {//不一样，但属于长按导致1
            j++;
        }
        else {//不对
            return false;
        }
    }
    return i == n;
}
