#include <stdio.h>
#include <assert.h>
#pragma warning(disable:4996)
void* MyMemcpy(void* dst, const void* src, int n)
{
    assert(dst);
    assert(src);//����Ϸ���У��
    char* _dst = (char*)dst;
    char* _src = (char*)src;
    if (_dst > _src && (_dst - _src < n)) {
        _src += n - 1; //ָ�����һ���ֽ�
        _dst += n - 1;
        while (n--) {//���ֽڿ���right->left
            *_dst = *_src;
            _dst--, _src--;
        }
    }
    else {
        while (n--) { //���ֽڿ���left->right
            *_dst = *_src;
            _dst++, _src++;
        }
    }
    return dst;
}

void* MyMemmove(void* dst, const void* src, int n)
{
    assert(dst);
    assert(src);//����Ϸ���У��
    char* _dst = (char*)dst;
    char* _src = (char*)src;
    if (_dst > _src && (_dst - _src < n)) {
        _src += n - 1; //ָ�����һ���ֽ�
        _dst += n - 1;
        while (n--) {//���ֽڿ���right->left
            *_dst = *_src;
            _dst--, _src--;
        }
    }
    else {
        while (n--) { //���ֽڿ���left->right
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