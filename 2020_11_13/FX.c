#include "FX.h"

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
	int x_cpy[nums] = {0};
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
long int Factorials(int n)
{
	if (n > 1) { // n!(n>1)
		return n * Factorials(n - 1);;
	}
	return 1;  //0！or 1!
}
int FactorialsSum(int num)
{
	int i = 1, result = 0;
	for (; i < num + 1; i++) {
		result += Factorials(i);
	}
	return result;
}
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
int Count9(int _Min, int _Max)
{	//计算[_Min,_Max]范围内所有数含9的个数
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
int IsLeapyear(int year)

{   //判断闰年    1:是 0：不是
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int Strlen(const char* s)
{
	if (*s != '\0') {  //未遇到字符串结束符，则进行递归
		return 1 + Strlen(s + 1);
	}
	else {
		return 0;
	}
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
	while (n > 1){
		third = first + second;
		first = second;
		second = third;
		n--;
	}
	return third;
}
void reverse_string(char* string)
{
	int len = Strlen(string);//计算字符串长度
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
		sum += pow(n_cpy % 10, (double)len);
		n_cpy /= 10;
	}
	if (sum == n) { //判断是否是水仙花数
		return 1;
	}
	return 0;
}
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