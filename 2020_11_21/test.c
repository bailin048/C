#include <stdio.h>
/// <function>��ӡ�������ǰn�У�Ŀǰ��
/// 1
/// 1 1
/// 1 2 1
/// 1 3 3 1
/// ����
/// <param name="n"></int��ӡ����> warnong��n���ô���100��������Ҫ��������Ԫ����Ŀ
void YHTriangle(int n)
{ 
	int old[100] = { 0,1 }; //��������100Ԫ�����ͣ���������������еĴ洢�����
	int new[100] = { 0 }; // ��������0����ֵ����0��Զ���䣬����ʹ����λ�õ�Ԫ�ؼ��㷽��һ��
	int i = 0, j = 1;
	printf("1\n"); //��ӡ��һ�� 1
	for (i = 2; i <= n; i++) { //�ӵڶ����ٿ�ʼ����
		for (j = 1; j <= i ; j++) { 
			new[j] = old[j] + old[j - 1]; //new�ĵ�j����old[j]+old[j-1]�������
			printf("%d ", new[j]);  //��ӡ��ǰ����
		}
		printf("\n"); //��ǰ���Ѵ�ӡ�꣬����
		for (j = 1; j <= i; j++) { //����old��Ϊ��һ�м�����׼��
			old[j] = new[j];
		}
	}
}

int main()
{
	for (char killer = 'A'; killer <= 'D'; killer++) {
		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3) {
			printf("%c\n",killer);
		}
	}
}