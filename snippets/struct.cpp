#include <iostream>
#include <string>
#include <array>

struct _STRUCT_
{
  // Data members
  int intValue;
  double doubleValue;
  std::string stringValue;
  std::array<int, 5> intArray; // Array member variable (fixed size of 5)

  // Default constructor
  _STRUCT_() : intValue(0), doubleValue(0.0), stringValue(""), intArray({}) {}

  // Parameterized constructor
  _STRUCT_(int intVal, double doubleVal, const std::string &strVal, const std::array<int, 5> &arr)
      : intValue(intVal), doubleValue(doubleVal), stringValue(strVal), intArray(arr) {}

  // Copy constructor
  _STRUCT_(const _STRUCT_ &other)
      : intValue(other.intValue), doubleValue(other.doubleValue), stringValue(other.stringValue), intArray(other.intArray) {}

  // Destructor
  ~_STRUCT_()
  {
    // Cleanup code if needed
  }

  // Assignment operator
  _STRUCT_ &operator=(const _STRUCT_ &other)
  {
    if (this != &other)
    {
      intValue = other.intValue;
      doubleValue = other.doubleValue;
      stringValue = other.stringValue;
      intArray = other.intArray;
    }
    return *this;
  }

  // Move constructor
  _STRUCT_(_STRUCT_ &&other) noexcept
      : intValue(std::move(other.intValue)), doubleValue(std::move(other.doubleValue)),
        stringValue(std::move(other.stringValue)), intArray(std::move(other.intArray)) {}

  // Move assignment operator
  _STRUCT_ &operator=(_STRUCT_ &&other) noexcept
  {
    if (this != &other)
    {
      intValue = std::move(other.intValue);
      doubleValue = std::move(other.doubleValue);
      stringValue = std::move(other.stringValue);
      intArray = std::move(other.intArray);
    }
    return *this;
  }

  // Getter for intValue
  int getIntValue() const
  {
    return intValue;
  }

  // Setter for intValue
  void setIntValue(int value)
  {
    intValue = value;
  }

  // Getter for doubleValue
  double getDoubleValue() const
  {
    return doubleValue;
  }

  // Setter for doubleValue
  void setDoubleValue(double value)
  {
    doubleValue = value;
  }

  // Getter for stringValue
  std::string getStringValue() const
  {
    return stringValue;
  }

  // Setter for stringValue
  void setStringValue(const std::string &value)
  {
    stringValue = value;
  }

  // Getter for intArray
  std::array<int, 5> getIntArray() const
  {
    return intArray;
  }

  // Setter for intArray
  void setIntArray(const std::array<int, 5> &arr)
  {
    intArray = arr;
  }

  // Utility function to display all values
  void display() const
  {
    std::cout << "intValue: " << intValue << ", doubleValue: " << doubleValue
              << ", stringValue: " << stringValue << std::endl;
    std::cout << "intArray: ";
    for (const auto &elem : intArray)
    {
      std::cout << elem << " ";
    }
    std::cout << std::endl;
  }

  // Comparison operator
  bool operator==(const _STRUCT_ &other) const
  {
    return intValue == other.intValue && doubleValue == other.doubleValue &&
           stringValue == other.stringValue && intArray == other.intArray;
  }

  // Inequality operator
  bool operator!=(const _STRUCT_ &other) const
  {
    return !(*this == other);
  }

  // Overload the stream insertion operator
  friend std::ostream &operator<<(std::ostream &os, const _STRUCT_ &obj)
  {
    os << "intValue: " << obj.intValue << ", doubleValue: " << obj.doubleValue
       << ", stringValue: " << obj.stringValue << ", intArray: ";
    for (const auto &elem : obj.intArray)
    {
      os << elem << " ";
    }
    return os;
  }

  // Overload the stream extraction operator
  friend std::istream &operator>>(std::istream &is, _STRUCT_ &obj)
  {
    is >> obj.intValue >> obj.doubleValue >> obj.stringValue;
    for (auto &elem : obj.intArray)
    {
      is >> elem;
    }
    return is;
  }
};