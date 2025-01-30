[© 2023, A.Voß, FH Aachen, codebasedlearning.dev](mailto:cpp@codebasedlearning.dev)

# Tasks – Exam 2

---

Die Aufgaben *A1* bis *A4* ergeben insgesamt ein Programm, welches gemäß dem EVA-Prinzip (Eingabe, Verarbeitung, Ausgabe) 
Daten, hier konkret eindimensionale und ganzzahlige Zahlenfolgen, aus einer Quelle einliest, diese für eine weitergehende 
Analyse aufbereitet und so modifiziert wieder ausgibt. Die Analyse selbst ist nicht Teil der Arbeit, sondern nur eine 
exemplarische Datenaufbereitung inkl. Ein- und Ausgabe.

Es sei betont, dass, obwohl *A1* bis *A4* im Idealfall zusammenarbeiten, die Teilaufgaben immer auch Tipps für den Fall 
enthalten, dass eine andere Aufgabe nicht ganz funktioniert. Es können daher die Aufgaben auch unabhängig voneinander 
gelöst werden!

Zeit: 2h, Punkte: 60, Bonuspunkte: 4

**Bitte implementieren Sie alles in einer Datei `exam2.cpp`, auch, wenn diese dadurch etwas groß wird. 
Das vermeidet Fehler bei der Abgabe durch fehlende Dateien.**

---

### A1

Daten einer (endlichen) Messung, z.B. die Geschwindigkeit bei einer Autofahrt vom Start bis zum Ziel, sind 
oftmals verrauscht, besitzen messbedingte Ausreisser oder sind anderweitig gestört. Man versucht nun, die Originaldaten 
durch Daten mit weniger Fehlern, aber möglichst gleichen Eigenschaften, zu ersetzen, sodass eine nachfolgende Analyse 
mit Daten höherer Qualität arbeiten kann.

Stellvertretend für eine einfache Datenaufbereitung soll hier der sogenannte gleitende Mittelwert betrachtet werden, 
der eine endliche Zahlenfolge insgesamt glättet. Das ist eine sehr einfache Methode, aber sie reicht für diese
Aufgabe hier aus.

Beim gleitenden Mittelwert wird ein Wert der Zahlenfolge durch den Mittelwert der Werte in einer kleinen Umgebung ersetzt.
Da man diese Operation für alle Positionen der Zahlenfolge durchführt, 'gleitet' man sozusagen mit einem
Fenster über die Zahlenfolge – daher der Name.

#### Beispiel

In unserem C++-Kontext ist eine endliche Zahlenfolge, genannt `(x)_i`, vom Typ `vektor<int>`, beispielsweise `[1,3,10,2,2]`. 
Das Element an Position `i`, mit `i in [0..4]`, wird hier mit `x_i` bezeichnet, also im Beispiel `x_1=3` bzw. `x_4=2`
(Indizierung startet bei 0). `size-1` bezeichnet den Index des letzten Elements, hier demnach `size-1=4`.

Gleitet man in diesem Beispiel mit einem Fenster der Breite `3` über die Zahlenfolge, ersetzt man im Inneren (!)
immer den aktuellen Wert `x_i` durch das Mittel der Werte `x_(i-1)`, `x_i`, und `x_(i+1)`. 
Das führt wegen `(1+3+10)/3=4`, `(3+10+2)/3=5` und `(10+2+2)/3=4` auf den geglätteten und abgerundeten Vektor `[?,4,5,4,?]`.
Am Rand fallen benachbarte Werte weg, sodass wir hier einfach das Mittel über die vorhandenen Nachbarn nehmen, d.h.
links `(1+3)/2=2` und rechts `(2+2)/2=2`. Der geglättete Vektor ist dann `[2,4,5,4,2]`.

#### Mittelwert

Wir definieren den Mittelwert, genannt `y_i`, inkl. Umgebung durch

