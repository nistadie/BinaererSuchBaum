#include <string>

using namespace std;

class Knoten {
	int schluessel; // ----------------------------------------------- Schluesselwert, wird beim Konstruktor übergeben
	Knoten* linkerNachfolger; // ------------------------------------- Zeiger auf den linken NachfolgerKnoten
	Knoten* rechterNachfolger; // ------------------------------------ Zeiger auf den rechten NachfolgerKnoten
	Knoten* vorgaenger; // ------------------------------------------- Zeiger auf den vorgängerKnoten
	string value; // ------------------------------------------------- Inhalt des Knotens
public:
	Knoten(); // ----------------------------------------------------- Standardkonstruktor
	Knoten(int); // -------------------------------------------------- Konstruktor mit Parameter (Schluessel)
	~Knoten(); // ---------------------------------------------------- Standarddestruktor
	int get_key(); // ------------------------------------------------ Gebe den Schluessel des Knotens zurueck
	Knoten* get_last(); // ------------------------------------------- Gebe die Adresse des VorgaengerKnotens zurueck
	Knoten* get_left(); // ------------------------------------------- Gebe die Adresse des linken Nachfolgerknotens zurueck
	Knoten* get_right(); // ------------------------------------------ Gebe die Adrese des rechten Nachfolger´knotens zurueck
	void set_last(Knoten*); // --------------------------------------- Setze die Adresse des Vorgaengerknotens
	void set_left(Knoten*); // --------------------------------------- Setze die Adresse des linken Nachfolgerknotens
	void set_right(Knoten*); // -------------------------------------- Setze die Adresse des rechten Nachfolgerknotens
	void set_value(int); // ------------------------------------------ Setze den Inhalt des Knotens
	string get_value(); // ------------------------------------------- Gebe den Value Inhalt zurueck
};
