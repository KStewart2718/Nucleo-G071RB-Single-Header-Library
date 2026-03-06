#ifndef NUCLEO_DRIVER_H
#define NUCLEO_DRIVER_H

#include <stdint.h>

// Types for various register structures on STM32G071RB
typedef struct {
    volatile uint32_t CR;
    volatile uint32_t ICSCR;
    volatile uint32_t CFGR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t RESERVED;
    volatile uint32_t CRRCR;
    volatile uint32_t CIER;
    volatile uint32_t CIFR;
    volatile uint32_t CICR;
    volatile uint32_t IOPRSTR;
    volatile uint32_t AHBRSTR;
    volatile uint32_t APBRSTR1;
    volatile uint32_t APBRSTR2;
    volatile uint32_t IOPENR;
    volatile uint32_t AHBENR;
    volatile uint32_t APBENR1;
    volatile uint32_t APBENR2;
    volatile uint32_t IOPSMENR;
    volatile uint32_t AHBSMENR;
    volatile uint32_t APBSMENR1;
    volatile uint32_t APBSMENR2;
    volatile uint32_t CCIPR;
    volatile uint32_t CCIPR2;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
} RCC_TypeDef;

typedef struct {
    volatile uint32_t ISR;
    volatile uint32_t IER;
    volatile uint32_t CR;
    volatile uint32_t CFGR1;
    volatile uint32_t CFGR2;
    volatile uint32_t SMPR;
    uint32_t RESERVED_BLOCK_1[2];
    volatile uint32_t AWD1TR;
    volatile uint32_t AWD2TR;
    volatile uint32_t CHSELR;
    volatile uint32_t AWD3TR;
    uint32_t RESERVED_BLOCK_2[4];
    volatile uint32_t DR;
    volatile uint32_t AWD2CR;
    volatile uint32_t AWD3CR;
} ADC_TypeDef;

typedef struct {
    volatile uint32_t CR;
    volatile uint32_t SWTRGR;
    volatile uint32_t DHR12R1;
    volatile uint32_t DHR12L1;
    volatile uint32_t DHR8R1;
    volatile uint32_t DHR12R2;
    volatile uint32_t DHR12L2;
    volatile uint32_t DHR8R2;
    volatile uint32_t DHR12RD;
    volatile uint32_t DHR12LD;
    volatile uint32_t DHR8RD;
    volatile uint32_t DOR1;
    volatile uint32_t DOR2;
    volatile uint32_t SR;
    volatile uint32_t CCR;
    volatile uint32_t MCR;
    volatile uint32_t SHSR1;
    volatile uint32_t SHSR2;
    volatile uint32_t SHHR;
    volatile uint32_t SHRR;
} DAC_TypeDef;

typedef struct{
    uint32_t CR1;
    uint32_t CR2;
    uint32_t CR3;
    uint32_t BRR;
    uint32_t GTPR;
    uint32_t RTOR;
    uint32_t RQR;
    uint32_t ISR;
    uint32_t ICR;
    uint32_t RDR;
    uint32_t TDR;
    uint32_t PRESC;
} USART_TypeDef;

typedef struct{
    uint32_t CR1;
    uint32_t CR2;
    uint32_t OAR1;
    uint32_t OAR2;
    uint32_t TIMINGR;
    uint32_t TIMEOUTR;
    uint32_t ISR;
    uint32_t ICR;
    uint32_t PECR;
    uint32_t RXDR;
    uint32_t TXDR;
} I2C_TypeDef;

typedef struct{
    uint32_t CR1;
    uint32_t CR2;
    uint32_t SR;
    uint32_t DR;
    uint32_t CRCPR;
    uint32_t RXCRCR;
    uint32_t TXCRCR;
    uint32_t I2SCFGR;
    uint32_t I2SPR;
} SPI_TypeDef;

