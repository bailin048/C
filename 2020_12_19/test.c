#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
/// �ַ���ת����
/// <param name="ptr"></�ַ�������>
/// <returns></returns int������>
int myatoi(const char* ptr)
{
	assert(ptr);
	int res = 0;
	char* p = ptr;
	int flag = 1;//������־,Ĭ��Ϊ��
	while (*p == ' ') {
		p++;
	}
	if (*p == '-') {
		flag = -1;
		p++;
	}
	while (*p >= '0' && *p <= '9') {//�ۼ�
		res = (res * 10 + *p - '0');
		p++;
	}
	if (*p == '\0' || res != 0) { //res����0�����ַ����ѱ������
		return flag * res;
	}
	else {  //res = 0���ַ���δ������ֻ��˵�����ַ�������ת��
		return 0;
	}
}

/// Ѱ���ַ������������д�����󹫹�ǰ׺
/// <param name="strs"></�ַ�������>
/// <param name="strsSize"></����Ԫ����Ŀ>
/// <returns></returns ����ǰ׺��ָ��>
char* longestCommonPrefix(char** strs, int strsSize) {
	if (!strsSize) {  //�����鷵�ؿմ�
		return "";
	}
	for (int i = 0; i < strlen(strs[0]); i++) {//i������
		for (int j = 1; j < strsSize; j++) {//j������
			if (strs[0][i] != strs[j][i]) {//j�г��ֲ�һ����Ԫ��
				strs[0][i] = '\0'; //\0���ǵ�ǰ�У����ؼ���
				break;
			}
		}
	}
	return strs[0];
}

///����ƥ��
/// <param name="s"></������>
/// <returns></returns������>
char MatesOfBracket(char s)
{
	if (s == ')') {
		return '(';
	}
	if (s == ']') {
		return '[';
	} 
	if (s == '}') {
		return '{';	
	}
	return '0';
}
/// </summary>�ַ���ƥ������
/// <param name="s"></param�����ַ���>
/// <returns></returns 1:��Ч 0����Ч>
int isValid(char* s) {
	int n = strlen(s);
	if (n % 2) {//�ַ�����Ϊ���������жϣ���Ч��
		return 0;
	}
	char* stack = (char*)malloc((n + 1) * sizeof(char));//���붯̬�ռ�
	int top = 0;
	if (stack != NULL) {
		for (int i = 0; i < n; i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {//��ջ
				stack[++top] = s[i];
			}
			else if (stack[top] == MatesOfBracket(s[i])) {//��ջ
				top--;
			}
			else {
				return 0;
			}
		}
	}
	if (stack != NULL) {//�ͷſռ�
		free(stack);
		stack = NULL;
	}
	return top == 0;
}
int main() 
{
	char* str = "()[]{}";
	printf("%d\n", isValid(str));
	return 0;
}





























