#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Data {
	int zi;
	char luna[21];
	int an;

public:

	Data() 
	{

	}

	Data(const int& other_zi, const char other_luna[21], const int& other_an)
	{
		//cout << "Sunt in constructorul cu mai multi parammetri"<<endl;
		zi = other_zi;
		strcpy_s(luna, other_luna);
		an = other_an;
	}

	Data(const Data& other)
		:zi(other.zi),
		an(other.an)
	{
		//cout << "Sunt in constructorul de copiere" << endl;
		strcpy_s(luna, other.luna);	
	}

	Data& operator=(const Data& other)
	{
		//cout << "Sunt in operatorul =" << endl;
		zi = other.zi;
		strcpy_s(luna, other.luna);
		an = other.an;
		return *this;
	}

	~Data()
	{
		//cout << "Sunt in destructorul Data" << endl;
	}

	friend ostream& operator<<(ostream& os, const Data& data);
};

ostream& operator<<(ostream& os, const Data& data)
{
	os << data.zi << " ";
	os << data.luna << " ";
	os << data.an;
	return os;
}


class Actor {
	string nume;
	Data data_nasterii;

public:

	Actor()
	{

	}

	Actor(const string& other_nume,const Data& data)
	{
		nume = other_nume;
		data_nasterii = data;
	}

	Actor(const string& other_nume, const int& other_zi, const char other_luna[21], const int& other_an)
	{
		nume = other_nume;
		data_nasterii = Data(other_zi, other_luna, other_an);
		//cout << "Sunt in constructorul cu mai multi parammetri" << endl;
	}

	~Actor()
	{
		//cout << "Sunt in destructorul Actor" << endl;
	}

	friend ostream& operator<<(ostream& os, const Actor& data);
};

ostream& operator<<(ostream& os, const Actor& data)
{
	os << data.nume << " ";
	os << data.data_nasterii;
	return os;
}


class Film{
	char titlu[51];
	int nrActori;
	vector <Actor> Act;

public:

	Film()
	{

	}

	Film(const char other_titlu[51])
	{
		strcpy_s(titlu, other_titlu);
	}

	Film(const char other_titlu[51], vector<Actor> new_Act, const int& other_nrActori)
	{
		strcpy_s(titlu, other_titlu);
		Act = new_Act;
		nrActori = other_nrActori;
		//nrActori++;  creste nrActori -> pentru ca valoarea lui other_nrActori este constanta(nu o pot modifica) 
		//o trec in variabila nrActori, iar aceasta se poate incrementa
		//other_nrActori++;  nu pot modifica deoarece este o valoare "const"
	}

	Film(const Film& other)
		:nrActori(other.nrActori)
	{
		//cout << "Sunt in constructorul de copiere" << endl;
		strcpy_s(titlu, other.titlu);
	}

	Film& operator=(const Film& other)
	{
		//cout << "Sunt in operatorul =" << endl;
		nrActori = other.nrActori;
		strcpy_s(titlu, other.titlu);
		Act = other.Act;
		return *this;
	}

	Film& operator+=(const Actor& other)
	{
		//cout << "Sunt in operatorul +=" << endl;
		Act.push_back(other);
		nrActori++;
		return *this;
	}

	~Film()
	{
		//cout << "Sunt in destructorul Film" << endl;
	}

	friend ostream& operator<<(ostream& os, const Film& data);
	friend istream& operator>>(istream&, Film&);
};

ostream& operator<<(ostream& os, const Film& data)
{
	os << data.titlu << " (nr actori:)" << data.nrActori << " [ ";
	for (Actor x : data.Act)
		os << x << "; ";
	os << "]";
	return os;
}

istream& operator>>(istream& is, Film& data)
{
	cout << "Dati titlu: ";
	is >> data.titlu;
	return is;
}

int main()
{
	Data d1(15, "iulie", 1975), d2=d1;
	//cout << d1 << endl; // afiseaza d1 corect
	//cout << d2 << endl; // afiseaza d2 corect


	Actor a1("Ionescu", d1), a2("Popescu", 2, "ianuarie", 1980);  //a3("Ion", d2);
	//cout << a1 << endl; // afiseaza a1 corect
	//cout << a2 << endl; // afiseaza a2 corect
 
	
	Film f1("Matrix"), f2, f3;
	f1 += a1;
	f1 += a2;
	cout << f1 << endl;
	cin >> f2;	//acesta merge corect
	f3 = f2;
	//f3 += a3;
	cout << f3; //acesta merge corect 

	return 0;
}