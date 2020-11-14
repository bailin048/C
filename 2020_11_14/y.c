#include "Y.h"

int isPrimeNum(int x)
{	//判断质数
	if (x == 2) {   //2是质数
		return 1;
	}
	if ((x % 2 == 0) || (x > 10 && x % 10 == 5) || (x <= 1)) {
		return 0; //非2偶数, 大于的数若个位数为5则不是质数，小于2的数不是质数
	}
	else {
		for (int i = 3; i <= sqrt(x); i += 2) { //算到开方，步进2
			if (x % i == 0) {
				return 0;
				break;
			}
		}
	}
	return 1;
}

void BubbleSort(int x[], int num)
{
	//改进的冒泡排序:时间复杂度O(n^2)，空间复杂度O(1)
	int temp = 0;
	int flag = 1;//用来表示是否是否仍需排序
	for (int i = 0; i < num && flag; i++) {
		flag = 0; //若flag没有被内层循环重置为1，则说明数字已全部有序，循环这次进行完则会结束
		for (int j = 0; j < num - 1 - i; j++) {
			if (x[j + 1] > x[j]) {
				temp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = temp;
				flag = 1; //标志仍存在乱序数字			
			}
		}
	}
}

void SelectSort(int x[], int num)
{
	//简单选择排序:时间复杂度O(n^2)，空间复杂度O(1)
	int temp = 0;
	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			if (x[j] > x[i]) {
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
	}
}

int QKpass(int x[], int L, int H)
{
	int temp = x[L];  //枢轴设置
	while (L < H) {
		while (L < H && x[H] >= temp) {   //大于枢轴，则高指针下移，直至找到小于枢轴的数
			H--;
		}
		x[L] = x[H];  //与低指针交换数字
		while (L < H && x[L] < temp) {  //小于枢轴，则低指针下移，直至找到大于枢轴的数
			L++;
		}
		x[H] = x[L]; //与高指针交换数字
	}
	x[L] = temp; //枢轴回代
	return L; //返回枢轴所在位置
}

void QKSort(int x[], int L, int H)
{	//	快排：时间复杂度O(nlogn)，空间复杂度O(logn)
	if (L < H) {
		int pos = QKpass(x, L, H); //获取上次枢轴位置
		QKSort(x, pos + 1, H); //右表递归快排
		QKSort(x, L, pos - 1); //左表递归快排
	}
}

void InsertSort(int x[], int num)
{	//直接插入排序：时间复杂度O(n^2),空间复杂度:O(1)
	int temp = 0;
	int j = 0;
	for (int i = 1; i < num; i++)
	{
		if (x[i] < x[i - 1]) {
			temp = x[i]; //记录当前需要插入的数字
			for (j = i - 1; temp < x[j]; j--) { //大数后移
				x[j + 1] = x[j];
			}
			x[j + 1] = temp;  //插入
		}
	}
}

void BiInsertSort(int x[], int num)
{	//折半插入排序：时间复杂度O(n^2),空间复杂度:O(1)
	int temp = 0;
	int j = 0;
	for (int i = 1; i < num; i++)
	{
		if (x[i] < x[i - 1]) {
			temp = x[i]; //记录当前需要插入的数字
			int L = 0, H = i - 1; //设置双指针
			while (L <= H) {
				int mid = (L + H) / 2;  //折半
				if (temp < x[mid]) {
					H = mid - 1;
				}
				else {
					L = mid + 1;
				}
			}
			for (j = i - 1; j >= L; j--) { //大数后移
				x[j + 1] = x[j];
			}
			x[j + 1] = temp;  //插入
		}
	}
}

void ShellInsert(int x[], int dk, int num)
{
	int temp = 0, j = 0;
	for (int i = dk; i < num; i++) { //同组插入排序
		if (x[i] < x[i - dk]) {
			temp = x[i];
			for (j = i - dk; j >= 0 && (x[j] > temp); j -= dk) {
				x[j + dk] = x[j];
			}
			x[j + dk] = temp;
		}
	}
}

void ShellSort(int x[], int x_num)
{	//希尔排序：时间复杂度O(n^2),空间复杂度O(1)
	int delt = x_num;
	while (delt) {
		delt = (delt / 2);
		if (delt == 0) {
			break;
		}
		ShellInsert(x, delt, x_num); //传入增量
	}
}

