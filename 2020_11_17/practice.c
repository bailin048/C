#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)

/// <�ж������3�������Ƿ���Թ��������Σ��ܲ��������������>
/// 
/// </summary> �����Թ���������/���Թ��������Σ��ȱߣ���������ͨ��
/// <param name="a"></�߳�a>
/// <param name="b"></�߳�b>
/// <param name="c"></�߳�c>
void IsTriangle_Type(float a, float b ,float c )
{
    int flag = (a + b > c) ? (a + c > b) ? (b + c > a) ? 1 : 0 : 0 : 0; //�ж��Ƿ񹹳�������
    if (flag == 1 && (a == b) && (b == c)) {  //�ȱ�������
        printf("Equilateral triangle!\n");
    }
    else if (flag == 1 && ((a == b) || (b == c) || (a == c))) //����������
        {
            printf("Isosceles triangle!\n");
        }
    else if (flag == 0) {                  //���ܹ���������
            printf("Not a triangle!\n");
        }
    else {
            printf("Ordinary triangle!\n");   //����������
        }
}

/// <����BMI������������>
/// 
/// </summary>
/// <param name="weight"></����kg>
/// <param name="height"></���cm>
void BmiComputeJudge(float weight, float height)
{
    height /= 100;
    float bmi = weight / (height * height); //BMI=����(kg)/���^2(m)
    if (bmi < 18.5) {
         printf("Underweight\n");  //����
    }
    else if (bmi <= 23.9) {
         printf("Normal\n");   //����
    }
    else if (bmi <= 27.9) {
         printf("Overweight\n");  //����
    }
    else {
         printf("Obese\n");   //����
    }
}

/// </summary>������������������������к�
/// <param name="nums"></int����>
/// <param name="numsSize"></int����Ԫ����Ŀ>
/// <returns></returns ������������к�>
int maxSubArray(int* nums, int numsSize) {
    int max = nums[0];
    int subMax = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (subMax > 0)
        {
            subMax += nums[i];//subMax�Ե�ǰ����������Ч������˼��ϵ�ǰ�������ϳ���
        }
        else//һ��subMaxС��0��һ����ִ����һ�ֺ󣨳�β��������һ���ǳ���ĸ�������������Ϊ������һ��������һ����
        {
            subMax = nums[i];//ֱ������֮ǰ�ģ���Ϊ������ʺ���԰�ǰ��Ķ�����������subMax��ֵ����Ϊ��ǰԪ�ص�ֵ
        }
        max = subMax > max ? subMax : max;
    }
    return max;
}


/// ��haystack��Ѱ��neddle��λ��
/// </summary>
/// <param name="haystack"></char*�ַ���>
/// <param name="needle"></char*�ַ���>
/// <returns></returns haystack�г���needle��λ��int>
int strStr(char* haystack, char* needle)
{
    // needle �ǿ��ַ�������Ϊ�����ַ������������ַ���������Ϊ 0
    if (*needle == NULL) return 0;
    // haystack �ǿ��ַ�������Ϊ���������κ��ַ��������ַ������⣩
    if (*haystack == NULL) return -1;
    // ��� haystack ��ͷָ��
    char* head = haystack;
    // ɨ��ƫ��
    int offset;
    // ���� haystack ���Ӵ�
    while (*haystack) {
        offset = 0;
        while (1) {
            // ���� needle ĩβ����Ϊ��ƥ����
            if (needle[offset] == 0) return haystack - head;
            // ���� haystack ĩβ����Ϊû��ƥ��
            if (haystack[offset] == 0) return -1;
            // ���������������ѭ��
            if (haystack[offset] != needle[offset]) break;
            offset++;
        }
        // �ƶ����¸��Ӵ�
        haystack++;
    }
    return -1;
}
/// <summary>
/// ������������N�Ĳ���ǰ��0�Ķ�������λ��eg.5:101  4:100  7:111
/// </summary>
/// <param name="N"></�Ǹ�����int>
/// <returns></returns N�Ķ�������λ>
int CountBit(int N)
{
    int cnt = (0 == N) ? 1 : 0;  //0Ҳ��1λ��
    while (N) {  //��������ƶ���λ
        cnt++;
        N >>= 1;
    }
    return cnt;
}

/// <summary>
/// ����Ǹ���������ǰ��0�Ķ����Ƶķ���
/// </summary>
/// <param name="N"></�Ǹ�����int>
/// <returns></returns ����>
int BitWiseComplement(int N) {
    int k = CountBit(N);  //����N�Ķ����ƣ�û��ǰ��0
    return pow(2, k) - 1 - N; //N�ķ��� = 2^k-1-N
}

/// <����x���������ƽ����>
/// ����Ǹ�������ƽ������ֻ��������
/// <param name="x"></�Ǹ�int>
/// <returns></returns x�ķ�����������int>
int MySqrt(int x) {
    int left = 1;
    int right = x / 2 + 1; //�۰�,+1Ϊ�˱�֤1Ҳ����ͨ��
    int mid = 0;
    while (left <= right) {
        mid = (left + right) / 2; //�۰�
        if (mid > x / mid) {  //mid^2 > x
            right = mid - 1;
        }
        else if (mid < x / mid) { //mid^2 < x
            left = mid + 1;
        }
        else {  //mid^2 = x
            return mid;
        }
    }
    return right; //�ܵ���˵��left^2 > x && mid^2 > x && right = mid - 1
}

int main()
{ 
    char *s1 = "mississippi";
    char *s2 = "pi";
    printf("%d\n", strStr(s1, s2));
    return 0;
}