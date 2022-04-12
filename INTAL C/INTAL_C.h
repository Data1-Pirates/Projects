#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *initializeINTAL()
{
    char *ptr = (char *)malloc(1001 * sizeof(char));
    for (int i = 0; i < 1000; i++)
        ptr[i] = '0';
    ptr[1000] = '\0';
    return ptr;
}

char *rmv_zro(char *a)
{
    int n = strlen(a);
    char *ans = (char *)malloc((n + 1) * sizeof(char));
    int i = 0;
    while (i < n - 1 && a[i] == '0')
        i++;
    for (int j = i; j < n; j++)
        ans[j - i] = a[j];
    ans[n - i] = '\0';
    return ans;
}

int INTAL_compare(char *a, char *b)
{
    int n1 = strlen(a);
    int n2 = strlen(b);
    if (n1 > n2)
        return 1;
    if (n1 < n2)
        return -1;
    for (int i = 0; i < n1; i++)
    {
        if (a[i] < b[i])
            return -1;
        if (a[i] > b[i])
            return 1;
    }
    return 0;
}
int compare_INTAL(char *a, char *b)
{
    int n1 = strlen(a);
    int n2 = strlen(b);
    if (n1 > 1000 || n2 > 1000)
    {
        printf("Overflow\n");
        exit(1);
    }
    if (a[0] == '-' && b[0] == '-')
    {
        char *a1 = (char *)malloc(n1 * sizeof(char));
        char *b1 = (char *)malloc(n2 * sizeof(char));
        for (int i = 0; i < n1 - 1; i++)
            a1[i] = a[i + 1];
        for (int i = 0; i < n2 - 1; i++)
            b1[i] = b[i + 1];
        a1[n1 - 1] = '\0';
        b1[n2 - 1] = '\0';
        return -INTAL_compare(a1, b1);
    }
    if (a[0] == '-')
    {
        return -1;
    }
    if (b[0] == '-')
    {
        return 1;
    }
    return INTAL_compare(a, b);
}

char *subINTAL(char *a, char *b);
char *INTAL_add(char *a, char *b)
{
    int n1 = strlen(a);
    int n2 = strlen(b);
    int n = (n1 > n2) ? n1 : n2;
    char *ans = (char *)malloc((n + 1) * sizeof(char));
    ans[n] = '\0';
    int i = n1 - 1;
    int j = n2 - 1;
    int k = 1, sum, carry = 0;
    while (i >= 0 && j >= 0)
    {
        sum = a[i] - '0' + b[j] - '0' + carry;
        carry = sum / 10;
        ans[n - k] = (sum % 10) + '0';
        i--;
        j--;
        k++;
    }
    while (i >= 0)
    {
        sum = a[i] - '0' + carry;
        carry = sum / 10;
        ans[n - k] = (sum % 10) + '0';
        i--;
        k++;
    }
    while (j >= 0)
    {
        sum = b[j] - '0' + carry;
        carry = sum / 10;
        ans[n - k] = (sum % 10) + '0';
        j--;
        k++;
    }
    if (carry)
    {
        char *ans1 = (char *)malloc((n + 2) * sizeof(char));
        ans1[0] = carry + '0';
        for (int i = 0; i < n; i++)
            ans1[i + 1] = ans[i];
        ans1[n + 1] = '\0';
        return ans1;
    }
    return ans;
}
char *add_INTAL(char *a, char *b)
{
    int n1 = strlen(a);
    int n2 = strlen(b);
    int n = (n1 > n2) ? n1 : n2;
    if (n1 > 1000 || n2 > 1000)
    {
        printf("Overflow\n");
        exit(1);
    }
    char *ans = (char *)malloc((n + 2) * sizeof(char));
    if (a[0] == '-' && b[0] == '-')
    {
        char *a1 = (char *)malloc(n1 * sizeof(char));
        char *b1 = (char *)malloc(n2 * sizeof(char));
        for (int i = 0; i < n1 - 1; i++)
            a1[i] = a[i + 1];
        for (int i = 0; i < n2 - 1; i++)
            b1[i] = b[i + 1];
        a1[n1 - 1] = '\0';
        b1[n2 - 1] = '\0';
        char *ans1 = INTAL_add(a1, b1);
        int x = strlen(ans1);
        ans[0] = '-';
        for (int i = 1; i <= x; i++)
            ans[i] = ans1[i - 1];
        ans[x + 1] = '\0';
        return ans;
    }
    if (a[0] == '-')
    {
        char *a1 = (char *)malloc(n1 * sizeof(char));
        for (int i = 0; i < n1 - 1; i++)
            a1[i] = a[i + 1];
        a1[n1 - 1] = '\0';
        strcpy(ans, subINTAL(b, a1));
        return ans;
    }
    if (b[0] == '-')
    {
        char *b1 = (char *)malloc(n2 * sizeof(char));
        for (int i = 0; i < n2 - 1; i++)
            b1[i] = b[i + 1];
        b1[n2 - 1] = '\0';
        strcpy(ans, subINTAL(a, b1));
        return ans;
    }
    return INTAL_add(a, b);
}

