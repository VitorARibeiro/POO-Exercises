
#include<iostream>
#include<fstream>

using namespace std;

class Data
{
private:
    int ano,mes,dia;
public:
//construtores
    Data();
    Data(int _dia,int _mes, int _ano);

 //getters e setters

    void SetDia(int _dia);
    void SetMes(int _mes);
    void SetAno(int _ano);
    int GetDia();
    int GetMes();
    int GetAno();

//metodos
    void Show();
    void Update(int _ano, int _mes, int _dia);
    bool Igual(Data x);
    
    friend bool operator== (Data& x , Data& y);
    friend bool operator!= (Data& x , Data& y);
    friend ostream& operator<< (ostream& os, Data& y);
    friend istream& operator>> (istream& is , Data& y);

    void ReadFile(ifstream& is);
    void WriteFile(ofstream& os);
};

