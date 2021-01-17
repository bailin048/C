#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#pragma warning(disable:4996)

//���鷭ת
void Reverse(int* nums, int start, int end)
{
    while (start < end) {
        int tmp = nums[end];
        nums[end--] = nums[start];
        nums[start++] = tmp;
    }
}
//������ת
void Rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    Reverse(nums, 0, numsSize - 1);//���ڵ�һ������������������������
    Reverse(nums, 0, k - 1);
    Reverse(nums, k, numsSize - 1);
}

int* addToArrayForm(int* A, int ASize, int K,int* returnSize)//, int* returnSize
{
    int flag = 0, i = 0;
    int KSize = log10(K) + 1;
    *returnSize = ASize > KSize ? ASize + 1 : KSize + 1; //��������󳤶�+1����ֹ���
    int delta = *returnSize - ASize;
    int* res = (int*)malloc((*returnSize) * sizeof(int)); //����ռ�
    assert(res);
    memset(res, 0, sizeof(int) * (*returnSize)); //�ռ��ʼ��
    for (i = *returnSize - 1; i >= 0; i--) {
        if (i - delta>=0) {
            res[i] = A[i - delta] + K % 10 + flag; //��λ��־+k%10+A[i-delta]
        }
        else {
            res[i] = K % 10 + flag;
        }
        flag = res[i] > 9 ? 1 : 0; //��λ��־����
        res[i] %= 10;//ȡ��
        K /= 10;//������λ
    }
    if (!res[0]) {//���λû�н�λ����˶��0
        *returnSize = *returnSize - 1;
        int* p =(int *)malloc((*returnSize) * sizeof(int));
        assert(p);
        for (int i = 0; i < *returnSize; i++) { //�̳���Ч����
            p[i] = res[i + 1];
        }
        free(res);//�ͷſռ�
        res = NULL;//����Ұָ��
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
