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
#include <Time/Time.h>


/*******************************************/
/***   Pantalla ConfDesarrollo           ***/
/*******************************************/

#define CONFIGURACION_ANTERIOR NULL


/****** Definicion de Menues ***************/

TouchScreenMenuItem confDesarrolloItems[] = {
		TouchScreenMenuItem("Germinacion"),
		TouchScreenMenuItem("Crecimiento"),
		TouchScreenMenuItem("Floracion"),
		TouchScreenMenuItem("ENDOFMENU")
};


/****** Funcion Acciones del Menu ***************/

pantalla * confDesarrolloAccion(pantalla * este,TouchScreenMenuItem * item ){
	pantalla *res;
		if(!strcmp(item->getText(),"Germinacion")){
			res = este;
			TSC.clearScreen();
			res->dibujar();
		}
		else if(!strcmp(item->getText(),"Crecimiento")){
				res = este;
				TSC.clearScreen();
				res->dibujar();
		}
		else if(!strcmp(item->getText(),"FLoracion")){
				res = este;
				TSC.clearScreen();
				res->dibujar();
		}

return res;
}


/****** Definicion de Pantalla ***************/

TouchScreenMenu confDesarrollo = TouchScreenMenu(confDesarrolloItems, 2, 10, 10, CENTERJ, "Desarrollo");

/****** Definicion de Botones ***************/
TouchScreenArea confDesarrolloBotones[] = {
		TouchScreenButton("Atras", TSC.createColor(255, 0,0 ), TSC.createColor(0, 0, 0), 10, TSC.getScreenHeight()-50 , 2, 10),
	//	TouchScreenButton("Listo", TSC.createColor(0, 255, 0 ), TSC.createColor(0, 0, 0), 5+TSC.getScreenWidth()/2, TSC.getScreenHeight()-50 , 2, 10),
};



/****** Funcion Acciones de Botones **********/

