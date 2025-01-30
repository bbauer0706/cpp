#include "../snippets/include.h"

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class window
{
public:
  int id;

  window() = default;
  window(const int &id) : id{id} {}
  window(const window &w) = default;
  virtual ~window() = default;

  void show()
  {
    cout << "called super show" << endl;
  }
  void hide()
  {
    cout << "called super hide" << endl;
  }
  virtual void draw()
  {
    cout << "called super draw" << endl;
  }
};

class button : public window
{
public:
  button() : window() {}
  button(const int &id) : window(id) {}

  void draw() override
  {
    cout << "called button draw" << endl;
  }
};

class checkbox : public window
{
public:
  checkbox() : window() {}
  checkbox(const int &id) : window(id) {}

  void draw() override
  {
    cout << "called checkbox draw" << endl;
  }
};

#include <iostream>
#include <memory>
#include <unordered_map>
#include <stdexcept>

using namespace std;

// Abstrakte Klasse 'matrix'
template <typename T>
class matrix
{
protected:
  size_t dim;

public:
  matrix(size_t dim) : dim(dim) {}
  virtual ~matrix() = default;

  virtual T at(size_t x, size_t y) const = 0;
  virtual void set(size_t x, size_t y, T value) = 0;
  virtual void make_zero() = 0;

  // Setzt die Matrix auf die Einheitsmatrix
  void make_one()
  {
    make_zero();
    for (size_t i = 0; i < dim; ++i)
    {
      set(i, i, 1);
    }
  }

  size_t get_dim() const { return dim; }
};

// Vollständige Matrix, speichert die Werte in einem dynamischen Array
template <typename T>
class full_matrix : public matrix<T>
{
private:
  unique_ptr<T[]> data;

public:
  full_matrix(size_t dim) : matrix<T>(dim)
  {
    data = make_unique<T[]>(dim * dim);
  }

  T at(size_t x, size_t y) const override
  {
    if (x >= this->dim || y >= this->dim)
      throw out_of_range("Index out of range");
    return data[x * this->dim + y];
  }

  void set(size_t x, size_t y, T value) override
  {
    if (x >= this->dim || y >= this->dim)
      throw out_of_range("Index out of range");
    data[x * this->dim + y] = value;
  }

  void make_zero() override
  {
    fill(data.get(), data.get() + this->dim * this->dim, 0);
  }

  // Optionale Methode, um die Matrix auszugeben
  void print() const
  {
    for (size_t i = 0; i < this->dim; ++i)
    {
      for (size_t j = 0; j < this->dim; ++j)
      {
        cout << at(i, j) << " ";
      }
      cout << endl;
    }
  }
};

// Sparse Matrix, speichert die Werte in einer unordered_map
template <typename T>
class sparse_matrix : public matrix<T>
{
private:
  unordered_map<size_t, T> data;

  // Hilfsmethode, um den Schlüssel aus den Indizes zu berechnen
  size_t get_key(size_t x, size_t y) const
  {
    return y * this->dim + x;
  }

public:
  sparse_matrix(size_t dim) : matrix<T>(dim) {}

  T at(size_t x, size_t y) const override
  {
    size_t key = get_key(x, y);
    auto it = data.find(key);
    if (it != data.end())
    {
      return it->second;
    }
    return 0; // Standardwert für nicht gespeicherte Elemente
  }

  void set(size_t x, size_t y, T value) override
  {
    size_t key = get_key(x, y);
    if (value == 0)
    {
      data.erase(key); // Löscht den Eintrag, wenn der Wert 0 ist
    }
    else
    {
      data[key] = value;
    }
  }

  void make_zero() override
  {
    data.clear(); // Löscht alle Einträge
  }

  // Optionale Methode, um die Matrix auszugeben
  void print() const
  {
    for (size_t i = 0; i < this->dim; ++i)
    {
      for (size_t j = 0; j < this->dim; ++j)
      {
        cout << at(i, j) << " ";
      }
      cout << endl;
    }
  }
};

// Testcode für beide Matrix-Klassen
int main()
{
  // Test für die vollständige Matrix
  full_matrix<int> mat1(3);
  mat1.set(0, 0, 1);
  mat1.set(1, 1, 2);
  mat1.set(2, 2, 3);
  cout << "Full Matrix:" << endl;
  mat1.print();
  cout << endl;

  // Test für die sparse Matrix
  sparse_matrix<int> mat2(3);
  mat2.set(0, 0, 1);
  mat2.set(1, 1, 2);
  mat2.set(2, 2, 3);
  cout << "Sparse Matrix:" << endl;
  mat2.print();
  cout << endl;

  // Setzen der Einheitsmatrix
  mat1.make_one();
  cout << "Full Matrix after make_one:" << endl;
  mat1.print();
  cout << endl;

  mat2.make_one();
  cout << "Sparse Matrix after make_one:" << endl;
  mat2.print();
  cout << endl;

  return 0;
}
