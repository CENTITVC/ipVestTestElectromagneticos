/* 
 * File: display.h   
 * Author: jmatos
 * Comments:
 * Revision history: 
 * Created on 14 de Outubro de 2019, 9:42
 */
#ifndef U8G2_CONFIGS_H
#define	U8G2_CONFIGS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "u8g2/u8g2.h"
#include "../globalVars.h"
    

static u8g2_t u8g2;

////////////////////////////////////////////
//variables for each one of the magnetic field axis
char tx_data_buffer_x[10]={0};
char tx_data_buffer_y[10]={0};
char tx_data_buffer_z[10]={0};
char tx_data_buffer_total[10]={0};
char tx_data_buffer_totalH[10]={0};
////////////////////////////////////////////

/**
  @Description
    
  @Preconditions
     
  @Param
    None
  @Returns
    None
  @TODO
    None
*/
void Display_SSD1327_Init();
/**
  @Description
    
  @Preconditions
     
  @Param
    None
  @Returns
    None
  @TODO
    None
*/
void Display_SH1106_Init();
/**
  @Description
    
  @Preconditions
     
  @Param
    None
  @Returns
    None
  @TODO
    None
*/

void Display_LogoCenti();

/**
  @Description
    
  @Preconditions
     
  @Param
    None
  @Returns
    None
  @TODO
    None
*/
void Display_Loop();

/**
  @Description
    
  @Preconditions
     
  @Param
    None
  @Returns
    None
  @TODO
    None
*/
void clearDisplay();

/**
  @Description
    
  @Preconditions
     
  @Param
    None
  @Returns
    None
  @TODO
    None
*/
void setContrast(int val);

void Display_GaussMeterImage();

void updateOled(int x,int  y, int z, int totalMag, bool blinkScreen);

#ifdef	__cplusplus
}
#endif

#endif	/* U8G2_CONFIGS_H */

