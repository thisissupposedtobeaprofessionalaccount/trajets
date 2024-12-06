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
    T getData() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void setData(T d);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    Cell *getNext() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void setNext(Cell *n);
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

    Cell (T value);
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
    T data;
    Cell* next;
};

//-------------------------------- Autres definitions dependantes de <Cell>

#endif // CELL_H
