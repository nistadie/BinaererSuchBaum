
#include "Knoten.h"
#include <sstream>

stringstream stream;

Knoten::Knoten() {
	linkerNachfolger = NULL;
	rechterNachfolger = NULL;
	vorgaenger = NULL;
}

Knoten::Knoten(int key) {
	linkerNachfolger = NULL;
	rechterNachfolger = NULL;
	vorgaenger = NULL;
	schluessel = key;
	istRot = false;
}

Knoten::~Knoten() {

}

int Knoten::get_key() {
	return schluessel;
}

void Knoten::set_value(int key) {
	string inhalt;
	int temp = (key / 10);
	stream << temp;
	stream >> inhalt;
	stream.clear();
	value = "Knoten_" + inhalt;
}

Knoten* Knoten::get_last() {
	return vorgaenger;
}

Knoten* Knoten::get_left() {
	return linkerNachfolger;
}

Knoten* Knoten::get_right() {
	return rechterNachfolger;
}

void Knoten::set_last(Knoten* element) {
	this->vorgaenger = element;
}

void Knoten::set_left(Knoten* element) {
	this->linkerNachfolger = element;
}

void Knoten::set_right(Knoten* element) {
	this->rechterNachfolger = element;
}

string Knoten::get_value() {
	return value;
}

void Knoten::set_istRot(bool rot) {
	istRot = rot;
}

bool Knoten::get_istRot() {
	return istRot;
}