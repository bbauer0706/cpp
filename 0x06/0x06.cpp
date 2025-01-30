#include "../snippets/include.h"

// int main()
// {

//   char *str = "hallo";

//   char *ptr = str;

//   while (*ptr != '\0')
//   {
//     cout << "Adress: " << static_cast<void *>(ptr)
//          << " | Char: " << *ptr
//          << " | ASCII: " << static_cast<int>(*ptr) << endl;
//     ptr++;
//   }

//   cout << "Adress: " << static_cast<void *>(ptr)
//        << " | Char: " << *ptr
//        << " | ASCII: " << static_cast<int>(*ptr) << endl;

//   return 0;
// }
// void print_reverse(char *arr[], const int size)
// {
//   for (int i = size - 1; i >= 0; i--)
//   {
//     cout << arr[i] << " ";
//   }
//   cout << endl;
// }

// void reverse_arr(char *arr[], const int size)
// {
//   for (int i = 0; i < size / 2; i++)
//   {
//     swap(arr[i], arr[size - 1 - i]);
//   }
// }

// void reverse_str(char *str)
// {
//   int len = strlen(str);
//   for (int i = 0; i < len / 2; i++)
//   {
//     swap(str[i], str[len - 1 - i]);
//   }
// }

// int main()
// {
//   char w1[] = "Dies";
//   char w2[] = "ist";
//   char w3[] = "ein";
//   char w4[] = "Satz";

//   char *words[] = {w1, w2, w3, w4};
//   // sizeof(words) = anzahl elemente * größe von pointer
//   // sizeof(words[i]) = größe von pointer
//   int size = (sizeof(words) / sizeof(words[0]));
//   print_reverse(words, size);
//   reverse_arr(words, size);
//   for (int i = 0; i < size; i++)
//   {
//     reverse_str(words[i]);
//     cout << words[i] << " ";
//   }
//   cout << endl;
//   return 0;
// }

// char *copy(const char *str)
// {
//   int len = strlen(str) + 1;
//   char *str1 = new char[len];
//   strcpy(str1, str);
//   return str1;
// }

// int main()
// {
//   const char *str = "hallo";
//   auto ptr = copy(str);
//   cout << ptr << endl;
//   delete[] ptr;
//   return 0;
// }

// struct adress
// {
//   string name;
//   string tel_number;
// };

// int main()
// {

//   unordered_map<int, unique_ptr<adress>> map;

//   map[0] = make_unique<adress>(adress{"Peter", "+49 0000 1111 2222"});
//   map[1] = make_unique<adress>(adress{"Solepe", "+49 0001 1111 2222"});
//   map[2] = make_unique<adress>(adress{"August", "+49 0002 1111 2222"});
//   for (const auto &pair : map)
//   {
//     cout << pair.first << ": " << pair.second->name << ": " << pair.second->tel_number << endl;
//   }

//   cout << endl;

//   return 0;
// }

template <typename T>
class linked_list
{
  struct node
  {
    T value;
    unique_ptr<node> next;

    node(T val) : value(val), next(nullptr) {}
  };

  unique_ptr<node> root;
  int count;

public:
  linked_list() : root{nullptr}, count{0} {};
  linked_list(const T value) : count{1}
  {
    root = make_unique<node>(value);
  }
  ~linked_list() = default;

  void add(const T n)
  {
    unique_ptr<node> new_node = make_unique<node>(n);
    if (count == 0)
    {
      root = move(new_node);
    }
    else
    {
      node *current = root.get();
      while (current->next != nullptr)
      {
        current = current->next.get();
      }
      current->next = move(new_node);
    }

    count++;
  }

  void clear()
  {
    root = nullptr;
    count = 0;
  }

  friend ostream &operator<<(ostream &os, const linked_list &list)
  {
    os << "[";
    if (list.root != nullptr)
    {
      node *current = list.root.get();
      while (current->next != nullptr)
      {
        os << current->value << ", ";
        current = current->next.get();
      }
      os << current->value;
    }
    os << "]";
    return os;
  }
};

int main()
{

  linked_list<int> list(10);
  list.add(20);
  list.add(20);
  list.add(30);
  list.add(40);
  cout << list << endl;

  linked_list<string> list2("hallo");
  list2.add("gg");
  list2.add("awa");
  list2.add("egsg");
  list2.add("31231");
  cout << list2 << endl;
  list2.clear();
  cout << list2 << endl;

  return 0;
}