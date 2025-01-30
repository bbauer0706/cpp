#include <iostream>
#include <cstring> // Für strlen, strcpy, strcmp

using namespace std;

int main()
{
  // 🔹 1. Deklaration und Initialisierung von C-Strings
  char str1[] = "Hallo";     // Direkt im Array gespeichert
  const char *str2 = "Welt"; // Zeiger auf eine Zeichenkette (nicht veränderbar)

  // 🔹 2. Zugriff auf Zeichen im C-String
  cout << "Erstes Zeichen von str1: " << str1[0] << endl;
  cout << "Letztes Zeichen von str1 (vor \\0): " << str1[4] << endl;

  // 🔹 3. Pointer-Arithmetik: String mit Zeiger durchlaufen
  cout << "Zeichen in str1 (mit Zeiger): ";
  for (char *ptr = str1; *ptr != '\0'; ++ptr)
  {
    cout << *ptr << " ";
  }
  cout << endl;

  // 🔹 4. ASCII-Werte und Adressen von Zeichen ausgeben
  cout << "ASCII-Werte von str1: " << endl;
  for (char *ptr = str1; *ptr != '\0'; ++ptr)
  {
    cout << "Adresse: " << (void *)ptr << " | Zeichen: " << *ptr << " | ASCII: " << (int)(*ptr) << endl;
  }

  // 🔹 5. String modifizieren (Achtung: Nur bei char-Array, nicht bei const char*)
  str1[0] = 'h';
  cout << "Nach Modifikation: " << str1 << endl;

  // 🔹 6. C-String-Funktionen (Vergleichen, Kopieren, Länge bestimmen)
  char str3[20];      // Speicher für Kopie
  strcpy(str3, str1); // Kopiert str1 nach str3
  cout << "Kopie von str1 in str3: " << str3 << endl;

  // Vergleich
  if (strcmp(str1, str3) == 0)
  {
    cout << "str1 und str3 sind gleich." << endl;
  }
  else
  {
    cout << "str1 und str3 sind verschieden." << endl;
  }

  // Länge
  cout << "Länge von str1: " << strlen(str1) << endl;

  // 🔹 7. Eingabe eines C-Strings
  char input[50];
  cout << "Gib einen Text ein: ";
  cin.getline(input, 50); // Sicherere Alternative zu `cin >> input`
  cout << "Eingabe: " << input << endl;

  return 0;
}