typedef struct {
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SMCR;
    volatile uint32_t DIER;
    volatile uint32_t SR;
    volatile uint32_t EGR;
    volatile uint32_t CCMR1;
    volatile uint32_t CCMR2;
    volatile uint32_t CCER;
    volatile uint32_t CNT;
    volatile uint32_t PSC;
    volatile uint32_t ARR;
    volatile uint32_t RCR;
    volatile uint32_t CCR1;
    volatile uint32_t CCR2;
    volatile uint32_t CCR3;
    volatile uint32_t CCR4;
    volatile uint32_t BDTR;
    volatile uint32_t DCR;
    volatile uint32_t DMAR;
    volatile uint32_t OR1;
    volatile uint32_t CCMR3;
    volatile uint32_t CCR5;
    volatile uint32_t CCR6;
    volatile uint32_t AF1;
    volatile uint32_t AF2;
    volatile uint32_t TISEL;
} TIM_TypeDef;

typedef struct{
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR; // Write only
    volatile uint32_t LCKR;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;
    volatile uint32_t BRR; // Write only
} GPIO_TypeDef;

typedef enum{
    PIN_0,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7,
    PIN_8,
    PIN_9,
    PIN_10,
    PIN_11,
    PIN_12,
    PIN_13,
    PIN_14,
    PIN_15
} PinNumber;

typedef enum{
    INPUT,
    OUTPUT,
    ALTERNATE,
    ANALOG,
    UNSET
} PinMode;

typedef struct{
    GPIO_TypeDef* port;
    PinNumber num;
} Pin_TypeDef;

typedef enum{
    LOW,
    HIGH
} Output_Type;

#define RCC_BaseAddr 0x40021000
#define RCC ((RCC_TypeDef*)RCC_BaseAddr)

#define GPIO_OFFSET 0x400

#define GPIOA_BaseAddr 0x50000000
#define GPIOA ((GPIO_TypeDef*)GPIOA_BaseAddr)

#define GPIOB_BaseAddr (GPIOA_BaseAddr + GPIO_OFFSET)
#define GPIOB ((GPIO_TypeDef*)GPIOB_BaseAddr)

#define GPIOC_BaseAddr (GPIOA_BaseAddr + (2 * GPIO_OFFSET))
#define GPIOC ((GPIO_TypeDef*)GPIOC_BaseAddr)

#define GPIOD_BaseAddr (GPIOA_BaseAddr + (3 * GPIO_OFFSET))
#define GPIOD ((GPIO_TypeDef*)GPIOD_BaseAddr)

#define GPIOE_BaseAddr (GPIOA_BaseAddr + (4 * GPIO_OFFSET))
#define GPIOE ((GPIO_TypeDef*)GPIOE_BaseAddr)

#define GPIOF_BaseAddr (GPIOA_BaseAddr + (5 * GPIO_OFFSET))
#define GPIOF ((GPIO_TypeDef*)GPIOF_BaseAddr)

#define GPIOx_MODER_ALL_OUTPUT_MASK 0x555555F5

// Aliases for USART Memory Mapping

#define USART1_BaseAddr 0x40013800
#define USART2_BaseAddr 0x40004400
#define USART3_BaseAddr 0x40004800
#define USART4_BaseAddr 0x40004C00

#define USART1 ((USART_TypeDef*)USART1_BaseAddr)
#define USART2 ((USART_TypeDef*)USART2_BaseAddr) // Connected to Virtual COM port - Will be used for Serial Methods
#define USART3 ((USART_TypeDef*)USART3_BaseAddr)
#define USART4 ((USART_TypeDef*)USART4_BaseAddr)

typedef struct{
    USART_TypeDef* usart;
    void (*begin)(int);
    void (*print)(char*);
    void (*println)(char*);
    //void (*print_char)(char);
    //void (*print_str)(char*);
    void (*print_int)(int);
    void (*print_float)(float);
    //void (*println_char)(char);
    //void (*println_str)(char*);
    void (*println_int)(int);
    void (*println_float)(float);
} Serial_TypeDef;

