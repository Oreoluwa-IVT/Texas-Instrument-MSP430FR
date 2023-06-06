/**********************************************************************************
 *                                                                                *
 *                            PROPRIETARY SOFTWARE                                *
 *                                                                                *
 *        This file is part of the proprietary software developed by              *
 *        [Company Name].                                                         *
 *                                                                                *
 *        Unauthorized copying of this file, via any medium is strictly           *
 *        prohibited.                                                             *
 *                                                                                *
 *        All information contained in this file is confidential and              *
 *        proprietary information of [Company Name].                              *
 *                                                                                *
 *        File: uart.c                                                            *
 *                                                                                *
 *        Created on: Jun 2, 2023                                                 *
 *        Author: [Author Name]                                                   *
 *        Revision: 1.0                                                           *
 *                                                                                *
 *        Redistribution and use in source and binary forms, with                 *
 *        or without modification, are not permitted unless                       *
 *        explicitly provided for in writing by [Company Name].                   *
 *                                                                                *
 *        For further details, please contact [Company Name] at:                  *
 *        [Contact Information]                                                   *
 *                                                                                *
 **********************************************************************************/

#include "uart.h"

/**
 * @brief Configure UART port with specified settings.
 *
 * This function configures the GPIO and UART settings for the specified port and clock option.
 *
 * @param port The UART port to configure.
 * @param clock The clock speed to use for UART configuration.
 *
 * @note This function assumes that the clocks and necessary peripherals have been initialized.
 */

