#include"Header.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
/*functie ajutatoare pentru adaugarea unui nod in Trie*/
TrieNode* SpellChecker::put(TrieNode* node, const string& str, int index) {
	if (!node) 
	{
		node = new TrieNode(str[index]); //construieste noul nod
	}

	if (node->c > str[index]) 
		node->left = put(node->left, str, index); //se pargurge arborele stang
	else  
		if (node->c < str[index])
		node->right = put(node->right, str, index); //se parcurge argorele drept
	else 
		if (index < str.size() - 1) 
	
		node->mid = put(node->mid, str, index + 1); // se parcurge mijlocul
	
	else
		node->is_end = true; //Daca arborele a ajuns la sfarsit 

	return node; // returneaza 
}
/*functie ce adauga cuvantul "word" in trie*/
void SpellChecker::insert(string word) 
{
	root = put(root, word, 0);
}

/*functie ajutatoare pentru functia de cautare*/
TrieNode* SpellChecker::get(TrieNode* node, const string& str, int index) {
	if (node == NULL)
		return NULL;

	if (node->c > str[index])
		return get(node->left, str, index);
	if (node->c < str[index])
		return get(node->right, str, index);
	if (index < str.size() - 1)
		return get(node->mid, str, index + 1);
	return node;
}
//functie de cautare ce primeste ca si parametru un cuvant 
//returneaza 1 daca acesta se afla in arbore
//in caz contrar
//returneaza 0
bool SpellChecker::search(string word) {
	TrieNode* p = get(root, word, 0);

	return p && p->is_end;
}
bool SpellChecker::startsWith(string prefix) {
	TrieNode* p = get(root, prefix, 0);
	
	return p != NULL;
}
