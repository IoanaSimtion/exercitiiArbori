#pragma once
#include "arbore2.h";
#include <fstream>


/*Se consideră un arbore binar în care nodurile memorează numere naturale nenule.
Să se determine câte noduri din arbore au un singur descendent direct.*/


void citireVector(int v[], int& n) {

	ifstream f("nrnod.in");
	n = 0;
	while (!f.eof()) {
		f >> v[n];
		n++;
	}

}





void sol756() {

	int v[100], n, ct=0;

	citireVector(v, n);

	BinaryTree tree;

	tree.addPreordine(v, n);

	tree.ctNoduri(tree.root, ct);

	cout << ct;

}