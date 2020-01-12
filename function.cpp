#include"Header.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

TrieNode* SpellChecker::put(TrieNode* node, const string& str, int index) {
	if (!node) {
		node = new TrieNode(str[index]);
	}

	if (node->c > str[index])
		node->left = put(node->left, str, index);
	else if (node->c < str[index])
		node->right = put(node->right, str, index);
	else if (index < str.size() - 1) {
		node->mid = put(node->mid, str, index + 1);
	}
	else
		node->is_end = true;

	return node;
}

void SpellChecker::insert(string word) {
	root = put(root, word, 0);
}


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
bool SpellChecker::search(string word) {
	TrieNode* p = get(root, word, 0);

	return p && p->is_end;
}
bool SpellChecker::startsWith(string prefix) {
	TrieNode* p = get(root, prefix, 0);
	
	return p != NULL;
}
