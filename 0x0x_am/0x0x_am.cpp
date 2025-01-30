// author: a.voss@fh-aachen.de

// Ihr Name: Vorname Nachname
// Matr.nr.: 1234567

/***************************************************************+****
 *                                                                  *
 * Name und Matr.nr. oben (und ggf. in ident.h) eintragen!          *
 *                                                                  *
 * Die Teilaufgaben sind am Ende dieser Datei formuliert!           *
 * Zur Bearbeitung ist ggf. ein View-Split hilfreich.               *
 *                                                                  *
 * In der Prüfung bekommen Sie ein eigenes Aufgabenblatt.           *
 *                                                                  *
 * Ergänzen Sie bzw. kommentieren Sie den Code entsprechend ein!    *
 *                                                                  *
 ********************************************************************/

#include "../snippets/include.h"

// Datentyp für die Zahlenfolge
typedef vector<int> vector_t;

// A1 ---------------------------------

// a) c) stencil, Ausnahme
vector_t stencil(const vector_t & x, size_t i) {
    size_t size = x.size() - 1;
    if(i > size || size <= 0){
        throw runtime_error("i to big or v is empty");
    }
    if(i == size){
        return vector_t{x[i - 1], x[i]};
    }
    if(i == 0){
        return vector_t{x[i], x[i + 1]};
    }
    return vector_t{x[i - 1], x[i], x[i + 1]};
}

// b) c) avg, Ausnahme
int avg(const vector_t & x, size_t i) {
    vector_t v = stencil(x,i);
    int sum = std::accumulate(v.begin(), v.end(), 0);

    return static_cast<int>(floor((sum / v.size())));
}

void test_A1() {
    cout << "- test A1 ... ";

// d) Einkommentieren
   auto x = vector_t{1,3,10,2,2};
   assert((stencil(x,0) == vector_t{1,3}));
   assert((stencil(x,1) == vector_t{1,3,10}));
   assert((stencil(x,4) == vector_t{2,2}));
   assert(avg(x,1)==4);
   assert(avg(x,2)==5);
   assert(avg(x,4)==2);

    cout << "ok" << endl;
}

// A2 ---------------------------------

class config {
    // a) Attribut name
    string name;
    // b) getter und setter file_name, Ausgabeoperator
    public:
    config() = default;
    config(const string & name) : name{name} {}
    ~config() = default;

    // setter
    config file_name(const string& name) {
        this->name = name;
        return *this;
    }

    // getter 
    const string file_name() {
        return this->name;
    } 

    friend std::ostream& operator<<(std::ostream& os, const config& config) {
        os << config.name;
        return os;
    }
};

void test_A2() {
    cout << "- test A2 ... ";

    string name{"file"};
// c) Einkommentieren
   auto cfg = config().file_name(name);
   assert(cfg.file_name() == name);
   cout << "cfg={'" << cfg << "'} ";
   cout << "ok" << endl;
}

// A3 ---------------------------------

// für i)
typedef function<int(const vector_t &, size_t)> func_t;

// a) Basisklasse mit input, process, output
class IPO {
    public:
    virtual IPO & input() = 0;
    virtual IPO & process() = 0;
    virtual IPO & output() = 0;
    virtual IPO & process(const func_t & f) = 0;
};

// b) ableiten
class IHK : public IPO {
    // d) private Attribute input_data und output_data
    config cfg;
    vector_t input_data{}, output_data{};
    public:
    // c) ctor
    IHK(const config & cfg) : cfg{cfg} {}
    // e) input
    stringstream data{string("1 3 10 2 2")};
    IPO & input() override {
        int number;
        while (data >> number) {
            input_data.push_back(number);
        }
        return *this;
    }
    // f) process (ggf. i)
    IPO & process() override {
        for(int i = 0; i < input_data.size(); i++){
            int y_i = avg(input_data, i);
            output_data.push_back(y_i);
        }
        return *this;
    }

     IPO & process(const func_t & f) override {
        for(int i = 0; i < input_data.size(); i++){

            int y_i;
            if(f == nullptr){
                y_i = avg(input_data, i);
            } else {
                y_i = f(input_data, i);
            }
            output_data.push_back(y_i);
        }
        return *this;
    }

    // g) output
    IPO & output() override {
        cout << "[ ";
        for(auto i : output_data){
            cout << i << " ";
        }
        cout << "]";
        return *this;
    }

};

void test_A3() {
    cout << "- test A3 ... ";

// h) Einkommentieren
    // Ausgabe: [ 2 4 5 4 2 ]
    IHK(config().file_name("file")).input().process().output();
// i) Bonus [ 1 3 10 2 2 ]
    IHK(config().file_name("file")).input().process([](const vector_t & x, size_t i) -> int { return  x[i]; }).output();

    cout << "ok" << endl;
}

// A4 ---------------------------------

// a) generische Klasse
template<typename T> struct clever_ptr {
    // a) Instanz
    T *p;
    // b) vom Heap
    clever_ptr<T>(const T & t) : p{new T{t}} {}
    ~clever_ptr() {
        delete p;
    }
    // c) get
    T& get() const {
        return *p;
    }

    T& operator*() const {
        return *p;
    }
};

void test_A4() {
    cout << "- test A4 ... ";
// d) Einkommentieren
   auto cfg = clever_ptr<config>({});
   IHK(cfg.get().file_name("file")).input().process().output();

// e) *
//    für (e): 
IHK((*cfg).file_name("file")).input().process().output();

    cout << "ok" << endl;
}

int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    test_A1();
    test_A2();
    test_A3();
    test_A4();

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
