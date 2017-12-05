/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   RSBaum.h
* Author: pibruegg
*
* Created on 4. Dezember 2017, 18:34
*/

#ifndef RSBAUM_H
#define RSBAUM_H
#include "Suchbaum.h"


class RSBaum : public Suchbaum {
public:
	RSBaum();
	RSBaum(const RSBaum& orig);
	virtual ~RSBaum();
	void insert(int);
	void repairInsert(Knoten*);
	void rotateLeft(Knoten*);
	void rotateRight(Knoten*);
	bool check();
	bool check(Knoten*);
	int bheight();
	bool checkBheight(Knoten*);
	void bheight(int&, Knoten*, bool&);
private:

};

#endif /* RSBAUM_H */

