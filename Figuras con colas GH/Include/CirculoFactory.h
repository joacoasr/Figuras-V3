//============================================================================
// Name        : CirculoFactory.h
// Author      : Joaquin Gonzalez
// Version     : 1
// Copyright   : --
// Description : Clases, polimorfismo, herencia C++, Ansi-style
//============================================================================

#ifndef CIRCULOFACTORY_H_
#define CIRCULOFACTORY_H_

#include "FigureFactory.h"
#include "Punto.h"
#include "Circulo.h"
#include "FigurasGeometricas.h"


class CirculoFactory:public FigureFactory {

	private:


	public:

		//CirculoFactory();
		virtual ~CirculoFactory();
		FigurasGeometricas *CrearFigura();
		void MostrarFiguraACrear();


};

#endif /* CIRCULOFACTORY_H_ */
