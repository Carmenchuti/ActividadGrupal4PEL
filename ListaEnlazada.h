//
// Created by Carmen Bolaños Villarejo on 5/12/25.
//

#ifndef ACTIVIDADGRUPAL4PEL_LINKEDLIST_H
#define ACTIVIDADGRUPAL4PEL_LINKEDLIST_H
#include <iostream>
//Estructura del Nodo(Template)
template <typename T>
struct Node {
    T data;
    Node* next;

    Node (T value) : data(value), next(nullptr) {}
};

//Clase Lista Enlazada (Template)
template <typename T>
class ListaEnlazada {
private:
    Node<T>* head;
    int size;
public:
    ListaEnlazada() : head(nullptr), size(0) {}
    //Destructor para limpiar memoria
    ~ListaEnlazada() {
        limpiar();
    }
    void limpiar() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        size = 0;
    }
    //Insertar al final
    void push_back(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
        }else {
            Node<T>* current = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }
    //Eliminar por valor (requiere que T tenga operador ==)
    bool remove(T value) {
        if (!head) return false;

        if (head->data == value) {
            Node<T>* toDelete  = head;
            head = head->next;
            delete toDelete;
            size--;
            return true;
        }
        Node<T>* current = head;
        while (current->next && current->next->data == value) {
            current = current->next;
        }
        if (current->next) {
            Node<T>* toDelete = current->next;
            current->next = toDelete->next;
            delete toDelete;
            size--;
            return true;
        }
        return false;
    }
    //Comprobar si existe un elemento
    bool contains(T value) {
        Node<T>* current = head;
        while (current) {
            if (current->data == value) return true;
            current = current->next;
        }
        return false;
    }
    //Obtener tamaño
    int getSize() const { return size;}
    //Obetener nodo cabeza (para iterar externamente si es necesario
    Node<T>* getHead() const { return head;}
};


#endif //ACTIVIDADGRUPAL4PEL_LINKEDLIST_H