#include <stdio.h>
#include <assert.h>
#pragma warning(disable:4996)
void* MyMemcpy(void* dst, const void* src, int n)
{
    assert(dst);
    assert(src);//输入合法性校验
    char* _dst = (char*)dst;
    char* _src = (char*)src;
    if (_dst > _src && (_dst - _src < n)) {
        _src += n - 1; //指向最后一个字节
        _dst += n - 1;
        while (n--) {//按字节拷贝right->left
            *_dst = *_src;
            _dst--, _src--;
        }
    }
    else {
        while (n--) { //按字节拷贝left->right
            *_dst = *_src;
            _dst++, _src++;
        }
    }
    return dst;
}

void* MyMemmove(void* dst, const void* src, int n)
{
    assert(dst);
    assert(src);//输入合法性校验
    char* _dst = (char*)dst;
    char* _src = (char*)src;
    if (_dst > _src && (_dst - _src < n)) {
        _src += n - 1; //指向最后一个字节
        _dst += n - 1;
        while (n--) {//按字节拷贝right->left
            *_dst = *_src;
            _dst--, _src--;
        }
    }
    else {
        while (n--) { //按字节拷贝left->right
            *_dst = *_src;
            _dst++, _src++;
        }
    }
    return dst;
}
int main()
{

    char a[] = "hello world";
    char b[] = "bullshit";
    printf("%s\n",a);
    printf("%s\n",MyMemcpy(a,a+1,4));
    return 0;
}