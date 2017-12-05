/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   RSBaum.cpp
* Author: pibruegg
*
* Created on 4. Dezember 2017, 18:34
*/

#include "RSBaum.h"
#include <iostream>

RSBaum::RSBaum() :Suchbaum() {
}

RSBaum::RSBaum(const RSBaum& orig) {
}

RSBaum::~RSBaum() {
}

void RSBaum::insert(int key) {
	Knoten* newKnoten = new Knoten(key);
	Knoten* akt = NULL;
	Knoten* parent;
	//cout << "Knoten : " << key << endl;
	parent = NULL;

	akt = this->get_top();
	while (akt != NULL) {
		parent = akt;
		if (newKnoten->get_key() < akt->get_key()) {
			akt = akt->get_left();
		}
		else {
			akt = akt->get_right();
		}
	}
	newKnoten->set_last(parent);
	if (parent == NULL) {
		top = newKnoten;

	}
	else {
		if (newKnoten->get_key()<parent->get_key()) {
			parent->set_left(newKnoten);
		}
		else {
			parent->set_right(newKnoten);
		}
	}
	newKnoten->set_istRot(true);
	repairInsert(newKnoten);



}

void RSBaum::repairInsert(Knoten* _node) {
	Knoten* node = _node;
	//existiert ein parent?
	if (node->get_last()) {
		//existiert der parent vom parent?
		while (node->get_last()->get_istRot()) {
			if (node->get_last()->get_last()) {
				// node.parent ist links von node.parent.parent
				if (node->get_last() == node->get_last()->get_last()->get_left()) {
					//Fall 1
					Knoten* y = node->get_last()->get_last()->get_right();
					bool uncleRed;
					if (y) {
						uncleRed = y->get_istRot();
					}
					else {
						uncleRed = false;
					}
					if (uncleRed) {
						node->get_last()->set_istRot(false);
						y->set_istRot(false);
						node->get_last()->get_last()->set_istRot(true);
						node = node->get_last()->get_last();
					}
					//Fall 2
					else {
						if (node == node->get_last()->get_right()) {
							node = node->get_last();
							this->rotateLeft(node);
						}
						//Fall 3
						node->get_last()->set_istRot(false);
						node->get_last()->get_last()->set_istRot(true);
						this->rotateRight(node->get_last()->get_last());
					}
				}
				// node.parent ist rechts von node.parent.parent
				else {
					//Fall 4
					Knoten* y = node->get_last()->get_last()->get_left();
					bool uncleRed;
					if (y) {
						uncleRed = y->get_istRot();
					}
					else {
						uncleRed = false;
					}
					if (uncleRed) {
						node->get_last()->set_istRot(false);
						y->set_istRot(false);
						node->get_last()->get_last()->set_istRot(true);
						node = node->get_last()->get_last();
					}
					//Fall 5
					else {
						if (node == node->get_last()->get_left()) {
							node = node->get_last();
							this->rotateRight(node);
						}
						//Fall 6
						node->get_last()->set_istRot(false);
						node->get_last()->get_last()->set_istRot(true);
						this->rotateLeft(node->get_last()->get_last());
					}
				}
			}
			//Kontrolle, ob neuer node vater bzw grossvater hat
			if (node->get_last()) {
				if (!node->get_last()->get_last()) break;
			}
			else break;
		}
	}
	this->get_top()->set_istRot(false);
}

void RSBaum::rotateLeft(Knoten* node) {
	Knoten* y = node->get_right();
	node->set_right(y->get_left());

	if (y->get_left()) y->get_left()->set_last(node);
	if (node == this->get_top()) {
		this->set_top(y);
	}
	else {
		if (node == node->get_last()->get_left()) {
			node->get_last()->set_left(y);
		}
		else {
			node->get_last()->set_right(y);
		}
		y->set_last(node->get_last());
	}
	y->set_left(node);
	node->set_last(y);
}

void RSBaum::rotateRight(Knoten* node) {
	Knoten* y = node->get_left();
	node->set_left(y->get_right());

	if (y->get_right()) y->get_right()->set_last(node);
	if (node == this->get_top()) {
		this->set_top(y);
	}
	else {
		if (node == node->get_last()->get_right()) {
			node->get_last()->set_right(y);

		}
		else {
			node->get_last()->set_left(y);
		}
		y->set_last(node->get_last());
	}
	y->set_right(node);
	node->set_last(y);
}

bool RSBaum::check() {
	return this->check(this->get_top());
}

bool RSBaum::check(Knoten* node) {
	//siehe VL 2. Bedigungn RS Baum    
	if (node->get_last() == NULL) {
		if (node->get_istRot()) return false;
	}
	//siehe VL 3. Bedigungn RS Baum  
	else if (node->get_istRot()) {
		if (node->get_left() && node->get_right()) {
			if (node->get_left()->get_istRot() || node->get_right()->get_istRot()) {
				return false;
			}
		}
	}

	else if (!node->get_istRot()) {
		if ((node->get_left() && !node->get_right()) ||
			(!node->get_left() && node->get_right())) {
			//rausfinden, welcher nachfolger existiert
			Knoten* nachfolger;
			if (node->get_left()) {
				nachfolger = node->get_left();
			}
			else nachfolger = node->get_right();
			if (nachfolger->get_istRot()) {
				//ist der nachfolger blatt?
				if (nachfolger->get_left() || nachfolger->get_right()) {
					return false;
				}
			}
			//nachfolger ist schwarz -> fehler
			else return false;
		}
	}
	//Kontrolle der schwarzen Hoehe
	if (!this->checkBheight(node)) return false;


	//vergleich node key mit node->left.key
	if (node->get_left()) {
		if (node->get_key() > node->get_left()->get_key()) {
			check(node->get_left());
		}
		else {
			return false;
		}
	}
	if (node->get_right()) {
		if (node->get_key() < node->get_right()->get_key()) {
			check(node->get_right());
		}
		else {
			return false;
		}
	}
	return true;
}



int RSBaum::bheight() {
	int hoehe = 0;
	bool schwarz = true;
	this->bheight(hoehe, this->get_top(), schwarz);
	return hoehe;
}

bool RSBaum::checkBheight(Knoten* node) {
	int hoehe = 0;
	bool schwarz = true;
	this->bheight(hoehe, node, schwarz);
	return schwarz;
}

void RSBaum::bheight(int& schwarzehoehe, Knoten* node, bool& schwarz) {
	int links = schwarzehoehe;
	int rechts = schwarzehoehe;
	if (node->get_left()) {
		//links existiert
		this->bheight(links, node->get_left(), schwarz);
	}
	if (node->get_right()) {
		//rechts existiert
		this->bheight(rechts, node->get_right(), schwarz);
	}

	if (links != rechts) {
		schwarz = false;
	}

	schwarzehoehe = links;
	if (!node->get_istRot()) schwarzehoehe += 1;
	return;
}

