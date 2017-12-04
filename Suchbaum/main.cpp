
#include <iostream>
#include "Suchbaum.h"

using namespace std;

int main() {
	try {
		Suchbaum sb;
		sb.insert(10);
		sb.insert(8);
		sb.insert(7);
		sb.insert(9);
		sb.insert(11);
		sb.insert(12);
		sb.insert(14);
		sb.insert(13);
		sb.insert(15);
		sb.insert(16);
		sb.insert(17);
		sb.insert(18);




		sb.gebeUmliegendeKnotenAus(sb.search(10));
		//sb.remove(sb.search(8));
		sb.gebeUmliegendeKnotenAus(sb.search(9));

		cout << "\nBinaerbaum : " << sb.check(sb.get_top()) << endl;

		//sb.removeByValue(sb.get_top(), "Knoten_1");

		sb.height(sb.get_top(),0);
		cout << "\nHoehe des Baums : " << sb.get_hoehe()<<endl;
		cout << "\nAnzahl der Knoten: " << sb.get_anzahl_Knoten();
		cout << "\nAVGLEVEL : " << sb.avgLevel();

	}
	catch (const char* error) {
		cout << "!!!FAILURE!!!\n";
		cout << error << endl;
	}
	cin.get();
	return 0;
}
