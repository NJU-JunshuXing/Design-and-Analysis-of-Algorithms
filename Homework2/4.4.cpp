#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) {
    int tmp = b;
    b = a;
    a = tmp;
}

vector<int> MySort(int A, int B, int C, int D, int E) {
    if (A > B) swap(A, B);
    if (C > D) swap(C, D);
    if (A > C) {
        swap(A, C);
        swap(B, D);
    }
    if (E > C) {
        if (E > D) {  // A C D E
            if (B > D) {
                if (B > E) return {A, C, D, E, B};
                else return {A, C, D, B, E};
            } 
            else {
                if (B < C) return {A, B, C, D, E};
                else return {A, C, B, D, E};
            }
        } 
        else {  // A C E D
            if (B > E) {
                if (B > D) return {A, C, E, D, B};
                else return {A, C, E, B, D};
            } 
            else {
                if (B < C) return {A, B, C, E, D};
                else return {A, C, B, E, D};
            }
        }
        } 
    else {
        if (E < A) {  // E A C D
            if (B > C) {
                if (B > D) return {E, A, C, D, B};
                else return {E, A, C, B, D};
            } 
            else {
                return {E, A, B, C, D};
            }
        } 
        else {  // A E C D
            if (B > C) {
                if (B > D) return {A, E, C, D, B};
                else return {A, E, C, B, D};
            } 
            else {
                if (B < E) return {A, B, E, C, D};
                else return {A, E, B, C, D};
            }
        }
    }
}

int main() {
    vector<int> v = MySort(10, 5, 9, 3, 7);
    for (int i = 0; i <= 4; i++) {
        cout << v[i] << " ";
    }
    return 0;
}