pantalla * confDesarrolloAccionBotones(pantalla * este){
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

EtiquetaR confDesarrolloEtiquetasR[] = {};

/****** Definicion de labels************/

TouchScreenLabel confDesarrolloLables[]={};

pantalla ConfDesarrollo (NULL,
					confDesarrolloItems,
					confDesarrolloAccion,
					&confDesarrollo,
					confDesarrolloBotones,
					sizeof(confDesarrolloBotones)/sizeof(confDesarrolloBotones[0]),
					confDesarrolloAccionBotones,
					confDesarrolloEtiquetasR,
					sizeof(confDesarrolloEtiquetasR)/sizeof(confDesarrolloEtiquetasR[0]),
					confDesarrolloLables,
					sizeof(confDesarrolloLables)/sizeof(confDesarrolloLables[0]));



/*******************************************/
/***   Pantalla ConfiguracionHora        ***/
/*******************************************/

#define CONFIGURACIONHORA_ANTERIOR NULL


/****** Definicion de Menues ***************/

TouchScreenMenuItem configuracionHoraItems[] = {
		TouchScreenMenuItem("ENDOFMENU")
};


/****** Funcion Acciones del Menu ***************/

pantalla * configuracionHoraAccion(pantalla * este,TouchScreenMenuItem * item ){
return este;
}


/****** Definicion de Pantalla ***************/

TouchScreenMenu configuracionHora = TouchScreenMenu(configuracionHoraItems, 2, 10, 10, CENTERJ, "Configuracion");

/****** Definicion de Botones ***************/
TouchScreenArea configuracionHoraBotones[] = {
		TouchScreenButton("Atras", TSC.createColor(255, 0,0 ), TSC.createColor(0, 0, 0), 10, TSC.getScreenHeight()-50 , 2, 10),
		TouchScreenButton("Listo", TSC.createColor(0, 255, 0 ), TSC.createColor(0, 0, 0), 5+TSC.getScreenWidth()/2, TSC.getScreenHeight()-50 , 2, 10),
		TouchScreenArrowButton("+",TSC.createColor(255, 255, 255), TSC.createColor(0, 0, 255), 70, 55, 25, 25,UP),
		TouchScreenArrowButton("-",TSC.createColor(255, 255, 255), TSC.createColor(0, 0, 255), 70, 110, 25, 25, DOWN),
		TouchScreenArrowButton("+",TSC.createColor(255, 255, 255), TSC.createColor(0, 0, 255), 135, 55, 25, 25, UP),
		TouchScreenArrowButton("-",TSC.createColor(255, 255, 255), TSC.createColor(0, 0, 255), 135, 110, 25, 25,DOWN),

		TouchScreenArrowButton("+",TSC.createColor(255, 255, 255), TSC.createColor(0, 0, 255), 40, 155, 25, 25,UP),
		TouchScreenArrowButton("-",TSC.createColor(255, 255, 255), TSC.createColor(0, 0, 255), 40, 210, 25, 25, DOWN),
		TouchScreenArrowButton("+",TSC.createColor(255, 255, 255), TSC.createColor(0, 0, 255), 105, 155, 25, 25, UP),
		TouchScreenArrowButton("-",TSC.createColor(255, 255, 255), TSC.createColor(0, 0, 255), 105, 210, 25, 25,DOWN),
		TouchScreenArrowButton("+",TSC.createColor(255, 255, 255), TSC.createColor(0, 0, 255), 170, 155, 25, 25, UP),
		TouchScreenArrowButton("-",TSC.createColor(255, 255, 255), TSC.createColor(0, 0, 255), 170, 210, 25, 25,DOWN),

		//		TouchScreenCircleButton("+",TSC.createColor(0, 0, 0), TSC.createColor(255, 255, 255), 10, 10, 70, 70),
};



/****** Funcion Acciones de Botones **********/

pantalla * configuracionHoraAccionBotones(pantalla * este){
	pantalla *res=este;
	int min,hora,dia,mes,ano;
	for (int i=0 ; i< este->getBotonesLen();i++){ // Atras
		if (i==0 && este->getBotones()[i].process()){
			res=este->getAnterior();
			TSC.clearScreen();
			res->dibujar();
		}
		else if (i==1 && este->getBotones()[i].process()){ // LISTO
			hora=este->getEtiquetasR()[0].getValorInt();
			min=este->getEtiquetasR()[1].getValorInt();
			dia=este->getEtiquetasR()[2].getValorInt();
			mes=este->getEtiquetasR()[3].getValorInt();
			ano=este->getEtiquetasR()[4].getValorInt();
			ano=ano+2000;

			setTime(hora,min,0,dia,mes,ano);
			res=este->getAnterior();
			TSC.clearScreen();
			res->dibujar();
		}
		else if (i==2 && este->getBotones()[i].process()){ //UP HORA
			hora=este->getEtiquetasR()[0].getValorInt();
			hora++;
			if (hora>=24) hora=0;
			este->getEtiquetasR()[0].setValor(hora);
		}
		else if (i==3 && este->getBotones()[i].process()){ //DOWN HORA
			hora=este->getEtiquetasR()[0].getValorInt();
			hora--;
			if (hora<0) hora=23;
			este->getEtiquetasR()[0].setValor(hora);
		}
		else if (i==4 && este->getBotones()[i].process()){ //UP MINUTO
			min=este->getEtiquetasR()[1].getValorInt();
			min++;
			if (min>=60) min=0;
			este->getEtiquetasR()[1].setValor(min);
		}
		else if (i==5 && este->getBotones()[i].process()){ //DOWN MINUTO
			min=este->getEtiquetasR()[1].getValorInt();
			min--;
			if (min<=0) min=59;
			este->getEtiquetasR()[1].setValor(min);
		}
		else if (i==6 && este->getBotones()[i].process()){ //UP DIA
			dia=este->getEtiquetasR()[2].getValorInt();
			dia++;
			if (dia>=31) dia=1;
			este->getEtiquetasR()[2].setValor(dia);
		}
		else if (i==7 && este->getBotones()[i].process()){ //DOWN DIA
			dia=este->getEtiquetasR()[2].getValorInt();
			dia--;
			if (dia<=0) dia=31;
			este->getEtiquetasR()[2].setValor(dia);
		}
		else if (i==8 && este->getBotones()[i].process()){ //UP MES
			mes=este->getEtiquetasR()[3].getValorInt();
			mes++;
			if (mes>=13) mes=1;
			este->getEtiquetasR()[3].setValor(mes);
		}
		else if (i==9 && este->getBotones()[i].process()){ //DOWN MES
			mes=este->getEtiquetasR()[3].getValorInt();
			mes--;
			if (mes<=0) mes=12;
			este->getEtiquetasR()[3].setValor(mes);
		}
		else if (i==10 && este->getBotones()[i].process()){ //UP AÑO
			ano=este->getEtiquetasR()[4].getValorInt();
			ano++;
			if (ano<=13) ano=14;
			if (ano>=100) ano=14;
			este->getEtiquetasR()[4].setValor(ano);
		}
		else if (i==11 && este->getBotones()[i].process()){ //DOWN AÑO
			ano=este->getEtiquetasR()[4].getValorInt();
			ano--;
			if (ano<=13) ano=14;
			este->getEtiquetasR()[4].setValor(ano);
		}
	}

	return res;
}



/****** Definicion de labels************/

TouchScreenLabel configuracionHoraLables[]={
		TouchScreenLabel("88", 	TSC.createColor(0,	 255, 255), TSC.createColor(0, 0, 0),   60,  85, 3, 0, false),
		TouchScreenLabel(":", 	TSC.createColor(0,	 255, 255), TSC.createColor(0, 0, 0),   105,  85, 3, 0, false),
		TouchScreenLabel("88", 	TSC.createColor(0,	 255, 255), TSC.createColor(0, 0, 0),   125,  85, 3, 0, false),

		TouchScreenLabel("88", 	TSC.createColor(0,	 255, 255), TSC.createColor(0, 0, 0),   30,   185, 3, 0, false),
		TouchScreenLabel("/", 	TSC.createColor(0,	 255, 255), TSC.createColor(0, 0, 0),   75,  185, 3, 0, false),
		TouchScreenLabel("88", 	TSC.createColor(0,	 255, 255), TSC.createColor(0, 0, 0),   95,  185, 3, 0, false),
		TouchScreenLabel("/", 	TSC.createColor(0,	 255, 255), TSC.createColor(0, 0, 0),   140,  185, 3, 0, false),
		TouchScreenLabel("88", 	TSC.createColor(0,	 255, 255), TSC.createColor(0, 0, 0),   160,  185, 3, 0, false),

};

/****** Definicion de EtiquetasR ************/

EtiquetaR configuracionHoraEtiquetasR[] = {
		EtiquetaR(&configuracionHoraLables[0]),
		EtiquetaR(&configuracionHoraLables[2]),
		EtiquetaR(&configuracionHoraLables[3]),
		EtiquetaR(&configuracionHoraLables[5]),
		EtiquetaR(&configuracionHoraLables[7]),

};


pantalla ConfiguracionHora (NULL,
					configuracionHoraItems,
					configuracionHoraAccion,
					&configuracionHora,
					configuracionHoraBotones,
					sizeof(configuracionHoraBotones)/sizeof(configuracionHoraBotones[0]),
					configuracionHoraAccionBotones,
					configuracionHoraEtiquetasR,
					sizeof(configuracionHoraEtiquetasR)/sizeof(configuracionHoraEtiquetasR[0]),
					configuracionHoraLables,
					sizeof(configuracionHoraLables)/sizeof(configuracionHoraLables[0]));




/*******************************************/
/***   Pantalla Informacion            ***/
/*******************************************/

#define INFORMACION_ANTERIOR NULL


/****** Definicion de Menues ***************/

TouchScreenMenuItem informacionItems[] = {
		TouchScreenMenuItem("ENDOFMENU"),
};
/****** Funcion Acciones del Menu ***************/

pantalla * informacionAccion(pantalla * este,TouchScreenMenuItem * item ) {return este;}


/****** Definicion de Pantalla ***************/


TouchScreenMenu informacion = TouchScreenMenu(informacionItems, 2, 10, 10, CENTERJ, "Informacion");


/****** Definicion de Botones ***************/
TouchScreenArea informacionBotones[] = {                                             // x       y                    w    h
	TouchScreenButton("Atras", TSC.createColor(255, 0,0 ), TSC.createColor(0, 0, 0), 10, TSC.getScreenHeight()-40 , 2, 10),
//	TouchScreenButton("Listo", TSC.createColor(0, 255, 0 ), TSC.createColor(0, 0, 0), 5+TSC.getScreenWidth()/2, TSC.getScreenHeight()-50 , 2, 10),
};



/****** Funcion Acciones de Botones **********/

pantalla * informacionAccionBotones(pantalla * este){
	pantalla *res=este;
	for (int i=0; i< este->getEtiquetasRLen(); i++){
		if (i==0){
			este->getEtiquetasR()[i].setValor(hour());
		}
		else /*if (i==0) */{
			este->getEtiquetasR()[i].setValor(minute());
		}

	}

	for (int i=0 ; i< este->getBotonesLen();i++)
		if (i==0 && este->getBotones()[i].process()){
			res=este->getAnterior();
			TSC.clearScreen();
			res->dibujar();
		}


return res;
}

/****** Definicion de labels************/

TouchScreenLabel informacionLabels[]={
TouchScreenLabel("Hora:", 	TSC.createColor(0,	 255, 255), TSC.createColor(0, 0, 0),   0,  60, 2, 0, false),
TouchScreenLabel("ºC:", 	TSC.createColor(0, 	 255, 255), TSC.createColor(0, 0, 0),   0,  95, 2, 0, false),
TouchScreenLabel("Humedad:",TSC.createColor(0, 	 255, 255), TSC.createColor(0, 0, 0),   0, 130, 2, 0, false),
TouchScreenLabel("Tiempo:", TSC.createColor(0, 	 255, 255), TSC.createColor(0, 0, 0),   0, 165, 2, 0, false),
TouchScreenLabel("Altura:", TSC.createColor(0, 	 255, 255), TSC.createColor(0, 0, 0),   0, 200, 2, 0, false),
TouchScreenLabel("Periodo:",TSC.createColor(0, 	 255, 255), TSC.createColor(0, 0, 0),   0, 235, 2, 0, false),
TouchScreenLabel("--", 		TSC.createColor(255, 255, 255), TSC.createColor(0, 0, 0), 160,  60, 2, 0, false),
TouchScreenLabel(":", 		TSC.createColor(255, 255, 255), TSC.createColor(0, 0, 0), 190,  60, 2, 0, false),
TouchScreenLabel("--", 		TSC.createColor(255, 255, 255), TSC.createColor(0, 0, 0), 200,  60, 2, 0, false),
TouchScreenLabel("--", 		TSC.createColor(255, 255, 255), TSC.createColor(0, 0, 0), 200,  95, 2, 0, false),
TouchScreenLabel("--", 		TSC.createColor(255, 255, 255), TSC.createColor(0, 0, 0), 200, 130, 2, 0, false),
TouchScreenLabel("--", 		TSC.createColor(255, 255, 255), TSC.createColor(0, 0, 0), 200, 165, 2, 0, false),
TouchScreenLabel("--", 		TSC.createColor(255, 255, 255), TSC.createColor(0, 0, 0), 200, 200, 2, 0, false),
TouchScreenLabel("--", 		TSC.createColor(255, 255, 255), TSC.createColor(0, 0, 0), 200, 235, 2, 0, false),
TouchScreenLabel("Hora:", 	TSC.createColor(0,	 255, 255), TSC.createColor(0, 0, 0),   0,  60, 2, 0, false),
};

/****** Definicion de EtiquetasR ************/

EtiquetaR informacionEtiquetasR[] = {
		EtiquetaR(&informacionLabels[6]),
		EtiquetaR(&informacionLabels[8]),
		EtiquetaR(&informacionLabels[9]),
		EtiquetaR(&informacionLabels[10]),
		EtiquetaR(&informacionLabels[11]),
		EtiquetaR(&informacionLabels[12]),
		EtiquetaR(&informacionLabels[13]),
};

pantalla Informacion (NULL,
					informacionItems,
					informacionAccion,
					&informacion,
					informacionBotones,
					sizeof(informacionBotones)/sizeof(informacionBotones[0]),
					informacionAccionBotones,
					informacionEtiquetasR,
					sizeof(informacionEtiquetasR)/sizeof(informacionEtiquetasR[0]),
					informacionLabels,
					sizeof(informacionLabels)/sizeof(informacionLabels[0]));


/*******************************************/
/***   Pantalla Configuracion           ***/
/*******************************************/

#define CONFIGURACION_ANTERIOR NULL


/****** Definicion de Menues ***************/

TouchScreenMenuItem configuracionItems[] = {
		TouchScreenMenuItem("Hora"),
		TouchScreenMenuItem("Desarrollo"),
		TouchScreenMenuItem("ENDOFMENU")
};


/****** Funcion Acciones del Menu ***************/

pantalla * configuracionAccion(pantalla * este,TouchScreenMenuItem * item ){
	pantalla *res;
		if(!strcmp(item->getText(),"Hora")){
			res = &ConfiguracionHora;
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






/*******************************************/
/***   Enlace de Menus (Atras)           ***/
/*******************************************/

void pantallaInit(void){
Configuracion.setAnterior(&Principal);
Informacion.setAnterior(&Principal);
ConfiguracionHora.setAnterior(&Configuracion);
ConfDesarrollo.setAnterior(&Configuracion);
}



