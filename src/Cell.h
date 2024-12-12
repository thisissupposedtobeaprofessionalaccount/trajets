/*************************************************************************
                           Cell  -  description
                             -------------------
    debut                : 26/11/2024
    copyright            : (C) 2024 par Dan Maria-Andrada et Marin Hugo
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Cell> (fichier Cell.h) ----------------
#if ! defined (CELL_H )
#define CELL_H

//--------------------------------------------------- Interfaces utilisees

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <Cell>
//
//
//------------------------------------------------------------------------

template <typename T>
class Cell 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques
    // type Methode ( liste des parametres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    const T* getData() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void setData(const T& d);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    const Cell *getNext() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void setNext(const Cell *n);
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Cell ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Cell (const T& value);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Cell ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Methodes protegees

//----------------------------------------------------- Attributs proteges
    T* data;
    Cell* next;
};

//-------------------------------- Autres definitions dependantes de <Cell>
template <typename T>
const T* Cell<T>::getData() const
// Algorithme :
//
{
    return data;
} //----- Fin de getData

template <typename T>
void Cell<T>::setData(const T& d)
// Algorithme :
//
{
    data = d;
} //----- Fin de setData

template <typename T>
const Cell<T>* Cell<T>::getNext() const
// Algorithme :
//
{
    return next;
} //----- Fin de getNext

template <typename T>
void Cell<T>::setNext(const Cell *n)
// Algorithme :
//
{
    next = n;
} //----- Fin de setNext

//------------------------------------------------- Surcharge d'opérateurs
/*Xxx & Xxx::operator = ( const Xxx & unXxx )
// Algorithme :
//
{
} //----- Fin de operator =*/

//-------------------------------------------- Constructeurs - destructeur
template <typename T>
Cell<T>::Cell ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cell>" << endl;
#endif
    data = 0;
    next = nullptr;
} //----- Fin de Cell

template <typename T>
Cell<T>::Cell (const T& value) //: data(value)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cell>" << endl;
#endif
    *this->data = value;
    this->next = nullptr;
} //----- Fin de Cell

template <typename T>
Cell<T>::~Cell()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Cell>" << endl;
#endif
} //----- Fin de ~Cell

#endif // CELL_H
