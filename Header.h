#pragma once
#include<iostream>
#include<string>
using namespace std; 

class TrieNode {
public:

	bool is_end;
	TrieNode* left, * mid, * right;
	char c;

	TrieNode(char _c) :c(_c), left(NULL), mid(NULL), right(NULL), is_end(false) {

	}
	~TrieNode() {
		if (left)
			delete left;
		if (right)
			delete right;
		if (mid)
			delete mid;
	}
};

class SpellChecker {
private:
	TrieNode* root;
public:
	SpellChecker() {
		root = NULL;
	}
	~SpellChecker() {
		delete root;
	}

	TrieNode* put(TrieNode* node, const string& str, int index);	
	void insert(string word);
	TrieNode* get(TrieNode* node, const string& str, int index);
	bool search(string word);


};