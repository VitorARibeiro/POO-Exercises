#include "Class.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Data::Data(){ano = 0; dia = 0 ; mes = 0;}
Data::Data(int _dia,int _mes, int _ano){ano = _ano;mes = _mes;dia = _dia;}
//setters

void Data::SetDia(int _dia){dia = _dia;}
void Data::SetMes(int _mes){dia = _mes;}
void Data::SetAno(int _ano){dia = _ano;}
int Data::GetDia(){return dia;}
int Data::GetMes(){return mes;}
int Data::GetAno(){return ano;}

//metodos

void Data::Show(){
    cout << "dia: " << dia << endl;
    cout << "mes: " << mes << endl;
    cout << "ano: " << ano << endl;
}

void Data::Update(int _ano, int _mes, int _dia){
    ano = _ano;
    mes = _mes;
    dia = _dia;
}

bool Data::Igual(Data x){
    if (x.ano == ano && x.mes == mes && x.dia == dia){
        return true;
    }
    else{
        return false;
    }
}

bool operator==(Data& x , Data& y){
      if (x.ano == y.ano && x.mes == y.mes && x.dia == y.dia){
        return true;
    }
    else{
        return false;
    }
}

bool operator!=(Data& x , Data& y){
      if (x.ano == y.ano && x.mes == y.mes && x.dia == y.dia){
        return false;
    }
    else{
        return true;
    }
    
}

ostream& operator<< (ostream& os, Data& y){
    os << "dia: " << y.dia << endl;
    os << "mes: " << y.mes << endl;
    os << "ano: " << y.ano << endl;

    return os;
}

istream& operator>> (istream& is , Data& y){

    cout << "indique o dia : ";
    is >> y.dia ;
    cout << "indique o mes : ";
    is >> y.mes ;
    cout << "indique o ano : ";
    is >> y.ano ;

    return is;
}

void Data::WriteFile(ofstream& os){

    os << dia << "/" << mes << "/" << ano <<endl; // ou entao usar getters
}

void Data::ReadFile(ifstream& is){
    string aux;

    getline(is, aux, '/');
    dia = stoi(aux);

    getline(is, aux, '/');
    mes = stoi(aux);

    getline(is, aux);
    ano = stoi(aux);


}
int main(){

    Data Ultimo(14,10,15),Primeiro;

    ofstream escrever;
    ifstream ler;

    escrever.open("escrita.txt");
    
    if(!escrever){
        cout << "erro ao abrir ficheiro" <<endl;
    }

    ler.open("escrita.txt");

     if(!escrever){
        cout << "erro ao abrir ficheiro" <<endl;
    }
    

    
    Ultimo.WriteFile(escrever);

    escrever.close();


    Primeiro.ReadFile(ler);

    cout << Primeiro ;

    ler.close();




    

    return 0;
}
