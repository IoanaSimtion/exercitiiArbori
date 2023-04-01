#pragma once
#include "arbore2.h";
#include <fstream>


/*Se consideră un arbore binar în care nodurile memorează numere naturale nenule.
Să se afișeze valorile memorate în arbore în urma parcurgerii în postordine.*/



void citireVector(int v[], int& n) {

	ifstream f("postordine1.in");
	n = 0;
	while (!f.eof()) {
		f >> v[n];
		n++;
	}
	
}




void sol755() {

	int v[100], n;

	citireVector(v, n);

	BinaryTree tree;

	tree.addPreordine(v, n);

	tree.afisarePostordine(tree.root);

}