void Merge(int x[], int _L, int _R, int _mid)
{
	int i, p1, p2;
	int x_cpy[nums] = { 0 };
	for (i = _L; i <= _R; i++) {//Copyx保存待排序序列
		x_cpy[i] = x[i];
	}
	p1 = _L;//左半部有序记录起始位置
	p2 = _mid + 1;//右半部有序记录起始位置
	i = _L; //左半部开始归并

	while (p1 <= _mid && p2 <= _R)//两个半区内
	{
		if (x_cpy[p1] <= x_cpy[p2]) {//找出较小的放入合并后的序列中
			x[i] = x_cpy[p1];
			p1++;
		}
		else {
			x[i] = x_cpy[p2];
			p2++;
		}
		i++;
	}
	//剩下的序列无论左右半部都放入到合并后的记录中
	while (p1 <= _mid) {
		x[i] = x_cpy[p1];
		i++;
		p1++;
	}
	while (p2 <= _R) {
		x[i] = x_cpy[p2];
		i++;
		p2++;
	}
}

void MergeSort(int x[], int L, int R)
{	//二路归并：时间复杂度O(nlogn),空间复杂度O(n)
	// 传入的R = 数组元素数目 - 1
	int mid;
	if (L < R) {
		mid = (L + R) / 2;  //序列分割
		MergeSort(x, L, mid); //左序列归并
		MergeSort(x, mid + 1, R); //右序列归并
		Merge(x, L, R, mid);  //归并函数
	}
}

/*
*function : 计算num!
*input :    int num
*output:    int num!
*/
long int Factorials(int n)
{
	if (n > 1) { // n!(n>1)
		return n * Factorials(n - 1);;
	}
	return 1;  //0！or 1!
}

/*
*function : 计算1！+2！+……+num!
*input :    int 累加上限
*output:    int 累加和
*/
int FactorialsSum(int num)
{
	int i = 1, result = 0;
	for (; i < num + 1; i++) {
		result += Factorials(i);
	}
	return result;
}

/*
*function : 寻找两个整数的最大公因数
*input :    int _a，int_b 两个整数
*output:    int 最大公因数
*/
int SeekMaxFactor2(int _a, int _b)
{  //寻找a与b的最大公因数
	int temp = 0, i = 0;
	if (_b < _a) {   //确保a是较小的数
		temp = _a;
		_a = _b;
		_b = temp;
	}
	for (i = _a; i > 0; i--) { //递增不可选，会增加计算量
		if (_a % i == 0) {  //i是否为a的因数
			if (_b % i == 0) { //是，i是否是b的因数
				return i;//是，返回i，跳出	
			}
		}
	}
	return 1;
}

/*
*function : 打印[_Min,_Max]年份范围内所有闰年
*input :    int _Min，int_Max 查找区间
*output:    无
*/
void PrintLeapyear(int _Min, int _Max)
{	//打印[_Min,_Max]之间的所有闰年
	int i = _Min;
	while (i < _Max + 1) {
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {//公历闰年or世纪闰年
			printf("%d ", i);
		}
		i++;
	}
}

/*
*function : 计算[_Min,_Max]范围内所有整数中含9的个数
*input :    int _Min，int_Max 查找区间
*output:    int 9的数目
*/
int Count9(int _Min, int _Max)
{	
	int i, j;
	int cnt = 0;
	for (i = _Min; i < _Max + 1; i++) { //控制范围
		for (j = i; j > 0; j /= 10) { //倒序获得i的各数位
			if (j % 10 == 9) {//发现一个9,cnt自增1
				cnt++;
			}
		}
	}
	return cnt;
}

/*
*function : 二分查找
*input :    int数组，int查找元素，int数组元素数目 
*output:    存在则返回int索引，否则返回-1
*/
int BiSearch(int x[], int target, int _num)
{
	int L = 0;
	int R = _num - 1;
	while (L <= R) {  //左索引未超过右索引，说明仍有元素未被比较
		int mid = (L + R) / 2;   //折半
		if (x[mid] > target) {   //目标值小于中指，说明该值位于左半区
			R = mid - 1;
		}
		else if (x[mid] < target) {  //目标...右半区
			L = mid + 1;
		}
		else {
			return mid;   //中值就是目标值
		}
	}
	return -1;
}

/*
*function : 判断某年是否是闰年
*input :    int 合法年份
*output:    1:是  0:不是
*/
int IsLeapyear(int year)

