
#include "Knoten.h"


class Suchbaum {
	Knoten* top;
public:
	Suchbaum();
	~Suchbaum();
	Knoten* search(int);
	void insert(int) throw (const char*);
	void remove(int);
	Knoten* push(int);
	void gebeUmliegendeKnotenAus(Knoten*);

};