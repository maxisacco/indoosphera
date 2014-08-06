/*
 * pantallas.cpp

 *
 *  Created on: 03/08/2014
 *      Author: msacco
 */
#include <TouchScreenMenu.h>
#include <TouchScreen.h>
#include <TFT.h>
#include <WString.h>
#include <stddef.h>
#include "pantalla.h"
#include "EtiquetaR.h"



/*******************************************/
/***   Esquema Menues                    ***/
/*******************************************/


//TouchScreenMenu confHora = TouchScreenMenu(confHoraItems, 2, 10, 10, CENTERJ, "Configuracion");
//TouchScreenMenu confDesarrollo = TouchScreenMenu(confDesarrolloItems, 2, 10, 10, CENTERJ, "Configuracion");



/*******************************************/
/***   Pantalla Informacion            ***/
/*******************************************/

#define INFORMACION_ANTERIOR NULL


/****** Definicion de Menues ***************/

TouchScreenMenuItem informacionItems[] = {
  TouchScreenMenuItem("ENDOFMENU")
};
/****** Funcion Acciones del Menu ***************/

pantalla * informacionAccion(pantalla * este,TouchScreenMenuItem * item ){
	pantalla *res;
		if(!strcmp(item->getText(),"<-Atras")){
				res = este->getAnterior();
				TSC.clearScreen();
				res->dibujar();
		}
	for (int i=0; i< este->getBotonesLen();i++)
		if(este->getBotones()[i].process()){
			res = este->getAnterior();
			TSC.clearScreen();
			res->dibujar();
		 }

	return res;
}


/****** Definicion de Pantalla ***************/


TouchScreenMenu informacion = TouchScreenMenu(informacionItems, 2, 10, 10, CENTERJ, "Informacion");


/****** Definicion de Botones ***************/
TouchScreenArea informacionBotones[] = {                                             // x       y                    w    h
	TouchScreenButton("Atras", TSC.createColor(255, 0,0 ), TSC.createColor(0, 0, 0), 10, TSC.getScreenHeight()-50 , 2, 10),
//	TouchScreenButton("Listo", TSC.createColor(0, 255, 0 ), TSC.createColor(0, 0, 0), 5+TSC.getScreenWidth()/2, TSC.getScreenHeight()-50 , 2, 10),
};



/****** Funcion Acciones de Botones **********/

pantalla * informacionAccionBotones(pantalla * este){
	pantalla *res=este;
	for (int i=0 ; i< este->getBotonesLen();i++)
		if (i==0 && este->getBotones()[i].process()){
			res=este->getAnterior();
			TSC.clearScreen();
			res->dibujar();
		}

return res;
}

/****** Definicion de EtiquetasR ************/

EtiquetaR informacionEtiquetasR[] = {};

/****** Definicion de labels************/

TouchScreenLabel informacionLables[]={};

pantalla Informacion (NULL,
					informacionItems,
					informacionAccion,
					&informacion,
					informacionBotones,
					sizeof(informacionBotones)/sizeof(informacionBotones[0]),
					informacionAccionBotones,
					informacionEtiquetasR,
					sizeof(informacionEtiquetasR)/sizeof(informacionEtiquetasR[0]),
					informacionLables,
					sizeof(informacionLables)/sizeof(informacionLables[0]));


/*******************************************/
/***   Pantalla Configuracion           ***/
/*******************************************/

#define CONFIGURACION_ANTERIOR NULL


/****** Definicion de Menues ***************/

TouchScreenMenuItem configuracionItems[] = {
		TouchScreenMenuItem("Hora"),
		TouchScreenMenuItem("Desarrollo"),
		TouchScreenMenuItem("<-Atras"),
		TouchScreenMenuItem("ENDOFMENU")
};


/****** Funcion Acciones del Menu ***************/

pantalla * configuracionAccion(pantalla * este,TouchScreenMenuItem * item ){
	pantalla *res;
		if(!strcmp(item->getText(),"<-Atras")){
				res = este->getAnterior();
				TSC.clearScreen();
				res->dibujar();
		}
		else if(!strcmp(item->getText(),"Hora")){
			res = este;
			TSC.clearScreen();
			res->dibujar();
		}
		else if(!strcmp(item->getText(),"Desarrollo")){
				res = este;
				TSC.clearScreen();
				res->dibujar();
		}
return res;
}


