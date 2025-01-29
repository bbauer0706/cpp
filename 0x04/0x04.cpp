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
int main()
{
  vector<int> v{1, 2, 3, 4, 5};
  unordered_map<int, string> m{
      {1, "Eins"},
      {2, "Zwei"},
      {3, "Drei"},
      {4, "Vier"},
      {5, "Fuenf"},
  };

  using it_type_v = vector<int>::const_iterator;
  using it_type_m = unordered_map<int, string>::const_iterator;

  auto f_v = find<it_type_v, int>(v.begin(), v.cend(), 2);

  for (auto it = f_v; it < v.cend() && it <= f_v + 3; ++it)
  {
    cout << *it << " ";
  }
  cout << endl;

  auto f_m = m.find(2);

  for (auto it = m.begin(); it != m.cend();)
  {
    if (it->first > 2)
    {
      it = m.erase(it);
    }
    else
    {
      ++it;
    }
  }

  for (auto it = m.begin(); it != m.cend(); ++it)
  {
    cout << it->second << " ";
  }
  cout << endl;

  return 0;
}

// todo: 4) Ashfield, 5) Sparrow Town, 6) Bakeropolis