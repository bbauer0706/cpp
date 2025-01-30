#include "../snippets/include.h"

// task 2
const size_t dim = 3;
template <typename T>
class fastverctor
{
  array<T, dim> v_;

public:
  fastverctor(const array<T, dim> &v) : v_{v} {}
  fastverctor(const fastverctor &f) = default;
  ~fastverctor() = default;

  fastverctor &operator=(const T &n)
  {
    // for (auto &n_ : this->v_)
    // {
    //   n_ = n;
    // }
    v_.fill(n);
    return *this;
  }

  fastverctor operator+(const fastverctor &v2)
  {
    fastverctor result = *this;
    for (auto i = 0; i < dim; i++)
    {
      result.v_[i] += v2.v_[i];
    }

    return result;
  }

  T &operator[](size_t index)
  {
    if (index >= dim)
      throw out_of_range("Index out of range");
    return v_[index];
  }

  friend ostream &operator<<(ostream &os, const fastverctor &v)
  {
    os << "[";
    for (auto n = 0; n < v.v_.size(); n++)
    {
      os << v.v_[n];
      if (n != v.v_.size() - 1)
      {
        os << ", ";
      }
    }
    os << "]";
    return os;
  }
};

int main()
{
  fastverctor<int> v({1, 2, 3});
  fastverctor<int> v1({1, 2, 3});
  fastverctor<int> v2({1, 2, 3});

  cout << v << endl;

  v = 4;
  cout << v << endl;

  v = v + v1;
  cout << v << endl;

  return 0;
}