{   //判断闰年    1:是 0：不是
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/*
* function: 计算输入字符串的长度
* input:    char*   字符指针
* ouput:    int     字符串长度
*/
int MyStrlen(const char* s)
{
	const char* p = s;
	assert(p != NULL);
	while (*p) { //当前字符不为\0，则指针后移
		p++;
	}
	return p - s;
}

int FibNum(int n)
{    //递归算法:效率低下
	/*if (n < 3) {
		return 1;
	}
	return FibNum(n - 1) + FibNum(n - 2);*/
	int first = 0;  //迭代算法
	int second = 1;
	int third = n > 0 ? 1 : 0;
	while (n > 1) {
		third = first + second;
		first = second;
		second = third;
		n--;
	}
	return third;
}

/*
*function : 实现反向字符串
*input :    字符数组
*output:    无
*/
void reverse_string(char* string)
{
	int len = MyStrlen(string);//计算字符串长度
	if (len <= 1)
		return 0;
	else
	{
		char temp = string[0];
		string[0] = string[len - 1];//前两句实现字符串前后对应符号交换
		string[len - 1] = '\0';	//将最后一个字符的内容赋为'\0'以达到扔掉尾部的效果
		reverse_string(string + 1);//递归调用下一次反转；
		string[len - 1] = temp;	//返回过程中将temp交给len-1的位置；
	}
}

/*
*function : 判断一个数是否是水仙花数
*input :    int 非负整数
*output:    1:是  0:不是
*/
int IsNarcissisticNum(int n)
{
	int len = 1;
	int n_cpy = n, sum = 0;
	while (n_cpy / 10) { //计算数字位数，个位数不计算
		n_cpy /= 10;
		len++;
	}
	n_cpy = n;
	for (int i = len; i > 0; i--) { //计算数位指数和
		sum += (int)pow(n_cpy % 10, (double)len);
		n_cpy /= 10;
	}
	if (sum == n) { //判断是否是水仙花数
		return 1;
	}
	return 0;
}

/*
*function : 打印如下图形
*  *
  ***
 *****
*******
 *****
  ***
   * 
* input : int 奇数
* output: 无
*/
void PrintRhombus(int n)
{	//将行数对称化【(1 - n) / 2;，i <= (n - 1) / 2】
	char space = ' ';
	char star = '*';
	for (int i = (1 - n) / 2; i <= (n - 1) / 2; i++) {
		for (int j = abs(i); j > 0; j--) {  //打印空格
			printf("%c", space);
		}
		for (int k = n - 2 * abs(i); k > 0; k--) {
			printf("%c", star);  //打印*
		}
		printf("\n");
	}
}

/*
*function : 实现字符串复制
*input :    容量足够的可修改字符数组指针arr，不可修改字符指针p
*output:    被p指向字符串覆盖后的arr
*/
char* MyStrcpy(char* arr, const char* p)
{
	char* s = arr;
	assert(arr && p);
	while (*arr = *p) { //*p先赋值给arr,再判断arr==\0?
		arr++;
		p++;
	}
	return arr;
}

/*
*function: 调整数组中数字的顺序使得数组中所有的奇数位于数组的前半部分
*input:    int数组，int数组元素数目
*output:   空
*/
void SwapNumBit(int* arr, int num)
{
	int left = 0;
	int right = num - 1;
	while (left < right) {
		while (arr[left] % 2) {  //左起找第一个偶数
			left++;
		}
		while (!(arr[right] % 2)) { //右起找第一个奇数
			right--;
		}
		if (left >= right) {  //left>=right说明已经没有需要交换的
			break;
		}
		int temp = arr[left];  //交换
		arr[left] = arr[right];
		arr[right] = temp;
	}
}

/*
*function: 打印n盘汉诺塔移动顺序
*input：   int 盘的数目，3个char塔名：原塔，辅助塔，目的塔
*output:   无
*/
void Hanoi(int n, char a, char b, char c)
{
	if (n == 1) { //最后一个盘：从A塔移动至C塔
		printf("第%d个盘:%c->%c\n", n, a, c);
	}
	else {
		Hanoi(n - 1, a, c, b); //借C塔将n-1个盘从X塔移动到Y塔
		printf("第%d个盘:%c->%c\n", n, a, c);
		Hanoi(n - 1, b, a, c); //借B塔将n-1个盘从A塔移动至C塔
	}
}

/// functon : 青蛙跳台阶，一次1or2,n阶多少种跳法 
/// input : int 台阶数
/// output : int 跳法数目
int WayOfFrogJumpsStairs(int n)
{
	int first = 0;  //斐波那契变体
	int second = 1;
	int third = 0;
	while (n--) {
		third = first + second;
		first = second;
		second = third;
	}
	return third; //跳法数目
}

/// function : 打印变种水仙花
/// Lily Number：把任意的数字，从中间拆分成两个数字，
/// 比如1461 可以拆分成（1和461）,（14和61）,（146和1),
/// 如果所有拆分后的乘积之和等于自身，则是一个Lily Number。
/// 655 = 6 * 55 + 65 * 5
/// 1461 = 1 * 461 + 14 * 61 + 146 * 1
/// inupt :非负int
/// output : 无
void PrintLilyNum(int n)
{
	int sum = 0;
	int flag = 10;
	while ((n / flag) > 0)
	{
		sum += ((n % flag) * (n / flag));
		flag *= 10;
	}
	if (sum == n) {
		printf("%d ", n);
	}
}