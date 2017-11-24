
#include "Knoten.h"


class Suchbaum {
	Knoten* top; // -------------------------------------------------- Zeiger auf den ersten Knoten im Suchbaum
public:
	Suchbaum(); //---------------------------------------------------- Standardkonstruktor
	~Suchbaum(); // -------------------------------------------------- Standarddestruktor
	Knoten* search(int); // ------------------------------------------ Durchsuche den Suchbaum nach einem bestimmten Schluesselknoten
	void insert(int) throw (const char*); // ------------------------- Füge einen neuen Knoten in den Suchbaum ein und stelle die gegebenheit wieder her
	void remove(int); // --------------------------------------------- Entferne den Knoten mit einem bestimmten Schluesselwert
	Knoten* push(int); // -------------------------------------------- Erstelle einen neuen Speicherbereich einess Knotens und gebe den Zeiger darauf zurueck
	void gebeUmliegendeKnotenAus(Knoten*); // ------------------------ Ausgabe der Umliegenden Knoten zur Kontrolle!

};