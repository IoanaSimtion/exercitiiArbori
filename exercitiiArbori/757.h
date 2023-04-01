#pragma once
#include "arbore2.h";
#include <fstream>


/*Se consideră un arbore binar în care nodurile memorează numere naturale nenule.
Să se determine valorile maxime din subarborii stâng și drept ai rădăcinii.*/


void citireVect(int v[], int& n) {

	ifstream f("bimax.in");
	n = 0;

	while (!f.eof()) {
		f >> v[n];
		n++;
	}

}




void sol757() {

	int v[100], n, maxLeft=INT_MIN, maxRight=INT_MIN;

	citireVect(v, n);

	BinaryTree tree;

	tree.addPreordine(v, n);

	tree.maxSubarboreStang(maxLeft, tree.root->left);

	cout << maxLeft << ' ';

	tree.maxSubarboreDrept(maxRight, tree.root->right);

	cout << maxRight << endl;

}