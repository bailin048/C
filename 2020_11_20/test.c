#include <stdio.h>
/// <整型数组中寻找出现次数多于n/2的数>:假设这个数组一定存在这个数
/// <param name="nums"></int数组>
/// <param name="numsSize"></int数组元素数目>
/// <returns></returns int出现次数多余n/2的数字>
int majorityElement(int* nums, int numsSize) {
    int sum = 0, flag = 0;
    for (int i = 0; i < numsSize; i++) {
        if (sum <= 0) { //sum<=0说明当前flag并不是目标数
            flag = nums[i];
            sum++;
        }
        else {
            nums[i] == flag ? sum++ : sum--; //摩尔投票法
        }
    }
    return flag;
}
int main()
{
    int arr[] = { 2,2,1,1,1,2,2,1,1,1 };
    int num = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n", majorityElement(arr,num));
	return 0;
}