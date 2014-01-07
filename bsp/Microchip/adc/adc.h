/*--------------------------------------------------------------------------------------------------
  "THE BEER-WARE LICENSE" (Revision 42):
  <phk@FreeBSD.ORG> wrote this file. As long as you retain this notice you
  can do whatever you want with this stuff. If we meet some day, and you think
  this stuff is worth it, you can buy me a beer in return to Hotboards crew 
  (Beer-ware license created by Poul-Henning Kamp)

  \file         adc.h
  \author       Diego
  \email        diego.perez@hotboards.org
  \ver          1.0
  \date         August 13, 2013
  \target       PIC18FJ
  \brief        Pieza de c�digo que maneja el convertidor an�logo digital interno de el uC. mediante
                la funci�n de inicializacion se puede elegir resoluciones de 8 y 10 bits, ademas de
                escoger el canal que se leer� cada que se efectu� una operaci�n de lectura. Debido a
                la cantidad tan peque�a de tiempo (en el orden de los micro segundos), no se utilizan
                interrupciones.

                El tiempo de adquisici�n del modulo adc se ajusta autom�ticamente dependiendo de la
                frecuencia de operaci�n del CPU, y el tiempo de conversi�n se fija a 12 veces el
                tiempo de adquisici�n.
 -------------------------------------------------------------------------------------------------*/
#ifndef __ADC_H__
#define __ADC_H__


    /*-- Includes --*/
    #include "types.h"
     

    /*-- Defines --*/
    /**---------------------------------------------------------------------------------------------
      \def      ADC_CLOCK
      \brief    Frecuencia de cpu que alimenta este periferico
                Esta definicion es interna unicamente, actuando solo como valor por default cuando
                no se define BSP_CLOCK en hardware_profile.h
    ----------------------------------------------------------------------------------------------*/
    //#define ADC_CLOCK           12000000

    /**---------------------------------------------------------------------------------------------
      \def      ADC_8BITS
      \brief    Configura el modulo adc para conversiones de 8 bits
    ----------------------------------------------------------------------------------------------*/
    #define ADC_8BITS               1
    
    /**---------------------------------------------------------------------------------------------
      \def      ADC_10BITS
      \brief    Configura el modulo adc para conversiones de 10 bits
    ----------------------------------------------------------------------------------------------*/
    #define ADC_10BITS              2


    /*-- Macros --*/
    /**--------------------------------------------------------------------------------------------- 
      \def        Macro
      \brief      Write a nice description for your macros
    ----------------------------------------------------------------------------------------------*/ 
    
    
    /*-- Functions --*/
    /**---------------------------------------------------------------------------------------------
      \brief      Enciende el modulo ADC a la resoluci�n indicada
      \param      u8Flags.- Selecciona resoluci�n entre ADC_8BITS y ADC_10BITS
      \return     None
      \warning    None
    ----------------------------------------------------------------------------------------------*/
    void Adc_Init(_U08 u8Flags);

    /**---------------------------------------------------------------------------------------------
      \brief      Lee un canal de adc
      \param      u8Channel.- Canal de adc a leer
      \return     Lectura del adc
      \warning    Esta funci�n traba al cpu hasta que se termina de samplear y convertir una lectura
    ----------------------------------------------------------------------------------------------*/
    _U16 Adc_u16Read(_U08 u8Channel);


#endif   
 