#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)

/// <判断输入的3个长度是否可以构成三角形，能并输出三角形类型>
/// 
/// </summary> 不可以构成三角形/可以构成三角形：等边？等腰？普通？
/// <param name="a"></边长a>
/// <param name="b"></边长b>
/// <param name="c"></边长c>
void IsTriangle_Type(float a, float b ,float c )
{
    int flag = (a + b > c) ? (a + c > b) ? (b + c > a) ? 1 : 0 : 0 : 0; //判断是否构成三角形
    if (flag == 1 && (a == b) && (b == c)) {  //等边三角形
        printf("Equilateral triangle!\n");
    }
    else if (flag == 1 && ((a == b) || (b == c) || (a == c))) //等腰三角形
        {
            printf("Isosceles triangle!\n");
        }
    else if (flag == 0) {                  //不能构成三角形
            printf("Not a triangle!\n");
        }
    else {
            printf("Ordinary triangle!\n");   //常规三角形
        }
}

/// <计算BMI并输出健康情况>
/// 
/// </summary>
/// <param name="weight"></体重kg>
/// <param name="height"></身高cm>
void BmiComputeJudge(float weight, float height)
{
    height /= 100;
    float bmi = weight / (height * height); //BMI=体重(kg)/身高^2(m)
    if (bmi < 18.5) {
         printf("Underweight\n");  //过轻
    }
    else if (bmi <= 23.9) {
         printf("Normal\n");   //正常
    }
    else if (bmi <= 27.9) {
         printf("Overweight\n");  //过重
    }
    else {
         printf("Obese\n");   //肥胖
    }
}

/// </summary>计算整数数组最大连续子序列和
/// <param name="nums"></int数组>
/// <param name="numsSize"></int数组元素数目>
/// <returns></returns 最大连续子序列和>
int maxSubArray(int* nums, int numsSize) {
    int max = nums[0];
    int subMax = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (subMax > 0)
        {
            subMax += nums[i];//subMax对当前的数有增益效果，因此加上当前的数（上车）
        }
        else//一旦subMax小于0，一定是执行上一轮后（车尾）加上了一个非常大的负数，导致整体为负数，一个老鼠坏了一锅汤
        {
            subMax = nums[i];//直接跳过之前的（因为有老鼠屎所以把前面的都丢掉），将subMax的值设置为当前元素的值
        }
        max = subMax > max ? subMax : max;
    }
    return max;
}


/// 在haystack中寻找neddle的位置
/// </summary>
/// <param name="haystack"></char*字符串>
/// <param name="needle"></char*字符串>
/// <returns></returns haystack中出现needle的位置int>
int strStr(char* haystack, char* needle)
{
    // needle 是空字符串，认为所有字符串都包含空字符串，索引为 0
    if (*needle == NULL) return 0;
    // haystack 是空字符串，认为它不包含任何字符串（空字符串除外）
    if (*haystack == NULL) return -1;
    // 标记 haystack 的头指针
    char* head = haystack;
    // 扫描偏移
    int offset;
    // 遍历 haystack 的子串
    while (*haystack) {
        offset = 0;
        while (1) {
            // 到达 needle 末尾，认为能匹配上
            if (needle[offset] == 0) return haystack - head;
            // 到达 haystack 末尾，认为没有匹配
            if (haystack[offset] == 0) return -1;
            // 不相等则跳出本次循环
            if (haystack[offset] != needle[offset]) break;
            offset++;
        }
        // 移动到下个子串
        haystack++;
    }
    return -1;
}
/// <summary>
/// 计算输入整数N的不带前导0的二进制数位，eg.5:101  4:100  7:111
/// </summary>
/// <param name="N"></非负整数int>
/// <returns></returns N的二进制数位>
int CountBit(int N)
{
    int cnt = (0 == N) ? 1 : 0;  //0也是1位数
    while (N) {  //计算二进制多少位
        cnt++;
        N >>= 1;
    }
    return cnt;
}

/// <summary>
/// 计算非负整数不带前导0的二进制的反码
/// </summary>
/// <param name="N"></非负整数int>
/// <returns></returns 反码>
int BitWiseComplement(int N) {
    int k = CountBit(N);  //计算N的二进制，没有前导0
    return pow(2, k) - 1 - N; //N的反码 = 2^k-1-N
}

/// <计算x的最大整数平方根>
/// 计算非负整数的平方根，只保留整数
/// <param name="x"></非负int>
/// <returns></returns x的方根整数部分int>
int MySqrt(int x) {
    int left = 1;
    int right = x / 2 + 1; //折半,+1为了保证1也可以通过
    int mid = 0;
    while (left <= right) {
        mid = (left + right) / 2; //折半
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
    return right; //能到这说明left^2 > x && mid^2 > x && right = mid - 1
}

int main()
{ 
    char *s1 = "mississippi";
    char *s2 = "pi";
    printf("%d\n", strStr(s1, s2));
    return 0;
}