- `y_i = 1/3 (x_(i-1) + x_i + x_(i+1))`     im Inneren des Vektors `(x)_i` bzw.
- `y_0 = 1/2 (x_0 + x_1)`  und  `y_(size-1) = 1/2 (x_(size-2) + x_(size-1))`    am Rand, bzw.
- `y_0 = 1/1 x_0`,      falls die Zahlenreihe `(x)_i` nur aus einem Wert besteht.

#### `stencil` und `avg`

Diese Betrachtung motiviert eine Funktion `stencil`, die zu einer Zahlenfolge `(x)_i` und Position `i` 
die Umgebung von `x_i` zurück gibt, d.h. `x_i` und, wenn möglich, die Nachbarn links und rechts.
Ebenso eine Funktion `avg`, die auf dieser Umgebung den Mittelwert berechnet. 

Beispiele: 
- `stencil([1,3,10,2,2],0) = [1,3]`, `avg([1,3,10,2,2],0)=2`
- `stencil([1,3,10,2,2],1) = [1,3,10]`, `avg([1,3,10,2,2],1)=4`
- `stencil([1,3,10,2,2],2) = [3,10,2]`, `avg([1,3,10,2,2],2)=5`
- `stencil([1,3,10,2,2],3) = [10,2,2]`, `avg([1,3,10,2,2],3)=4`
- `stencil([1,3,10,2,2],4) = [2,2]`, `avg([1,3,10,2,2],4)=2`

Im weiteren Verlauf sei `vector_t` definiert als `vector<int>`.

a) [4P] Implementieren Sie die Funktion `vector_t stencil(const vector_t & x, size_t i) `,
die entsprechend obiger Definition die Umgebung von `x_i` in einem Vektor zurückgibt.

b) [4P] Implementieren Sie eine Funktion `int avg(const vector_t & x, size_t i)`,
die den Mittelwert `y_i` der Umgebung von `x_i` berechnet und abgerundet (als `int`) zurückgibt.
Nutzen Sie `stencil` für die Umgebung.
<br>**Tipp:** `std::accumulate`, falls Sie die Algorithmen aus `std` nutzen möchten.

c) [2P] Falls die Zahlenfolge `(x)_i` leer ist oder die Position `i` ausserhalb der gültigen Indizes liegt, 
werfen Sie in (a) und (b) eine Ausnahme vom Typ `runtime_error`.

d) [2P] Kommentieren Sie den Code in `test_A1` ein und überprüfen Sie die Beispiele.
<br>**Zur Erinnerung:** `assert` testet das Argument auf Wahrheit und bricht ggf. ab.

---

### A2

Vervollständigen Sie die Klasse `config`, die der Konfiguration unseres Programmes dient und exemplarisch 
einen Dateinamen zum Einlesen einer Datei mit Zahlenfolgen enthält.

a) [1P] Statten Sie die Klasse `config` mit einem privaten Attribute `name` vom Typ `string` aus.

b) [6P] Implementieren Sie die beiden Funktionen `file_name` (getter und setter) und einen Ausgabeoperator so, dass 
der Code
```
auto cfg = config().file_name(name);
cout << "cfg={'" << cfg << "'} ";
```

c) [1P] in `test_A2` funktioniert. Kommentieren Sie dazu den Code in `test_A2` ein.
<br>**Tipp:** Beachten Sie den Rückgabetyp des Setters.
---

### A3

Ziel dieser Aufgabe ist ein Programm, welches nach dem EVA-Prinzip Daten verarbeitet. Benötigt wird zunächst

a) [6P] eine Basisklasse `IPO` (=EVA) mit drei *rein virtuellen Funktionen* `input`, `process` und `output`. 
Die Funktionen haben zunächst keine Parameter und der Rückgabetyp ist jeweils `IPO &`, 
also eine Referenz auf sich selbst.

Von dieser Basisklasse wird die Klasse `IHK` abgeleitet, genauer:

