/*--------------------------------------------------------------------------------------------------
  "THE BEER-WARE LICENSE" (Revision 42):
  <phk@FreeBSD.ORG> wrote this file. As long as you retain this notice you
  can do whatever you want with this stuff. If we meet some day, and you think
  this stuff is worth it, you can buy me a beer in return to Hotboards crew
  (Beer-ware license created by Poul-Henning Kamp)

  \file         spi.h
  \author       Diego
  \email        diego.perez@hotboards.org
  \ver          1.0
  \date         August 20, 2013
  \target       PIC18FJ

  \brief        Driver para controlar la comunicaci�n serial sincrona de tipo spi usando el perif�rico
                MSSP del uC. El perif�rico MSSP de los PIC18FJ puede tener dos funciones, como spi o
                i2c, en este caso este driver lo configura para ser usado �nicamente como spi en modo
                maestro. Aparte de solo implementarse como maestro, no se implementan interrupciones
                pues solo se usa una simple funci�n bloqueante para tx y rx un byte por vez.
--------------------------------------------------------------------------------------------------*/
#ifndef __SPI2_H__
#define __SPI2_H__


    /*-- Includes --*/
    #include "types.h"
     

    /*-- Defines --*/
    /**---------------------------------------------------------------------------------------------
      \def      _eSPI
      \brief    Puertos spi que pueden ser usados en el driver
    ----------------------------------------------------------------------------------------------*/
    typedef enum
    {
        SPI_PORT1 = 1,
        SPI_PORT2
    }_eSPI;

    /**---------------------------------------------------------------------------------------------
      \def      SPI_DIV
      \brief    Valores que dividen la frecuencia de operaci�n del uC (valores 4, 16, 64)
    ----------------------------------------------------------------------------------------------*/
    #define SPI_4DIV                        0
    #define SPI_16DIV                       1
    #define SPI_64DIV                       2

    /*----------------------------------------------------------------------------------------------
    |                            SPI_BUSCLK                                                        |
    |   Baud rate generation  = ------------                                                       |
    |                           (SPI_DIV)                                                          |
    ----------------------------------------------------------------------------------------------*/

    
    /*-- Macros --*/
    
    
    /*-- Functions --*/
    /**---------------------------------------------------------------------------------------------
      \brief      Inicializa el perif�rico MSSP como SPI en modo maestro
      \param	  u8Divisor.- divide la frecuencia de operaci�n del cpu, SPI2_4DIV, SPI2_16DIV, SPI2_64DIV
      \param      u8Spi.- Puerto spi que sera inicializado
      \return     None
      \warning	  El perif�rico se inicia con modo de transmicion 0
    ----------------------------------------------------------------------------------------------*/
    void Spi_Init(_U08 u8Spi, _U08 u8Divisor);

    /**---------------------------------------------------------------------------------------------
      \brief      Establece el modo de transmicion SPI a usar
      \param	  u8Mode.- mode  clk pha         descripci�n
                            0      0,  0   (clk idle=0, data sample=rising)
                            1      0,  1   (clk idle=0, data sample=fall)
                            2      1,  0   (clk idle=1, data sample=fall)
                            3      1,  1   (clk idle=1, data sample=rise)
      \param      u8Spi.- Puerto spi que se seteara su modo de trasnmision
      \return     None
      \warning	  None
    ----------------------------------------------------------------------------------------------*/
    void Spi_SetMode(_U08 u8Spi, _U08 u8Mode);

    /**---------------------------------------------------------------------------------------------
      \brief      Transmite un simple byte, ademas de regresar un byte de llegada (si lo hay)
      \param	  u8TxByte.- byte a transmitir
      \param      u8Spi.- Puerto spi que sera usado para trnasferir un dato
      \return     byte recibido
      \warning	  Esta funci�n traba el cpu hasta que se termine de transmitir y/o recibir un byte
    ----------------------------------------------------------------------------------------------*/
    _U08 Spi_u8Transfer(_U08 u8Spi, _U08 u8TxByte);


#endif   
 