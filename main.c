#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

unsigned char weights[] = {6, 5, 7, 2, 3, 4, 5, 6, 7};

unsigned int parse_input(char **argv)
{
    unsigned int result = 0;
    unsigned int len = strlen(argv[1]);

    for (unsigned int i = 0; i < len; i++)
    {
        unsigned char d = argv[1][i] - '0';
        if (d > 9)
        {
            printf("input not a number\n");
            return -1;
        }

        result += d * (int)pow((int)10, (int)(len - i - 1));
    }
    return result;
}

void generate_nip(char *result)
{
    unsigned int sum = 0;
    unsigned char digit = 0;
    unsigned int weighed_digit = 0;

    for (int i = 0; i < 9; i++)
    {
        digit = rand() % 10;
        weighed_digit = digit * weights[i];
        sum += weighed_digit;
        result[i] = digit + '0';
    }

    unsigned char checksum = sum % 11;
    if (checksum == 10)
    {
        checksum = 0;
    }
    result[9] = checksum + '0';
    result[10] = '\0';
}

int main(int argc, char **argv)
{
    srand(time(NULL));

    int n = 1;
    if (argc == 2)
    {
        n = parse_input(argv);
        if (n == -1)
        {
            printf("invalid input\n");
            return 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        char result[11];
        generate_nip(result);
        printf("%s\n", result);
    }

    return 0;
}
