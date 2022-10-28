#include <stdio.h>
int main(void)
{
    int num =15;
    float score =3.1415926;
    double s =0.000000123456789;
    printf("num=%d,score=%f,s=%.2f\n",num,score,s);
    printf("num=%o,score=%10f,s=%e\n",num,score,s);
    return 0;
}