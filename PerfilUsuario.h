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
    //Getter
    std::string getAlias() const { return alias;}

    //Agregar contacto
    void agregarContacto(Contacto c) {
        //Evitamos duplicados al añadir
        if (!misContactos.contains(c)) {
            misContactos.push_back(c);
            std::cout << "Contacto " << c.getNombre() << " agregado exitosamente." << std::endl;
        }else {
            std::cout << "Error: El contacto ya existe en tu lista."<< std::endl;
        }
    }
    void eliminarContacto(std::string telefono) {
        //Creamos un contacto temporal solo con el telefono para comparar
        Contacto temp("", telefono, 0);
        if (misContactos.remove(temp)) {
            std::cout << "Contacto eliminado." << std::endl;
        }else {
            std::cout << "No se encontró un contacto con ese telefono. "<< std::endl;
        }
    }
    void mostrarTodosLosContactos() {
        Node<Contacto>* actual = misContactos.getHead();
        std::cout << "--- Contactos de " << alias << " ---" << std::endl;
        if (!actual) {
            std::cout << "(Lista vacía)" << std::endl;
        }
        while (actual) {
            actual->data.imprimirInfo();
            actual = actual->next;
        }
    }
    //Importar contactos sin duplicados
    void importarContactosDe(PerfilUsuario& otroUsuario) {
        Node<Contacto>* nodoOtro = otroUsuario.misContactos.getHead();
        int contador = 0;
        std::cout << "Iniciando importación desde el perfil de " << otroUsuario.getAlias() << "..." << std::endl;

        while (nodoOtro) {
            //Reutilizamos 'contiene' de la lista para no duplicar
            if (!this->misContactos.contains(nodoOtro->data)) {
                this->misContactos.push_back(nodoOtro->data);
                contador++;
            }
            nodoOtro = nodoOtro->next;
        }
        std::cout << "Importación completada: "<< contador << " contactos nuevos agregados." << std::endl;
    }
};


#endif //ACTIVIDADGRUPAL4PEL_PERFILUSUARIO_H