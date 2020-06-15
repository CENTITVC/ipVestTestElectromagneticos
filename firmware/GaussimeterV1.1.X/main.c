/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F27K42
        Driver Version    :  2.00
*/


#include "Display/display.h"
#include "globalVars.h"


void calculateMagneticField(){
    float aux = 0;
    
    // Start single measurement mode, X, Y, Z-Axis enabled(0x3E)
    config[0] = 0x3E;
//    config[0] = 0x6F;
    i2c1_writeNBytes(GaussimeterAddr, config, 1);
    __delay_ms(50);
    
    // Read 1 byte
    // status
    i2c1_readNBytes(GaussimeterAddr,data, 1);
        
    // Send read measurement command, X, Y, Z-Axis enabled(0x4E)
    config[0] = 0x4E;
    i2c1_writeNBytes(GaussimeterAddr, config, 1);

    i2c1_readNBytes(GaussimeterAddr,data, 7);
//        I2C1_ReadNBytes(GaussimeterAddr,data2, 9);
    __delay_ms(50);


    // Convert the data
    xMag = (data[1]* 256 + data[2]);
    if(xMag > 32767)
    {
        xMag -= 65536;
    }

    yMag = (data[3] * 256 + data[4]);
    if(yMag > 32767)
    {
        yMag -= 65536;
    }

    zMag = (data[5] * 256 + data[6]);
    if(zMag > 32767)
    {
        zMag -= 65536;
    }

    aux = (float) pow(xMag,2) + (float) pow(yMag,2) + (float) pow(zMag,2);
    
    totalMag = (int) sqrt( aux );
    
//        temp = (data[7] * 256 + data[8]);
//		if(temp > 32767)
//		{
//			temp -= 65536;
//		}

    // Output data to screen
    printf("Magnetic Field in X-Axis : %d \n", xMag);
    printf("Magnetic Field in Y-Axis : %d \n", yMag);
    printf("Magnetic Field in Z-Axis : %d \n", zMag);
    printf("Magnetic Field Total: %d \n", totalMag);
//        printf("Temperature : %dºC \n", temp);
    printf("\n");
    
    __delay_ms(500);
}

void setupGaussimeter()
{
    
    xMagH=0;
    yMagH=0;
    zMagH=0;
    totalMagH=0;
	// Write register command, AH = 0x00, AL = 0x5C, Hall plate spinning rate = DEFAULT, GAIN_SEL = 5(0x60, 0x00, 0x5C, 0x00)
	// Address register, (0x00 << 2) 
//   	char config[4] = {0};
	config[0] = 0x60;
	config[1] = 0x00;
	config[2] = 0x5C;
	config[3] = 0x00;
    
    i2c1_writeNBytes(GaussimeterAddr, config, 4);
    
    // Read 1 Byte of data
	// status byte
//    char data[7] = {0};
    i2c1_readNBytes(GaussimeterAddr,data, 1);
    __delay_ms(50);
    
    printf("\n\nDATA=%s",data);
    
    // Write register command, AH = 0x02, AL = 0xB4, RES for magnetic measurement = 0(0x60, 0x02, 0xB4, 0x08)
	// Address register, (0x02 << 2)
	config[0] = 0x60;
	config[1] = 0x02;
	config[2] = 0xB4;
	config[3] = 0x08;
    i2c1_writeNBytes(GaussimeterAddr, config, 4);
    
	// Read 1 Byte of data
	// status byte
    i2c1_readNBytes(GaussimeterAddr,data, 1);
    //__delay_ms(300);
    __delay_ms(50);

    printf("\nDone config gaussimeter!\n");
    
}

// initialize some global vars for the devices
void initializeOled(){

    //Oled display related vars and initializations
    #ifdef SH1106
        Display_SH1106_Init();
    #endif

    #ifdef SSD1327
         Display_SSD1327_Init();
    #endif

    clearDisplay();
    Display_LogoCenti();
    __delay_ms(1000);
    clearDisplay();
    __delay_ms(10);
    Display_GaussMeterImage();
    __delay_ms(1000);
    setContrast(200);//setContrast should be in the range from 0..255
    printf("\n\nDone config oled!!");
}



/*
                         Main application
 */
int main(void)
{
    /* MCU Configuration--------------------------------------------------------*/
    SYSTEM_Initialize();
    
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();
    ONGaussimeter_SetHigh();
    
    printf("\n\n----------- START GAUSSIMETER ---------------");
    __delay_ms(100);
    
    initializeOled();
    setupGaussimeter();

    while(1){
        calculateMagneticField();
        updateOled(xMag,yMag,zMag,totalMag,false);
        __delay_ms(200);
    }

}
/*
 End of File
*/