char *INTAL_sub(char *a, char *b)
{
    int n1 = strlen(a), n2 = strlen(b);
    char *ans = (char *)malloc((n1 + 1) * sizeof(char));
    char *a_cpy = (char *)malloc((n1 + 1) * sizeof(char));
    ans[n1] = '\0';
    a_cpy = strcpy(a_cpy, a);
    a_cpy[n1] = '\0';
    int i = n1 - 1, j = n2 - 1;
    while (i >= 0 && j >= 0)
    {
        if (a_cpy[i] >= b[j])
        {
            ans[i] = a_cpy[i] - b[j] + '0';
        }
        else
        {
            int a1 = a_cpy[i] - b[j] + 10;
            ans[i] = a1 + '0';
            int k = i - 1;
            while (k >= 0 && a_cpy[k] == '0')
            {
                a_cpy[k] = '9';
                k--;
            }
            a_cpy[k]--;
        }
        i--;
        j--;
    }
    while (i >= 0)
    {
        ans[i] = a_cpy[i];
        i--;
    }
    ans = rmv_zro(ans);
    return ans;
}
char *subINTAL(char *a, char *b)
{
    if (compare_INTAL(a, b) == 0)
    {
        char *ans = "0";
        return ans;
    }
    if (compare_INTAL(a, b) == -1)
    {
        char *ans1 = INTAL_sub(b, a);
        int n = strlen(ans1);
        char *ans = (char *)malloc((n + 2) * sizeof(char));
        ans[0] = '-';
        for (int i = 1; i <= n; i++)
            ans[i] = ans1[i - 1];
        ans[n + 1] = '\0';
        return ans;
    }
    return INTAL_sub(a, b);
}
char *sub_INTAL(char *a, char *b)
{
    int n1 = strlen(a);
    int n2 = strlen(b);
    if (n1 > 1000 || n2 > 1000)
    {
        printf("Overflow\n");
        exit(1);
    }
    int n = (n1 > n2) ? n1 : n2;
    char *ans = (char *)malloc((n + 2) * sizeof(char));
    if (a[0] == '-' && b[0] == '-')
    {
        char *a1 = (char *)malloc(n1 * sizeof(char));
        char *b1 = (char *)malloc(n2 * sizeof(char));
        for (int i = 0; i < n1 - 1; i++)
            a1[i] = a[i + 1];
        for (int i = 0; i < n2 - 1; i++)
            b1[i] = b[i + 1];
        a1[n1 - 1] = '\0';
        b1[n2 - 1] = '\0';
        char *ans = subINTAL(b1, a1);
        return ans;
    }
    if (a[0] == '-')
    {
        char *b1 = (char *)malloc((n2 + 2) * sizeof(char));
        b1[0] = '-';
        for (int i = 1; i <= n2; i++)
            b1[i] = b[i - 1];
        b1[n2 + 1] = '\0';
        return add_INTAL(a, b1);
    }
    if (b[0] == '-')
    {
        char *b1 = (char *)malloc(n2 * sizeof(char));
        for (int i = 0; i < n2 - 1; i++)
            b1[i] = b[i + 1];
        b1[n2 - 1] = '\0';
        return add_INTAL(a, b1);
    }
    return subINTAL(a, b);
}

