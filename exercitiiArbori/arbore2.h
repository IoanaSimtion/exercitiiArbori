#include "treeNode.h";

#include "stiva.h";

#include "coada.h";

#include <fstream>

#pragma once


struct BinaryTree {

	TreeNode* root = NULL;

	BinaryTree() {

	}

	TreeNode* find(TreeNode* current) {

		if (current == NULL) {
			return current;
		}

		TreeNode* aux = find(current->left);

		if (aux == NULL) {
			return aux;
		}

		return find(current->right);
	}



	//ADD



	void addClasic(TreeNode* current, int data) {

		if (current == NULL) {
			TreeNode* nou = new TreeNode();
			nou->left = NULL;
			nou->right = NULL;
			nou->data = data;
		}
		else {
			if (current->data > data) {
				if (current->left != NULL) {
					addClasic(current->left, data);
				}
				else {
					current->left = new TreeNode();
					current->left->data = data;
					current->left->left = NULL;
					current->left->right = NULL;
				}
			}
			else {
				if (current->right != NULL) {
					addClasic(current->right, data);
				}
				else {
					current->right = new TreeNode();
					current->right->data = data;
					current->right->left = NULL;
					current->right->right = NULL;
				}
			}
		}

	}


	TreeNode* addData(TreeNode* current, int data) {


		if (current->data == 0) {

			return NULL;
		}

		if (current->left == NULL) {
			TreeNode* aux = new TreeNode();
			aux->data = data;
			aux->left = NULL;
			aux->right = NULL;
			current->left = aux;
			return aux;
		}

		TreeNode* left = addData(current->left, data);

		if (left == NULL) {

			if (current->right == NULL) {
				TreeNode* aux = new TreeNode();
				aux->data = data;
				aux->left = NULL;
				aux->right = NULL;
				current->right = aux;
				return aux;
			}
			return addData(current->right, data);

		}
		return left;
	}



	

	void addPreordine(int v[], int n) {

		root = new TreeNode();

		root->data = v[0];

		TreeNode* current = root;

		for (int i = 1; i < n; i++) {
			addData(current, v[i]);
		}

	}


	void afisare() {

		TreeNode* aux = root;
		Coada<TreeNode*> c;
		c.push(aux);

		while (!c.isEmpty()) {
			aux = c.peak()->data;

			if (aux->left != NULL) {
				c.push(aux->left);
			}
			if (aux->right != NULL) {
				c.push(aux->right);
			}

			cout << aux->data << ' ';

			c.pop();
		}

	}
	

};