#define PA0 (Pin_TypeDef){GPIOA, PIN_0}
#define PA1 (Pin_TypeDef){GPIOA, PIN_1}
#define PA2 (Pin_TypeDef){GPIOA, PIN_2}
#define PA3 (Pin_TypeDef){GPIOA, PIN_3}
#define PA4 (Pin_TypeDef){GPIOA, PIN_4}
#define PA5 (Pin_TypeDef){GPIOA, PIN_5}
#define PA6 (Pin_TypeDef){GPIOA, PIN_6}
#define PA7 (Pin_TypeDef){GPIOA, PIN_7}
#define PA8 (Pin_TypeDef){GPIOA, PIN_8}
#define PA9 (Pin_TypeDef){GPIOA, PIN_9}
#define PA10 (Pin_TypeDef){GPIOA, PIN_10}
#define PA11 (Pin_TypeDef){GPIOA, PIN_11}
#define PA12 (Pin_TypeDef){GPIOA, PIN_12}
#define PA13 (Pin_TypeDef){GPIOA, PIN_13}
#define PA14 (Pin_TypeDef){GPIOA, PIN_14}
#define PA15 (Pin_TypeDef){GPIOA, PIN_15}

#define PB0 (Pin_TypeDef){GPIOB, PIN_0}
#define PB1 (Pin_TypeDef){GPIOB, PIN_1}
#define PB2 (Pin_TypeDef){GPIOB, PIN_2}
#define PB3 (Pin_TypeDef){GPIOB, PIN_3}
#define PB4 (Pin_TypeDef){GPIOB, PIN_4}
#define PB5 (Pin_TypeDef){GPIOB, PIN_5}
#define PB6 (Pin_TypeDef){GPIOB, PIN_6}
#define PB7 (Pin_TypeDef){GPIOB, PIN_7}
#define PB8 (Pin_TypeDef){GPIOB, PIN_8}
#define PB9 (Pin_TypeDef){GPIOB, PIN_9}
#define PB10 (Pin_TypeDef){GPIOB, PIN_10}
#define PB11 (Pin_TypeDef){GPIOB, PIN_11}
#define PB12 (Pin_TypeDef){GPIOB, PIN_12}
#define PB13 (Pin_TypeDef){GPIOB, PIN_13}
#define PB14 (Pin_TypeDef){GPIOB, PIN_14}
#define PB15 (Pin_TypeDef){GPIOB, PIN_15}

#define PC0 (Pin_TypeDef){GPIOC, PIN_0}
#define PC1 (Pin_TypeDef){GPIOC, PIN_1}
#define PC2 (Pin_TypeDef){GPIOC, PIN_2}
#define PC3 (Pin_TypeDef){GPIOC, PIN_3}
#define PC4 (Pin_TypeDef){GPIOC, PIN_4}
#define PC5 (Pin_TypeDef){GPIOC, PIN_5}
#define PC6 (Pin_TypeDef){GPIOC, PIN_6}
#define PC7 (Pin_TypeDef){GPIOC, PIN_7}
#define PC8 (Pin_TypeDef){GPIOC, PIN_8}
#define PC9 (Pin_TypeDef){GPIOC, PIN_9}
#define PC10 (Pin_TypeDef){GPIOC, PIN_10}
#define PC11 (Pin_TypeDef){GPIOC, PIN_11}
#define PC12 (Pin_TypeDef){GPIOC, PIN_12}
#define PC13 (Pin_TypeDef){GPIOC, PIN_13}
#define PC14 (Pin_TypeDef){GPIOC, PIN_14}
#define PC15 (Pin_TypeDef){GPIOC, PIN_15}

#define PD0 (Pin_TypeDef){GPIOD, PIN_0}
#define PD1 (Pin_TypeDef){GPIOD, PIN_1}
#define PD2 (Pin_TypeDef){GPIOD, PIN_2}
#define PD3 (Pin_TypeDef){GPIOD, PIN_3}
#define PD4 (Pin_TypeDef){GPIOD, PIN_4}
#define PD5 (Pin_TypeDef){GPIOD, PIN_5}
#define PD6 (Pin_TypeDef){GPIOD, PIN_6}
#define PD8 (Pin_TypeDef){GPIOD, PIN_8}
#define PD9 (Pin_TypeDef){GPIOD, PIN_9}

