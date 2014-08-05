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

TouchScreenMenuItem informacionItems[] = {
  TouchScreenMenuItem("ENDOFMENU")
};
TouchScreenMenu _informacion = TouchScreenMenu(informacionItems, 2, 10, 10, CENTERJ, "Informacion");
TouchScreenArea informacionBotones[] = {                                             // x       y                    w    h
	TouchScreenButton("Atras", TSC.createColor(255, 0,0 ), TSC.createColor(0, 0, 0), 10, TSC.getScreenHeight()-50 , 2, 10),
//	TouchScreenButton("Listo", TSC.createColor(0, 255, 0 ), TSC.createColor(0, 0, 0), 5+TSC.getScreenWidth()/2, TSC.getScreenHeight()-50 , 2, 10),
};


pantalla * informacionAccion(pantalla * este,TouchScreenMenuItem * item ){
	pantalla *res;
		if(!strcmp(item->getText(),"<-Atras")){
				res = este->getAnterior();
				TSC.clearScreen();
				res->dibujar();
		}
	for (int i=0; i< este->botonesLen;i++)
		if(este->botones[i].process()){
			res = este->getAnterior();
			TSC.clearScreen();
			res->dibujar();
		 }

	return res;
}

pantalla Informacion(NULL,
					informacionItems,
					informacionAccion,
					&_informacion,
					informacionBotones,
					sizeof(informacionBotones)/sizeof(informacionBotones[0]));


/*******************************************/
/***   Pantalla Configuracion           ***/
/*******************************************/

TouchScreenMenuItem configuracionItems[] = {
		TouchScreenMenuItem("Hora"),
		TouchScreenMenuItem("Desarrollo"),
		TouchScreenMenuItem("<-Atras"),
		TouchScreenMenuItem("ENDOFMENU")
};

TouchScreenArea configuracionBotones[] = {
		TouchScreenButton("Atras", TSC.createColor(255, 0,0 ), TSC.createColor(0, 0, 0), 10, TSC.getScreenHeight()-50 , 2, 10),
	//	TouchScreenButton("Listo", TSC.createColor(0, 255, 0 ), TSC.createColor(0, 0, 0), 5+TSC.getScreenWidth()/2, TSC.getScreenHeight()-50 , 2, 10),
};
TouchScreenMenu configuracion = TouchScreenMenu(configuracionItems, 2, 10, 10, CENTERJ, "Configuracion");

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

pantalla Configuracion (NULL,
						configuracionItems,
						configuracionAccion,
						&configuracion,
						configuracionBotones,
						sizeof(configuracionBotones)/sizeof(configuracionBotones[0]));


/*******************************************/
/***   Pantalla principal                ***/
/*******************************************/

//pantalla Principal();
TouchScreenMenuItem principalItems[] = {
  TouchScreenMenuItem("Informacion"),
  TouchScreenMenuItem("Configuracion"),
  TouchScreenMenuItem("ENDOFMENU")
};
TouchScreenMenu principal = TouchScreenMenu(principalItems, 2, 10, 10, CENTERJ, "Indoosphera");
TouchScreenArea principalBotones[] = {
//		TouchScreenButton("Atras", TSC.createColor(255, 0,0 ), TSC.createColor(0, 0, 0), 10, TSC.getScreenHeight()-50 , 2, 10),
//		TouchScreenButton("Listo", TSC.createColor(0, 255, 0 ), TSC.createColor(0, 0, 0), 5+TSC.getScreenWidth()/2, TSC.getScreenHeight()-50 , 2, 10),
};

pantalla * accionPrincipal(pantalla * este,TouchScreenMenuItem * item ){
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

pantalla Principal (NULL,
					principalItems,
					accionPrincipal,
					&principal,
					principalBotones,
					sizeof(principalBotones)/sizeof(principalBotones[0]));
//pantalla Principal (NULL,principalItems,accionPrincipal,&principal,NULL,2);
