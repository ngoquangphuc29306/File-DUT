#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define faster() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

const int MAX_DEGREE = 100; // Mua lon nhat

struct PolynomialInfo {
    double C[MAX_DEGREE + 1];
    int high_power;
};

typedef PolynomialInfo* POLYNOMIAL;

void zero_polynomial(POLYNOMIAL poly){
	for(int i = 0; i <= MAX_DEGREE; i++){
		poly->C[i] = 0;
	}
	poly->high_power = 0;
}

POLYNOMIAL createPolynomial(){
	POLYNOMIAL poly = new PolynomialInfo();
	zero_polynomial(poly);
	return poly;
}

void initialize_coefs(POLYNOMIAL poly, int high_power, const double coef[]){
	for(int i = 0; i <= MAX_DEGREE; i++){
		poly->C[i] = coef[i];
	}
	poly->high_power = high_power;
}

void add_polynomial(POLYNOMIAL A, POLYNOMIAL B, POLYNOMIAL SUM) {
    int high_power = (A->high_power > B->high_power) ? A->high_power : B->high_power;
    zero_polynomial(SUM);
    for (int i = 0; i <= high_power; i++) {
        SUM->C[i] = A->C[i] + B->C[i];
    }
    SUM->high_power = high_power;
}

void mult_polynomial(POLYNOMIAL A, POLYNOMIAL B, POLYNOMIAL MULT) {
    zero_polynomial(MULT);
    MULT->high_power = A->high_power + B->high_power;
    for (int i = 0; i <= A->high_power; i++) {
        for (int j = 0; j <= B->high_power; j++) {
            MULT->C[i + j] += A->C[i] * B->C[j];
        }
    }
}

void show_polynomial(POLYNOMIAL poly) {
    for (int i = poly->high_power; i >= 0; i--) {
        if (poly->C[i] != 0) {
            if (poly->C[i] == floor(poly->C[i])) { // vi du 7.0 == 7.0 -> 7
            	if(i != poly->high_power) cout << "+ ";
                if (i != 0) cout << (long long)poly->C[i] << "x^" << i << " ";
                else cout << (long long)poly->C[i] << " ";
            } else {
            	if(i != poly->high_power) cout << " + ";
                if (i != 0) cout << poly->C[i] << "x^" << i << " ";
                else cout << poly->C[i] << " ";
            }
        }
    }
    cout << "\n";
}

int main() {
	faster();
    POLYNOMIAL A = createPolynomial();
    POLYNOMIAL B = createPolynomial();
    POLYNOMIAL SUM = createPolynomial();
    POLYNOMIAL MULT = createPolynomial();

    double A_Coef[] = {10.5, 4, 0, 7};
    double B_Coef[] = {7, -4, 5};

    initialize_coefs(A, 3, A_Coef);
    initialize_coefs(B, 2, B_Coef);

    show_polynomial(A);
    show_polynomial(B);

    add_polynomial(A, B, SUM);
    cout << "SUM = ";
    show_polynomial(SUM);

    mult_polynomial(A, B, MULT);
    cout << "MULT = ";
    show_polynomial(MULT);

    delete A;
    delete B;
    delete SUM;
    delete MULT;
    return 0;
}
