/* mbed Microcontroller Library
 * Copyright (c) 2006-2013 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "PeripheralPins.h"

/************RTC***************/
const PinMap PinMap_RTC[] = {
    {NC, OSC32KCLK, 0},
};

/************ADC***************/
const PinMap PinMap_ADC[] = {
    {PTE16, ADC0_SE1,  0},
    {PTE17, ADC0_SE5a, 0},
    {PTE18, ADC0_SE2,  0},
    {PTE19, ADC0_SE6a, 0},
    {PTE20, ADC0_SE0,  0},
    {PTE21, ADC0_SE4a, 0},
    {PTE22, ADC0_SE3,  0},
    {PTE23, ADC0_SE7a, 0},
    {PTE24, ADC0_SE20, 0},
    {PTE25, ADC0_SE21, 0},
    //{PTE29, ADC0_SE4b, 0},
    {PTE30, ADC0_SE23, 0},
    {PTA17, ADC0_SE22, 0},
    {PTB0 , ADC0_SE8 , 0},
    {PTB1 , ADC0_SE9 , 0},
    {PTB2 , ADC0_SE12, 0},
    {PTB3 , ADC0_SE13, 0},
    {PTC0 , ADC0_SE14, 0},
    {PTC1 , ADC0_SE15, 0},
    {PTC2,  ADC0_SE11, 0},
    {PTD1,  ADC0_SE5b, 0},
    {PTD5,  ADC0_SE6b, 0},
    {PTD6,  ADC0_SE7b, 0},
    {NC   , NC       , 0}
};

/************LPI2C***************/
const PinMap PinMap_I2C_SDA[] = {
    {PTE18 , LPI2C_0 , 4},
    {PTE25 , LPI2C_0 , 5},
    {PTB1  , LPI2C_0 , 2},
    {PTB3  , LPI2C_0 , 2},
    {PTC9  , LPI2C_0 , 2},

    {PTE0  , LPI2C_1 , 6},
    {PTA4  , LPI2C_1 , 2},
    {PTC2  , LPI2C_1 , 2},
    {PTC11 , LPI2C_1 , 2},

    {PTA13 , LPI2C_2 , 5},

    {NC   , NC   , 0}
};

const PinMap PinMap_I2C_SCL[] = {
    {PTE19 , LPI2C_0 , 4},
    {PTE24 , LPI2C_0 , 5},
    {PTB0  , LPI2C_0 , 2},
    {PTB2  , LPI2C_0 , 2},
    {PTC8  , LPI2C_0 , 2},

    {PTE1  , LPI2C_1 , 6},
    {PTA3  , LPI2C_1 , 2},
    {PTC1  , LPI2C_1 , 2},
    {PTC10 , LPI2C_1 , 2},

    {PTA12 , LPI2C_2 , 5},
    {PTA14 , LPI2C_2 , 5},

    {NC   , NC   , 0}
};

const PinMap PinMap_I2C_HREQ[] = {
    {PTE31 , LPI2C_0 , 5},

    {PTB18 , LPI2C_1 , 5},

    {PTA5  , LPI2C_2 , 5},

    {NC   , NC   , 0}
};

const PinMap PinMap_I2C_SDAS[] = {
    {PTA0  , LPI2C_0 , 5},

    {PTE2  , LPI2C_1 , 6},
    {PTC13 , LPI2C_1 , 2},

    {PTA7  , LPI2C_2 , 5},

    {NC   , NC   , 0}
};

const PinMap PinMap_I2C_SCLS[] = {
    {PTE26 , LPI2C_0 , 5},
    {PTA20 , LPI2C_0 , 2},

    {PTE3  , LPI2C_1 , 6},
    {PTC12 , LPI2C_1 , 2},

    {NC   , NC   , 0}
};

