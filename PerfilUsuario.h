//
// Created by Carmen Bolaños Villarejo on 5/12/25.
//

#ifndef ACTIVIDADGRUPAL4PEL_PERFILUSUARIO_H
#define ACTIVIDADGRUPAL4PEL_PERFILUSUARIO_H
#include <string>
#include "ListaEnlazada.h"
#include "Contacto.h"

class PerfilUsuario {
private:
    std::string alias;
    int edad;
    std::string descripcion;
    ListaEnlazada<Contacto> misContactos; //Uso de la plantilla obligatoria
public:
    PerfilUsuario(std::string a, int e, std::string d) : alias(a),edad(e),descripcion(d) {}


};


#endif //ACTIVIDADGRUPAL4PEL_PERFILUSUARIO_H