#include <string>

using namespace std;

class Knoten {
	int schluessel;
	Knoten* linkerNachfolger;
	Knoten* rechterNachfolger;
	Knoten* vorgaenger;
	string value;
public:
	Knoten();
	Knoten(int);
	~Knoten();
	int get_key();
	Knoten* get_last();
	Knoten* get_left();
	Knoten* get_right();
	void set_last(Knoten*);
	void set_left(Knoten*);
	void set_right(Knoten*);
	void set_value(int);
};
