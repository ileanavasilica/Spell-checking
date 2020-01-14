#include"Header.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;


int main()
{
	SpellChecker a;
	string cuvant, prefix; 
	char nume_fisier[30]; 
	string s; 
	int option=0;
	cout << "Introduceti numele fisierului (dictionary.txt): ";
	cin >> nume_fisier; 
	ifstream fin(nume_fisier);
	if (strcmp(nume_fisier, "dictionary.txt") != 0)
		cout << "Ati gresit numele fisierului";
	else
	{
		cout << "Continutul dictionarului este:";
		while (option != 2)
		{
			while (fin >> s)
			{
				a.insert(s);

				cout << s << " ";
			}
			cout << endl;
			cout << "-----------------------------";
			cout << endl;
			cout << "Meniul :" << endl;
			cout << "1.Doriti sa cautati un cuvant intreg " << endl;
			cout << "2.Doriti sa cautati un prefix " << endl;
			cout << "Alegerea dumneavoastra este: ";
			cin >> option;
			cout << endl;
			switch (option)
			{
			case 1: //doriti sa cautati un cuvant
				cout << "Introduceti cuvantul pe care doriti sa - l cautati:";
				cin >> cuvant;
				if (a.search(cuvant) == 0)
					cout << "Cuvantul nu exista in dictionar.";
				else
					cout << "Yeeeeeey!!! Cuvantul exista in dictionar.";
				break;
			case 2: //doriti sa cautati un prefix
				cout << "Introduceti prefixul pe care doriti sa - l cautati:";
				cin >> prefix;
				if (a.startsWith(prefix) == 0)
					cout << "Nu exista cuvinte in dictionar cu prefixul :" << prefix << endl;
				else
					cout << "Exista cuvinte in dictionar cu prefixul introdus ! ";
				break;
			default:
				cout << "EROARE";
				break;
			}
		}
	}
	return 0;
}
