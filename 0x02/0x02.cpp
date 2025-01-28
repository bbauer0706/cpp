#include "../snippets/include.h"

// task 1
// void cut(double &x, double &y); 
// void shift(string &x, string &y, string &z);
// int main() {

//     double xd{4.6};
//     double yd{8.9};

//     string x{"1"};
//     string y{"2"};
//     string z{"3"};


//     cut(xd,yd);
//     shift(x,y,z);

//     cout << xd << " " << yd << endl;
//     cout << x << y << z << endl;
//     return 0;
// }

// void cut(double &x, double &y){
//     x = floor(x);
//     y = floor(y);
// }

// void shift(string &x, string &y, string &z){
//     string tem{x};
//     x = y;
//     y = z;
//     z = tem;
// }


// task 2
// const int dim{3};

// struct polynom 
// {
//     int coeffs[dim];

//     friend ostream& operator<<(ostream& os, const polynom& obj) {
//         os << "f(x) = ";
//         for (int i = dim - 1; i >= 0; --i) {  
//             os << obj.coeffs[i] << "x^" << i;
//             if (i > 0) os << " + "; 
//         }
//         return os;
//     }
// };

// double eval(const polynom& p, const int& x);

// int main() {
//     polynom p{{2, 2, 2}};
//     cout << p << endl;

//     cout << "f(2)=" << eval(p,2) << endl;

//     return 0;
// }

// double eval(const polynom& p, const int& x){
//     double result{};
//     for (int i = dim - 1; i >= 0; --i) {  
//         result += (p.coeffs[i]*pow(x,i));
//     }
//     return result;
// }

// task 3

struct s_stack
{
    int stack[3];
    int next;

    s_stack() : next(0) {}

    int pop() {
        if(next == 0) {
            throw new exception;
        }
            return stack[next--];
    }

    int push(int x){
        if(next == 3){
            throw new exception;
        }
        return stack[next++] = x;
    }
};


int main(){

    s_stack s;
    s.push(3);
    cout << s.stack[0] << endl;
    s.push(3);
    cout << s.stack[0] << endl;
    s.push(3);
    cout << s.stack[0] << endl;
    s.push(3);
    cout << s.stack[0] << endl;



    return 0;
}