//============================================================================
// Name        : Nodos.cpp
// Author      : Joaquin Gonzalez
// Version     : 1
// Copyright   : --
// Description : Clases, polimorfismo, herencia C++, Ansi-style
//============================================================================


#include "../Include/Nodo.h"

#include <iostream>

#include "../Include/ControlDeFiguras.h"

using namespace std;

/*Nodo::Nodo() {

};*/
void Nodo::setid(int ident){

	this -> id = ident;

};
void Nodo::setFigurasGeometricas(FigurasGeometricas *FG){

	this -> FiGe = FG;

};
void Nodo::setNodo(Nodo *ptrsig){

	this -> PtrSiguiente = ptrsig;

};
int Nodo::getid(){

	return(this->id);
}

FigurasGeometricas *Nodo::getFigGeo(){

	return(this->FiGe);

};
Nodo *Nodo::getNodo(){

	return(this->PtrSiguiente);

};

Nodo::~Nodo() {

}

void Nodo::Lista_Push(Nodo *&Frente, Nodo *&Final, FigurasGeometricas *FigGeo, int M){

	 Nodo *NuevoNodo = new Nodo();          //Creacion nuevo nodo
	 NuevoNodo -> FiGe = FigGeo;			//Creacion nuevo nodo
	 NuevoNodo -> PtrSiguiente = NULL;		//Creacion nuevo nodo
	 NuevoNodo -> id = M;

	 if( ListaVacia(Frente) ){

		 Frente = NuevoNodo;

	 }else{

		 Final -> PtrSiguiente = NuevoNodo;

	 }

	 Final = NuevoNodo;
	 cout << "\nFigura correctamente incertada." << endl ;

};

bool Nodo::ListaVacia(Nodo *Frente){

	if( Frente == NULL ){

		return true;

	}else{

		return false;

	}
};

void Nodo::Lista_Pop(Nodo *&Frente, Nodo *&Final){

	Nodo *aux = Frente;
	Nodo *actual = new Nodo();
	actual = Frente;
	int idaux;

	if( ListaVacia(Frente) ){

		cout << "\n-----Lista vacia.-----" << endl;

	}else{

		while ( actual -> PtrSiguiente != NULL ){

			actual = actual -> PtrSiguiente;
			idaux = ( actual -> getid() ) - 1;
			actual -> setid(idaux);
		}

		if ( Frente == Final ){

			Frente = NULL;
			Final = NULL;

		}else{

			Frente = Frente -> PtrSiguiente;

		}

		delete (aux);
		cout << "\nFigura eliminada correctamente." << endl;
	}
};

void Nodo::mostrar_lista(Nodo *Frente){

	Nodo *actual = new Nodo();
	actual = Frente;

	if( ListaVacia(Frente) ){

		cout << "\n-----Lista vacia.-----" << endl;

	}else{

		cout <<"\n-----Lista:-----" << endl;

		while ( actual != NULL ){

			cout << "\nid Figura: " << actual -> id << endl;
			actual -> FiGe-> mostrarDatos();
			actual = actual -> PtrSiguiente;
			cout <<"\n----------------" << endl;
		}
	}
};

