
#include "Suchbaum.h"
#include <iostream>

Suchbaum::Suchbaum() {
	top = NULL;
}

Suchbaum::~Suchbaum() {

}

//------------------------------------------------------------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------------------------------------------------------

void Suchbaum::remove(int key) {
	Knoten* element = search(key);


	if (element->get_last() != NULL) { // Falls es nicht die Wurzel ist
		Knoten* voriger = element->get_last(); // Vorgänger des gesuchten Elementes

		// Erster Fall
		if (element->get_left() == NULL && element->get_right() == NULL) {
			//Falls insgesamt nur ein Knoten vorhanden ist, wird dieser einfach am Ende der Funktion geloescht
			if (voriger->get_left() == element) {
				voriger->set_left(NULL);
			}
			else { voriger->set_right(NULL); }
		}
		//Zweiter Fall - ElternKnoten hat linken Nachfolger
		else if (element->get_left() != NULL && element->get_right() == NULL) {
			if (voriger->get_left() == element) { // LINKS
				voriger->set_left(element->get_left());
				element->get_left()->set_last(voriger);
			}
			else { //RECHTS
				voriger->set_right(element->get_left());
				element->get_left()->set_last(voriger);
			}
		}
		//Zweiter Fall - ElternKnoten hat rechten Nachfolger
		else if (element->get_left() == NULL && element->get_right() != NULL) {
			if (voriger->get_left() == element) { // LINKS
				voriger->set_left(element->get_right());
				element->get_right()->set_last(voriger);
			}
			else { //RECHTS
				voriger->set_right(element->get_right());
				element->get_right()->set_last(voriger);
			}
		}

		//Normalfall
		//Dritter Fall - Knoten von ganz rechts wird genommen um die Lücke zu füllen
		else {

			Knoten* akt_Knoten;

			if (element->get_key() > top->get_key()) { //Wenn sich das Element im rechten Teilbaum befindet
				akt_Knoten = element->get_left();
				while (akt_Knoten->get_right() != NULL) {
					akt_Knoten = akt_Knoten->get_right();
				}
				if (akt_Knoten->get_left() != NULL) { //Wenn das zu tauschende Element gefunden wurde , jedoch links noch ein Knoten sitzt
					akt_Knoten->get_left()->set_last(akt_Knoten->get_last()); // Nachfolger mit Vorgänger verbinden
					akt_Knoten->get_last()->set_right(akt_Knoten->get_left()); //Vorgänger mit Nachfolger verbinden
				}
				else {
					if (element->get_left() != akt_Knoten) { //falls der Neue Knoten nicht der nachfolger des alten ist
						akt_Knoten->get_last()->set_right(NULL);
					}
					else{
						akt_Knoten->set_left(NULL);
					}
				}
			}
			else {//Wenn sich das Element im linken Teilbaum befindet
				akt_Knoten = element->get_right();
				while (akt_Knoten->get_left() != NULL) {
					akt_Knoten = akt_Knoten->get_left();
				}
				if (akt_Knoten->get_right() != NULL) { //Wenn das zu tauschende Element gefunden wurde , jedoch links noch ein Knoten sitzt
					akt_Knoten->get_right()->set_last(akt_Knoten->get_last()); // Nachfolger mit Vorgänger verbinden
					akt_Knoten->get_last()->set_left(akt_Knoten->get_right()); // Vorgänger mit Nachfolger verbinden
				}
				else {
					if (element->get_right() != akt_Knoten) {
						akt_Knoten->get_last()->set_left(NULL);
					}
					else {
						akt_Knoten->set_right(NULL);
					}
				}	
			}

			//Voränger des zu löschenden Elementes behandeln
			if (element->get_last()->get_left() == element) {
				element->get_last()->set_left(akt_Knoten);
				akt_Knoten->set_last(element->get_last());
			}
			else {
				element->get_last()->set_right(akt_Knoten);
				akt_Knoten->set_last(element->get_last());
			}

			//Linker Nachfolger des zu löschenden Elementes behandeln
			if (element->get_left() != akt_Knoten) {
				akt_Knoten->set_left(element->get_left());
				element->get_left()->set_last(akt_Knoten);
			}
			else {
				akt_Knoten->set_left(NULL);
			}

			//Rechter Nachfolger des zu löschenden Elementes behandeln
			if (element->get_right() != akt_Knoten) {
				akt_Knoten->set_right(element->get_right());
				element->get_right()->set_last(akt_Knoten);
			}
			else {
				akt_Knoten->set_right(NULL);
			}

			if (top == element) {
				top = NULL;
			}
		}
	} // Ende element->get_last() != NULL
//###############################################################################################################
	//Falls die Wurzel gelöscht werden soll
	else {
		//Erster Fall, wenn Element gleich Wurzel
		if (element->get_left() == NULL && element->get_right() == NULL) {
			top = NULL;
		}
		//Zweiter Fall, wenn Element gleich Wurzel
		else if (element->get_left() == NULL && element->get_right() != NULL) {
			top = element->get_right();
			element->get_right()->set_last(NULL);
		}
		//Zweiter Fall, wenn Element gleich Wurzel
		else if (element->get_left() != NULL && element->get_right() == NULL) {
			top = element->get_left();
			element->get_left()->set_last(NULL);
		}
		//Dritter Fall, wenn Element gleich Wurzel
		else {
			Knoten* akt_Knoten;

			akt_Knoten = element->get_left();
			while (akt_Knoten->get_right() != NULL) {
				akt_Knoten = akt_Knoten->get_right();
			}
			if (akt_Knoten->get_left() != NULL) { //Wenn das zu tauschende Element gefunden wurde , jedoch links noch ein Knoten sitzt
				akt_Knoten->get_left()->set_last(akt_Knoten->get_last()); // Nachfolger mit Vorgänger verbinden
				akt_Knoten->get_last()->set_right(akt_Knoten->get_left()); //Vorgänger mit Nachfolger verbinden
			}
			else {
				akt_Knoten->get_last()->set_right(NULL);
			}

			akt_Knoten->set_last(NULL);
			top = akt_Knoten;

			//Linker Nachfolger des zu löschenden Elementes behandeln
			if (element->get_left() != NULL) { //Wenn akt_Knoten nicht das Nachfolgeelement ist
				akt_Knoten->set_left(element->get_left());
				element->get_left()->set_last(akt_Knoten);
			}
			else {
				akt_Knoten->set_left(NULL);
			}

			//Rechter Nachfolger des zu löschenden Elementes behandeln
			if (element->get_right() != NULL) { // Wenn akt_Knoten nicht das Nachfolgeelement ist
				akt_Knoten->set_right(element->get_right());
				element->get_right()->set_last(akt_Knoten);
			}
			else {
				akt_Knoten->set_right(NULL);
			}
		}
	}
	delete element;
}

