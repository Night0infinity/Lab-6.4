#include <iostream>  
#include <iomanip>  
#include <time.h>  
#include <math.h>
using namespace std;

void random(double* mas, const int size, const double min, const double max) {

    for (int i = 0; i < size; i++) {
        mas[i] = min + rand() * (max - min) / RAND_MAX;
    }
}

void wivid(double* mas, const int size) {
    for (int i = 0; i < size; i++)
        cout << setw(6) << mas[i];
    cout << endl;
}

int Minpos(double* mas, const int size, int num) {
    int min = mas[0];
    for (int i = 0; i < size; i++)
        if (mas[i] < min) {
            min = mas[i];
            num = i + 1;
        }

    return num;
}

int Minnum(double* mas, const int size) {
    double min = mas[0];
    for (int i = 0; i < size; i++)
        if (mas[i] < min) {
            min = mas[i];
        }
    return min;
}

double poshuk1min(double* mas, const int size, double minus1)
{
    int num1 = 0;
    for (int i = 0; i < size; i++)
        if (mas[i] < 0) {
            minus1 = mas[i];
            num1 = i;
            break;

        }
    return num1;
}

double poshuk2min(double* mas, const int size, double minus2, double m1)
{
    int num2 = 0;
    for (int i = m1 + 1; i < size; i++)
        if (mas[i] < 0) {
            minus2 = mas[i];
            num2 = i;
            break;
        }
    return num2;
}

double suma(double* mas, int firstminus, int secondminus)
{
    double S = 0;
    for (int i = firstminus + 1.0; i < secondminus; i++)
        S += mas[i];
    return S;
}


void abscent(double* mas, double* secmas, const int size, int& sm) {
    for (int i = 0; i < size; i++) {
        if (abs(mas[i]) < 1) {
            secmas[sm] = mas[i];
            sm++;
        }
    }
}

void abscent2(double* mas, double* thirdmas, const int size, int& tm) {
    for (int i = 0; i < size; i++) {
        if (abs(mas[i]) >= 1.) {
            thirdmas[tm] = mas[i];
            tm++;
        }
    }
}

void abscentcount(double* mas, const int size, int& smm) {
    for (int i = 0; i < size; i++) {
        if (abs(mas[i]) < 1) {
            smm++;
        }
    }
}

void result1(double* mas, double* secmas, double* d, const int size, int smm) {
    int j = 0, l = 0;
    for (int i = 0; i < size; i++) {
        if (i < smm)
            mas[i] = secmas[j++];
        else
            mas[i] = d[l++];
    }
}
int main() {

    cout << fixed; cout.precision(2);
    srand((unsigned)time(NULL));
    int min = -5.0;
    int max = 5.0;
    int n;
    cout << "n = "; cin >> n;
    double* b = new double[n];
    int k = 0;
    int h = 0;
    int np = 0;
    int smm = 0;
    int sm = 0;
    int tm = 0;
    abscentcount(b, n, smm);
    int q = smm;
    double* c = new double[smm];
    double* d = new double[n - smm];
    random(b, n, min, max);
    cout << "Massive :" << endl;
    wivid(b, n);
    cout << endl;
    cout << setw(4) << endl;
    cout << "min position = " << Minpos(b, n, k) << endl;
    cout << "min number = " << Minnum(b, n) << endl;
    cout << setw(4) << endl;
    cout << "first minus = " << poshuk1min(b, n, k) << endl;
    int m1 = poshuk1min(b, n, k);
    cout << "second minus = " << poshuk2min(b, n, h, m1) << endl;
    int m2 = poshuk2min(b, n, k, m1);
    cout << "Suma mish m1 i m2 = " << suma(b, m1, m2) << endl;
    cout << endl;
    abscent(b, c, n, sm);
    abscent2(b, d, n, tm);
    result1(b, c, d, n, sm);
    wivid(b, n);
}

