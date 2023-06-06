
/*
 *
 * @file uart.h
 * @brief UART Configuration and Communication
 *
 *  Created on: Jun 2, 2023
 *  Author: R-and-D
 */

#ifndef USERDEFINED_UART_H_
#define USERDEFINED_UART_H_

#include <msp430.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief UART Configuration Options
 */
typedef enum
{
    CONFIG_A0 = (1 << 0), /**< Configuration A0 */

    CONFIG_A1 = (1 << 1), /**< Configuration A1 */

    CONFIG_B0 = (1 << 2), /**< Configuration B0 */

    CONFIG_B1 = (1 << 3), /**< Configuration B1 */

    CONFIG_ALL, /**< Configure all ports */
} uart_t;

/**
 * @brief Clock Speed Options
 */
typedef enum
{
    CLOCK_1MHZ, /**< 1 MHz Clock Speed */
    CLOCK_8MHZ,  /**< 8 MHz Clock Speed */
    CLOCK_16MHZ  /**< 8 MHz Clock Speed */

} clock_t;

/**
 * @brief Initialize UART configuration for the specified port and clock.
 *
 * @param port The UART port to configure.
 * @param clock The clock speed to use for UART configuration.
 */
void uart_init(uart_t port, clock_t clock);

/**
 * @brief Send a character over UART.
 *
 * @param data The character to send.
 */
void UART_sendCharacter(unsigned char data);

/**
 * @brief Transmit a null-terminated string over UART.
 *
 * @param message The string to transmit.
 */
void transmitString(const char *message);

/**
 * @brief Transmit a formatted message over UART.
 *
 * This function accepts a format string and variable number of arguments,
 * similar to printf, and transmits the formatted message over UART.
 *
 * @param format The format string.
 * @param ... Variable number of arguments.
 */
void transmitMessage(const char *format, ...);

#endif /* USERDEFINED_UART_H_ */