void uart_init(uart_t port, clock_t clock)
{
    switch (port)
    {
    case CONFIG_A0:
        /**
         * @brief Configure GPIO for CONFIG_A0.
         *
         * - P2SEL0: Set BIT0 and BIT1 for USCI_A0 UART operation.
         * - P2SEL1: Clear BIT0 and BIT1.
         */
        P2SEL0 |= BIT0 | BIT1; // USCI_A0 UART operation
        P2SEL1 &= ~(BIT0 | BIT1);
        /**
         * @brief Configure USCI_A0 for UART mode.
         *
         * - UCA0CTLW0: Set UCSWRST to put eUSCI in reset.
         * - UCA0CTLW0: Set UCSSEL__SMCLK to select SMCLK as the clock source.
         */
        UCA0CTLW0 |= UCSWRST;       // Put eUSCI in reset
        UCA0CTLW0 |= UCSSEL__SMCLK; // CLK = SMCLK
                                    /**
                                     * @brief Apply clock-specific settings for CONFIG_A0.
                                     *
                                     * The settings are based on the specified clock option.
                                     */
        switch (clock)
        {
        case CLOCK_1MHZ:
            /**
             * @brief Configure UART for 1 MHz clock.
             *
             * - UCA0BRW: Set the baud rate divisor for 1000000/16/9600.
             * - UCA0MCTLW: Set UCOS16, UCBRF_8, and 0x1100 for fractional portion.
             */

            UCA0BRW = 6; // 1000000/16/9600
            UCA0MCTLW |= UCOS16 | UCBRF_8 | 0x1100;
            break;
        case CLOCK_8MHZ:
            /**
             * @brief Configure UART for 8 MHz clock.
             *
             * - UCA0BR0: Set the baud rate divisor for 8000000/16/9600.
             * - UCA0BR1: Set high byte of the baud rate divisor.
             * - UCA0MCTLW: Set UCOS16, UCBRF_1, and 0x4900 for fractional portion.
             */
            // Baud Rate calculation
            // 8000000/(16*9600) = 52.083
            // Fractional portion = 0.083
            // User's Guide Table 21-4: UCBRSx = 0x04
            // UCBRFx = int ( (52.083-52)*16) = 1

            UCA0BR0 = 52; // 8000000/16/9600
            UCA0BR1 = 0x00;
            UCA0MCTLW |= UCOS16 | UCBRF_1 | 0x4900;
            break;

        case CLOCK_16MHZ:
                 /**
                  * @brief Configure UART for 16 MHz clock.
                  *
                  * - UCA0BRW: Set the baud rate divisor for 16000000/16/9600.
                  * - UCA0MCTLW: Set UCOS16, UCBRF_2, and 0xB600 for fractional portion.
                  */

                 UCA0BRW = 104; // 1000000/16/9600
                 UCA0MCTLW |= UCOS16 | UCBRF_2 | 0xB600;
                 break;

        default:
            /**
             * @brief Invalid clock option.
             *
             * Do nothing.
             */
            break;
        }
        /**
         * @brief Initialize and enable UART.
         *
         * - UCA0CTLW0: Clear UCSWRST to initialize eUSCI.
         * - UCA0IE: Enable USCI_A0 RX interrupt and TX interrupt.
         */
        UCA0CTLW0 &= ~UCSWRST;     // Initialize eUSCI
        UCA0IE |= UCTXIE | UCRXIE; // Enable USCI_A0 RX interrupt

        break;

    case CONFIG_A1:
        /**
         * @brief Configure GPIO for CONFIG_A1.
         *
         * - P3SEL0: Set BIT4 and BIT5 for USCI_A1 UART operation.
         * - P3SEL1: Clear BIT4 and BIT5.
         */
        P3SEL0 |= BIT4 | BIT5;
        P3SEL1 &= ~(BIT4 | BIT5);

        /**
         * @brief Configure UART for CONFIG_A1.
         *
         * - UCA1CTLW0: Set UCSWRST to put eUSCI in reset.
         * - UCA1CTLW0: Set UCSSEL__SMCLK to select SMCLK as the clock source.
         */
        UCA1CTLW0 |= UCSWRST;
        UCA1CTLW0 |= UCSSEL__SMCLK;

        /**
         * @brief Apply clock-specific settings for CONFIG_A1.
         *
         * The settings are based on the specified clock option.
         */
        switch (clock)
        {
        case CLOCK_1MHZ:
            /**
             * @brief Configure UART for 1 MHz clock.
             *
             * - UCA1BRW: Set the baud rate divisor for 1000000/16/9600.
             * - UCA1MCTLW: Set 0x1100, UCOS16, and UCBRF_8 for fractional portion.
             */
            UCA1BRW = 6; // 1000000/16/9600
            UCA1MCTLW = 0x1100 | UCOS16 | UCBRF_8;
            break;
        case CLOCK_8MHZ:
            /**
             * @brief Configure UART for 8 MHz clock.
             *
             * - UCA1BR0: Set the baud rate divisor for 8000000/16/9600.
             * - UCA1BR1: Set high byte of the baud rate divisor.
             * - UCA1MCTLW: Set 0x4900, UCOS16, and UCBRF_1 for fractional portion.
             */
            UCA1BR0 = 52; // 8000000/16/9600
            UCA1BR1 = 0x00;
            UCA1MCTLW = 0x4900 | UCOS16 | UCBRF_1;
            break;

        case CLOCK_16MHZ:
                   /**
                    * @brief Configure UART for 16 MHz clock.
                    *
                    * - UCA0BRW: Set the baud rate divisor for 16000000/16/9600.
                    * - UCA0MCTLW: Set UCOS16, UCBRF_2, and 0xB600 for fractional portion.
                    */

                   UCA0BRW = 104; // 1000000/16/9600
                   UCA0MCTLW |= UCOS16 | UCBRF_2 | 0xB600;
                   break;
        default:
            /**
             * @brief Invalid clock option.
             *
             * Do nothing.
             */
            break;
        }

        /**
         * @brief Initialize and enable UART.
         *
         * - UCA1CTLW0: Clear UCSWRST to initialize eUSCI.
         * - UCA1IE: Enable USCI_A1 RX interrupt and TX interrupt.
         */
        UCA1CTLW0 &= ~UCSWRST;
        UCA1IE |= UCTXIE | UCRXIE;
        break;

    case CONFIG_B0:
        /**
         * @brief Configure GPIO for CONFIG_B0.
         *
         * Additional configuration for CONFIG_B0 can be added here.
         */
        // ...
        break;

    case CONFIG_B1:
        /**
         * @brief Configure GPIO for CONFIG_B1.
         *
         * Additional configuration for CONFIG_B1 can be added here.
         */
        // ...
        break;

    case CONFIG_ALL:
        /**
         * @brief Configure GPIO and UART for all ports.
         *
         * Additional configuration for all ports can be added here.
         */
        // ...

        /**
         * @brief Configure UART for all ports.
         *
         * Additional configuration for all ports can be added here.
         */
        // ...

        /**
         * @brief Initialize UART for all ports.
         *
         * Uncomment the code block below to initialize UART for all ports.
         */
        /*
        for (uart_t config = CONFIG_A0; config <= CONFIG_B1; config++) {
            uart_init(config, clock);
        }
        */

        break;

    default:
        /**
         * @brief Invalid configuration option.
         *
         * Do nothing.
         */
        break;
    }
}

