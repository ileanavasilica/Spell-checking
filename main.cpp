#include"Header.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
ifstream fin("dictionary.txt");

int main()
{
	SpellChecker a;
	string s, p;
	cout << "Continutul dictionarului este:" << endl;
	while (fin >> s)
	{
		a.insert(s);
		cout << s << endl;
	}
	cout << "....................................." << endl;
	cout << "Introduceti cuvantul pe care doriti sa-l cautati: ";
	cin >> p;
	if (a.search(p) == 0)
		cout << "Cuvantul nu exista in dictionar.";
	else
		cout << "Yeeeeeey!!! Cuvantul exista in dictionar.";

	return 0;
}