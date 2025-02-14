#include <iostream>
const int Tam=500;

class Pila{
private:
    float datos[Tam];
    int ult;
public:
    Pila(){ult=-1;}
    bool vacia()const{
        if(ult==-1)
            return true;
        return false;
    }
    bool llena()const{
        if(ult==Tam-1)
            return true;
        return false;
    }
    void insertar(float elem, int pos){
        if(llena()|| pos<0 || pos>ult+1){
            std::cout<<"\n Error de insercion";
        }
        else{
            int i=ult+1;
            while(i>pos){
                datos[i]=datos[i-1];
                i--;
            }
            datos[pos]=elem;
            ult++;
        }
    }
    void eliminar(int pos){
        if(vacia() || pos<0 || pos>ult){
            std::cout<<"error de eliminacion";
        }
        else{
            int i=pos;
            while(i<ult){
               datos[i]=datos[i+1];
               i++;
            }
            ult--;
        }
    }
    int ultimo()const{
        return ult;
    }
    
    float recupera(int pos){
        if(vacia() ||pos<0 || pos>ult){
            std::cout<<"\n Insuficiencia datos";
        }
        else{
            return datos[pos];
        }
    }
};

int main()
{
    Pila Mipila;
    for(int i=0; i<400;i++){
        Mipila.insertar(i*.01,Mipila.ultimo()+1);
    }
    for(int i=0; i<400;i++){
        std::cout<<"->"<<Mipila.recupera(Mipila.ultimo());
        Mipila.eliminar(Mipila.ultimo());
    }

    return 0;
}
