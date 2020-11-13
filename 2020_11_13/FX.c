#include "FX.h"

int isPrimeNum(int x)
{	//�ж�����
	if (x == 2) {   //2������
		return 1;
	}
	if ((x % 2 == 0) || (x > 10 && x % 10 == 5) || (x <= 1)) {
		return 0; //��2ż��, ���ڵ�������λ��Ϊ5����������С��2������������
	}
	else {
		for (int i = 3; i <= sqrt(x); i += 2) { //�㵽����������2
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
	//�Ľ���ð������:ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(1)
	int temp = 0;
	int flag = 1;//������ʾ�Ƿ��Ƿ���������
	for (int i = 0; i < num && flag; i++) {
		flag = 0; //��flagû�б��ڲ�ѭ������Ϊ1����˵��������ȫ������ѭ����ν�����������
		for (int j = 0; j < num - 1 - i; j++) {
			if (x[j + 1] > x[j]) {
				temp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = temp;
				flag = 1; //��־�Դ�����������			
			}
		}
	}
}
void SelectSort(int x[], int num)
{
	//��ѡ������:ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(1)
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
	int temp = x[L];  //��������
	while (L < H) {
		while (L < H && x[H] >= temp) {   //�������ᣬ���ָ�����ƣ�ֱ���ҵ�С���������
			H--;
		}
		x[L] = x[H];  //���ָ�뽻������
		while (L < H && x[L] < temp) {  //С�����ᣬ���ָ�����ƣ�ֱ���ҵ������������
			L++;
		}
		x[H] = x[L]; //���ָ�뽻������
	}
	x[L] = temp; //����ش�
	return L; //������������λ��
}
void QKSort(int x[], int L, int H)
{	//	���ţ�ʱ�临�Ӷ�O(nlogn)���ռ临�Ӷ�O(logn)
	if (L < H) {
		int pos = QKpass(x, L, H); //��ȡ�ϴ�����λ��
		QKSort(x, pos + 1, H); //�ұ�ݹ����
		QKSort(x, L, pos - 1); //���ݹ����
	}
}
void InsertSort(int x[], int num)
{	//ֱ�Ӳ�������ʱ�临�Ӷ�O(n^2),�ռ临�Ӷ�:O(1)
	int temp = 0;  
	int j = 0;
	for (int i = 1; i < num; i++)
	{
		if (x[i] < x[i - 1]) {
			temp = x[i]; //��¼��ǰ��Ҫ���������
			for (j = i - 1; temp < x[j]; j--) { //��������
				x[j + 1] = x[j];
			}
			x[j + 1] = temp;  //����
		}
	}
}
void BiInsertSort(int x[], int num)
{	//�۰��������ʱ�临�Ӷ�O(n^2),�ռ临�Ӷ�:O(1)
	int temp = 0;
	int j = 0;
	for (int i = 1; i < num; i++)
	{
		if (x[i] < x[i - 1]) {
			temp = x[i]; //��¼��ǰ��Ҫ���������
			int L = 0, H = i - 1; //����˫ָ��
			while (L <= H) {
				int mid = (L + H) / 2;  //�۰�
				if (temp < x[mid]) {   
					H = mid - 1;
				}
				else {
					L = mid + 1;
				}
			}
			for (j = i - 1; j >= L; j--) { //��������
				x[j + 1] = x[j];
			}
			x[j + 1] = temp;  //����
		}
	}
}
void ShellInsert(int x[], int dk, int num)
{
	int temp = 0, j = 0;
	for (int i = dk; i < num; i++) { //ͬ���������
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
{	//ϣ������ʱ�临�Ӷ�O(n^2),�ռ临�Ӷ�O(1)
	int delt = x_num;
	while (delt) {
		delt = (delt / 2);
		if (delt == 0) {
			break;
		}
		ShellInsert(x, delt, x_num); //��������
	}
}
void Merge(int x[], int _L, int _R, int _mid)
{
	int i, p1, p2;
	int x_cpy[nums] = {0};
	for (i = _L; i <= _R; i++) {//Copyx�������������
		x_cpy[i] = x[i];
	}
	p1 = _L;//��벿�����¼��ʼλ��
	p2 = _mid + 1;//�Ұ벿�����¼��ʼλ��
	i = _L; //��벿��ʼ�鲢

	while (p1 <= _mid && p2 <= _R)//����������
	{
		if (x_cpy[p1] <= x_cpy[p2]) {//�ҳ���С�ķ���ϲ����������
			x[i] = x_cpy[p1];
			p1++;
		}
		else {
			x[i] = x_cpy[p2];
			p2++;
		}
		i++;
	}
	//ʣ�µ������������Ұ벿�����뵽�ϲ���ļ�¼��
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
{	//��·�鲢��ʱ�临�Ӷ�O(nlogn),�ռ临�Ӷ�O(n)
	// �����R = ����Ԫ����Ŀ - 1
	int mid;
	if (L < R) {
		mid = (L + R) / 2;  //���зָ�
		MergeSort(x, L, mid); //�����й鲢
		MergeSort(x, mid + 1, R); //�����й鲢
		Merge(x, L, R, mid);  //�鲢����
	}
}
long int Factorials(int n)
{
	if (n > 1) { // n!(n>1)
		return n * Factorials(n - 1);;
	}
	return 1;  //0��or 1!
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
{  //Ѱ��a��b���������
	int temp = 0, i = 0;
	if (_b < _a) {   //ȷ��a�ǽ�С����
		temp = _a;
		_a = _b;
		_b = temp;
	}
	for (i = _a; i > 0; i--) { //��������ѡ�������Ӽ�����
		if (_a % i == 0) {  //i�Ƿ�Ϊa������
			if (_b % i == 0) { //�ǣ�i�Ƿ���b������
				return i;//�ǣ�����i������	
			}
		}
	}
	return 1;
}
void PrintLeapyear(int _Min, int _Max)
{	//��ӡ[_Min,_Max]֮�����������
	int i = _Min;
	while (i < _Max + 1) {
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {//��������or��������
			printf("%d ", i);
		}
		i++;
	}
}
int Count9(int _Min, int _Max)
{	//����[_Min,_Max]��Χ����������9�ĸ���
	int i, j;
	int cnt = 0;
	for (i = _Min; i < _Max + 1; i++) { //���Ʒ�Χ
		for (j = i; j > 0; j /= 10) { //������i�ĸ���λ
			if (j % 10 == 9) {//����һ��9,cnt����1
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
	while (L <= R) {  //������δ������������˵������Ԫ��δ���Ƚ�
		int mid = (L + R) / 2;   //�۰�
		if (x[mid] > target) {   //Ŀ��ֵС����ָ��˵����ֵλ�������
			R = mid - 1;
		}
		else if (x[mid] < target) {  //Ŀ��...�Ұ���
			L = mid + 1;
		}
		else {
			return mid;   //��ֵ����Ŀ��ֵ
		}
	}
	return -1;
}
int IsLeapyear(int year)

{   //�ж�����    1:�� 0������
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int Strlen(const char* s)
{
	if (*s != '\0') {  //δ�����ַ���������������еݹ�
		return 1 + Strlen(s + 1);
	}
	else {
		return 0;
	}
}
int FibNum(int n) 
{    //�ݹ��㷨:Ч�ʵ���
	/*if (n < 3) {
		return 1;
	}
	return FibNum(n - 1) + FibNum(n - 2);*/
	int first = 0;  //�����㷨
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
	int len = Strlen(string);//�����ַ�������
	if (len <= 1)
		return 0;
	else
	{
		char temp = string[0];
		string[0] = string[len - 1];//ǰ����ʵ���ַ���ǰ���Ӧ���Ž���
		string[len - 1] = '\0';	//�����һ���ַ������ݸ�Ϊ'\0'�Դﵽ�ӵ�β����Ч��
		reverse_string(string + 1);//�ݹ������һ�η�ת��
		string[len - 1] = temp;	//���ع����н�temp����len-1��λ�ã�
	}
}
int IsNarcissisticNum(int n)
{
	int len = 1;
	int n_cpy = n, sum = 0;
	while (n_cpy / 10) { //��������λ������λ��������
		n_cpy /= 10;
		len++;
	}
	n_cpy = n;
	for (int i = len; i > 0; i--) { //������λָ����
		sum += pow(n_cpy % 10, (double)len);
		n_cpy /= 10;
	}
	if (sum == n) { //�ж��Ƿ���ˮ�ɻ���
		return 1;
	}
	return 0;
}
void PrintRhombus(int n)
{	//�������Գƻ���(1 - n) / 2;��i <= (n - 1) / 2��
	char space = ' ';
	char star = '*';
	for (int i = (1 - n) / 2; i <= (n - 1) / 2; i++) {
		for (int j = abs(i); j > 0; j--) {  //��ӡ�ո�
			printf("%c", space);
		}
		for (int k = n - 2 * abs(i); k > 0; k--) {
			printf("%c", star);  //��ӡ*
		}
		printf("\n");
	}
}