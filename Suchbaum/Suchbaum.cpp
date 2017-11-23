
#include "Suchbaum.h"
#include <iostream>

Suchbaum::Suchbaum() {
	top = NULL;
}

Suchbaum::~Suchbaum() {

}

void Suchbaum::insert(int key) throw (const char*) {

	if (top == NULL) {
		top = push(key);
	}
	else {
		Knoten* akt_Knoten = top;
		while (akt_Knoten != NULL) {
			if (key < akt_Knoten->get_key()) {
				if (akt_Knoten->get_left() == NULL) {
					Knoten* temp = this->push(key);
					temp->set_last(akt_Knoten);
					akt_Knoten->set_left(temp);
					return;
				}
				else {akt_Knoten = akt_Knoten->get_left();}
			}
			else {
				if (akt_Knoten->get_right() == NULL){
					Knoten* temp = this->push(key);
					temp->set_last(akt_Knoten);
					akt_Knoten->set_right(temp);
					return;
				}
				else {akt_Knoten = akt_Knoten->get_right();}
			}
		}
	}
}


//NOCH EINFÜGEN : WENN DER ZU ENTFERNENDE KNOTEN DER WURZELKNOTEN IST!!!!!!
void Suchbaum::remove(int key) {
	Knoten* element = search(key);
	Knoten* voriger = element->get_last();
	// Erster Fall
	if (element->get_left() == NULL && element->get_right() == NULL) {
		if (voriger->get_left() == element) {
			voriger->set_left(NULL);
		}
		else { voriger->set_right(NULL); }
	}
	//Zweiter Fall - ElternKnoten hat linken Nachfolger
	else if (voriger->get_left() != NULL && voriger->get_right() == NULL) {
		voriger->set_left(NULL);
	}
	//Zweiter Fall - ElternKnoten hat rechten Nachfolger
	else if (voriger->get_left() == NULL && voriger->get_right() != NULL) {
		voriger->set_right(NULL);
	}
	//Dritter Fall - Knoten von ganz rechts wird genommen um die Lücke zu füllen
	else {
		Knoten* akt_Knoten = element;
		while (akt_Knoten->get_right() != NULL) {
			akt_Knoten = akt_Knoten->get_right();
			//Wenn der letzte Knoten auf der rechten Seite gefunden wurde

			// NEUER KNOTEN = Knoten der von unten rechts im TeilBaum auf die neue Stelle gesetzt wird
			// ALTER KNOTEN = Stelle des Knoten , der gelöscht wird

			if (akt_Knoten->get_right() == NULL) {
				//Falls der letzte Knoten gefunden wurde jedoch noch ein Blatt enthält!!
				if (akt_Knoten->get_left() != NULL) {
					akt_Knoten->get_last()->set_right(akt_Knoten->get_left()); // -- NEUER KNOTEN | VORIGER ZU KINDERKNOTEN | SETZE LINKEN KINDERKNOTEN
				}

				akt_Knoten->set_last(voriger); // -- NEUER KNOTEN | VORIGER | SETZE VORIGEN AUF NEUEN KNOTEN

				//Zeiger vom Vorgängerknoten wird entfernt
				if (voriger->get_left() == element) {
					voriger->set_left(akt_Knoten); // -- ALTER KNOTEN | ELTERNKNOTEN ZU ALTER KNOTEN | SETZE LINKEN KINDERKNOTEN
				}
				else { voriger->set_right(akt_Knoten); } // -- ALTER KNOTEN | ELTERNKNOTEN ZU ALTER KNOTEN | SETZE RECHTEN KINDERKNOTEN
				//NachfolgerKnoten bekommen einen neuen vorigen Zeiger
				if (element->get_left() != NULL) {
					element->get_left()->set_last(akt_Knoten);  // -- ALTER KNOTEN | LINKER KINDERKNOTEN ZU VORIGEM | SETZE NEUEN KNOTEN
					akt_Knoten->set_left(element->get_left());  // -- NEUER KNOTEN | LINKER KINDERKNOTEN | SETZE LINKEN KINDERKNOTEN
				}
				if (element->get_right() != akt_Knoten) {
					element->get_right()->set_last(akt_Knoten); // -- ALTER KNOTEN | RECHTER KINDERKNOTEN | SETZE NEUEN KNOTEN
					akt_Knoten->set_right(element->get_right()); // -- NEUER KNOTEN | RECHTER KINDERKNOTEN | SETZE AUF KINDERKNOTEN
				}

			}
		}
	}
	delete element;
}

Knoten* Suchbaum::search(int key) {
	Knoten* akt_Knoten = top;
	while (akt_Knoten != NULL) {
		if (key < akt_Knoten->get_key()) {
			akt_Knoten = akt_Knoten->get_left();
		}
		else if (key == akt_Knoten->get_key()) {
			return akt_Knoten;
		}
		else {
			akt_Knoten = akt_Knoten->get_right();
		}
	}
}

Knoten* Suchbaum::push(int key) {
	Knoten* temp = new Knoten(key);
	temp->set_value(key);
	return temp;
}

void Suchbaum::gebeUmliegendeKnotenAus(Knoten* element) {

	cout << "\nDer aktuelle Knoten hat den Schluesselwert: " << element->get_key() << endl;

	if (element->get_last() != NULL) {cout << "Der Voerige Knoten hat den Schluesselwert: " << element->get_last()->get_key() << endl;}
	else {cout << "Der Voerige Knoten hat den Schluesselwert: NULL" << endl;}

	if (element->get_left() != NULL) {cout << "Der linke NachfolgeKnoten hat den Schluesselwert: " << element->get_left()->get_key() << endl;}
	else { cout << "Der linke NachfolgeKnoten hat den Schluesselwert: NULL" << endl; }

	if (element->get_right() != NULL) {cout << "Der rechte NachfolgeKnoten hat den Schluesselwert: " << element->get_right()->get_key() << endl;}
	else {cout << "Der rechte NachfolgeKnoten hat den Schluesselwert: NULL" << endl;}

}
