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
#include <Time/Time.h>
#include "pantalla.h"
#include "pantallas.h"

// keep track of which menu is the currently active one
//TouchScreenMenu *curMenu = &principal;
pantalla *Activa=&Principal;
unsigned int backColor=TSC.createColor(0, 0, 0);


void setup(void) {
//	Timer1.initialize(1000000);
//	Timer1.attachInterrupt(atenderInter,1000000);

	TSC.setBackColor(backColor); // change the default background color
	TSC.init(); // make sure everything get initialized
	pantallaInit();
	Activa->dibujar();
}

void loop(void) {
  // handle the current menu
	Activa=Activa->ejecutar();
}

