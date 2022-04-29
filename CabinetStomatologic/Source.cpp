#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Interventie
{
public:
	// functie virtuala pura -> clasa abstracta
	virtual float calculPret() = 0;
};
class Plomba : public Interventie
{
public:
	float pret;

	Plomba()
	{
		this->pret = 250;
	}

	// Inherited via Interventie
	virtual float calculPret() override
	{
		return this->pret;
	}

};
class Extractie : public Interventie
{
public:
	float pret;

	Extractie()
	{
		this->pret = 340;
	}

	// Inherited via Interventie
	virtual float calculPret() override
	{
		return this->pret;
	}

};
class Exceptie
{
public:
	string mesaj;
	Exceptie(string mesaj)
	{
		this->mesaj = mesaj;
	}
};
class CabinetStomatologic
{
private:
	char* adresa;
	int nrMedici;
	int* varstaMedic;

protected:
	const int id;
	string denumire;

public:
	static int contor;
	Interventie** vector;
	int nrInterventii;

	char* getAdresa()
	{
		return this->adresa;
	}
	void setAdresa(const char* adresa)
	{
		if (this->adresa != nullptr)
		{
			delete[] this->adresa;
		}
		if (strlen(adresa) > 3)
		{
			this->adresa = new char[strlen(adresa) + 1];
			strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
		}
		else
		{
			throw new Exceptie("Adresa este prea mica");
		}
	}
	int getNrMedici()
	{
		return this->nrMedici;
	}
	int& getVarstaMedic(int index)
	{
		return this->varstaMedic[index];
	}
	int operator[](int index)
	{
		return this->varstaMedic[index];
	}
	void setVarstaMedic(int* varstaMedic, int nrMedici)
	{
		if (this->varstaMedic != nullptr)
		{
			delete[] this->varstaMedic;
		}
		if (varstaMedic != nullptr && nrMedici > 0)
		{
			this->nrMedici = nrMedici;
			this->varstaMedic = new int[nrMedici];
			for (int i = 0; i < nrMedici; i++)
			{
				this->varstaMedic[i] = varstaMedic[i];
			}
		}
	}
	string getDenumire()
	{
		return this->denumire;
	}
	void setDenumire(string denumire)
	{
		if (denumire.size() > 3)
		{
			this->denumire = denumire;
		}
		else
		{
			throw Exceptie("Denumirea este prea scurta");
		}
	}
	int getId()
	{
		return this->id;
	}
	CabinetStomatologic() : id(1)
	{
		this->adresa = new char[strlen("Necunoscuta") + 1];
		strcpy_s(this->adresa, strlen("Necunoscuta") + 1, "Necunoscuta");
		this->nrMedici = 3;
		// this->nrMedici = 0; cu null in for
		this->varstaMedic = new int[3];
		this->varstaMedic[0] = 30;
		this->varstaMedic[1] = 32;
		this->varstaMedic[2] = 34;
		// for(int i=0; i<this->nrMedici; i++)
		// { this->varstaMedici = 37;}
		this->denumire = "Necunoscuta";
		this->nrInterventii = 2;
		this->vector = new Interventie * [2];
		this->vector[0] = new Plomba();
		this->vector[1] = new Extractie();
	}
	CabinetStomatologic(const char* adresa, int nrMedici, int* varstaMedic, string denumire,
		int nrInterventii, Interventie** vector, const int id) : id(id)
	{
		this->adresa = new char[strlen(adresa) + 1];
		strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
		this->nrMedici = nrMedici;
		this->varstaMedic = new int[nrMedici];
		for (int i = 0; i < nrMedici; i++)
		{
			this->varstaMedic[i] = varstaMedic[i];
		}
		this->denumire = denumire;
		this->nrInterventii = nrInterventii;
		this->vector = new Interventie * [nrInterventii];
		for (int i = 0; i < this->nrInterventii; i++)
		{
			this->vector[i] = vector[i];
		}
	}
	CabinetStomatologic(const CabinetStomatologic& c) : id(c.id)
	{
		this->adresa = new char[strlen(c.adresa) + 1];
		strcpy_s(this->adresa, strlen(c.adresa) + 1, c.adresa);
		this->nrMedici = c.nrMedici;
		this->varstaMedic = new int[c.nrMedici];
		for (int i = 0; i < c.nrMedici; i++)
		{
			this->varstaMedic[i] = c.varstaMedic[i];
		}
		this->denumire = c.denumire;
		this->nrInterventii = c.nrInterventii;
		this->vector = new Interventie * [c.nrInterventii];
		for (int i = 0; i < c.nrInterventii; i++)
		{
			this->vector[i] = c.vector[i];
		}
	}
	~CabinetStomatologic()
	{
		if (this->adresa != nullptr)
		{
			delete[] this->adresa;
		}
		if (this->varstaMedic != nullptr)
		{
			delete[] this->varstaMedic;
		}
		if (this->vector != nullptr)
		{
			delete[] this->vector;
		}
	}
	CabinetStomatologic& operator=(const CabinetStomatologic& c)
	{
		if (this->adresa != nullptr)
		{
			delete[] this->adresa;
		}
		if (this->varstaMedic != nullptr)
		{
			delete[] this->varstaMedic;
		}
		if (this->vector != nullptr)
		{
			delete[] this->vector;
		}
		this->adresa = new char[strlen(c.adresa) + 1];
		strcpy_s(this->adresa, strlen(c.adresa) + 1, c.adresa);
		this->nrMedici = c.nrMedici;
		this->varstaMedic = new int[c.nrMedici];
		for (int i = 0; i < c.nrMedici; i++)
		{
			this->varstaMedic[i] = c.varstaMedic[i];
		}
		this->denumire = c.denumire;
		this->nrInterventii = c.nrInterventii;
		this->vector = new Interventie * [c.nrInterventii];
		for (int i = 0; i < c.nrInterventii; i++)
		{
			this->vector[i] = c.vector[i];
		}
		return *this;
	}

