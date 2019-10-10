#include <iostream>
#include <string>

using namespace std;

class Masina{
protected:
	static int nr_masini;
	string marca;
	string culoare;
	int an_fabricatie;
public:
	Masina(){
		nr_masini = 0;
	}
	Masina(string m, string c, int an){
		nr_masini++;
		marca = m;
		culoare = c;
		an_fabricatie = an;
	}
	Masina(const Masina &masina){
		marca = masina.marca;
		culoare = masina.culoare;
		an_fabricatie = masina.an_fabricatie;
	}
	virtual ~Masina(){
		nr_masini--;
	}
	
	static int get_nr_masini(){
		return nr_masini;
	}
	
	friend istream &operator >> (istream &in, Masina &masina){
		int aux = 0;
		cout << "Introduceti marca masinii\n";
		in >> masina.marca;
		cout << "Introduceti culoarea masinii\n";
		in >> masina.culoare;
		cout << "Introduceti anul fabricatiei\n";
		while (aux == 0){
			aux = 1;
			try {
				in >> masina.an_fabricatie;
				if(masina.an_fabricatie < 1900 || masina.an_fabricatie > 2019)
					throw masina.an_fabricatie;
			}
			catch (...){
				aux = 0;
			}
		}
		return in;
	}
	friend ostream &operator << (ostream &out, Masina &masina){
		out << "Marca masinii:  " << masina.marca << "\n";
		out << "Culoarea masinii:   " << masina.culoare << "\n";
		out << "Anul fabricatiei:   " << masina.an_fabricatie << "\n\n";
		return out;
	}
	Masina &operator =(const Masina &masina){
		marca = masina.marca;
		culoare = masina.culoare;
		an_fabricatie = masina.an_fabricatie;
		return *this;
	}
};

int Masina::nr_masini;

class Coupe: public Masina{
private:
	string combustibil;
public:
	Coupe(){}
	Coupe(string m, string c, int a, string comb): Masina(m,c,a),combustibil(comb){}
	Coupe(const Coupe& coupe): Masina(coupe){
		combustibil = coupe.combustibil;
	}
	~Coupe(){}
	
	virtual void citire(istream &in){
		int p = 0;
		cout << "Introduceti marca masini\n ";
		in >> marca;
		cout << "Introduceti culoarea masinii\n";
		in >> culoare;
		cout << "Introduceti anul fabricatiei\n";
		in >> an_fabricatie;
		cout << "Introduceti tipul de combustibil\n";
		while(p == 0){
			p = 1;
			try{
				in>>combustibil;
				if(combustibil!="Benzina" && combustibil!="Diesel" && combustibil!="GPL" && combustibil!="Hibrid" && combustibil!="Electric")
					if(combustibil!="benzina" && combustibil!="diesel" && combustibil!="gpl" && combustibil!="hibrid" && combustibil!="electric")
						throw combustibil;
			}
			catch(string s){
				p = 0;
			}
		}
	}
	virtual void afisare(ostream& out) const {
		out << "Marca masinii:  " << marca << "\n";
		out << "Culoarea masinii:   " << culoare << "\n";
		out << "Anul fabricatiei:   " << an_fabricatie << "\n";
		out << "Tipul de combustibil:   " << combustibil << "\n\n";
	}
	
	Coupe& operator=(const Coupe& coupe){
		combustibil = coupe.combustibil;
		this->Masina::operator = (coupe);
		return (*this);
	}
};
class Coupe_4: public Masina{
private:
	int rulaj;
public:
	Coupe_4(){}
	Coupe_4(string m, string c, int a, int r): Masina(m,c,a),rulaj(r){}
	Coupe_4(const Coupe_4& coupe4): Masina(coupe4){
		rulaj = coupe4.rulaj;
	}
	~Coupe_4(){}
	
	virtual void citire(istream& in){
		cout << "Introduceti marca masini\n ";
		in >> marca;
		cout << "Introduceti culoarea masinii\n";
		in >> culoare;
		cout << "Introduceti anul fabricatiei\n";
		in >> an_fabricatie;
		cout<<"Introduceti rulajul masinii\n";
		in >> rulaj;
	}
	virtual void afisare(ostream& out){
		out << "Marca masinii:  " << marca << "\n";
		out << "Culoarea masinii:   " << culoare << "\n";
		out << "Anul fabricatiei:   " << an_fabricatie << "\n";
		out << "Rulajul masinii:    " << rulaj << "\n\n";
	}
	
	Coupe_4 &operator = (const Coupe_4& coupe4){
		rulaj = coupe4.rulaj;
		this->Masina::operator=(coupe4);
		return (*this);
	}
};
class Hot_Hatch: public Masina{
private:
	int motor;
public:
	Hot_Hatch(){}
	Hot_Hatch(string m, string c, int a, int mot): Masina(m,c,a),motor(mot){}
	Hot_Hatch(const Hot_Hatch& ob): Masina(ob){
		motor = ob.motor;
	}
	~Hot_Hatch(){}
	
