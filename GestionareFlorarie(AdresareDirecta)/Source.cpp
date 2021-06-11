#include<iostream>
#include<fstream>
#include <string>
#define m 100
using namespace std;

ifstream f("flori.txt", ios::in);
ofstream g("flori.txt", ios::app);
ifstream f1("flori1.txt");
ofstream g1("flori1.txt");


struct Element
{
	int cheie;
	int pret_bucata, flori_disponibile, numar_flori_dorite;
	char nume[100];
};

Element* T[m];

void inserare(Element* e)
{
	T[e->cheie] = e;
}

Element* cautare(int k)
{
	return T[k];
}

void stergere(Element* e)
{
	T[e->cheie] = NULL;
}

int pret_total(int pret_bucata, int numar_flori_dorite, int flori_disponibile)
{
	int pret;
	if (numar_flori_dorite > flori_disponibile)
	{
		pret = 0;
	}
	else {
		pret = pret_bucata * numar_flori_dorite;
	}
	return pret;
}

void afisare()
{
	for (int k = 0; k < m; k++)
	{
		if (T[k] != NULL)
		{
			cout << T[k]->cheie << " " << T[k]->nume << " " << T[k]->flori_disponibile << " " << T[k]->pret_bucata << " ";
			cout << pret_total(T[k]->pret_bucata, T[k]->numar_flori_dorite, T[k]->flori_disponibile) << endl;
		}
	}
}

int main()
{
	int k, n;

	int optiune;
	do {
		cout << "Alegeti optiunea: " << endl;
		cout << "1. Inserare: " << endl;
		cout << "2. Stergere: " << endl;
		cout << "3. Cautare: " << endl;
		cout << "4. Afisarea tuturor florilor: " << endl;
		cout << "5. Afisarea listei actualizate cu flori: " << endl;
		cout << "6. Terminare " << endl;
		cin >> optiune;

		switch (optiune)
		{
		case 1: {
			cout << "Numarul de flori pe care vreti sa le inregistrati: ";
			cin >> n;
			while (n > m)
				cin >> n;
			for (int i = 1; i <= n; i++)
			{
				Element* e = new Element;
				if (e == NULL)
				{
					cout << "Alocare esuata" << endl;
					exit(1);
				}
				cout << "Introduceti codul pentru floarea " << i << " format din 2 cifre: ";
				cin >> e->cheie;
				while (e->cheie < 10 || e->cheie >= m)
					cin >> e->cheie;
				cout << "Nume: ";
				cin >> e->nume;
				cout << "Numarul de flori disponibile: ";
				cin >> e->flori_disponibile;
				cout << "Pret pe bucata: ";
				cin >> e->pret_bucata;
				cout << "Numar de flori dorite: ";
				cin >> e->numar_flori_dorite;
				cout << "Pret total: " << pret_total(e->pret_bucata, e->numar_flori_dorite, e->flori_disponibile) << endl;
				inserare(e);
				g << e->cheie << " " << e->nume << " " << e->flori_disponibile << " " << e->pret_bucata << " " << e->numar_flori_dorite << " ";
				g << pret_total(e->pret_bucata, e->numar_flori_dorite, e->flori_disponibile) << endl;
			}
			afisare();
			cout << endl;
		}break;
		case 2: {
			cout << "Introduceti codul pentru floarea pe care doriti sa o stergeti: ";
			cin >> k;
			if (T[k] != NULL)
				stergere(T[k]);
			afisare();
			string line;
			string s = to_string(k);
			while (getline(f, line)) {

				if (line.find(s) == line.npos)
				{
					g1 << line << endl;
				}
			}
			cout << endl;
		}break;
		case 3: {
			cout << "Introduceti codul pentru floarea pe care doriti sa o cautati: ";
			cin >> k;
			if (cautare(k) != NULL)
				cout << "Floarea cu codul " << k << " este disponibila in florarie" << endl;
			else
				cout << "Floarea cu codul " << k << " nu este disponibila in florarie" << endl;
			cout << endl;
		}break;
		case 4: {
			cout << "Afisati lista tuturor florilor: ";
			string line;
			if (f.is_open())
			{
				while (getline(f, line))
				{
					cout << line << endl;
				}
				f.close();
			}
			cout << endl;
		}break;
		case 5: {
			cout << "Afisati lista actualizata a florilor: ";
			string line1;
			if (f1.is_open())
			{
				while (getline(f1, line1))
				{
					cout << line1 << endl;
				}
				f1.close();
			}
			cout << endl;
		}break;
		case 6:break;
		default:cout << " Introduceti un numar valid de optiune (1 -> 6) !" << endl;
		}
	} while (optiune != 6);


	return 0;
}