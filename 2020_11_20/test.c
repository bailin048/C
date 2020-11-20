#include <stdio.h>
/// <����������Ѱ�ҳ��ִ�������n/2����>:�����������һ�����������
/// <param name="nums"></int����>
/// <param name="numsSize"></int����Ԫ����Ŀ>
/// <returns></returns int���ִ�������n/2������>
int majorityElement(int* nums, int numsSize) {
    int sum = 0, flag = 0;
    for (int i = 0; i < numsSize; i++) {
        if (sum <= 0) { //sum<=0˵����ǰflag������Ŀ����
            flag = nums[i];
            sum++;
        }
        else {
            nums[i] == flag ? sum++ : sum--; //Ħ��ͶƱ��
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