/************LPUART***************/
const PinMap PinMap_UART_TX[] = {
    {PTE20 , LPUART_0 , 4},
    {PTA2  , LPUART_0 , 2},
    {PTA14 , LPUART_0 , 3},
    {PTB17 , LPUART_0 , 3},
    {PTD7  , LPUART_0 , 3},

    {PTE0  , LPUART_1 , 3},
    {PTA19 , LPUART_1 , 3},
    {PTC4  , LPUART_1 , 3},

    {PTE16 , LPUART_2 , 3},
    {PTE22 , LPUART_2 , 4},
    {PTD3  , LPUART_2 , 3},
    {PTD5  , LPUART_2 , 3},

    {NC    , NC   , 0}
};

const PinMap PinMap_UART_RX[] = {
    {PTE21 , LPUART_0 , 4},
    {PTA1  , LPUART_0 , 2},
    {PTA15 , LPUART_0 , 3},
    {PTB16 , LPUART_0 , 3},
    {PTD6  , LPUART_0 , 3},

    {PTE1  , LPUART_1 , 3},
    {PTA18 , LPUART_1 , 3},
    {PTC3  , LPUART_1 , 3},

    {PTE17 , LPUART_2 , 3},
    {PTE23 , LPUART_2 , 4},
    {PTD2  , LPUART_2 , 3},
    {PTD4  , LPUART_2 , 3},

    {NC   ,  NC    , 0}
};

/************LPSPI***************/
const PinMap PinMap_SPI_SCLK[] = {
    {PTE17 , LPSPI_0, 2},
    {PTA15 , LPSPI_0, 2},
    {PTC5  , LPSPI_0, 2},
    {PTD1  , LPSPI_0, 2},

    {PTE2  , LPSPI_1, 2},
    {PTB9  , LPSPI_1, 2},
    {PTB11 , LPSPI_1, 2},
    {PTD5  , LPSPI_1, 2},

    {PTE20 , LPSPI_2, 2},
    {PTB21 , LPSPI_2, 2},

    {NC   , NC   , 0}
};

//Serial Data Output or DATA[0]
const PinMap PinMap_SPI_MOSI[] = {
    {PTE18 , LPSPI_0, 2},
    {PTA16 , LPSPI_0, 2},
    {PTC6  , LPSPI_0, 2},
    {PTD2  , LPSPI_0, 2},
    //{PTE19 , LPSPI_0, 2},
    //{PTA17 , LPSPI_0, 2},
    //{PTC7  , LPSPI_0, 2},
    //{PTD3  , LPSPI_0, 2},

    {PTE1  , LPSPI_1, 2},
    {PTB16 , LPSPI_1, 2},
    {PTD6  , LPSPI_1, 2},
    //{PTE0  , LPSPI_1, 2},
    //{PTE3  , LPSPI_1, 2},
    //{PTB17 , LPSPI_1, 2},
    //{PTD7  , LPSPI_1, 2},

    {PTE21 , LPSPI_2, 2},
    {PTB22 , LPSPI_2, 2},
    //{PTE22 , LPSPI_2, 2},
    //{PTB23 , LPSPI_2, 2},

    {NC   , NC   , 0}
};

//Serial Data Input or DATA[1]
const PinMap PinMap_SPI_MISO[] = {
    {PTE19 , LPSPI_0, 2},
    {PTA17 , LPSPI_0, 2},
    {PTC7  , LPSPI_0, 2},
    {PTD3  , LPSPI_0, 2},
    //{PTE18 , LPSPI_0, 2},
    //{PTA16 , LPSPI_0, 2},
    //{PTC6  , LPSPI_0, 2},
    //{PTD2  , LPSPI_0, 2},

    {PTE0  , LPSPI_1, 2},
    {PTE3  , LPSPI_1, 2},
    {PTB17 , LPSPI_1, 2},
    {PTD7  , LPSPI_1, 2},
    //{PTE1  , LPSPI_1, 2},
    //{PTB16 , LPSPI_1, 2},
    //{PTD6  , LPSPI_1, 2},

    {PTE22 , LPSPI_2, 2},
    {PTB23 , LPSPI_2, 2},
    //{PTE21 , LPSPI_2, 2},
    //{PTB22 , LPSPI_2, 2},

    {NC   , NC   , 0}
};

