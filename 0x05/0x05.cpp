#include "../snippets/include.h"

// task 1
// int main()
// {
//   int i{1};
//   float f{6.5};

//   int *ptr_i{&i};
//   float *ptr_f{&f};

//   *ptr_i = 5;
//   *ptr_f = 5.7;

//   int **ptr_ptr_i{&ptr_i};

//   cout << ptr_i << ": " << *ptr_i << endl;

//   cout << ptr_ptr_i << ": " << **ptr_ptr_i << " | " << *ptr_ptr_i << endl;

//   return 0;
// }

// task 2
// void swap_val(double &d1, double &d2);
// void swap_ptr(double **d1, double **d2);

// int main()
// {

//   double d1{1.0};
//   double d2{2.0};
//   double *ptr_d1{&d1};
//   double *ptr_d2{&d2};

//   cout << d1 << " " << d2 << endl;
//   swap_val(d1, d2);
//   cout << d1 << " " << d2 << endl;
//   swap_ptr(&ptr_d1, &ptr_d2);
//   cout << *ptr_d1 << " " << *ptr_d2 << endl;

//   return 0;
// }

// void swap_val(double &d1, double &d2)
// {
//   double temp{d1};
//   d1 = d2;
//   d2 = temp;
// }

// void swap_ptr(double **d1, double **d2)
// {
//   double *temp = *d1;
//   *d1 = *d2;
//   *d2 = temp;
// }

// todo: mcallen spring - speichermanipulation

// int main()
// {
//   int a = 42;
//   int b = 1337;

//   std::cout << "Vorher: a = " << a << ", b = " << b << std::endl;

//   int *p = &a; // Zeiger auf `a`

//   *(p + 1) = 999; // Manipuliert b, indem wir einen Offset nutzen! (Nur wenn b genau daneben liegt)

//   std::cout << "Nachher: a = " << a << ", b = " << b << std::endl;

//   return 0;
// }