#define PF0 (Pin_TypeDef){GPIOF, PIN_0}
#define PF1 (Pin_TypeDef){GPIOF, PIN_1}
#define PF2 (Pin_TypeDef){GPIOF, PIN_2}

#define A0 PA0      // ADC Channel 0
#define A1 PA1      // ADC Channel 1
#define A2 PA4      // DAC Output & ADC Channel 4
#define A3 PB1      // ADC Channel 9
#define A4 PB11     // ADC Channel 15
#define A5 PB12     // ADC Channel 16

#define D0 PC5      // UART1_RX
#define D1 PC4      // UART1_TX
#define D2 PA10
#define D3 PB3      // PWM 
#define D4 PB5
#define D5 PB4      // PWM
#define D6 PB14     // PWM
#define D7 PA8
#define D8 PA9
#define D9 PC7      // PWM
#define D10 PB0     // PWM
#define D11 PA7     // PWM
#define D12 PA6
#define D13 PA5     // Bulit-in LED and DAC Output
#define D14 PB9     // I2C_SDA
#define D15 PB8     // I2C_SCL

// Initialisation and Pin Control Functions
void initialiseMCU(void);
void digitalWrite(Pin_TypeDef pin, Output_Type output);
void pinMode(Pin_TypeDef pin, PinMode mode);

// Serial Helper Functions
void begin(int baud_rate);
void print(char* str);
void println(char* str);
void print_int(int num);
void println_int(int num);
void print_float(float num);
void println_float(float num);

// Useful extern variables
extern Serial_TypeDef Serial;

#endif

#ifdef STM_DRIVER_IMPLEMENTATION

Serial_TypeDef Serial = {USART2, begin, print, println, print_int, print_float, println_int, println_float};

void initialiseMCU()
{
    // Initialise arduino header pins for anticipated use case (Dx as digital outputs, Ax as analog inputs, Tx/Rx as UART)
    RCC->IOPENR |= 0x3F; // Enable GPIOA-F
}

void digitalWrite(Pin_TypeDef pin, Output_Type output)
{
    (pin.port)->BSRR |= 1UL << (pin.num + 16*(!output)); // Set or reset pin by writing to Bit Set/Reset Register (BSSR) [pg. 241 of STM32G0x1 reference manual]
}

void pinMode(Pin_TypeDef pin, PinMode mode)
{
    (pin.port)->MODER &= ~(0x3UL << (2 * pin.num)); // Clear current mode by zeroing the relevant bits
    (pin.port)->MODER |= (mode << (2 * pin.num)); // Set new mode
}

// Serial Functions Definitions
void begin(int baud_rate)
{
    //Initialise USART2 for Serial use
    RCC->APBENR1 |= 1UL << 17; // Enable USART2 Clock (Needed for Serial)
    pinMode(PA2, ALTERNATE);   // Set Pins for ALT functions
    pinMode(PA3, ALTERNATE);
    GPIOA->AFRL &= ~((0xFU << (2 * 4)) | (0xFU << (3*4)));  // Clear the AF bits for the pins 2 and 3
    GPIOA->AFRL |= ((0x1U << (2 * 4)) | (0x1U << (3*4)));   // Set the AF bits for AF1

    USART2->BRR = 16000000UL / baud_rate;
    USART2->CR1 |= (1UL << 3) | (1U << 0);
}

void print(char* str)
{
    while(*str)
    {
        while(!(USART2->ISR & (1UL << 7)));

        USART2->TDR = *str++;
    }
}

void println(char* str)
{
    Serial.print(str);
    Serial.print("\r\n");
}

void print_int(int num)
{

}

void println_int(int num)
{

}

void print_float(float num)
{

}

void println_float(float num)
{

}

#endif