	float calculSuma()
	{
		float suma = 0;
		for (int i = 0; i < nrInterventii; i++)
		{
			suma += this->vector[i]->calculPret();
		}
		return suma;
	}
	friend ostream& operator<<(ostream& out, CabinetStomatologic c);
	friend istream& operator>>(istream& in, CabinetStomatologic& c);
};
int CabinetStomatologic::contor = 1;

ostream& operator<<(ostream& out, CabinetStomatologic c)
{
	out << "Id: " << c.id << endl;
	out << "Adresa: " << c.adresa << endl;
	out << "Nr medici: " << c.nrMedici << endl;
	out << "Varsta medic: ";
	for (int i = 0; i < c.nrMedici; i++)
	{
		out << c.varstaMedic[i] << " ";
	}
	out << endl;
	out << "Denumire cabinet: " << c.denumire << endl;
	out << "Nr interventii: " << c.nrInterventii << endl;
	out << "Vector: ";
	for (int i = 0; i < c.nrInterventii; i++)
	{
		// out << c.vector[i]->calculPret();
		out << c.vector[i] << " ";
	}
	out << endl;

	return out;
}
istream& operator>>(istream& in, CabinetStomatologic& c)
{
	cout << "Adresa: ";
	char buffer[20];
	in >> ws;
	in.getline(buffer, 19);
	//in >> buffer;
	//getline(in, c.adresa);
	if (c.adresa)
	{
		delete[] c.adresa;
	}
	c.adresa = new char[strlen(buffer) + 1];
	strcpy_s(c.adresa, strlen(buffer) + 1, buffer);

	cout << "Nr medici: ";
	in >> c.nrMedici;
	cout << "Varsta medic: ";
	if (c.varstaMedic)
	{
		delete[] c.varstaMedic;
	}
	c.varstaMedic = new int[c.nrMedici];
	for (int i = 0; i < c.nrMedici; i++)
	{
		cout << i << ": ";
		in >> c.varstaMedic[i];
	}

	cout << "Denumire: ";
	//in >> c.denumire;
	in >> ws;
	getline(in, c.denumire);

	/*cout << "Nr interventii: ";
	in >> c.nrInterventii;
	cout << "Vector:";
	if (c.vector)
	{
		delete[] c.vector;
	}
	c.vector = new Interventie * [c.nrInterventii];
	for (int i = 0; i < c.nrInterventii; i++)
	{
		cout << i << ": ";
		in >> c.vector[i]->calculPret();
	}*/

	return in;
}

int main()
{
	CabinetStomatologic c1;
	cout << c1 << endl;



}