#pragma once
#include "arbori.h";
#include <fstream>


/*Considerăm un arbore binar cu n noduri în care fiecare nod este numerotat de la 1 la n 
și conține o valoare număr natural.
Să se determine diferența în valoare absolută a sumei valorilor 
memorate în subarborele stâng al rădăcinii și suma valorilor memorate
în subarborele drept al rădăcinii.*/


//todo functie ce memoreaza datele in matrice

void treeMatrice(int m[100][100], int d, int& n) {

	ifstream f("postordine.in");

	f >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			f >> m[i][j];
		}
	}

}


//todo functie ce afiseaza o matrice

void afisareMatrice(int m[100][100], int n, int d) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			cout << m[i][j] << ' ';
		}
		cout << endl;
	}

}

//todo functie ce verifica daca un nr se gaseste in matrice

bool exista(int m[100][100], int n, int d, int data) {

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < d; j++) {
			if (m[i][j] == data) {
				return true;
			}
		}
	}

	return false;

}


//todo functie ce returneaza valoarea root ului

int treeRoot(int m[100][100], int n, int d) {

	for (int i = 0; i < n; i++) {
		if (!exista(m, n, d, i + 1)) {
			return m[i][0];
		}
	}

}


//tood functie ce returneaza indicele root ului

int pozRoot(int m[100][100], int n, int d, int root) {

	for (int i = 0; i < n; i++) {
		if (m[i][0] == root) {
			return i;
		}
	}

}



void sol673() {

	int m[100][100], d = 3, n, root, parinte, sumaLeft = 0, sumaRight = 0;

	treeMatrice(m, d, n);

	afisareMatrice(m, n, d);

	root = treeRoot(m, n, d);

	BinaryTree tree;

	tree.add(m, n, d, pozRoot(m, n, d, root));

	tree.sumaLeft(tree.root->left, sumaLeft);

	cout << sumaLeft << endl;

	tree.sumaRight(tree.root->right, sumaRight);

	cout << sumaRight << endl;

	cout << "Diferenta: " << abs(sumaLeft - sumaRight) << endl;

}