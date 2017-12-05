
#include <iostream>
#include "Suchbaum.h"
#include "time.h"
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int main() {
	try {
		Suchbaum sb;

		const int anzahl = 1000000;



		const int min = 0;
		const int max = anzahl - 1;
		default_random_engine generator;
		uniform_int_distribution<int> distribution(min, max);

		vector<unsigned int> zahlen;
		for (int i = 0;i < anzahl;i++) {
			zahlen.push_back(i);
		}
		int temp = anzahl * 10;
		for (int i = 0;i < temp;i++) {
			swap(zahlen[distribution(generator)], zahlen[distribution(generator)]);
		}

		// ----- AUFGABE 1---------------------
		//Insert
		clock_t start = clock();
		for (int i = 0;i < anzahl;i++) {
			sb.insert(zahlen[i]);
		}
		clock_t end = clock();
		double time = ((end - start) * 1000) / CLOCKS_PER_SEC;
		cout << "Zeit fuer den Insert bei " << anzahl << " Knoten : " << time<<endl;

		////height
		//start = clock();
		//sb.height(sb.get_top(), 0);
		//end = clock();
		//time = ((end - start) * 1000) / CLOCKS_PER_SEC;
		//cout << "Zeit fuer die height bei " << anzahl << " Knoten : " << time<<endl;

		//check
		start = clock();
		bool wahr = sb.check(sb.get_top());
		end = clock();
		time = ((end - start) * 1000) / CLOCKS_PER_SEC;
		cout << "Zeit fuer den check bei " << anzahl << " Knoten : " << time<<endl;

		////remove
		//start = clock();
		//sb.removeByValue(sb.get_top(), "Knoten_1000");
		//end = clock();
		//time = ((end - start) * 1000) / CLOCKS_PER_SEC;
		//cout << "Zeit fuer den remove bei " << anzahl << " Knoten : " << time << endl;

		//cout << "\nHoehe des Baums : " << sb.get_hoehe()<<endl;
		//cout << "\nAVGLEVEL : " << sb.avgLevel();

		// --------------- AUFGABE 2 ----------------------
		//// Insert
		//clock_t start = clock();
		//for (int i = 0;i < anzahl;i++) {
		//	sb.insert(zahlen[i]);
		//}
		//clock_t end = clock();
		//double time = ((end - start) * 1000) / CLOCKS_PER_SEC;
		//cout << "Zeit fuer den Insert bei " << anzahl << " Knoten : " << time<<endl;

		////check
		//start = clock();
		//bool wahr = sb.check();
		//end = clock();
		//time = ((end - start) * 1000) / CLOCKS_PER_SEC;
		//cout << "Zeit fuer den check bei " << anzahl << " Knoten : " << time<<endl;

		////height
		//start = clock();
		//sb.bheight();
		//end = clock();
		//time = ((end - start) * 1000) / CLOCKS_PER_SEC;
		//cout << "Zeit fuer die bheight bei " << anzahl << " Knoten : " << time<<endl;





	}
	catch (const char* error) {
		cout << "!!!FAILURE!!!\n";
		cout << error << endl;
	}
	cin.get();
	return 0;
}
