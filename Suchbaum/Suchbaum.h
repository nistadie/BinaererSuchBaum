
#include "Knoten.h"


class Suchbaum {
protected:
	Knoten* top; // -------------------------------------------------- Zeiger auf den ersten Knoten im Suchbaum
	int hoehe; // ---------------------------------------------------- Hoehe des Baums
	double anzahl_Knoten; //´----------------------------------------- Anzahl der Knoten im Baum
	int summeKnoten; // ---------------------------------------------- Anzahl Summierung der Knoten
public:
	Suchbaum(); //---------------------------------------------------- Standardkonstruktor
	~Suchbaum(); // -------------------------------------------------- Standarddestruktor
	Knoten* search(int); // ------------------------------------------ Durchsuche den Suchbaum nach einem bestimmten Schluesselknoten
	void insert(int) throw (const char*); // ------------------------- Füge einen neuen Knoten in den Suchbaum ein und stelle die gegebenheit wieder her
	void remove(Knoten*); // ----------------------------------------- Entferne den Knoten mit einem bestimmten Schluesselwert
	Knoten* push(int); // -------------------------------------------- Erstelle einen neuen Speicherbereich einess Knotens und gebe den Zeiger darauf zurueck
	bool check(Knoten*) throw (const char*); // ---------------------- Prüft den binären Suchbaum auf korrektheit
	int durchsucheTeilbaum(Knoten*); // ------------------------------ Zählt die Ebenen im Teilbaum in der Breitensuche
	void gebeUmliegendeKnotenAus(Knoten*); // ------------------------ Ausgabe der Umliegenden Knoten zur Kontrolle!
	void removeByValue(Knoten*,string); // --------------------------- Knoten anhand von Value Inhalten löschen
	Knoten* get_top(); //--------------------------------------------- Gebe den Knoten Zeiger top zurueck
	void height(Knoten*,int); // ------------------------------------- Gebe die höhe des Baums zurueck
	void set_hoehe(); // --------------------------------------------- Setze hoehe um eins hoch
	int get_hoehe(); // ---------------------------------------------- Gibt die hoehe des Baums zurueck
	int get_anzahl_Knoten(); // -------------------------------------- Gibt die Anzahl der Knoten zurueck
	double avgLevel(); // -------------------------------------------- Gibt die Durchschnittsknotenhöhe zurueck
	void set_top(Knoten*);
};