b) [2P] `IHK` erbt öffentlich von `IPO`.

c) [2P] Der Konstruktor wird mit einem `config`-Objekt aufgerufen und kopiert dieses in ein 
privates Attribut `cfg` gleichen Typs.
<br>**Tipp:** Falls Ihre Klasse `config` aus *A2* nicht existiert oder fehlerhaft ist, übergeben Sie direkt den Dateinamen 
als `string`.

d) [2P] Die Klasse besitzt zwei weitere private Attribute `input_data` und `output_data` vom Typ `vector_t`.

e) [6P] Die Funktion `input` lädt eigentlich Zahlenfolgen aus der Datei, die in `cfg` angegeben ist. 
Um es hier etwas einfacher zu gestalten, nutzen Sie statt eines File-Streams einen fest codierten 
String-Stream
```
stringstream data{string("1,3,10,2,2")};
```
und überführen in der Funktion die Zahlen in den Vektor `input_data`.
<br>**Tipp:** Falls die Überführung fehlerhaft ist, füllen Sie den Vektor `input_data` direkt mit den Werten `1,3,10,2,2`. 
Nutzen Sie `std::stoi(string)` zur Umwandlung eines Strings in einen `int`.

f) [4P] Die Funktion `process` wendet für jeden Index `i` von `input_data` die Funktion `avg` aus *A1* mit den 
Parametern `input_data` und der jeweiligen Position `i` an und füllt so den Vektor `output_data` mit den entsprechenden 
Mittelwerten `y_i`.
<br>**Tipp:** Falls `avg` aus Aufgabe *A1* fehlerhaft ist, füllen Sie `output_data` mit den Werten aus `input_data`.

g) [2P] Die Funktion `output` gibt `output_data` in der Form `[ y0 y1 … y_size-1 ]` aus (genau so).

h) [2P] Kommentieren Sie den Code in `test_A3` ein und überprüfen Sie die Beispiele.

i) [6P] Erweitern Sie das Interface um eine Funktion `process` mit einem Parameter `f` vom Typ `func_t` 
und rufen Sie diese Funktion `f` anstelle von `avg` auf, falls `f` nicht der `nullptr` ist. 
Ergänzen Sie dann den Aufruf von `process` in `test_A3` um einen Lambda-Ausdruck, der der Einfachheit halber 
wieder den Originalwert `x_i` zurückgibt.
<br>**Achtung:** Je nachdem, wann diese Probeklausur bearbeitet wird, sind Funktionszeiger und Lambda-Ausdrücke noch nicht
behandelt worden. In diesem Fall ignorieren Sie diese Teilaufgabe einfach.
<br>**Tipp:** Sie dürfen auch das Interface entsprechend erweitern.

---

### A4

Angenommen, die Konfiguration `config` aus *A2* enthält sehr viele Einstellungen. Dann sollen die Daten 
unter der Verwendung von dynamischem Speicher und 'Smart'-Pointern angelegt werden. 
Leider ist die Klasse `unique_ptr` nach Auskunft von *ChatGPT* buggy (stimmt das? wir wissen es gerade nicht) 
und Sie verwenden daher lieber eine kleine eigene Implementierung namens `clever_ptr`.

a) [2P] Die Klasse `clever_ptr` ist ein Template mit generischem Parameter `T` und enthält einen Zeiger `p` auf 
eine Instanz vom Typ `T` als privates Attribut,

b) [4P] welche im Konstruktor dynamisch vom Heap allokiert und im Destruktor wieder freigegeben wird.

c) [2P] Die Funktion `get` gibt eine Referenz auf die Instanz in `p` zurück.

d) [0P] Kommentieren Sie den Code in `test_A4` ein und überprüfen Sie die Beispiele.

e) [Bonus 4P] Nutzen Sie statt `get` den Dereferenzierungsoperator `*`, siehe `test_A4`.

---

Viel Erfolg!

---

End of `Tasks – Exam 2`
