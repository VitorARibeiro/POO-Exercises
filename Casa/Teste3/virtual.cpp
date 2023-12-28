#include <iostream>

using namespace std;

class instrumento{
    public:
    virtual void play(){
        cout << "playing instrument..." << endl;
    }
};


class guitarra : public instrumento{
public:
    void play(){
        cout << "playing guitar..."<< endl;
    }

};

class saxofone : public instrumento{
public:
    void play(){
        cout << "playing saxo..."<< endl;
    }

};

int main(){
    instrumento* inst = new instrumento;
    instrumento* guit = new guitarra;
    instrumento* sax = new saxofone;
    inst->play();
    guit->play();
    sax->play();  


  


    return 0;
}