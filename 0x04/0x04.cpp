#include "../snippets/include.h"

// task 1
// int main()
// {

//   int a[]{2, 3, 5, 7};
//   vector<int> v{2, 3, 5, 7};

//   for (auto i : a)
//   {
//     cout << i << " ";
//   }
//   cout << endl;

//   for (auto i : v)
//   {
//     cout << i << " ";
//   }
//   cout << endl;

//   return 0;
// }

// task 2
// int main()
// {
//   vector<int> v{2, 3, 5, 7};

//   for (auto &i : v)
//   {
//     i *= 2;
//   }

//   using it_type = vector<int>::const_iterator;

//   for (it_type it = v.begin(); it != v.cend(); ++it)
//   {
//     cout << *it << " ";
//   }

//   cout << endl;
//   return 0;
// }

// task 3
// int main()
// {
//   vector<int> v{1, 2, 3, 4, 5};
//   unordered_map<int, string> m{
//       {1, "Eins"},
//       {2, "Zwei"},
//       {3, "Drei"},
//       {4, "Vier"},
//       {5, "Fuenf"},
//   };

//   using it_type_v = vector<int>::const_iterator;
//   using it_type_m = unordered_map<int, string>::const_iterator;

//   auto f_v = find<it_type_v, int>(v.begin(), v.cend(), 2);

//   for (auto it = f_v; it < v.cend() && it <= f_v + 3; ++it)
//   {
//     cout << *it << " ";
//   }
//   cout << endl;

//   auto f_m = m.find(2);

//   for (auto it = m.begin(); it != m.cend();)
//   {
//     if (it->first > 2)
//     {
//       it = m.erase(it);
//     }
//     else
//     {
//       ++it;
//     }
//   }

//   for (auto it = m.begin(); it != m.cend(); ++it)
//   {
//     cout << it->second << " ";
//   }
//   cout << endl;

//   return 0;
// }

// task 4
// struct buch
// {
//   string author;
//   string title;

//   friend ostream &operator<<(ostream &os, const buch &b)
//   {
//     os << "author: " << b.author << ", title: " << b.title << endl;
//     return os;
//   }
// };

// typedef unordered_map<string, buch> katalog_t;

// int main()
// {
//   katalog_t katalog;

//   katalog["44245381X"] = {"Walter Moers", "Die 13 1 / 2 Leben des Käpt'n Blaubär"};
//   katalog["44244381X"] = {"Peter Moers", "Die 14 1 / 2 Leben des Käpt'n Blaubär"};
//   katalog["44243426X"] = {"Gustav Moers", "Die 15 1 / 2 Leben des..."};

//   for (const auto &k_entry : katalog)
//   {
//     if (k_entry.second.title.size() > 30)
//     {
//       cout << k_entry.second;
//     }
//   }

//   return 0;
// }

// task 5
// template <typename T>
// class bruch
// {
//   T nenner;
//   T zaehler;

// public:
//   bruch(const T &zaehler, const T &nenner) : nenner{nenner}, zaehler{zaehler} {}
//   bruch(bruch &b) : nenner{b.nenner}, zaehler{b.zaehler} {}
//   ~bruch() {}

//   T get_nenner()
//   {
//     return this->nenner;
//   }

//   T get_zaehler()
//   {
//     return this->zaehler;
//   }

//   void set_nenner(const T nenner)
//   {
//     this->nenner = nenner;
//   }

//   void set_zaehler(const T zaehler)
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

//   bruch<int> b{8, 20};
//   bruch<string> b2{"oben", "unten"};

//   cout << b << endl;
//   cout << b2 << endl;
//   return 0;
// }

// task 6
// template <typename T>
// class punkt
// {
//   T x, y;

// public:
//   punkt() {};
//   punkt(const T &x, const T &y) : x{x}, y{y} {}
//   punkt(const punkt &p) : x{p.x}, y{p.y} {}
//   ~punkt() {}

//   T get_x()
//   {
//     return this->x;
//   }

//   T get_y()
//   {
//     return this->y;
//   }

//   void set_x(const T &x)
//   {
//     this->x = x;
//   }

//   void set_y(const T &y)
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
//   punkt<int> int_p{1, 2};
//   punkt<string> string_p{"x", "y"};
//   punkt<double> double_p{1.9, 2.3};

//   cout << int_p << endl
//        << string_p << endl
//        << double_p << endl;

//   return 0;
// }