#include <iostream>
#include <limits>


int generarnumero(int dif){
    int num;
    if (dif == 1){
        (num = ( rand() % (10 + 1) ) );
        std::cout<<"\nSe a seleccionado * Facil *\n";
        std::cout<<"Rango: 1-10\n\n";
        return num;
    }
    else if (dif == 2){
        (num = ( rand() % (50 + 1) ) );
        std::cout<<"\nSe a seleccionado * Medio *\n";
        std::cout<<"Rango: 1-50\n\n";
        return num;
    }
    else{
        ( num = rand() % (100 + 1) );
        std::cout<<"\nSe a seleccionado * Dificil *\n";
        std::cout<<"Rango: 1-100\n\n";
        return num;
    }
}

bool Adivinanza(int num){
    int intento = 1;
    int adiv;
    while (intento <= 5){
        std::cout<<"Intento "<<intento<<"/5\n";
        std::cout<<"Tu Eleccion: ";
        std::cin>>adiv;
        if ( std::cin.fail() ){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"x Introduccion no Valida x\n";
            continue;
        }
        if (adiv > num){
            std::cout<<"\nTu eleccion es mas alta\n";
        }
        else if(adiv < num){
            std::cout<<"\nTu eleccion es mas baja\n";
        }
        else
            return true;
        intento++;
    }
    return false;
}

int main(){
    int dif;
    int num;
    int jugar;
    
    while (true){
        std::cout<<"** Adivina el Numero **\n\n";
        std::cout<<"1- Iniciar Juego    2- Cerrar\n";
        std::cout<<"Eleccion: ";
        std::cin>>jugar;
        if ( std::cin.fail() ){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\n\nx Introduccion no Valida x\n";
            continue;
        }
        switch (jugar){
        case 1:
            std::cout<<"Dificultad: 1- Facil   2- Medio   3- Dificil \n";
            std::cout<<"Tu Seleccion: ";
            std::cin>>dif;
            if ( std::cin.fail() ){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"x Introduccion no Valida x\n";
                continue;
            }
            num = generarnumero(dif);
            if(Adivinanza(num)){
                std::cout<<"\n** Has Ganado **\n\n";
                std::cout<<"x El numero era: "<<num<<" x\n\n";
                continue;
            }
            else{
                std::cout<<"\n** Has Perdido **\n";
                std::cout<<"x El numero era: "<<num<<" x\n\n";

                continue;
            }
        case 2:
            break;
        
        default:
            std::cout<<"xx Opcion no Valida xx";
        }
        
    }
}