void Nodo::EliminarFiguraSegunId(Nodo *&Frente, int eliminar, int M){

	Nodo *actual = new Nodo();
	Nodo *anterior = new Nodo();
	Nodo *aux_cambioId = new Nodo();
	int idaux;

	actual = Frente;

	if( ListaVacia(Frente) ){

		cout << "\n-----Lista vacia.-----" << endl;

	}else{

		if( eliminar > 0 ){

			while( ( actual != NULL ) && ( actual -> id != eliminar ) ){

				anterior = actual;
				actual = actual -> PtrSiguiente;
				aux_cambioId->PtrSiguiente = actual;
			}

			anterior -> PtrSiguiente = actual -> PtrSiguiente;

		}

		if( actual -> getid() < M){

			aux_cambioId = actual->PtrSiguiente;

			while( aux_cambioId != NULL ){

				idaux = ( aux_cambioId -> getid() )-1;
				aux_cambioId -> setid(idaux);
				aux_cambioId = aux_cambioId -> PtrSiguiente;

			}
		}

		if( eliminar == 0 ){

			Frente = Frente -> PtrSiguiente;

		}

		delete (actual);
		cout << "\nFigura eliminada correctamente." << endl;
	}
};
void Nodo::CambiarFiguraDePosicion(Nodo *&Frente, int PosInicial, int PosFinal){

	Nodo *ptrPosInicial = new Nodo();
	Nodo *auxptrPosInicial = new Nodo();
	Nodo *ptrPosFinal = new Nodo();
	Nodo *auxptrPosFinal = new Nodo();
	Nodo *auxPF = new Nodo();
	Nodo *auxPI = new Nodo();

	int auxId;

	ptrPosInicial = Frente;
	auxptrPosInicial = Frente;
	ptrPosFinal = Frente;
	auxptrPosFinal = Frente;

//////////////////////////////////////////PosFinal///////////////////////////////////////////////////
	while( ( ptrPosFinal != NULL ) && ( ptrPosFinal -> id != PosFinal ) ){

		auxptrPosFinal = ptrPosFinal;							//Recorro hasta encontrar el nodo con el id que necesito
		ptrPosFinal = ptrPosFinal -> PtrSiguiente;				//Guardo la posicion y la del nodo anterior,Posicion final en este caso
		auxPF -> PtrSiguiente = auxptrPosFinal -> PtrSiguiente;

	}
/////////////////////////////////////////PosInicial///////////////////////////////////////////////////
	while( ( ptrPosInicial != NULL ) && ( ptrPosInicial -> id != PosInicial ) ){

		auxptrPosInicial = ptrPosInicial;						//Recorro hasta encontrar el nodo con el id que necesito
		ptrPosInicial = ptrPosInicial -> PtrSiguiente;			//Guardo la posicion y la del nodo anterior,Posicion inicial en este caso
		auxPI -> PtrSiguiente = auxptrPosInicial -> PtrSiguiente;

	}
/////////////////////////////////////////////A//////////////////////////////////////////////////////
	if( PosInicial > PosFinal ){

		auxPI = ptrPosInicial -> PtrSiguiente;

		if( PosFinal == 0 ){

			Frente = auxptrPosInicial -> PtrSiguiente;
			auxptrPosInicial -> PtrSiguiente = ptrPosInicial -> PtrSiguiente;
			ptrPosInicial -> PtrSiguiente = ptrPosFinal;

		}else{

			auxptrPosFinal -> PtrSiguiente = auxptrPosInicial -> PtrSiguiente;
			auxptrPosInicial -> PtrSiguiente = ptrPosInicial -> PtrSiguiente;
			ptrPosInicial -> PtrSiguiente = auxPF -> PtrSiguiente;

		}
			/////////Cambio de id/////////
			auxId = ptrPosFinal-> getid();
			ptrPosInicial -> setid(auxId);

		while( ( ptrPosFinal != NULL ) && (  ptrPosFinal  != auxPI) ){  //cambio los id de cada nodo

			cout << "\nptrPosFinal: " << ( ptrPosFinal -> getid() ) << endl;
			auxId = ( ptrPosFinal -> getid() ) + 1;
			ptrPosFinal -> setid(auxId);
			ptrPosFinal = ptrPosFinal -> PtrSiguiente;

		}

/////////////////////////////////////////////B////////////////////////////////////////////////////
	}else if( PosInicial < PosFinal ){

		if( PosInicial == 0 ){

			auxPI -> PtrSiguiente = ptrPosFinal -> PtrSiguiente;
			ptrPosFinal -> PtrSiguiente = Frente;
			Frente = ptrPosInicial -> PtrSiguiente;
			ptrPosInicial -> PtrSiguiente = auxPI -> PtrSiguiente;

		}else{

			auxptrPosInicial -> PtrSiguiente = ptrPosInicial -> PtrSiguiente;
			ptrPosInicial -> PtrSiguiente = ptrPosFinal -> PtrSiguiente;
			ptrPosFinal -> PtrSiguiente = auxPI -> PtrSiguiente;

		}

		/////////Cambio de id/////////
		auxId = ptrPosFinal -> getid();
		ptrPosInicial -> setid(auxId);

		if( PosInicial != 0 ){

			while( ( auxptrPosInicial != NULL ) && ( auxptrPosInicial != ptrPosFinal ) ){

				auxptrPosInicial = auxptrPosInicial -> PtrSiguiente;
				auxId = ( auxptrPosInicial -> getid() ) - 1;
				auxptrPosInicial -> setid(auxId);

			}

		}else{

			auxptrPosInicial = Frente;

			while( ( auxptrPosInicial != NULL ) && ( auxptrPosInicial != ptrPosInicial ) ){

				auxId = ( auxptrPosInicial -> getid() ) - 1;
				auxptrPosInicial -> setid(auxId);
				auxptrPosInicial = auxptrPosInicial -> PtrSiguiente;

			}
		}

	}
};
void Nodo::ReubicarFinalDeLaLista(Nodo *Frente, Nodo *&Final, int M){

	Nodo *actual = new Nodo();
	actual = Frente;


	while ( actual != NULL ){

		if( ( actual -> getid() == ( M - 1 ) ) ){

			Final = actual;

		}
		actual = actual -> PtrSiguiente;

	}

}
