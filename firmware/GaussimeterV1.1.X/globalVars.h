
/* 
 * File:   main.h
 * Author: Admin
 *
 * Created on September 16, 2019, 3:55 PM
 */

#ifndef MAIN_H
#define	MAIN_H

/******************************************************************************/
/* Libraries to Include                                                       */
/******************************************************************************/
#include <xc.h> // include processor files - each processor file is guarded. 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdbool.h>
#include "mcc_generated_files/mcc.h"

//#define SSD1327
#define SH1106

#define GaussimeterAddr 0x0C  

char config[4] = {0};
char data[7] = {0};

int xMag;
int yMag;
int zMag;
int totalMag;

int xMagH;
int yMagH;
int zMagH;
int totalMagH;

int temperature;

#ifdef	__cplusplus
extern "C" {
#endif



#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