char *INTAL_mul(char *a, char *b)
{
    int n1 = strlen(a);
    int n2 = strlen(b);
    char *ans = (char *)malloc((n1 + n2 + 1) * sizeof(char));
    for (int i = 0; i < (n1 + n2); i++)
        ans[i] = '0';
    ans[n1 + n2] = '\0';
    int k = 1;
    for (int i = n2 - 1; i >= 0; i--)
    {
        int sum = 0, carry = 0;
        int ptr = n1 + n2 - k;
        for (int j = n1 - 1; j >= 0; j--)
        {
            sum = (a[j] - '0') * (b[i] - '0') + carry + ans[ptr] - '0';
            ans[ptr] = sum % 10 + '0';
            carry = sum / 10;
            ptr--;
        }
        if (carry)
            ans[ptr] = ans[ptr] + carry;
        k++;
    }
    ans = rmv_zro(ans);
    return ans;
}
char *mulINTAL(char *a, char *b)
{
    if (a == "0" || b == "0")
    {
        char *ans = "0";
        return ans;
    }
    if (a == "1")
        return b;
    if (b == "1")
        return a;
    if (compare_INTAL(a, b) == -1)
        return INTAL_mul(b, a);
    return INTAL_mul(a, b);
}
char *mul_INTAL(char *a, char *b)
{
    int n1 = strlen(a);
    int n2 = strlen(b);
    if ((n1 + n2) > 1000)
    {
        printf("Overflow\n");
        exit(1);
    }
    if (a[0] == '-' && b[0] == '-')
    {
        char *a1 = (char *)malloc(n1 * sizeof(char));
        char *b1 = (char *)malloc(n2 * sizeof(char));
        for (int i = 0; i < n1 - 1; i++)
            a1[i] = a[i + 1];
        for (int i = 0; i < n2 - 1; i++)
            b1[i] = b[i + 1];
        a1[n1 - 1] = '\0';
        b1[n2 - 1] = '\0';
        return mulINTAL(a1, b1);
    }
    if (a[0] == '-')
    {
        char *a1 = (char *)malloc(n1 * sizeof(char));
        for (int i = 0; i < n1 - 1; i++)
            a1[i] = a[i + 1];
        a1[n1 - 1] = '\0';
        char *ans1 = mulINTAL(a1, b);
        int n = strlen(ans1);
        char *ans = (char *)malloc((n + 2) * sizeof(char));
        ans[0] = '-';
        for (int i = 1; i <= n; i++)
            ans[i] = ans1[i - 1];
        ans[n + 1] = '\0';
        return ans;
    }
    if (b[0] == '-')
    {
        char *b1 = (char *)malloc(n2 * sizeof(char));
        for (int i = 0; i < n2 - 1; i++)
            b1[i] = b[i + 1];
        b1[n2 - 1] = '\0';
        char *ans1 = mulINTAL(a, b1);
        int n = strlen(ans1);
        char *ans = (char *)malloc((n + 2) * sizeof(char));
        ans[0] = '-';
        for (int i = 1; i <= n; i++)
            ans[i] = ans1[i - 1];
        ans[n + 1] = '\0';
        return ans;
    }
    return mulINTAL(a, b);
}

char *Fibonacci_INTAL(unsigned int n)
{
    char *ans, *prv1, *prv2;
    if (n == 0)
    {
        ans = "0";
        return ans;
    }
    if (n == 1)
    {
        ans = "1";
        return ans;
    }
    prv1 = "1";
    prv2 = "0";
    for (int i = 2; i <= n; i++)
    {
        ans = add_INTAL(prv1, prv2);
        prv2 = prv1;
        prv1 = ans;
    }
    // free(prv1);
    free(prv2);
    return ans;
}

char *Factorial_INTAL(unsigned int n)
{
    char *ans, *prv1, *one;
    if (n == 0)
    {
        ans = "1";
        return ans;
    }
    if (n == 1)
    {
        ans = "1";
        return ans;
    }
    ans = "1";
    prv1 = "2";
    one = "1";
    for (int i = 2; i <= n; i++)
    {
        ans = mul_INTAL(ans, prv1);
        prv1 = add_INTAL(prv1, one);
    }
    return ans;
}
