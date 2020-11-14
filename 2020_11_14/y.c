#include "Y.h"

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
	int x_cpy[nums] = { 0 };
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

/*
*function : ����num!
*input :    int num
*output:    int num!
*/
long int Factorials(int n)
{
	if (n > 1) { // n!(n>1)
		return n * Factorials(n - 1);;
	}
	return 1;  //0��or 1!
}

/*
*function : ����1��+2��+����+num!
*input :    int �ۼ�����
*output:    int �ۼӺ�
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
*function : Ѱ�������������������
*input :    int _a��int_b ��������
*output:    int �������
*/
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

/*
*function : ��ӡ[_Min,_Max]��ݷ�Χ����������
*input :    int _Min��int_Max ��������
*output:    ��
*/
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

/*
*function : ����[_Min,_Max]��Χ�����������к�9�ĸ���
*input :    int _Min��int_Max ��������
*output:    int 9����Ŀ
*/
int Count9(int _Min, int _Max)
{	
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

/*
*function : ���ֲ���
*input :    int���飬int����Ԫ�أ�int����Ԫ����Ŀ 
*output:    �����򷵻�int���������򷵻�-1
*/
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

/*
*function : �ж�ĳ���Ƿ�������
*input :    int �Ϸ����
*output:    1:��  0:����
*/
int IsLeapyear(int year)

{   //�ж�����    1:�� 0������
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/*
* function: ���������ַ����ĳ���
* input:    char*   �ַ�ָ��
* ouput:    int     �ַ�������
*/
int MyStrlen(const char* s)
{
	const char* p = s;
	assert(p != NULL);
	while (*p) { //��ǰ�ַ���Ϊ\0����ָ�����
		p++;
	}
	return p - s;
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
	while (n > 1) {
		third = first + second;
		first = second;
		second = third;
		n--;
	}
	return third;
}

/*
*function : ʵ�ַ����ַ���
*input :    �ַ�����
*output:    ��
*/
void reverse_string(char* string)
{
	int len = MyStrlen(string);//�����ַ�������
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

/*
*function : �ж�һ�����Ƿ���ˮ�ɻ���
*input :    int �Ǹ�����
*output:    1:��  0:����
*/
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
		sum += (int)pow(n_cpy % 10, (double)len);
		n_cpy /= 10;
	}
	if (sum == n) { //�ж��Ƿ���ˮ�ɻ���
		return 1;
	}
	return 0;
}

/*
*function : ��ӡ����ͼ��
*  *
  ***
 *****
*******
 *****
  ***
   * 
* input : int ����
* output: ��
*/
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

/*
*function : ʵ���ַ�������
*input :    �����㹻�Ŀ��޸��ַ�����ָ��arr�������޸��ַ�ָ��p
*output:    ��pָ���ַ������Ǻ��arr
*/
char* MyStrcpy(char* arr, const char* p)
{
	char* s = arr;
	assert(arr && p);
	while (*arr = *p) { //*p�ȸ�ֵ��arr,���ж�arr==\0?
		arr++;
		p++;
	}
	return arr;
}

/*
*function: �������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿��
*input:    int���飬int����Ԫ����Ŀ
*output:   ��
*/
void SwapNumBit(int* arr, int num)
{
	int left = 0;
	int right = num - 1;
	while (left < right) {
		while (arr[left] % 2) {  //�����ҵ�һ��ż��
			left++;
		}
		while (!(arr[right] % 2)) { //�����ҵ�һ������
			right--;
		}
		if (left >= right) {  //left>=right˵���Ѿ�û����Ҫ������
			break;
		}
		int temp = arr[left];  //����
		arr[left] = arr[right];
		arr[right] = temp;
	}
}

/*
*function: ��ӡn�̺�ŵ���ƶ�˳��
*input��   int �̵���Ŀ��3��char������ԭ������������Ŀ����
*output:   ��
*/
void Hanoi(int n, char a, char b, char c)
{
	if (n == 1) { //���һ���̣���A���ƶ���C��
		printf("��%d����:%c->%c\n", n, a, c);
	}
	else {
		Hanoi(n - 1, a, c, b); //��C����n-1���̴�X���ƶ���Y��
		printf("��%d����:%c->%c\n", n, a, c);
		Hanoi(n - 1, b, a, c); //��B����n-1���̴�A���ƶ���C��
	}
}

/// functon : ������̨�ף�һ��1or2,n�׶��������� 
/// input : int ̨����
/// output : int ������Ŀ
int WayOfFrogJumpsStairs(int n)
{
	int first = 0;  //쳲���������
	int second = 1;
	int third = 0;
	while (n--) {
		third = first + second;
		first = second;
		second = third;
	}
	return third; //������Ŀ
}

/// function : ��ӡ����ˮ�ɻ�
/// Lily Number������������֣����м��ֳ��������֣�
/// ����1461 ���Բ�ֳɣ�1��461��,��14��61��,��146��1),
/// ������в�ֺ�ĳ˻�֮�͵�����������һ��Lily Number��
/// 655 = 6 * 55 + 65 * 5
/// 1461 = 1 * 461 + 14 * 61 + 146 * 1
/// inupt :�Ǹ�int
/// output : ��
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