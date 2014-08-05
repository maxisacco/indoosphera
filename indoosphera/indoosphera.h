// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _indoosphera_H_
#define _indoosphera_H_
#include "Arduino.h"
//add your includes for the project indoosphera here


//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
void checkMenuSelection(TouchScreenMenuItem *item);
void checkButtons();
void atenderInter(void);
//
//TouchScreenMenuItem configuracionItem[] = {
//  TouchScreenMenuItem("<- Atras"),
//  TouchScreenMenuItem("Hora"),
//  TouchScreenMenuItem("Desarrollo"),
//  TouchScreenMenuItem("ENDOFMENU")
//};
//
//TouchScreenMenuItem principalItems[] = {
//  TouchScreenMenuItem("Informacion"),
//  TouchScreenMenuItem("Configuracion"),
//  TouchScreenMenuItem("ENDOFMENU")
//};
//
//// create the various menus setting the items, font size, spacing, padding, justification and titles
//TouchScreenMenu configuracion = TouchScreenMenu(configuracionItem, 2, 10, 5, CENTERJ, "Configuracion");
//TouchScreenMenu principal = TouchScreenMenu(principalItems, 2, 10, 10, CENTERJ, "Indoosphera");
//
//TouchScreenArea atrasInformacion = TouchScreenButton("<- Atras", TSC.createColor(0, 0, 255), TSC.createColor(0, 0, 0), 50, TSC.getScreenHeight() - 50, 2, 10);
//TouchScreenArea atrasConfiguracion = TouchScreenButton("<- Atras", TSC.createColor(0, 0, 255), TSC.createColor(0, 0, 0), 50, TSC.getScreenHeight() - 50, 2, 10);
//TouchScreenArea listoHora = TouchScreenButton("Listo!", TSC.createColor(0, 0, 255), TSC.createColor(0, 0, 0), 50, TSC.getScreenHeight() - 50, 2, 10);


#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project indoosphera here




//Do not add code below this line
#endif /* _indoosphera_H_ */
