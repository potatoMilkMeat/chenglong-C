//C99.c
#include <stdio.h>
#include <stdint.h>
#include <complex.h>

int main(void)
{
    // C90
    signed int a = -10;
    printf("a=%d\n", a);

    // C99 支持布尔值 但是不支持 宏 _Bool
    // _Bool b = 1; // 不支持 宏 _Bool
    bool b = 1;
    if (b)
        printf("b is true.\n");
    else
        printf("b is false\n");

    // C99 int申明的位置 可以在任何位置
    for (int i = 0; i < 3; i++)
        printf("for 循环 i: %d\n", i);
    
    // 复数 - 实部和虚部
    printf("// 复数 - 实部和虚部 \n");
    double _Complex x = 1.0+2.0 * I;
    double _Complex y = 5.0+4.0 * I;
    printf("x = %f + %fi\n", creal(x), cimag(x));
    printf("y = %f + %fi\n", creal(y), cimag(y));
    x *= y; printf("x = %f + %fi\n", creal(x), cimag(x));
    x = csin(y); printf("x = %f + %fi\n", creal(x), cimag(x));
    // creal() 获得复数的实部
    // cimag() 获得复数的虚部
    // csqrt() 计算复数的平方根
    // csin() 计算复数的sin值
    // 除了这里用到的几个函数之外，gcc 提供的支持复数运算的函数还很多，这里总结如下。
    // 函数名        简介
    // cacos()        反余弦
    // casin()        反正弦
    // catan()        反正切
    // ccos()        余弦
    // csin()        正弦
    // ctan()        正切
    // cacosh()    反双曲余弦
    // casinh()    反双曲正弦
    // catanh()    反双曲正切
    // ccosh()        双曲余弦
    // csinh()        双曲正弦
    // ctanh()        双曲正切
    // cexp()        指数函数
    // clog()        对数函数
    // cpow(x,y)    x 的y 次方
    // csqrt        平方根
    // cabs        复数的模
    // carg        角
    // conj        共轭
    // cproj        投影
    // cimag        取虚部
    // creal        取实部


    return 0;
}