// (C) 2023 A.Voß, a.voss@fh-aachen.de, cpp@codebasedlearning.dev

#include <iostream>
#include <unordered_map>
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

struct address {
    string name;
    string number;
};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    unordered_map<int,address*> map;
    
    map[1] = new address{"Max","112"};
    map[2] = new address{"Mini","110"};
    map[3] = new address{"Jane","911"};
    
    cout << "01|    size map=" << map.size() << endl;
    
    for (auto a:map) {
        cout << "02|      {id:" << a.first 
            << ", name:" << a.second->name 
            << ", number:" << a.second->number << "}" << endl;
    }

    cout << "-----" << endl;

    unordered_map<int,address*>::iterator it{map.begin()};
    while (it!=map.end()) {
        delete it->second;
        // it = map.erase(it);  // C++11
        map.erase(it++);        // < C++11
    }

    // for (auto a:map) {       // all
    //     delete a.second;
    // }
    // map.clear();
    cout << "03|    size map=" << map.size() << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/*

// (C) 2023 A.Voß, a.voss@fh-aachen.de, cpp@codebasedlearning.dev

#include <iostream>
#include <unordered_map>
#include <memory>
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::unique_ptr;
using std::make_unique;

struct address {
    string name;
    string number;
    
    address(const string& name, const string& number)
        : name(name), number(number) {}
};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    unordered_map<int,unique_ptr<address>> map;
    
    map[1] = make_unique<address>("Max","112");
    map[2] = make_unique<address>("Mini","110");
    map[3] = make_unique<address>("Jane","911");

    cout << "01|    size map=" << map.size() << endl;
    
    for (auto& a:map) {
        cout << "02|      {id:" << a.first 
            << ", name:" << a.second->name 
            << ", number:" << a.second->number << "}" << endl;
    }

    cout << "-----" << endl;
    
    map.clear();
    cout << "03|    size map=" << map.size() << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

*/

/*

// (C) 2023 A.Voß, a.voss@fh-aachen.de, cpp@codebasedlearning.dev

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

// Legen Sie eine Struktur 'address' an, die einen Namen und eine Tel.Nr.,
// beides vom Typ 'string', enthält.
struct address {
    std::string tel;
    std::string name;

    address(const std::string &tel, const std::string &name)
            : tel(tel), name(name) {}
};

std::ostream &operator<<(std::ostream &os,
                         const std::unordered_map<int, address *> &map);
std::ostream &
operator<<(std::ostream &os,
           const std::unordered_map<int, std::unique_ptr<address>> &map);

// new, dynamische Strukturen, smart pointer
int main() {
    // Speichern Sie drei fiktive Datensätze jeweils unter einer ID in einer
    // 'unordered_map<int, address*>'. Die 'address'-Sruktur erhalten Sie
    // dynamisch mit 'new' und speichern nur den Zeiger.
    std::unordered_map<int, address *> map = {
            {0, new address{"1234", "Alexander"}},
            {1, new address{"5678", "Bertram"}},
            {2, new address{"9012", "Carl"}}};

    // Geben Sie die komplette Map aus.
    std::cout << map;

    // Erweiterung:
    // Geben Sie die Daten der Map am Ende wieder frei.
    std::unordered_map<int, address *>::iterator it{map.begin()};

    while (it != map.end()) {
        delete it->second;
        it = map.erase(it);
    }

    std::cout << "map size after cleanup: " << map.size() << std::endl;

    // Testen Sie Ihren Code auf Speicherlecks.

    std::unordered_map<int, std::unique_ptr<address>> map2;

    map2[0] = std::make_unique<address>("1234", "Alexander");
    map2[1] = std::make_unique<address>("5678", "Bertram");
    map2[2] = std::make_unique<address>("9012", "Carl");

    std::cout << map2;

    map2.clear();

    std::cout << "map size after cleanup: " << map2.size() << std::endl;
}

std::ostream &operator<<(std::ostream &os,
                         const std::unordered_map<int, address *> &map) {
    for (auto it : map) {
        os << "[" << it.first << "] : "
           << "[" << it.second->name << ", " << it.second->tel << "]" << std::endl;
    }
    return os;
}

std::ostream &
operator<<(std::ostream &os,
           const std::unordered_map<int, std::unique_ptr<address>> &map) {
    for (const auto &it : map) { // (A)
        os << "[" << it.first << "] : "
           << "[" << it.second->name << ", " << it.second->tel << "]" << std::endl;
    }
    return os;
}

*/