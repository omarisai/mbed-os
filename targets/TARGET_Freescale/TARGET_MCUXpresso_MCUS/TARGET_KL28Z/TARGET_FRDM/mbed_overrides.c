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
#include "platform/mbed_critical.h"
#include "platform/mbed_wait_api.h"
#include "gpio_api.h"
#include "pinmap.h"
#include "fsl_clock_config.h"

// called before main - implement here if board needs it otherwise, let
//  the application override this if necessary
void mbed_sdk_init()
{
    BOARD_BootClockRUN();
}

// Enable the RTC oscillator if available on the board
void rtc_setup_oscillator(RTC_Type *base)
{
    /* Enable the RTC oscillator */
    RTC->CR |= RTC_CR_OSCE_MASK;
}

// Change the NMI pin to an input. This allows NMI pin to
//  be used as a low power mode wakeup.  The application will
//  need to change the pin back to NMI_b or wakeup only occurs once!
void NMI_Handler(void)
{
    gpio_t gpio;
    gpio_init_in(&gpio, PTA4);
}

void mbed_die(void) {
#if !defined (NRF51_H) && !defined(TARGET_EFM32)
    core_util_critical_section_enter();
#endif

    gpio_t led_err; gpio_init_out(&led_err, LED1);
    gpio_t led_green; gpio_init_out(&led_green, LED2); gpio_write(&led_green, 1);
    gpio_t led_blue; gpio_init_out(&led_blue, LED3); gpio_write(&led_blue, 1);
    while (1) {
        for (int i = 0; i < 4; ++i) {
            gpio_write(&led_err, 1);
            wait_ms(150);
            gpio_write(&led_err, 0);
            wait_ms(150);
        }

        for (int i = 0; i < 4; ++i) {
            gpio_write(&led_err, 1);
            wait_ms(400);
            gpio_write(&led_err, 0);
            wait_ms(400);
        }
    }
}
