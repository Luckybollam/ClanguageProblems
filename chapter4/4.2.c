#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]) {
    double val = 0.0, power = 1.0;
    int i = 0, sign, exp_sign = 1, exponent = 0;

    while (isspace(s[i])) {
        i++;
    }

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }

    while (isdigit(s[i])) {
        val = 10.0 * val + (s[i++] - '0');
    }

    if (s[i] == '.') {
        i++;
        while (isdigit(s[i])) {
            val = 10.0 * val + (s[i++] - '0');
            power *= 10.0;
        }
    }

    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        if (s[i] == '-') {
            exp_sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        while (isdigit(s[i])) {
            exponent = 10 * exponent + (s[i++] - '0');
        }
    }

    double result = sign * val / power;
    if (exponent != 0) {
        result *= pow(10, exp_sign * exponent);
    }

    return result;
}

int main() {
    char line[1000];
    double sum = 0.0;


    while (fgets(line, sizeof(line), stdin)) {
        sum += atof(line);
        printf("\t%g\n", sum);
    }

    return 0;
}
