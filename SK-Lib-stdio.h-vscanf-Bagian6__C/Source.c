#pragma warning(disable:4996)

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <conio.h>

/*
    Source by Microsoft
    Modified For Learn by RK
    I.D.E : VS2022
*/

int call_vscanf_s(char* format, ...) {
    int result;
    va_list arglist;
    va_start(arglist, format);
    result = vscanf_s(format, arglist);
    va_end(arglist);
    return result;
}

int call_vwscanf_s(wchar_t* format, ...) {
    int result;
    va_list arglist;
    va_start(arglist, format);
    result = vwscanf_s(format, arglist);
    va_end(arglist);
    return result;
}

int main(void) {
    int   i, result;
    float fp;
    char  c, s[81];
    wchar_t wc, ws[81];
    result = call_vscanf_s("%d %f %c %C %s %S", &i, &fp, &c, 1, &wc, 1, s, _countof(s), ws, _countof(ws));
    printf("The number of fields input is %d\n", result);
    printf("The contents are: %d %f %c %C %s %S\n", i, fp, c, wc, s, ws);
    result = call_vwscanf_s(L"%d %f %hc %lc %S %ls", &i, &fp, &c, 2, &wc, 1, s, _countof(s), ws, _countof(ws));
    wprintf(L"The number of fields input is %d\n", result);
    wprintf(L"The contents are: %d %f %C %c %hs %s\n", i, fp, c, wc, s, ws);

    _getch();
    return 0;
}