	virtual void citire(istream& in){
		int p = 0;
		cout << "Introduceti marca masini\n ";
		in >> marca;
		cout << "Introduceti culoarea masinii\n";
		in >> culoare;
		cout << "Introduceti anul fabricatiei\n";
		in >> an_fabricatie;
		cout << "Introduceti motorizarea\n";
		while(p == 0){
			p = 1;
			try{
				in >> motor;
				if(motor < 600 || motor > 5000)
					throw motor;
			}
			catch(...){
				p = 0;
			}
		}
	}
	virtual void afisare(ostream& out){
		out << "Marca masinii:  " << marca << "\n";
		out << "Culoarea masinii:   " << culoare << "\n";
		out << "Anul fabricatiei:   " << an_fabricatie << "\n";
		out << "Motorizarea masinii:    "<< motor<< "\n\n";
	}
	
	Hot_Hatch &operator = (Hot_Hatch& hotHatch){
		motor = hotHatch.motor;
		this->Masina::operator = (hotHatch);
		return (*this);
	}
};
class Cabrio: public Masina{
private:
	int locuri;
public:
	Cabrio &operator = (Cabrio& cabrio){
		locuri = cabrio.locuri;
		this->Masina::operator=(cabrio);
		return (*this);
	}
	Cabrio(){}
	Cabrio(string m, string c, int a, int l): Masina(m,c,a),locuri(l){}
	~Cabrio(){}
	Cabrio(const Cabrio& cabrio): Masina(cabrio){
		locuri = cabrio.locuri;
	}
	virtual void citire(istream& in){
		int p=0;
		cout << "Introduceti marca masini\n ";
		in >> marca;
		cout << "Introduceti culoarea masinii\n";
		in >> culoare;
		cout << "Introduceti anul fabricatiei\n";
		in >> an_fabricatie;
		cout << "Introduceti numarul de locuri\n";
		while(p == 0)
		{
			p = 1;
			try
			{
				in >> locuri;
				if(locuri != 2 && locuri != 4)
					throw locuri;
			}
			catch(...)
			{
				p = 0;
			}
		}
	}
	virtual void afisare(ostream& out){
		out << "Marca masinii:  " << marca << "\n";
		out << "Culoarea masinii:   " << culoare << "\n";
		out << "Anul fabricatiei:   " << an_fabricatie << "\n";
		out << "Numarul de locuri:  " << locuri << "\n";
	}
	
};
class Supersport: public Masina{
private:
	int viteza;
	int pret;
public:
	Supersport& operator=(Supersport& ob){
		viteza = ob.viteza;
		pret = ob.pret;
		this->Masina::operator=(ob);
		return (*this);
	}
	Supersport(){};
	Supersport(string m, string c, int a, int v, int p): Masina(m,c,a),viteza(v),pret(p){}
	~Supersport(){}
	Supersport(const Supersport& ob): Masina(ob){
		viteza = ob.viteza;
		pret = ob.pret;
	}
	
	virtual void afisare(ostream& out){
		out << "Marca masinii:  " << marca << "\n";
		out << "Culoarea masinii:   " << culoare << "\n";
		out << "Anul fabricatiei:   " << an_fabricatie << "\n";
		out << "Viteza maxima:   " << viteza << "\n";
		out << "Pretul masinii:   " << pret <<"\n";
	}
	virtual void citire(istream& in){
		int p = 0;
		cout << "Introduceti marca masini\n ";
		in >> marca;
		cout << "Introduceti culoarea masinii\n";
		in >> culoare;
		cout << "Introduceti anul fabricatiei\n";
		in >> an_fabricatie;
		cout << "Introduceti viteza maxima a masinii\n";
		in >> viteza;
		while(p == 0){
			p = 1;
			try{
				in >> viteza;
				if(viteza < 0 || viteza > 400)
					throw viteza;
			}
			catch(...)
			{
				p = 0;
			}
		}
		cout << "Introduceti pretul masinii";
		p = 0;
		while(p == 0){
			p = 1;
			try{
				in >> pret;
				if(pret < 0)
					throw pret;
			}
			catch(...)
			{
				p = 0;
			}
		}
	}
};

