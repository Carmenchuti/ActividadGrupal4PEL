#include <iostream>
#include <string>
#include "ListaEnlazada.h"
#include "Contacto.h"
#include "PerfilUsuario.h"

// ---------------------------------------------------------
// ZONA DE FUNCIONES AUXILIARES (Tienen que ir ANTES del main)
// ---------------------------------------------------------

// Función auxiliar para pausar y limpiar pantalla
void esperarYLimpiar() {
    std::cout << "\nPresiona ENTER para continuar...";
    std::cin.ignore();
    if (std::cin.peek() == '\n') std::cin.ignore(); // Limpieza extra de buffer por si acaso
    // Simulamos limpiar pantalla con saltos de línea
    for(int i=0; i<50; i++) std::cout << std::endl;
}

// Función para cargar datos iniciales
// Fíjate que esta función está FUERA del main
void cargarDatosIniciales(ListaEnlazada<PerfilUsuario>& listaUsuarios) {
    // --- USUARIO 1: Juan ---
    PerfilUsuario u1("Juan", 25, "Amante del senderismo");
    u1.agregarContacto(Contacto("Lucia", "600111001", 24));
    u1.agregarContacto(Contacto("Pedro", "600111002", 26));
    u1.agregarContacto(Contacto("Maria", "600111003", 22));
    u1.agregarContacto(Contacto("Sofia", "600111004", 25));
    u1.agregarContacto(Contacto("Carlos", "600111005", 27));
    listaUsuarios.push_back(u1);

    // --- USUARIO 2: Ana ---
    PerfilUsuario u2("Ana", 30, "Fotografia y viajes");
    u2.agregarContacto(Contacto("Miguel", "600222001", 31));
    u2.agregarContacto(Contacto("Elena", "600222002", 29));
    u2.agregarContacto(Contacto("Jorge", "600222003", 35));
    u2.agregarContacto(Contacto("Laura", "600222004", 28));
    u2.agregarContacto(Contacto("David", "600222005", 30));
    listaUsuarios.push_back(u2);

    // --- USUARIO 3: Luis ---
    PerfilUsuario u3("Luis", 22, "Gamer y estudiante");
    u3.agregarContacto(Contacto("Pablo", "600333001", 21));
    u3.agregarContacto(Contacto("Marta", "600333002", 23));
    u3.agregarContacto(Contacto("Sara", "600333003", 22));
    u3.agregarContacto(Contacto("Raul", "600333004", 20));
    u3.agregarContacto(Contacto("Irene", "600333005", 24));
    listaUsuarios.push_back(u3);

    std::cout << "Sistema inicializado con 3 perfiles y 15 contactos cargados.\n" << std::endl;
}

// Función para buscar usuario
// También FUERA del main
Node<PerfilUsuario>* buscarUsuario(ListaEnlazada<PerfilUsuario>& lista, std::string aliasBusqueda) {
    Node<PerfilUsuario>* actual = lista.getHead();
    while (actual) {
        if (actual->data.getAlias() == aliasBusqueda) {
            return actual;
        }
        actual = actual->next;
    }
    return nullptr;
}

// ---------------------------------------------------------
// FUNCIÓN MAIN (Aquí empieza el programa)
// ---------------------------------------------------------
int main() {
    // 1. Crear la lista principal
    ListaEnlazada<PerfilUsuario> baseDeDatosUsuarios;

    // 2. Cargar los datos (llamamos a la función de arriba)
    cargarDatosIniciales(baseDeDatosUsuarios);

    Node<PerfilUsuario>* usuarioActivo = nullptr;
    int opcion = -1;
    std::string inputBuffer;

    // 3. Bucle del menú
    do {
        if (usuarioActivo == nullptr) {
            // --- MENÚ PRINCIPAL (LOGIN) ---
            std::cout << "=== TINDER: GESTION DE CONTACTOS ===" << std::endl;
            std::cout << "1. Iniciar Sesion (Seleccionar Perfil)" << std::endl;
            std::cout << "2. Ver todos los perfiles registrados" << std::endl;
            std::cout << "0. Salir" << std::endl;
            std::cout << "Seleccione una opcion: ";
            std::cin >> opcion;

            if (opcion == 1) {
                std::cout << "Ingrese el nombre del usuario: ";
                std::cin >> inputBuffer;
                usuarioActivo = buscarUsuario(baseDeDatosUsuarios, inputBuffer);
                if (!usuarioActivo) {
                    std::cout << "Usuario no encontrado." << std::endl;
                } else {
                    std::cout << "Bienvenido/a, " << usuarioActivo->data.getAlias() << "!" << std::endl;
                }
                esperarYLimpiar();
            }
            else if (opcion == 2) {
                Node<PerfilUsuario>* temp = baseDeDatosUsuarios.getHead();
                std::cout << "\n--- Usuarios Registrados ---" << std::endl;
                while (temp) {
                    std::cout << "- " << temp->data.getAlias() << std::endl;
                    temp = temp->next;
                }
                esperarYLimpiar();
            }
        }
        else {
            // --- MENÚ DE USUARIO LOGUEADO ---
            std::cout << "=== PERFIL DE " << usuarioActivo->data.getAlias() << " ===" << std::endl;
            std::cout << "1. Ver mis contactos" << std::endl;
            std::cout << "2. Agregar nuevo contacto" << std::endl;
            std::cout << "3. Eliminar contacto" << std::endl;
            std::cout << "4. IMPORTAR contactos de otro usuario" << std::endl;
            std::cout << "9. Cerrar Sesion (Volver al menu principal)" << std::endl;
            std::cout << "0. Salir del programa" << std::endl;
            std::cout << "Seleccione una opcion: ";
            std::cin >> opcion;

            if (opcion == 1) {
                usuarioActivo->data.mostrarTodosLosContactos();
                esperarYLimpiar();
            }
            else if (opcion == 2) {
                std::string n, t;
                int e;
                std::cout << "Nombre: "; std::cin >> n;
                std::cout << "Telefono: "; std::cin >> t;
                std::cout << "Edad: "; std::cin >> e;
                usuarioActivo->data.agregarContacto(Contacto(n, t, e));
                esperarYLimpiar();
            }
            else if (opcion == 3) {
                std::string t;
                std::cout << "Introduce el telefono del contacto a eliminar: ";
                std::cin >> t;
                usuarioActivo->data.eliminarContacto(t);
                esperarYLimpiar();
            }
            else if (opcion == 4) {
                std::string otroNombre;
                std::cout << "Nombre del usuario del que quieres importar contactos: ";
                std::cin >> otroNombre;

                if (otroNombre == usuarioActivo->data.getAlias()) {
                    std::cout << "No puedes importar contactos de ti mismo." << std::endl;
                } else {
                    Node<PerfilUsuario>* otroUsuario = buscarUsuario(baseDeDatosUsuarios, otroNombre);
                    if (otroUsuario) {
                        usuarioActivo->data.importarContactosDe(otroUsuario->data);
                    } else {
                        std::cout << "El usuario origen no existe." << std::endl;
                    }
                }
                esperarYLimpiar();
            }
            else if (opcion == 9) {
                usuarioActivo = nullptr;
                std::cout << "Sesion cerrada." << std::endl;
                esperarYLimpiar();
            }
        }

    } while (opcion != 0);

    std::cout << "Cerrando aplicacion..." << std::endl;
    return 0;
}