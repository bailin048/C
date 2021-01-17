#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#pragma warning(disable:4996)

//数组翻转
void Reverse(int* nums, int start, int end)
{
    while (start < end) {
        int tmp = nums[end];
        nums[end--] = nums[start];
        nums[start++] = tmp;
    }
}
//数组旋转
void Rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    Reverse(nums, 0, numsSize - 1);//放在第一次是右旋，第三次则是左旋
    Reverse(nums, 0, k - 1);
    Reverse(nums, k, numsSize - 1);
}

int* addToArrayForm(int* A, int ASize, int K,int* returnSize)//, int* returnSize
{
    int flag = 0, i = 0;
    int KSize = log10(K) + 1;
    *returnSize = ASize > KSize ? ASize + 1 : KSize + 1; //多申请最大长度+1，防止溢出
    int delta = *returnSize - ASize;
    int* res = (int*)malloc((*returnSize) * sizeof(int)); //申请空间
    assert(res);
    memset(res, 0, sizeof(int) * (*returnSize)); //空间初始化
    for (i = *returnSize - 1; i >= 0; i--) {
        if (i - delta>=0) {
            res[i] = A[i - delta] + K % 10 + flag; //进位标志+k%10+A[i-delta]
        }
        else {
            res[i] = K % 10 + flag;
        }
        flag = res[i] > 9 ? 1 : 0; //进位标志计算
        res[i] %= 10;//取余
        K /= 10;//丢弃个位
    }
    if (!res[0]) {//最高位没有进位，因此多出0
        *returnSize = *returnSize - 1;
        int* p =(int *)malloc((*returnSize) * sizeof(int));
        assert(p);
        for (int i = 0; i < *returnSize; i++) { //继承有效数字
            p[i] = res[i + 1];
        }
        free(res);//释放空间
        res = NULL;//避免野指针
        return p;
    }
    return res;
}
int main()
{
    int a[] = { 9,9,9,9 };
    int k = 1001;
    int* p = NULL;
    int len = 0;
    p = addToArrayForm(a, sizeof(a) / sizeof(a[0]), k, &len);
    for(int i = 0;i<len;i++){
        printf("%d ",p[i]);
    }
    printf("\n");
    return 0;
}
