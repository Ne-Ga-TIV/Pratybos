#include <stdlib.h>
#include <stdio.h>
#include <math.h>
long to_binary(int value)
{
    long numb = 0, j = 0;
    while (value)
    {
        numb += value % 2 * pow(10, j);
        value /= 2;
        j++;
    }
    return numb;
}

long binary_to_dec(long value)
{
    int numb = 0, j = 0;
    while (value)
    {
        numb += value % 10 * pow(2, j);
        value /= 10;
        j++;
    }
    return numb;
}
char convert_to_hx(int value)
{
    switch (value)
    {
    case 0: return '0';
    case 1: return '1';
    case 2: return '2';
    case 3: return '3';
    case 4: return '4';
    case 5: return '5';
    case 6: return '6';
    case 7: return '7';
    case 8: return '8';
    case 9: return '9';
    case 10: return 'A';
    case 11: return 'B';
    case 12: return 'C';
    case 13: return 'D';
    case 14: return 'E';
    case 15: return 'F';
    }
}

char* to_hx(long value)
{
    char* numb = malloc(50);
    int  j = 0;
    while (value)
    {
        for(int i = j; i > 0; i--){
            numb[i] = numb[i - 1];
        }
        numb[0] = convert_to_hx(value % 16);
        value /= 16;
        j++;
    }
    return numb;
}
int hx_to_dec(long value)
{
    int numb = 0, j = 0;
    while (value)
    {
        numb += value % 16 * pow(16, j);
        value /= 16;
        j++;
    }
    return numb;
}
long hx_to_binary(long value)
{
    int numb = 0, j = 0, tmp;
    while (value)
    {
        tmp = value % 16;
        while (tmp)
        {
            numb += tmp % 2 * pow(10, j);
            j++, tmp /= 2;
        }  
        value /= 16;
    }
    return numb;
}
char convert_bin_to_hx(int value)
{
    switch (value)
    {
    case 0: return '0';
    case 1: return '1';
    case 10: return '2';
    case 11: return '3';
    case 100: return '4';
    case 101: return '5';
    case 110: return '6';
    case 111: return '7';
    case 1000: return '8';
    case 1001: return '9';
    case 1010: return 'A';
    case 1011: return 'B';
    case 1100: return 'C';
    case 1101: return 'D';
    case 1110: return 'E';
    case 1111: return 'F';
    }
}
char* bin_to_hex(long value)
{
    char *numb = malloc(50);
    int j = 0;
    while (value)
    {
        for(int i = j; i > 0; i--){
            numb[i] = numb[i - 1];
        }

        numb[0] = convert_bin_to_hx(value % 10000);
        j++;
        value /= 10000;
    }
    return numb;
}
int main()
{
    printf("%s\n", bin_to_hex(1010101));
    return 0;
}