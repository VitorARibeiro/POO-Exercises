
#include<iostream>
#include<fstream>

using namespace std;

class Data
{
private:
    int ano,mes,dia;
public:
    Data(){ano = 0; dia = 0 ; mes = 0;}
    Data(int _dia,int _mes, int _ano){ano = _ano;mes = _mes;dia = _dia;}
//setters

    void SetDia(int _dia){dia = _dia;}
    void SetMes(int _mes){dia = _mes;}
    void SetAno(int _ano){dia = _ano;}
    int GetDia(){return dia;}
    int GetMes(){return mes;}
    int GetAno(){return ano;}

//metodos

    void Show(){
        cout << "dia: " << dia << endl;
        cout << "mes: " << mes << endl;
        cout << "ano: " << ano << endl;
    }

    void Update(int _ano, int _mes, int _dia){
        ano = _ano;
        mes = _mes;
        dia = _dia;
    }

    bool Igual(Data x){
        if (x.ano == ano && x.mes == mes && x.dia == dia){
            return true;
        }
        else{
            return false;
        }
    }

    friend bool operator==(Data& x , Data& y){
        if (x.ano == y.ano && x.mes == y.mes && x.dia == y.dia){
            return true;
        }
        else{
            return false;
        }
    }

    friend bool operator!=(Data& x , Data& y){
        if (x.ano == y.ano && x.mes == y.mes && x.dia == y.dia){
            return false;
        }
        else{
            return true;
        }
        
    }

    friend ostream& operator<< (ostream& os, Data y){
        os << "dia: " << y.dia << endl;
        os << "mes: " << y.mes << endl;
        os << "ano: " << y.ano << endl;

        return os;
    }

    friend istream& operator>> (istream& is , Data& y){

        cout << "indique o dia : ";
        is >> y.dia ;
        cout << "indique o mes : ";
        is >> y.mes ;
        cout << "indique o ano : ";
        is >> y.ano ;

        return is;
    }

    void WriteFile(ofstream& os){

        os << dia << "/" << mes << "/" << ano <<endl; // ou entao usar getters
    }

    void ReadFile(ifstream& is){
        string aux;

        getline(is, aux, '/');
        dia = stoi(aux);

        getline(is, aux, '/');
        mes = stoi(aux);

        getline(is, aux);
        ano = stoi(aux);


    }

};
 // definicoes fora da class



class Pessoa{
    private:
        string nome,morada;
        Data data;
    public:
    
    void SetNome(string _nome){nome = nome;} 
    void SetDatan(int _dia , int _mes , int _ano){
        data.SetAno(_ano);
        data.SetDia(_dia);
        data.SetMes(_mes);
    }
    void SetMorada(string _morada){morada = _morada;} 
    string GetNome(){return nome;} 
    Data GetDatan(){return data;} 
    string GetMorada(){return morada;}



}