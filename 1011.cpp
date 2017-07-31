#include<stdio.h>
#include<math.h>

const int eps = 1e-9;

char bet[] = {'W', 'T', 'L'};
double odds[3][3];
int result[3];
int cmp(double a, double b) {
    if (a - b < eps && a - b > -eps) {
        return 0;
    }
    return a > b ? 1 : -1;
}

int main() {
    for (int i = 0; i < 3; ++i) {
        double max_odd = -eps;
        int index = 0;
        for (int j = 0; j < 3; ++j) {
            scanf("%lf", &odds[i][j]);
            if (cmp(odds[i][j], max_odd) > 0) {
                max_odd = odds[i][j];
                result[i] = j;
            }
        }
    }
    double res = 1.0;
    for (int i = 0; i < 3; ++i){
        res *= odds[i][result[i]];
    }
    res = (res * 0.65 -1) * 2;
    printf("%c %c %c %.2lf\n", bet[result[0]], bet[result[1]], bet[result[2]], res);
    return 0;
}
