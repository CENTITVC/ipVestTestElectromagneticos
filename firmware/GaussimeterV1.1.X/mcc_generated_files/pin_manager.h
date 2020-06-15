/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F27K42
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>
#include "../globalVars.h"

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RST aliases
#define RST_TRIS                 TRISAbits.TRISA0
#define RST_LAT                  LATAbits.LATA0
#define RST_PORT                 PORTAbits.RA0
#define RST_WPU                  WPUAbits.WPUA0
#define RST_OD                   ODCONAbits.ODCA0
#define RST_ANS                  ANSELAbits.ANSELA0
#define RST_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define RST_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define RST_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RST_GetValue()           PORTAbits.RA0
#define RST_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define RST_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define RST_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define RST_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define RST_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define RST_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define RST_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define RST_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set ONGaussimeter aliases
#define ONGaussimeter_TRIS                 TRISAbits.TRISA3
#define ONGaussimeter_LAT                  LATAbits.LATA3
#define ONGaussimeter_PORT                 PORTAbits.RA3
#define ONGaussimeter_WPU                  WPUAbits.WPUA3
#define ONGaussimeter_OD                   ODCONAbits.ODCA3
#define ONGaussimeter_ANS                  ANSELAbits.ANSELA3
#define ONGaussimeter_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define ONGaussimeter_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define ONGaussimeter_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define ONGaussimeter_GetValue()           PORTAbits.RA3
#define ONGaussimeter_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define ONGaussimeter_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define ONGaussimeter_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define ONGaussimeter_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define ONGaussimeter_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define ONGaussimeter_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define ONGaussimeter_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define ONGaussimeter_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set button aliases
#define button_TRIS                 TRISBbits.TRISB4
#define button_LAT                  LATBbits.LATB4
#define button_PORT                 PORTBbits.RB4
#define button_WPU                  WPUBbits.WPUB4
#define button_OD                   ODCONBbits.ODCB4
#define button_ANS                  ANSELBbits.ANSELB4
#define button_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define button_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define button_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define button_GetValue()           PORTBbits.RB4
#define button_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define button_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define button_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define button_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define button_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define button_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define button_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define button_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF4 pin functionality
 * @Example
    IOCBF4_ISR();
 */
void IOCBF4_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF4 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF4 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF4_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF4_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF4 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF4_SetInterruptHandler() method.
    This handler is called every time the IOCBF4 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF4_SetInterruptHandler(IOCBF4_InterruptHandler);

*/
extern void (*IOCBF4_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF4 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF4_SetInterruptHandler() method.
    This handler is called every time the IOCBF4 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF4_SetInterruptHandler(IOCBF4_DefaultInterruptHandler);

*/
void IOCBF4_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/