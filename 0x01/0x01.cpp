#include <iostream>
using namespace std;


// task 1
// int main() {
//     int n{};
//     char c{};

//     cout << "enter int:" << endl;
//     cin >> n;

//     cout << "enter char:" << endl;
//     cin >> c;

//     bool b{n > 0 && c >= 'A' && c <= 'Z'};

//     cout << "isTrue:" << b << endl;
//     return 0;
// }

// task 2
// int pot_for(int& b, int& n);
// int pot_while(int& b, int& n);

// int main () {

//     int b{};
//     int n{};

//     cout << "enter base:" << endl;
//     cin >> b;
//     cout << "enter exponent:" << endl;
//     cin >> n;

//     cout << "[for] b^n = " << pot_for(b,n) << endl;
//     cout << "[while] b^n = " << pot_while(b,n) << endl;


//     return 0;
// }

// int pot_for(int& b, int& n){
//     int result{1};
//     for(int i = 0; i < n; i++){
//         result *= b;
//     }
//     return result;
// }

// int pot_while(int &b, int& n) {
//     int result{1};
//     int i{0};
//     while(i < n){
//         result *= b;
//         i++;
//     }

//     return result;
// }

// task 3
// int f_i(int& n);
// int f_r(int n);

// int main() {

//     int n{};

//     cout << "enter n:" << endl;

//     cin >> n;

//     cout << "f_i(n) = " << f_i(n) << endl;
//     cout << "f_r(n) = " << f_r(n) << endl;

//     return 0;
// }

// int f_i(int& n){
//     int a{0};
//     int b{1};

//     for(int i = 1; i < n; i++){
//         int tem = b;
//         b = a + b;
//         a = tem;
//     }

//     return b;
// }

// int f_r(int n){
//     if(n <= 2){
//         return 1;
//     } else {
//         return f_r(n-1) + f_r(n-2);
//     }
// }

// task 4
// void print_arr(double arr[], int n);
// int main() {
//     double d_arr[3] {1.0, 2.0};
//     double d2_arr[3];

//     d_arr[2] = d_arr[0] + d_arr[1];

//     for(int i = 0; i < 3;i++){
//         d2_arr[i] = d_arr[i];
//     }

//     cout << "arr 1: ";
//     print_arr(d_arr, 3);
//     cout << "arr 2: ";
//     print_arr(d2_arr, 3);

//     return 0;
// }

// void print_arr(double arr[], int n){
//     for(int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }  
//     cout << endl;
// }

// task 5
// bool isPrim(int &n);
// int main() {
//     int n{};

//     cout << "enter int:" << endl;
//     cin >> n;

//     bool isPrime{isPrim(n)};

//     if(isPrime) {
//         cout << n << " is a prime number!" << endl;
//     } else {
//         cout << n << " is NOT a prime number!" << endl;
//     }

//     return 0;
// }

// bool isPrim(int &n) {
//     for(int i = 2; i < n; i++){
//         if(n % i == 0){
//             return false;
//         }
//     }
//     return true;
// }