/****** Definicion de Pantalla ***************/

TouchScreenMenu configuracion = TouchScreenMenu(configuracionItems, 2, 10, 10, CENTERJ, "Configuracion");

/****** Definicion de Botones ***************/
TouchScreenArea configuracionBotones[] = {
		TouchScreenButton("Atras", TSC.createColor(255, 0,0 ), TSC.createColor(0, 0, 0), 10, TSC.getScreenHeight()-50 , 2, 10),
	//	TouchScreenButton("Listo", TSC.createColor(0, 255, 0 ), TSC.createColor(0, 0, 0), 5+TSC.getScreenWidth()/2, TSC.getScreenHeight()-50 , 2, 10),
};



/****** Funcion Acciones de Botones **********/

pantalla * configuracionAccionBotones(pantalla * este){
	pantalla *res=este;
	for (int i=0 ; i< este->getBotonesLen();i++)
		if (i==0 && este->getBotones()[i].process()){
			res=este->getAnterior();
			TSC.clearScreen();
			res->dibujar();
		}

	return res;
}

/****** Definicion de EtiquetasR ************/

EtiquetaR configuracionEtiquetasR[] = {};

/****** Definicion de labels************/

TouchScreenLabel configuracionLables[]={};

pantalla Configuracion (NULL,
					configuracionItems,
					configuracionAccion,
					&configuracion,
					configuracionBotones,
					sizeof(configuracionBotones)/sizeof(configuracionBotones[0]),
					configuracionAccionBotones,
					configuracionEtiquetasR,
					sizeof(configuracionEtiquetasR)/sizeof(configuracionEtiquetasR[0]),
					configuracionLables,
					sizeof(configuracionLables)/sizeof(configuracionLables[0]));






/*******************************************/
/***   Pantalla principal                ***/
/*******************************************/

#define PRINCIPAL_ANTERIOR NULL


/****** Definicion de Menues ***************/

TouchScreenMenuItem principalItems[] = {
  TouchScreenMenuItem("Informacion"),
  TouchScreenMenuItem("Configuracion"),
  TouchScreenMenuItem("ENDOFMENU")
};

/****** Funcion Acciones del Menu ***************/

pantalla * principalAccion(pantalla * este,TouchScreenMenuItem * item ){
	pantalla *res;
		if(!strcmp(item->getText(),"Configuracion")){
				res = &Configuracion;
				TSC.clearScreen();
				res->dibujar();
		}
		else if(!strcmp(item->getText(),"Informacion")){
				res = &Informacion;
				TSC.clearScreen();
				res->dibujar();
		}
	return res;
}

/****** Definicion de Pantalla ***************/

TouchScreenMenu principal = TouchScreenMenu(principalItems, 2, 10, 10, CENTERJ, "Indoosphera");

/****** Definicion de Botones ***************/
TouchScreenArea principalBotones[] = {
//		TouchScreenButton("Atras", TSC.createColor(255, 0,0 ), TSC.createColor(0, 0, 0), 10, TSC.getScreenHeight()-50 , 2, 10),
//		TouchScreenButton("Listo", TSC.createColor(0, 255, 0 ), TSC.createColor(0, 0, 0), 5+TSC.getScreenWidth()/2, TSC.getScreenHeight()-50 , 2, 10),
};



/****** Funcion Acciones de Botones **********/

pantalla * principalAccionBotones(pantalla * este){return este;}

/****** Definicion de EtiquetasR ************/

EtiquetaR principalEtiquetasR[] = {};

/****** Definicion de labels************/

TouchScreenLabel principalLables[]={};

pantalla Principal (NULL,
					principalItems,
					principalAccion,
					&principal,
					principalBotones,
					sizeof(principalBotones)/sizeof(principalBotones[0]),
					principalAccionBotones,
					principalEtiquetasR,
					sizeof(principalEtiquetasR)/sizeof(principalEtiquetasR[0]),
					principalLables,
					sizeof(principalLables)/sizeof(principalLables[0]));