//Peripheral Chip Select 0
const PinMap PinMap_SPI_SSEL[] = {
    {PTE16 , LPSPI_0, 2},
    {PTA14 , LPSPI_0, 2},
    {PTC4  , LPSPI_0, 2},
    {PTD0  , LPSPI_0, 2},

    {PTE4  , LPSPI_1, 2},
    {PTB8  , LPSPI_1, 2},
    {PTB10 , LPSPI_1, 2},
    {PTD4  , LPSPI_1, 2},

    {PTE23 , LPSPI_2, 2},
    {PTB20 , LPSPI_2, 2},

    {NC   , NC   , 0}
};

//Peripheral Chip Select 1 or HREQ
const PinMap PinMap_SPI_PCS1[] = {
    {PTC3  , LPSPI_0, 2},

    {PTE5  , LPSPI_1, 2},
    {PTB7  , LPSPI_1, 2},

    {PTB19 , LPSPI_2, 5},
    {PTC0  , LPSPI_2, 2},

    {NC   , NC   , 0}
};

//Peripheral Chip Select 2 or DATA[2]
const PinMap PinMap_SPI_PCS2[] = {
    {PTC18 , LPSPI_0, 3},

    {PTE6  , LPSPI_1, 2},

    {PTB17 , LPSPI_2, 5},

    {NC   , NC   , 0}
};

//Peripheral Chip Select 3 or DATA[3]
const PinMap PinMap_SPI_PCS3[] = {
    {PTA7  , LPSPI_0, 2},
    {PTC17 , LPSPI_0, 3},

    {PTE16 , LPSPI_1, 5},
    {PTB3  , LPSPI_1, 4},

    {PTB16 , LPSPI_2, 5},

    {NC   , NC   , 0}
};

/************PWM***************/
const PinMap PinMap_PWM[] = {
    {PTE24, PWM_1 , 3},
    {PTA3 , PWM_1 , 3},
    {PTC1 , PWM_1 , 4},
    {PTD0 , PWM_1 , 4},

    {PTE25, PWM_2 , 3},
    {PTA4 , PWM_2 , 3},
    {PTC2 , PWM_2 , 4},
    {PTD1 , PWM_2 , 4},

    {PTE29, PWM_3 , 3},
    {PTA5 , PWM_3 , 3},
    {PTC3 , PWM_3 , 4},
    {PTD2 , PWM_3 , 4},

    {PTE30, PWM_4 , 3},
    {PTA6 , PWM_4 , 3},
    {PTC4 , PWM_4 , 4},
    {PTD3 , PWM_4 , 4},

    {PTE31, PWM_5 , 3},
    {PTA7 , PWM_5 , 3},
    {PTC8 , PWM_5 , 3},
    {PTD4 , PWM_5 , 4},

    {PTE26, PWM_6 , 3},
    {PTA0 , PWM_6 , 3},
    {PTC9 , PWM_6 , 3},
    {PTD5 , PWM_6 , 4},

    {PTE20, PWM_7 , 3},
    {PTA12, PWM_7 , 3},
    {PTB0,  PWM_7 , 3},

    {PTE21, PWM_8 , 3},
    {PTA13, PWM_8 , 3},
    {PTB1,  PWM_8 , 3},

    {PTE22, PWM_9 , 3},
    {PTA1 , PWM_9 , 3},
    {PTB2 , PWM_9 , 3},
    {PTB18, PWM_9 , 3},

    {PTE23, PWM_10, 3},
    {PTA2 , PWM_10, 3},
    {PTB3 , PWM_10, 3},
    {PTB19, PWM_10, 3},

    {NC   , NC    , 0}
};

