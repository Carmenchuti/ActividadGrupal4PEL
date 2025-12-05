//
// Created by Carmen Bolaños Villarejo on 5/12/25.
//

#ifndef ACTIVIDADGRUPAL4PEL_CONTACT_H
#define ACTIVIDADGRUPAL4PEL_CONTACT_H
#include <string>
#include <iostream>

class Contacto {
private:
    std::string nombre;
    std::string telefono;
    int edad;
public:
    Contacto() { }//Constructor por defecto
    Contacto(std::string n, std:.string t, int e) : nombre(n), telefono(t), edad(e) {}
    //Getters
    std::string getNombre() const { return nombre;}
    std::string getTelefono() const { return telefono;}
    int getEdad() const { return edad;}

    //Setters
    void setnombre(std::string n){ nombre = n; }
    void setTelefono(std::string t){ telefono = t; }
    void setEdad(int e){ edad = e;}

    //Sobrecarga de operador == IMPORTANTE para la lista enlazada
    //Se considera duplicado si tienen el mismo teléfono
    bool operator == (const Contacto& otro) const {
        return this->telefono == otro.telefono;
    }

    //Metodo para imprimir info
    void imprimirInfo() const {
        std::cout << " - " << nombre << " (" << edad << " años) | Tlf: " << telefono << std:.endl;
    }
};


#endif //ACTIVIDADGRUPAL4PEL_CONTACT_H