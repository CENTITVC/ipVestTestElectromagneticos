/*
 * File:   display.c
 * Author: jmatos
 *
 * Created on 14 de Outubro de 2019, 9:42
 */

#include "display.h"
#include "logo.h"
/***************************External Functions*********************************/
extern uint8_t u8x8_byte_i2c(u8x8_t *u8x8, uint8_t msg, uint8_t cb_arg_int, void *arg_ptr);
extern uint8_t u8x8_gpio_and_delay_cb(u8x8_t *u8x8, uint8_t msg, uint8_t cb_arg_int, void *arg_ptr);
/**************************Internal Functions**********************************/
void i2c_transfer(uint8_t adr, uint8_t cnt, uint8_t *ptr);
void delay_ms(int xms);
/******************************************************************************/

/******************************************************************************/
void Display_SSD1327_Init(){
    u8g2_Setup_ssd1327_i2c_ea_w128128_f(&u8g2, U8G2_R0,u8x8_byte_i2c, u8x8_gpio_and_delay_cb);
    u8g2_InitDisplay(&u8g2);
    u8g2_SetPowerSave(&u8g2, 0);
}
void Display_SH1106_Init(){
    u8g2_Setup_sh1106_i2c_128x64_noname_f(&u8g2, U8G2_R0,u8x8_byte_i2c, u8x8_gpio_and_delay_cb);
    u8g2_InitDisplay(&u8g2);
    u8g2_SetPowerSave(&u8g2, 0);
}

void Display_LogoCenti()
{
    u8g2_FirstPage(&u8g2);
    do
    {
        u8g2_DrawXBM(&u8g2,0,0,128,64,logoCenti);
    }while (u8g2_NextPage(&u8g2));
    __delay_ms(500);
    
}


void Display_GaussMeterImage()
{
    u8g2_FirstPage(&u8g2);
    do
    {
        u8g2_DrawXBM(&u8g2,0,0,128,64,GaussMeterImage);
    }while (u8g2_NextPage(&u8g2));
    __delay_ms(500);
    
}

void Display_FrameBket()
{
    u8g2_DrawLine(&u8g2,64,0,64,150);
    u8g2_DrawStr(&u8g2,45,60,"N");
    u8g2_DrawStr(&u8g2,110,60,"N");
}
void Display_Loop(){
    
    u8g2_FirstPage(&u8g2);
    u8g2_SetFont(&u8g2,u8g2_font_ncenB14_tr);
    do
    {
        Display_FrameBket();
        u8g2_DrawStr(&u8g2,10,60," xx");
        u8g2_DrawStr(&u8g2,70,60," yy");
    }while (u8g2_NextPage(&u8g2));
    while(1);
}


void updateOled(int x,int  y, int z, int totalMag, bool blinkScreen){
    
    memset(tx_data_buffer_x,'\0',10);
    sprintf(tx_data_buffer_x,"x=%duT",x);
    
    memset(tx_data_buffer_y,'\0',10);
    sprintf(tx_data_buffer_y,"y=%duT",y);
    
    memset(tx_data_buffer_z,'\0',10);
    sprintf(tx_data_buffer_z,"z=%duT",z);
    
    memset(tx_data_buffer_total,'\0',10);
    sprintf(tx_data_buffer_total,"H=%d",totalMag);
    
    memset(tx_data_buffer_totalH,'\0',10);
    sprintf(tx_data_buffer_totalH,"  %duT",totalMagH);
        
//    clearDisplay();
//    __delay_ms(10);
    printf("\ntx_data_buffer_x=%s tx_data_buffer_y=%s tx_data_buffer_z=%s tx_data_buffer_total=%s",tx_data_buffer_x, tx_data_buffer_y, tx_data_buffer_z, tx_data_buffer_total);

    u8g2_FirstPage(&u8g2);
    do{
        
        //draw temperature
        if(blinkScreen == true){
            setContrast(5); //setContrast should be in the range from 0..255
        }

        u8g2_SetFont(&u8g2, u8g2_font_ncenB10_tr);
        u8g2_DrawUTF8(&u8g2, 1, 12, tx_data_buffer_x);
        u8g2_DrawUTF8(&u8g2, 1, 24, tx_data_buffer_y);
        u8g2_DrawUTF8(&u8g2, 1, 36, tx_data_buffer_z);
        u8g2_DrawUTF8(&u8g2, 1, 50, tx_data_buffer_total);
        u8g2_DrawUTF8(&u8g2, 58, 50, tx_data_buffer_totalH);
       
    }while (u8g2_NextPage(&u8g2));
    __delay_ms(300);
}






void clearDisplay(){
    u8g2_ClearDisplay(&u8g2);
}

void setContrast(int val){
    u8g2_SetContrast(&u8g2, val);
}

/******************************************************************************/


