/*
This example shows the various abilities of the TouchScreenMenu library.
See the readme.txt file for information on find the libraries this library uses.

 TouchScreenMenu Library.

 2012 Copyright (c) Scott Shaver

 Authors: Scott Shaver

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 3 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <TouchScreenMenu.h>
#include <TouchScreen.h>
#include <TFT.h>
#include <WString.h>
#include <stddef.h>
#include "indoosphera.h"
#include "Clock.h"
#include <TimerOne.h>
#include "pantalla.h"
#include "pantallas.h"

// keep track of which menu is the currently active one
//TouchScreenMenu *curMenu = &principal;
pantalla *Activa=&Principal;
//Clock reloj;


//TouchScreenArrowButton horaUp = TouchScreenArrowButton("+",TSC.createColor(0, 0, 0), TSC.createColor(255, 200, 0), 10, TSC.getScreenHeight() - 220, 30, 30, UP);
//TouchScreenArrowButton horaDown = TouchScreenArrowButton("-",TSC.createColor(0, 0, 0), TSC.createColor(255, 0, 255), 50, TSC.getScreenHeight() - 220, 30, 50, DOWN);
//TouchScreenArrowButton minUp = TouchScreenArrowButton("+",TSC.createColor(0, 0, 0), TSC.createColor(0, 255, 255), 90, TSC.getScreenHeight() - 220, 30, 70, UP);
//TouchScreenArrowButton minDown = TouchScreenArrowButton("-",TSC.createColor(0, 0, 0), TSC.createColor(255, 255, 255), 130, TSC.getScreenHeight() - 220, 30, 90, DOWN);
//
//
//TouchScreenCircleButton btn5 = TouchScreenCircleButton("btn5",TSC.createColor(0, 0, 0), TSC.createColor(255, 255, 255), 10, 10, 70, 70);
//TouchScreenCircleButton btn6 = TouchScreenCircleButton("btn6",TSC.createColor(0, 0, 0), TSC.createColor(0, 0, 255), 80, 10, 40, 40);
//TouchScreenSlider btn7 = TouchScreenSlider("btn7",TSC.createColor(200, 200, 200), TSC.createColor(50, 50, 255), 5, TSC.getScreenHeight() - 110, 150, 40, HORIZONTAL);
//TouchScreenSlider btn8 = TouchScreenSlider("btn8",TSC.createColor(255, 0, 0), TSC.createColor(200, 255, 0), TSC.getScreenWidth()-55, TSC.getScreenHeight() - 200, 40, 150, VERTICAL);
//
//TouchScreenArea lbl1 = TouchScreenLabel("This is a label with bg.", TSC.createColor(0, 0, 0), TSC.createColor(255, 255, 255), 45, 10, 1, 2, true);
//TouchScreenArea lbl2 = TouchScreenLabel("This is a label, no bg.", TSC.createColor(0, 0, 0), TSC.createColor(255, 255, 255), 45, 30, 1, 2, false);
//TouchScreenArea lbl3 = TouchScreenLabel("Big label.", TSC.createColor(255, 255, 255), TSC.createColor(0, 0, 0), 0, 60, 2, 2, true);
//TouchScreenArea lbl4 = TouchScreenLabel("Big label.", TSC.createColor(255, 0, 0), TSC.createColor(255, 255, 0), 0, 90, 2, 2, false);
//TouchScreenArea lbl5 = TouchScreenLabel("Big label.", TSC.createColor(0, 200, 0), TSC.createColor(255, 0, 255), 0, 120, 3, 2, true);
//TouchScreenArea lbl6 = TouchScreenLabel("Big label.", TSC.createColor(0, 200, 0), TSC.createColor(255, 0, 255), 0, 160, 3, 2, false);
//void atenderInter(void){
//	reloj.tick();
//}
void setup(void) {
//	Timer1.initialize(1000000);
//	Timer1.attachInterrupt(atenderInter,1000000);
	TSC.setBackColor(TSC.createColor(0, 0, 0)); // change the default background color
	TSC.init(); // make sure everything get initialized
	Configuracion.setAnterior(&Principal);
	Informacion.setAnterior(&Principal);
//  btn7.setValue(.5); // change the value on one of the sliders
//  btn7.setPadding(5); // change the padding on one of the sliders
//  btn8.setValue(.75); // change the value on one of the sliders
//  btn8.setPadding(5); // change the padding on one of the sliders
//  curMenu->draw(); // put up the main menu
	Activa->dibujar();
}

void loop(void) {
  // handle the current menu
	Activa=Activa->ejecutar();
	Activa->refrescar();
//  if(curMenu!=NULL){
//    // process the current menu
//    TouchScreenMenuItem *item = curMenu->process(false);
//    // check to see which, if any, menu item was pressed
//    checkMenuSelection(item);
//  }else{
//    // if there isn't a current menu being displayed check all of the buttons
//    // to see if any of them was pressed
//    checkButtons();
//  }
}

// check various buttons and perform actions if any was pressed
//void checkButtons(){
//  char cadena[10];
//  int minuto, hora;
//  reloj.getTexto().toCharArray(cadena,10);
//
//
//  if(atrasConfiguracion.process()){
//        curMenu = &principal;
//        TSC.clearScreen();
//        curMenu->draw();
//  }
//  else if(atrasInformacion.process()){
//        curMenu = &principal;
//        TSC.clearScreen();
//        curMenu->draw();
//  }
//  else if (listoHora.process()){
//	  curMenu = &configuracion;
//	  TSC.clearScreen();
//	  curMenu->draw();
//  }
//  else if (horaUp.process()){
//
//
//  }
//
//}
//
//// check to see if any menu item was pressed and do something
//void checkMenuSelection(TouchScreenMenuItem *item) {
//  boolean handled = false;
//  char cadena[10];
//  if(item != NULL){
//    // main menu items
//    if(curMenu == &principal){
//      if(!strcmp(item->getText(),"Configuracion")){
//        curMenu = &configuracion;
//        TSC.clearScreen();
//        curMenu->draw();
//        handled = true;
//      }
//      else if(!strcmp(item->getText(),"Informacion")){
//        curMenu = NULL;
//        TouchScreenArea etiqueta = TouchScreenLabel(cadena, TSC.createColor(0, 200, 0), TSC.createColor(255, 0, 255), 0, 160, 3, 2, false);
//
//        TSC.clearScreen();
//        atrasInformacion.draw();
////        TSC.drawCircle(40, 20, 19, TSC.createColor(0,100,0), false);
////        TSC.drawCircle(90, 20, 19, TSC.createColor(0,0,255), true);
////        TSC.drawArc(40, 50, 19, 0, 180, TSC.createColor(0,255,0), false, false);
////        TSC.drawArc(90, 50, 19, 90, 180, TSC.createColor(0,255,0), true, false);
////        TSC.drawArc(140, 50, 19, 90, 225, TSC.createColor(0,255,0), true, true);
////        TSC.drawRectangle(20, 80, 100, 20, TSC.createColor(255,0,0), false);
////        TSC.drawRectangle(140, 80, 100, 20, TSC.createColor(255,0,0), true);
////        TSC.drawLine(10, 110, 60, 110, TSC.createColor(0,0,255));
////        TSC.drawLine(10, 110, 10, 140, TSC.createColor(0,0,255));
////        TSC.drawLine(10, 110, 60, 140, TSC.createColor(0,0,255));
//        while (!atrasInformacion.process()){
//        	reloj.getTexto().toCharArray(cadena,10);
////        	etiqueta=TouchScreenLabel(cadena, TSC.createColor(0, 200, 0), TSC.createColor(255, 0, 255), 0, 160, 3, 2, false);
////        	etiqueta.draw();
//        	//_controller->drawString(getText(), x + _padding, y + _padding, _fontSize, getBackColor());
//        	TSC.drawString(cadena,0,160,3,TSC.createColor(0,0,255));
////        	delay(250);
//        	TSC.drawString(cadena,0,160,3,TSC.createColor(0,0,0));
//
//        }
//        handled = true;
//      }
//    }
//    // sub menu items
//    else if(curMenu == &configuracion){
//      if(!strcmp(item->getText(),"<- Atras")){
//        curMenu = &principal;
//        TSC.clearScreen();
//        curMenu->draw();
//        handled = true;
//      }
//      else if(!strcmp(item->getText(),"Hora")){
//        curMenu = NULL;
//        TSC.clearScreen();
//        reloj.getTexto().toCharArray(cadena,10);
//        TSC.drawString(cadena,0,160,3,TSC.createColor(0,0,255));
//        horaUp.draw();
//        horaDown.draw();
//        minUp.draw();
//        minDown.draw();
//        listoHora.draw();
//        }
//        handled = true;
//      }
//      else if(!strcmp(item->getText(),"Desarrollo")){
//        curMenu = &configuracion;
//        TSC.clearScreen();
//        curMenu->draw();
//        handled = true;
//      }
//    }
//
//    // if the menu item didn't get handled redraw it unpressed
//    if(handled==false)
//        curMenu->drawItem(item,false);
//  }
//}