/**
 * @brief Sends a single character over UART.
 *
 * This function sends a single character over UART by waiting for the transmit buffer
 * to be ready and then transmitting the character. After transmission, it clears the
 * transmit interrupt flag.
 *
 * @param data The character to be transmitted.
 */
void UART_sendCharacter(unsigned char data)
{
    while (!(UCA1IFG & UCTXIFG))
        ;                // Wait for TX buffer to be ready
    UCA1TXBUF = data;    // Transmit the character
    UCA1IFG &= ~UCTXIFG; // Clear the transmit interrupt flag
}



/**
 * @brief Transmits a null-terminated string over UART.
 *
 * This function transmits a null-terminated string over UART by iterating through each
 * character of the string and calling the UART_sendCharacter function to transmit each
 * character. After transmitting the entire string, it clears the transmit interrupt flag
 * if the last byte was sent.
 *
 * @param message Pointer to the null-terminated string to be transmitted.
 */



void transmitString(const char *message)
{

    const unsigned char messageLength = strlen(message);
    unsigned char TXbytes = 0;

    // Transmit the message
    while (TXbytes < messageLength)
    {
        // Transmit the next byte
        UART_sendCharacter(message[TXbytes]);
        TXbytes++;
    }

    // If last byte sent, disable the interrupt
    if (TXbytes == messageLength)
    {
        UCA1IFG &= ~UCTXIFG; // Clear the transmit interrupt flag
        TXbytes = 0;
    }
}
/**
 * @brief Transmits a formatted message over UART.
 *
 * This function transmits a formatted message over UART by accepting a format string and
 * variable number of arguments. It calculates the length of the formatted message,
 * allocates memory for it, formats the message using vsnprintf, transmits each character
 * of the message using the UART_sendCharacter function, and clears the transmit interrupt
 * flag if the last byte was sent. Finally, it frees the memory allocated for the message.
 *
 * @param format The format string for the message.
 * @param ... Additional arguments to be formatted into the message.
 */
void transmitMessage(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    // Calculate the length of the formatted message
    int messageLength = vsnprintf(NULL, 0, format, args);
    if (messageLength < 0)
    {
        va_end(args);
        return;
    }

    // Allocate memory for the formatted message
    char *message = (char *)malloc((messageLength + 1) * sizeof(char));
    if (message == NULL)
    {
        va_end(args);
        return;
    }

    // Format the message
    vsnprintf(message, messageLength + 1, format, args);
    va_end(args);

    unsigned char TXbytes = 0;

    // Transmit the message
    while (TXbytes < messageLength)
    {
        // Transmit the next byte
        UART_sendCharacter(message[TXbytes]);
        TXbytes++;
    }

    // If last byte sent, disable the interrupt
    if (TXbytes == messageLength)
    {
        UCA1IFG &= ~UCTXIFG; // Clear the transmit interrupt flag
        TXbytes = 0;
    }

    free(message);
}
