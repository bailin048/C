#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
/// 字符串转数字
/// <param name="ptr"></字符串常量>
/// <returns></returns int型数字>
int myatoi(const char* ptr)
{
	assert(ptr);
	int res = 0;
	char* p = ptr;
	int flag = 1;//正负标志,默认为正
	while (*p == ' ') {
		p++;
	}
	if (*p == '-') {
		flag = -1;
		p++;
	}
	while (*p >= '0' && *p <= '9') {//累加
		res = (res * 10 + *p - '0');
		p++;
	}
	if (*p == '\0' || res != 0) { //res不等0或者字符串已遍历完成
		return flag * res;
	}
	else {  //res = 0且字符串未结束，只能说明该字符串不能转换
		return 0;
	}
}

/// 寻找字符串数组中所有串的最大公共前缀
/// <param name="strs"></字符串数组>
/// <param name="strsSize"></数组元素数目>
/// <returns></returns 公共前缀的指针>
char* longestCommonPrefix(char** strs, int strsSize) {
	if (!strsSize) {  //空数组返回空串
		return "";
	}
	for (int i = 0; i < strlen(strs[0]); i++) {//i控制列
		for (int j = 1; j < strsSize; j++) {//j控制行
			if (strs[0][i] != strs[j][i]) {//j列出现不一样的元素
				strs[0][i] = '\0'; //\0覆盖当前列，返回即可
				break;
			}
		}
	}
	return strs[0];
}

///括号匹配
/// <param name="s"></右括号>
/// <returns></returns左括号>
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
/// </summary>字符串匹配问题
/// <param name="s"></param括号字符串>
/// <returns></returns 1:有效 0：无效>
int isValid(char* s) {
	int n = strlen(s);
	if (n % 2) {//字符串长为奇数不用判断，无效！
		return 0;
	}
	char* stack = (char*)malloc((n + 1) * sizeof(char));//申请动态空间
	int top = 0;
	if (stack != NULL) {
		for (int i = 0; i < n; i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {//入栈
				stack[++top] = s[i];
			}
			else if (stack[top] == MatesOfBracket(s[i])) {//出栈
				top--;
			}
			else {
				return 0;
			}
		}
	}
	if (stack != NULL) {//释放空间
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





























