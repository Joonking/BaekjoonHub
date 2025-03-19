#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int F[100001] = {0, 1};

int Fibo(int n)
{
    if (n == 0 || n == 1) return F[n];
    if (F[n] != 0) return F[n];
    return F[n] = (Fibo(n - 1) + Fibo(n - 2)) % 1234567;  // 여기서 꼭 모듈러!
}

int solution(int n) {
    return Fibo(n);
}