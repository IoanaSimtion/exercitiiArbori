#pragma once
#include "arbore2.h";
#include <fstream>


/*Se consideră un arbore binar în care nodurile memorează numere naturale nenule. 
Să se afișeze valorile memorate în subarborele stâng al rădăcinii în urma parcurgerii în preordine..*/


//todo functie ce memoreaza datele in vector

void treeVector(int v[], int& n) {

	ifstream f("preordine1.in");
	int i = 0;
	while (!f.eof()) {
		f >> v[i];
		i++;
	}

	n = i;

}

void afisareVector(int v[], int n) {

	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}

}
void sol753() {

	int v[100], n, root;

	treeVector(v, n);

	afisareVector(v, n);

	cout << endl << endl;
	
	BinaryTree tree;

	tree.addPreordine(v, n);

	//tree.afisare();

	tree.afisarePreordineStanga(tree.root->left);



	/*tree.root = new TreeNode();
	tree.root->data = 7;
	tree.addClasic(tree.root, 9);
	tree.addClasic(tree.root, -1);
	tree.addClasic(tree.root, 5);
	tree.addClasic(tree.root, 12);
	tree.addClasic(tree.root, 3);
	tree.addClasic(tree.root, -7);

	//tree.afisare();

	cout << tree.find(tree.root);
	*/
}