/******************************************************************************/
uint8_t u8x8_byte_i2c(u8x8_t *u8x8, uint8_t msg, uint8_t cb_arg_int, void *arg_ptr)
{
    static uint8_t buffer[32];		/* u8g2/u8x8 will never send more than 32 bytes between START_TRANSFER and END_TRANSFER */
    static uint8_t buf_idx;
    uint8_t *data;
    uint8_t *cntr;

    switch(msg)
    {
        case U8X8_MSG_BYTE_SEND:
            if(cb_arg_int == 1)
            {
                data = (uint8_t *)arg_ptr;
                buffer[buf_idx++] = *data;
            }
            else
            {
                cntr = (uint8_t *)arg_ptr;
                while( cb_arg_int > 0 )
                {
                    buffer[buf_idx++] = *cntr;
                    cntr++;
                    cb_arg_int--;
                }
            }
          break;
        case U8X8_MSG_BYTE_INIT:
            /* add your custom code to init i2c subsystem */
            for(uint8_t i = 0; i < 32 ; i++ )
            {
                buffer[i] = '\0';
            }
            break;
        case U8X8_MSG_BYTE_SET_DC:
          /* ignored for i2c */
          break;
        case U8X8_MSG_BYTE_START_TRANSFER:
            buf_idx = 0;
            break;
        case U8X8_MSG_BYTE_END_TRANSFER:
            i2c_transfer(u8x8_GetI2CAddress(u8x8) >> 1, buf_idx, buffer);
            break;
        default:
            return 0;
    }
    return 1;
}
uint8_t u8x8_gpio_and_delay_cb(u8x8_t *u8x8, uint8_t msg, uint8_t cb_arg_int, void *arg_ptr)
{
  switch(msg)
  {
    case U8X8_MSG_GPIO_AND_DELAY_INIT:
        __delay_ms(1);                  // called once during init phase of u8g2/u8x8
      break;							// can be used to setup pins
    case U8X8_MSG_DELAY_NANO:			// delay arg_int * 1 nano second
      break;
    case U8X8_MSG_DELAY_100NANO:		// delay arg_int * 100 nano seconds
      break;
    case U8X8_MSG_DELAY_10MICRO:		// delay arg_int * 10 micro seconds
      break;
      case U8X8_MSG_DELAY_MILLI:
            delay_ms(cb_arg_int);// delay arg_int * 1 milli second
      break;
    case U8X8_MSG_DELAY_I2C:			// arg_int is the I2C speed in 100KHz, e.g. 4 = 400 KHz
      break;							// arg_int=1: delay by 5us, arg_int = 4: delay by 1.25us
    case U8X8_MSG_GPIO_D0:				// D0 or SPI clock pin: Output level in arg_int
    //case U8X8_MSG_GPIO_SPI_CLOCK:
      break;
    case U8X8_MSG_GPIO_D1:				// D1 or SPI data pin: Output level in arg_int
    //case U8X8_MSG_GPIO_SPI_DATA:
      break;
    case U8X8_MSG_GPIO_D2:				// D2 pin: Output level in arg_int
      break;
    case U8X8_MSG_GPIO_D3:				// D3 pin: Output level in arg_int
      break;
    case U8X8_MSG_GPIO_D4:				// D4 pin: Output level in arg_int
      break;
    case U8X8_MSG_GPIO_D5:				// D5 pin: Output level in arg_int
      break;
    case U8X8_MSG_GPIO_D6:				// D6 pin: Output level in arg_int
      break;
    case U8X8_MSG_GPIO_D7:				// D7 pin: Output level in arg_int
      break;
    case U8X8_MSG_GPIO_E:				// E/WR pin: Output level in arg_int
      break;
    case U8X8_MSG_GPIO_CS:				// CS (chip select) pin: Output level in arg_int
      break;
    case U8X8_MSG_GPIO_DC:
//        if(cb_arg_int == 1)
//            DC_SetHigh();
//        else
//            DC_SetLow();
//                //DC(cb_arg_int);                 // DC (data/cmd, A0, register select) pin: Output level in arg_int
        break;
      case U8X8_MSG_GPIO_RESET:
          if(cb_arg_int == 1)
              RST_SetHigh();
          else
              RST_SetLow();
          //RST(cb_arg_int);                // Reset pin: Output level in arg_int
      break;
    case U8X8_MSG_GPIO_CS1:				// CS1 (chip select) pin: Output level in arg_int
      break;
    case U8X8_MSG_GPIO_CS2:				// CS2 (chip select) pin: Output level in arg_int
      break;
    case U8X8_MSG_GPIO_I2C_CLOCK:		// arg_int=0: Output low at I2C clock pin
      break;							// arg_int=1: Input dir with pullup high for I2C clock pin
    case U8X8_MSG_GPIO_I2C_DATA:		// arg_int=0: Output low at I2C data pin
      break;							// arg_int=1: Input dir with pullup high for I2C data pin
    case U8X8_MSG_GPIO_MENU_SELECT:
      u8x8_SetGPIOResult(u8x8, /* get menu select pin state */ 0);
      break;
    case U8X8_MSG_GPIO_MENU_NEXT:
      u8x8_SetGPIOResult(u8x8, /* get menu next pin state */ 0);
      break;
    case U8X8_MSG_GPIO_MENU_PREV:
      u8x8_SetGPIOResult(u8x8, /* get menu prev pin state */ 0);
      break;
    case U8X8_MSG_GPIO_MENU_HOME:
      u8x8_SetGPIOResult(u8x8, /* get menu home pin state */ 0);
      break;
    default:
      u8x8_SetGPIOResult(u8x8, 1);			// default return value
      break;
  }
  return 1;
}
/******************************************************************************/
void i2c_transfer(uint8_t adr, uint8_t cnt, uint8_t *ptr)
{
    i2c1_writeNBytes(adr,(uint8_t *)ptr,cnt);
}
void delay_ms(int xms)
{
    while(xms--)
        __delay_ms(1); 
}