#include "../snippets/include.h"

// task 1
// class bruch
// {
//   int nenner;
//   int zaehler;

// public:
//   bruch(const int &zaehler, const int &nenner) : nenner{nenner}, zaehler{zaehler} {}
//   bruch(bruch &b) : nenner{b.nenner}, zaehler{b.zaehler} {}
//   ~bruch() {}

//   int get_nenner()
//   {
//     return this->nenner;
//   }

//   int get_zaehler()
//   {
//     return this->zaehler;
//   }

//   void set_nenner(const int nenner)
//   {
//     this->nenner = nenner;
//   }

//   void set_zaehler(const int zaehler)
//   {
//     this->zaehler = zaehler;
//   }

//   friend ostream &operator<<(ostream &os, const bruch &b)
//   {
//     os << b.zaehler << "/" << b.nenner;
//     return os;
//   }
// };

// int main()
// {
//   bruch b{2, 4};

//   cout << b << endl;
//   return 0;
// }

// task 2
// class punkt
// {
//   double x, y;

// public:
//   punkt() {};
//   punkt(const double &x, const double &y) : x{x}, y{y} {}
//   punkt(const punkt &p) : x{p.x}, y{p.y} {}
//   ~punkt() {}

//   double get_x()
//   {
//     return this->x;
//   }

//   double get_y()
//   {
//     return this->y;
//   }

//   void set_x(const double &x)
//   {
//     this->x = x;
//   }

//   void set_y(const double &y)
//   {
//     this->y = y;
//   }

//   friend ostream &operator<<(ostream &os, const punkt &p)
//   {
//     os << "(" << p.x << "|" << p.y << ")";
//     return os;
//   }
// };

// int main()
// {
//   punkt p{2.9, 3.8};

//   cout << p << endl;
// }

// task 3
// SKIP

// task 4
// const int dim = 3;
// class polynom
// {

//   array<int, dim> coeffs;

// public:
//   polynom() {}
//   polynom(const array<int, dim> &coeffs) : coeffs(coeffs) {};
//   ~polynom() {}

//   const array<int, dim> get_coeffs() const
//   {
//     return this->coeffs;
//   }

//   int at(const int i)
//   {
//     if (i < 0 || i > dim - 1)
//     {
//       throw exception();
//     }
//     else
//     {
//       return coeffs[i];
//     }
//   }

//   friend ostream &operator<<(ostream &os, const polynom &obj)
//   {
//     os << "f(x) = ";
//     for (int i = 0; i < dim; ++i)
//     {
//       os << obj.coeffs[i] << "x^" << dim - 1 - i;
//       if (i != dim - 1)
//         os << " + ";
//     }
//     return os;
//   }
// };

// polynom add(const polynom &p1, const polynom &p2);

// int main()
// {
//   polynom p1{{1, 8, 6}};
//   polynom p2{{2, 3, 4}};

//   cout << "p1: " << p1 << endl;
//   cout << "p2: " << p2 << endl;

//   polynom p3 = add(p1, p2);
//   cout << "p1 + p2 = " << p3 << endl;
// }

// polynom add(const polynom &p1, const polynom &p2)
// {
//   array<int, dim> sum_coeffs{};

//   for (int i = 0; i < dim; ++i)
//   {
//     sum_coeffs[i] = p1.get_coeffs()[i] + p2.get_coeffs()[i];
//   }

//   return polynom{sum_coeffs};
// }