template <class T>
class Expozitie{
private:
	int nr_masini;
	T** masini;
public:
	Expozitie& operator=(const Expozitie& ob)
	{
		if(this!=&ob)
		{
			nr_masini=ob.nr_masini;
			for(int i=0;i<nr_masini;i++)
				masini[i]=ob.masini[i];
		}
	}
	Expozitie()
	{
		nr_masini=0;
		masini=new T*[100];
	}
	Expozitie(int i)
	{
		nr_masini=0;
		masini=new T*[i];
	}
	~Expozitie()
	{
		for(int i=0;i<nr_masini;i++)
			delete masini[i];
		delete[] masini;
	}
	Expozitie(const Expozitie& ob)
	{
		nr_masini=ob.nr_masini;
		masini=new T*[100];
		for(int i=0;i<nr_masini;i++)
			masini[i]=ob.masini[i];
	}
	T** get_masini()
	{
		return masini;
	}
	void adaugare_masina(int i);
	void afisare_masini();
};
template<>
class Expozitie <char*>
{
private:
	int nr_stoc,nr_vandute;
	Supersport** stoc;
	Supersport** vandute;
public:
	Expozitie& operator=(const Expozitie& ob)
	{
		if(this!=&ob)
		{
			nr_stoc=ob.nr_stoc;
			nr_vandute=ob.nr_vandute;
			for(int i=0;i<nr_stoc;i++)
				stoc[i]=ob.stoc[i];
			for(int i=0;i<nr_vandute;i++)
				vandute[i]=ob.vandute[i];
			return (*this);
		}
	}
	Expozitie()
	{
		stoc=new Supersport*[100];
		vandute=new Supersport*[100];
		nr_stoc=0;
		nr_vandute=0;
	}
	Expozitie(int i, int j)
	{
		stoc=new Supersport*[i];
		vandute=new Supersport*[j];
	}
	~Expozitie()
	{
		for(int i=0;i<nr_stoc;i++)
			delete stoc[i];
		for(int i=0;i<nr_vandute;i++)
			delete vandute[i];
		delete[] stoc;
		delete[] vandute;
	}
	void afisare_supersport()
	{
		int i;
		cout<<"In stoc: ";
		for(i=0;i<nr_stoc;i++)
		{
			cout<<i+1<<"\n";
			cout<<*(stoc[i]);
		}
		cout<<endl<<"Vandute: ";
		for(i=0;i<nr_vandute;i++)
		{
			cout<<i+1<<"\n";
			cout<<*(vandute[i]);
		}
	}
	int get_nr_stoc()
	{
		return nr_stoc;
	}
	void adaugare_stoc(Supersport& ob);
	Expozitie& operator-=(int i);
};
//template<>
void Expozitie<char*>::adaugare_stoc(Supersport& ob)
{
	stoc[nr_stoc]=new Supersport(ob);
	nr_stoc++;
}
Expozitie<char*>& Expozitie<char*>::operator-=(int i)
{
	vandute[nr_vandute]=new Supersport(*(stoc[i]));
	nr_vandute++;
	delete stoc[i];
	for(int j=i;j<nr_stoc-1;j++)
		stoc[j]=stoc[j+1];
	nr_stoc--;
	return (*this);
}
template<class T>
void Expozitie<T>::adaugare_masina(int i)
{
	switch(i)
	{
		case 1: masini[nr_masini]=new Coupe;
			break;
		case 2: masini[nr_masini]=new Coupe_4;
			break;
		case 3: masini[nr_masini]=new Hot_Hatch;
			break;
		case 4: masini[nr_masini]=new Cabrio;
			break;
		case 5: masini[nr_masini]=new Supersport;
			break;
	}
	cin>>*(masini[nr_masini]);
	nr_masini++;
}
template<class T>
void Expozitie<T>::afisare_masini()
{
	int i;
	for(i=0;i<nr_masini;i++)
	{
		cout<<*(masini[i]);
		cout<<"\n";
	}
}

int main()
{
	int nr,i,tip;
	Expozitie<Masina> masini;
	Expozitie<char*> supersport;
	cout<<"Cate masini doriti sa adaugati?"<<"\n";
	cin>>nr;
	for(i=0;i<nr;i++)
	{
		cout<<"Masina "<<i+1<<":\n 1.Coupe\n 2.Coupe cu 4 usi\n 3.Hot-Hatch\n 4.Cabrio\n 5.Supersport\n"<<"\n";
		cin>>tip;
		masini.adaugare_masina(tip);
		if(tip==5)
		{
			Supersport* sup=dynamic_cast<Supersport*>(masini.get_masini()[i]);
			supersport.adaugare_stoc(*sup);
		}
	}
	cout<<"Toate masinile din expozitie: "<<"\n";
	masini.afisare_masini();
	cout<<"\n";
	cout<<"Meniu:"<<"\n";
	cout<<"1.Afisare masini supersport din stoc sau vandute"<<"\n";
	cout<<"2.Vanzare masina supersport"<<"\n";
	cout<<"3.Exit"<<"\n";
	int opt=0, ord;
	while(opt!=3)
	{
		cout<<"Alegeti"<<"\n";
		cin>>opt;
		if(opt==1)
			supersport.afisare_supersport();
		if(opt==2)
		{
			cout<<"Alegeti numarul de ordine al masinii pe care doriti sa o vindeti"<<"\n";
			int p=0;
			while(p==0)
			{
				p=1;
				try
				{
					cin>>ord;
					ord--;
					if(ord>=supersport.get_nr_stoc())
						throw ord;
				}
				catch(int)
				{
					p=0;
				}
			}
			supersport-=ord;
			cout<<"Masina a fost vanduta!"<<"\n";
		}
	}
	return 0;
}