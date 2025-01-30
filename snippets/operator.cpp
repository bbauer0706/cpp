#include <iostream>

class _OPERATOR_ {
private:
    int value;

public:
    // Konstruktor
    _OPERATOR_(int v) : value(v) {}

    // Arithmetische Operatoren
    _OPERATOR_ operator+(const _OPERATOR_& other) const {
        return _OPERATOR_(value + other.value);
    }

    _OPERATOR_ operator-(const _OPERATOR_& other) const {
        return _OPERATOR_(value - other.value);
    }

    _OPERATOR_ operator*(const _OPERATOR_& other) const {
        return _OPERATOR_(value * other.value);
    }

    _OPERATOR_ operator/(const _OPERATOR_& other) const {
        if (other.value != 0) {
            return _OPERATOR_(value / other.value);
        } else {
            std::cerr << "Division durch Null!" << std::endl;
            return _OPERATOR_(0); // Rückgabe eines Fehlerwertes
        }
    }

    // Vergleichsoperatoren
    bool operator==(const _OPERATOR_& other) const {
        return value == other.value;
    }

    bool operator!=(const _OPERATOR_& other) const {
        return value != other.value;
    }

    bool operator<(const _OPERATOR_& other) const {
        return value < other.value;
    }

    bool operator>(const _OPERATOR_& other) const {
        return value > other.value;
    }

    bool operator<=(const _OPERATOR_& other) const {
        return value <= other.value;
    }

    bool operator>=(const _OPERATOR_& other) const {
        return value >= other.value;
    }

    // Zuweisungsoperator
    _OPERATOR_& operator=(const _OPERATOR_& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }

    // Inkrement-/Dekrementoperatoren
    _OPERATOR_& operator++() { // Prä-Inkrement
        ++value;
        return *this;
    }

    _OPERATOR_ operator++(int) { // Post-Inkrement
        _OPERATOR_ temp = *this;
        ++value;
        return temp;
    }

    _OPERATOR_& operator--() { // Prä-Dekrement
        --value;
        return *this;
    }

    _OPERATOR_ operator--(int) { // Post-Dekrement
        _OPERATOR_ temp = *this;
        --value;
        return temp;
    }

    // Eingabe-/Ausgabeoperatoren
    friend std::ostream& operator<<(std::ostream& os, const _OPERATOR_& op) {
        os << op.value;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, _OPERATOR_& op) {
        is >> op.value;
        return is;
    }
};

int main() {
    _OPERATOR_ op1(10), op2(5);

    // Arithmetische Operatoren
    _OPERATOR_ sum = op1 + op2;
    _OPERATOR_ diff = op1 - op2;
    _OPERATOR_ prod = op1 * op2;
    _OPERATOR_ quot = op1 / op2;

    std::cout << "Summe: " << sum << std::endl;
    std::cout << "Differenz: " << diff << std::endl;
    std::cout << "Produkt: " << prod << std::endl;
    std::cout << "Quotient: " << quot << std::endl;

    // Vergleichsoperatoren
    std::cout << "op1 == op2: " << (op1 == op2) << std::endl;
    std::cout << "op1 != op2: " << (op1 != op2) << std::endl;
    std::cout << "op1 < op2: " << (op1 < op2) << std::endl;

    // Zuweisungsoperator
    _OPERATOR_ op3 = op1;
    std::cout << "op3 (nach Zuweisung): " << op3 << std::endl;

    // Inkrement-/Dekrementoperatoren
    std::cout << "op1++: " << op1++ << std::endl;  // Post-Inkrement
    std::cout << "++op1: " << ++op1 << std::endl;  // Prä-Inkrement
    std::cout << "op1--: " << op1-- << std::endl;  // Post-Dekrement
    std::cout << "--op1: " << --op1 << std::endl;  // Prä-Dekrement

    // Eingabeoperator
    _OPERATOR_ op4(0);
    std::cout << "Geben Sie einen Wert für op4 ein: ";
    std::cin >> op4;
    std::cout << "op4: " << op4 << std::endl;

    return 0;
}
