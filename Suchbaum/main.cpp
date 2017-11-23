
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

		sb.gebeUmliegendeKnotenAus(sb.search(8));
		sb.remove(8);
		sb.gebeUmliegendeKnotenAus(sb.search(9));
		
	}
	catch (const char* error) {
		cout << "!!!FAILURE!!!\n";
		cout << error << endl;
	}
	cin.get();
	return 0;
}
