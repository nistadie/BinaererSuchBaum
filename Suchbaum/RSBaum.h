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
	RSBaum(); // ------------------------------------------- Standardkonstruktor
	RSBaum(const RSBaum& orig); // ------------------------- Kopierkonstruktor
	virtual ~RSBaum(); // ---------------------------------- Standarddestruktor
	void insert(int); // ----------------------------------- Füge einen Knoten dem Baum hinzu 
	void repairInsert(Knoten*); // ------------------------- Stelle die RS Baum Eigenschaft wieder her
	void rotateLeft(Knoten*); // --------------------------- Rotiere den Baum nach links
	void rotateRight(Knoten*); // -------------------------- Rotiere den Baum nach Rechts
	bool check(); // --------------------------------------- Checke, ob die RS Baum Eigenschaft erfüllt ist
	bool check(Knoten*); // -------------------------------- Checke, ob die RS Baum Eigenschaft erfüllt ist	
	int bheight(); // -------------------------------------- Berechne die Höhe des Baumes
	bool checkBheight(Knoten*); // ------------------------- Berechne die Höhe des Baumes
	void bheight(int&, Knoten*, bool&); // ----------------- Berechne die Höhe des Baumes
};

#endif /* RSBAUM_H */

