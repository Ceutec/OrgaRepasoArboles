#include <iostream>

using namespace std;

class Nodo
{
public:
    int num;
    Nodo* hijo_izq;
    Nodo* hijo_der;
    Nodo(int num)
    {
        this->num = num;
        hijo_izq = NULL;
        hijo_der = NULL;
    }
};

class Arbol
{
public:
    Nodo *raiz;

    Arbol()
    {
        raiz=NULL;
    }

    void agregar(Nodo* actual, Nodo* nuevo)
    {
        if(raiz == NULL)
        {
            raiz = nuevo;
        }else
        {
            if(actual->num < nuevo->num)
            {
                if(actual->hijo_izq == NULL)
                {
                    actual->hijo_izq = nuevo;
                }else
                {
                    agregar(actual->hijo_izq,nuevo);
                }
            }else
            {
                if(actual->hijo_der == NULL)
                {
                    actual->hijo_der= nuevo;
                }else
                {
                    agregar(actual->hijo_der,nuevo);
                }
            }
        }
    }

    void imprimir(Nodo* actual)
    {
        if(actual==NULL)
            return;
        cout<<actual->num<<endl;
        imprimir(actual->hijo_izq);
        imprimir(actual->hijo_der);
    }

    void borrar(Nodo* actual, int num)
    {
        if(actual == NULL)
            return;

        if(actual->hijo_izq!=NULL)
        {
            if(actual->hijo_izq->num == num)
            {
                if(actual->hijo_izq->hijo_der == NULL)
                {
                    actual->hijo_izq = actual->hijo_izq->hijo_izq;
                }
                else if(actual->hijo_izq->hijo_izq == NULL)
                {
                    actual->hijo_izq = actual->hijo_izq->hijo_der;
                }
                else
                {
                    Nodo* descartado = actual->hijo_izq->hijo_der;
                    actual->hijo_izq = actual->hijo_izq->hijo_izq;
                    agregar(raiz,descartado);
                }
            }
        }

        if(actual->hijo_der!=NULL)
        {
            if(actual->hijo_der->num == num)
            {
                if(actual->hijo_der->hijo_der == NULL)//Puedo descartar la derecha
                {
                    actual->hijo_der = actual->hijo_der->hijo_izq;
                }
                else if(actual->hijo_der->hijo_izq == NULL)//Puedo descartar la izquierda
                {
                    actual->hijo_der = actual->hijo_der->hijo_der;
                }else
                {
                    Nodo* descartado = actual->hijo_der->hijo_der;
                    actual->hijo_der = actual->hijo_der->hijo_izq;
                    agregar(raiz,descartado);
                }
            }
        }

        borrar(actual->hijo_izq,num);
        borrar(actual->hijo_der,num);
    }
};

int main()
{
    Arbol a;
    a.agregar(a.raiz,new Nodo(5));
    a.agregar(a.raiz,new Nodo(3));
    a.agregar(a.raiz,new Nodo(10));
    a.agregar(a.raiz,new Nodo(1));
    a.agregar(a.raiz,new Nodo(4));
    a.agregar(a.raiz,new Nodo(7));
    a.agregar(a.raiz,new Nodo(15));

    a.borrar(a.raiz,3);
    a.imprimir(a.raiz);
    return 0;
}