//---------------------------------------------------------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------------------------------------------------------
Knoten* Suchbaum::push(int key) {
	Knoten* temp = new Knoten(key);
	temp->set_value(key);
	return temp;
}

//-----------------------------------------------------------------------------------------------------------------------------
void Suchbaum::gebeUmliegendeKnotenAus(Knoten* element) {

	cout << "\nDer aktuelle Knoten hat den Schluesselwert: " << element->get_key() << endl;

	if (element->get_last() != NULL) {cout << "Der Voerige Knoten hat den Schluesselwert: " << element->get_last()->get_key() << endl;}
	else {cout << "Der Voerige Knoten hat den Schluesselwert: NULL" << endl;}

	if (element->get_left() != NULL) {cout << "Der linke NachfolgeKnoten hat den Schluesselwert: " << element->get_left()->get_key() << endl;}
	else { cout << "Der linke NachfolgeKnoten hat den Schluesselwert: NULL" << endl; }

	if (element->get_right() != NULL) {cout << "Der rechte NachfolgeKnoten hat den Schluesselwert: " << element->get_right()->get_key() << endl;}
	else {cout << "Der rechte NachfolgeKnoten hat den Schluesselwert: NULL" << endl;}

}

//-------------------------------------------------------------------------------------------------------------------------------
