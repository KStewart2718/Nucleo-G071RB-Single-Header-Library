#ifndef NUCLEO_DRIVER_H
#define NUCLEO_DRIVER_H

#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>

// Look into Infrared Interface (Simple wireless capabilities)

// Useful Type Aliasing
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;

typedef float f32;
typedef double f64;


// Helpful Constants
#define SYS_CLOCK_HZ 16000000
#define ONE_MS_TICKS ((SYS_CLOCK_HZ)/1000)

// Types for various register structures on STM32G071RB
typedef struct {
    volatile u32 CR;
    volatile u32 ICSCR;
    volatile u32 CFGR;
    volatile u32 PLLCFGR;
    volatile u32 RESERVED;
    volatile u32 CRRCR;
    volatile u32 CIER;
    volatile u32 CIFR;
    volatile u32 CICR;
    volatile u32 IOPRSTR;
    volatile u32 AHBRSTR;
    volatile u32 APBRSTR1;
    volatile u32 APBRSTR2;
    volatile u32 IOPENR;
    volatile u32 AHBENR;
    volatile u32 APBENR1;
    volatile u32 APBENR2;
    volatile u32 IOPSMENR;
    volatile u32 AHBSMENR;
    volatile u32 APBSMENR1;
    volatile u32 APBSMENR2;
    volatile u32 CCIPR;
    volatile u32 CCIPR2;
    volatile u32 BDCR;
    volatile u32 CSR;
} RCC_TypeDef;

typedef struct {
    volatile u32 ISR;
    volatile u32 IER;
    volatile u32 CR;
    volatile u32 CFGR1;
    volatile u32 CFGR2;
    volatile u32 SMPR;
    u32 RESERVED_BLOCK_1[2];
    volatile u32 AWD1TR;
    volatile u32 AWD2TR;
    volatile u32 CHSELR;
    volatile u32 AWD3TR;
    u32 RESERVED_BLOCK_2[4];
    volatile u32 DR;
    volatile u32 AWD2CR;
    volatile u32 AWD3CR;
} ADC_TypeDef;

typedef struct {
    volatile u32 CR;
    volatile u32 SWTRGR;
    volatile u32 DHR12R1;
    volatile u32 DHR12L1;
    volatile u32 DHR8R1;
    volatile u32 DHR12R2;
    volatile u32 DHR12L2;
    volatile u32 DHR8R2;
    volatile u32 DHR12RD;
    volatile u32 DHR12LD;
    volatile u32 DHR8RD;
    volatile u32 DOR1;
    volatile u32 DOR2;
    volatile u32 SR;
    volatile u32 CCR;
    volatile u32 MCR;
    volatile u32 SHSR1;
    volatile u32 SHSR2;
    volatile u32 SHHR;
    volatile u32 SHRR;
} DAC_TypeDef;

typedef struct{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 CR3;
    volatile u32 BRR;
    volatile u32 GTPR;
    volatile u32 RTOR;
    volatile u32 RQR;
    volatile u32 ISR;
    volatile u32 ICR;
    volatile u32 RDR;
    volatile u32 TDR;
    volatile u32 PRESC;
} USART_TypeDef;

typedef struct{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 OAR1;
    volatile u32 OAR2;
    volatile u32 TIMINGR;
    volatile u32 TIMEOUTR;
    volatile u32 ISR;
    volatile u32 ICR;
    volatile u32 PECR;
    volatile u32 RXDR;
    volatile u32 TXDR;
} I2C_TypeDef;

typedef struct{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SR;
    volatile u32 DR;
    volatile u32 CRCPR;
    volatile u32 RXCRCR;
    volatile u32 TXCRCR;
    volatile u32 I2SCFGR;
    volatile u32 I2SPR;
} SPI_TypeDef;

typedef struct {
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SMCR;
    volatile u32 DIER;
    volatile u32 SR;
    volatile u32 EGR;
    volatile u32 CCMR1;
    volatile u32 CCMR2;
    volatile u32 CCER;
    volatile u32 CNT;
    volatile u32 PSC;
    volatile u32 ARR;
    volatile u32 RCR;
    volatile u32 CCR1;
    volatile u32 CCR2;
    volatile u32 CCR3;
    volatile u32 CCR4;
    volatile u32 BDTR;
    volatile u32 DCR;
    volatile u32 DMAR;
    volatile u32 OR1;
    volatile u32 CCMR3;
    volatile u32 CCR5;
    volatile u32 CCR6;
    volatile u32 AF1;
    volatile u32 AF2;
    volatile u32 TISEL;
} TIM_TypeDef;

typedef struct{
    volatile u32 MODER;
    volatile u32 OTYPER;
    volatile u32 OSPEEDR;
    volatile u32 PUPDR;
    volatile u32 IDR;
    volatile u32 ODR;
    volatile u32 BSRR; // Write only
    volatile u32 LCKR;
    volatile u32 AFRL;
    volatile u32 AFRH;
    volatile u32 BRR; // Write only
} GPIO_TypeDef;

//Useful Enums for Code Clarity 
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

typedef enum{
    LOW,
    HIGH
} Output_Type;

// Useful Structures for Code Clarity and Implementation
typedef struct{
    GPIO_TypeDef* port;
    PinNumber num;
} Pin_TypeDef;

typedef struct{
    USART_TypeDef* usart;
    void (*begin)(i32);
    void (*print)(char*);
    void (*println)(char*);
    void (*print_int)(i32);
    void (*print_float)(f32);
    void (*println_int)(i32);
    void (*println_float)(f32);
} Serial_TypeDef;

// Registers in Core for SysTick
#define SYST_CSR (u32*)0xE000E010
#define SYST_RVR (u32*)0xE000E014
#define SYST_CVR (u32*)0xE000E018
#define SYST_CALIB (u32*)0xE000E01C
#define SYS_HPR3 (u32*)0xE000ED20

// Reset and Clock Control Register Address and Alias
#define RCC_BaseAddr 0x40021000
#define RCC ((RCC_TypeDef*)RCC_BaseAddr)


// GPIO Addresses and Aliases 
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

// USART Addresses and Aliases
#define USART1_BaseAddr 0x40013800
#define USART2_BaseAddr 0x40004400
#define USART3_BaseAddr 0x40004800
#define USART4_BaseAddr 0x40004C00

#define USART1 ((USART_TypeDef*)USART1_BaseAddr)
#define USART2 ((USART_TypeDef*)USART2_BaseAddr) //Connects to Virtual COM port
#define USART3 ((USART_TypeDef*)USART3_BaseAddr)
#define USART4 ((USART_TypeDef*)USART4_BaseAddr)

// I2C Addresses and Aliases
// Clocks enabled in APBENR1, I2C 1 - Bit 21, I2C2 - Bit 22, I2C3 - Bit 23
#define I2C1_BaseAddr 0x40005400
#define I2C2_BaseAddr 0x40005800
#define I2C3_BaseAddr 0x40008800

#define I2C1 ((I2C_TypeDef*)I2C1_BaseAddr)
#define I2C2 ((I2C_TypeDef*)I2C2_BaseAddr)
#define I2C3 ((I2C_TypeDef*)I2C3_BaseAddr)

#define I2C1_CLKEN (1UL << 21)

// Timer Addresses and Aliases

/* Timer Clock Base List
*  2,3,4,6,7 - APBENR1
*  1,14,15,16,17 - APBENR2 
*/

#define TIM1_BaseAddr 0x40012C00
#define TIM2_BaseAddr 0x40000000
#define TIM3_BaseAddr 0x40000400
#define TIM4_BaseAddr 0x40000800
#define TIM6_BaseAddr 0x40001000
#define TIM7_BaseAddr 0x40001400
#define TIM14_BaseAddr 0x40002000
#define TIM15_BaseAddr 0x40014000
#define TIM16_BaseAddr 0x40014400
#define TIM17_BaseAddr 0x40014800

#define TIM1 ((TIM_TypeDef*)TIM1_BaseAddr)
#define TIM2 ((TIM_TypeDef*)TIM2_BaseAddr)
#define TIM3 ((TIM_TypeDef*)TIM3_BaseAddr)
#define TIM4 ((TIM_TypeDef*)TIM4_BaseAddr)
#define TIM6 ((TIM_TypeDef*)TIM6_BaseAddr)
#define TIM7 ((TIM_TypeDef*)TIM7_BaseAddr)
#define TIM14 ((TIM_TypeDef*)TIM14_BaseAddr)
#define TIM15 ((TIM_TypeDef*)TIM15_BaseAddr)
#define TIM16 ((TIM_TypeDef*)TIM16_BaseAddr)
#define TIM17 ((TIM_TypeDef*)TIM17_BaseAddr)

// Pin Aliases for STM32 Pin Labels and Arduino Pin Labels
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

// Communication Peripheral Pin Aliases
#define I2C_SDA D14
#define I2C_SCL D15

#define UART1_RX D0
#define UART1_TX D1

#define SPI1_SCK D13
#define SPI1_MISO D12
#define SPI1_MOSI D11
#define SPI1_CS D10

#define SERIAL_TX PA2
#define SERIAL_RX PA3

// Led Pin Alias
#define LED_PIN PA5

// PWM Pin-Timer Associations
#define PA7_PWM_TIMER TIM3    // AF1, TIM3_CH2
#define PB0_PWM_TIMER TIM3    // AF1, TIM3_CH3
#define PB3_PWM_TIMER TIM1    // AF1, TIM1_CH2
#define PB4_PWM_TIMER TIM3    // AF1, TIM3_CH1
#define PB14_PWM_TIMER TIM15  // AF5, TIM15_CH1
#define PC7_PMW_TIMER TIM2    // AF2, TIM2_CH4

// Initialisation Functions
void initialiseMCU(void);
void SysTickInit(u32 ticks);
void GPIOInit(void);
void SerialInit(void);

// Pin Control Functions
void pinMode(Pin_TypeDef pin, PinMode mode);
void digitalWrite(Pin_TypeDef pin, Output_Type output);
void analogWrite(Pin_TypeDef pin, uint8_t duty_cycle);

// Pin Control LL functions
//void setAltFunction(Pin_TypeDef pin, uint8_t alt_func_num);

// Serial Helper Functions
void begin(i32 baud_rate);
void print(char* str);
void println(char* str);
void print_int(i32 num);
void println_int(i32 num);
void print_float(f32 num);
void println_float(f32 num);

// I2C Helper Functions
void I2C_Init(void);
void I2C_WriteByte(u8 addr, u8 data);
void I2C_ReadByte(u8 addr, u8* data_buffer);
void I2C_WriteBytes(u8 addr, u8* data, u16 length);

// Delay Helper Function
void delay(u32 milliseconds);

// Useful extern variables
extern Serial_TypeDef Serial;
extern volatile u32 Tick;

#endif

#ifdef STM_DRIVER_IMPLEMENTATION

// Helper Variable Definitions
Serial_TypeDef Serial = {USART2, begin, print, println, \
    print_int, print_float, println_int, println_float};

volatile u32 Tick = 0;

// Static Helper Functions
static i32 int_pow(i32 num, i32 power)
{
    i32 base_num = num;
    while(--power)
    {
        num *= base_num;
    }

    return num;
}

static void reverse_string(char* str, u32 length)
{
    i32 start = 0;
    i32 end = length - 1;
    while(start < end)
    {
        char tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        start++;
        end--;
    }
}

static i32 tiny_itoa(i32 num, char* str, i32 trailing_zeros)
{
    i32 i = 0;
    i32 negative = 0;

    if(num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return 1;
    }

    if(num < 0)
    {
        negative = 1;
        num = -num;
    }

    while(num != 0)
    {
        i32 rem = num % 10;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num /= 10;
    }

    while(i < trailing_zeros)
    {
        str[i++] = '0';
    }

    if(negative)
    {
        str[i++] = '-';
    }

    str[i] = '\0';
    reverse_string(str, i);
    return i;
}

static void tiny_ftoa(f32 num, char* str, i32 precision)
{
    char temp_buffer[32];

    i32 integer_part = (i32)num;
    f32 fractional_part = num - integer_part;
    
    if(fractional_part < 0) fractional_part = -fractional_part;

    i32 length = tiny_itoa(integer_part, temp_buffer, 0);
    
    if(precision > 0)
    {
        temp_buffer[length++] = '.';
        fractional_part = fractional_part * (f32)int_pow(10, precision);

        length += tiny_itoa((i32)(fractional_part+0.5f), temp_buffer + length, precision);
    }

    for(i32 j = 0; j < length; j++)
    {
        str[j] = temp_buffer[j];
    }
}

static void tiny_sprintf(char* buffer, const char* format, ...)
{
    va_list args;
    va_start(args, format);

    char tmp_buff[12] = {0};
    i32 integer_num = 0;
    f64 floating_point_num = 0;

    while(*format != '\0')
    {
        if(*format == '%')
        {
            format++;

            switch(*format)
            {
                case 'i':
                    integer_num = va_arg(args, i32);
                    tiny_itoa(integer_num, tmp_buff, 0);
                    char* t = tmp_buff;
                    while(*t)
                    {
                        *buffer++ = *t++;
                    }
                    format++;
                    break;
                case 'f':
                    floating_point_num = va_arg(args, f64);
                    tiny_ftoa(floating_point_num, tmp_buff, 6);
                    char* tmp = tmp_buff;
                    while(*tmp)
                    {
                        *buffer++ = *tmp++;
                    }
                    format++;
                    break;
                default:
                    break;
            }
        }
        else{
            *buffer++ = *format++;
        }
    }

    *buffer = '\0';
    va_end(args);
}

static void setAltFunction(Pin_TypeDef pin, u8 alt_func)
{
    if(pin.num < 8)
    {
        (pin.port)->AFRL &= ~(0xFUL) << 4*(pin.num);
        (pin.port)->AFRL |= alt_func << 4*(pin.num);
    }
    else
    {
        (pin.port)->AFRH &= ~(0xFUL) << 4*(pin.num - 8);
        (pin.port)->AFRH |= alt_func << 4*(pin.num - 8);
    }
}

static void setPWMMode(Pin_TypeDef pin)
{
    u32 compare_val = ((pin.port)->MODER & (3UL << 2*(pin.num)));
    if(compare_val != (2UL << 2*(pin.num)))
    {
        pinMode(pin, ALTERNATE);
    }

    switch(pin.num)
    {
        case 0:
            if(pin.port == GPIOB) setAltFunction(pin, 1); // TIM3_CH3
            break;
        case 3:
            if(pin.port == GPIOB) setAltFunction(pin, 1); // TIM1_CH2
            break;
        case 4:
            if(pin.port == GPIOB) setAltFunction(pin, 1); // TIM3_CH1
            break;
        case 7:
            if(pin.port == GPIOA) setAltFunction(pin, 1); // TIM3_CH2
            else if(pin.port == GPIOC) setAltFunction(pin, 2); // TIM2_CH4
            break;
        case 14:
            if(pin.port == GPIOB) setAltFunction(pin, 5); // TIM15_CH1
            break;
        default:
            break;
    }
}

static void setupTimer(Pin_TypeDef pin, u8 duty_cycle)
{
    TIM_TypeDef* timer;

    switch(pin.num)
    {
        case 0: 
            timer = TIM3;
            break;
        case 3:
            timer = TIM1;
            break;
        case 4:
            timer = TIM3;
            break;
        case 7:
            if(pin.port == GPIOA) timer = TIM3; 
            else if(pin.port == GPIOC) timer = TIM2;
            else timer = NULL;
            break;
        case 14:
            timer = TIM15;
            break;
        default: 
            break;
    }

    if(timer == NULL)
    {
        return;
    }
    //if(timer->CR1 & 1UL) return; // Return if timer is already on.

    f32 duty_cycle_percentage = duty_cycle / 255.0f;
    
    timer->CCMR1 |= (3UL << 5) | (1UL << 3); // Sets PWM Mode 1 (High -> Low)
    timer->CCER |= 1UL;
    timer->CR1 |= (1UL << 7);
    timer->PSC &= 0UL; // Zero the Prescaler
    timer->ARR &= 0UL; // Zero the Auto-Reload Register
    timer->ARR |= 799; // Should result in 20kHz PWM Frequency with 0 Prescaler
    timer->CCR1 &= 0UL;
    timer->CCR1 |= (u32)(800 * duty_cycle_percentage);
    timer->EGR |= 1UL;
    timer->CR1 |= 1UL; // Enable the counter
}


// Interrupt Handler for tracking millisecond time steps
void SysTick_Handler(void)
{
    Tick++;
}

/**************************************************************
*
*   User Facing Functions
*   
**************************************************************/

// Initialise core features for basic MCU use
void initialiseMCU()
{
    SysTickInit(ONE_MS_TICKS); 

    GPIOInit();
    RCC->APBENR1 |= 1UL << 1; // Enable TIM3
}

// Setup the SysTick timer for use in implementing a basic "delay" function
void SysTickInit(u32 ticks)
{
    //Clear SysTick Reset Value Register
    *SYST_RVR &= ~(0x00FFFFFF);

    // Set SysTick Reload value to 1ms worth of clock ticks (Clock is 16MHz)
    *SYST_RVR |= ticks - 1; 

    // Set Priority of SysTick Interrupt to highest (0 is highest)
    *SYS_HPR3 &= ~(0xFUL) << 28; 

    // Enable SysTick Timer and Interrupt
    *SYST_CSR |= 7UL; 
}

void GPIOInit()
{
    // Enable GPIOA-F Clocks
    RCC->IOPENR |= 0x3F;
}

void pinMode(Pin_TypeDef pin, PinMode mode)
{
    // Clear current mode by zeroing the relevant bits
    (pin.port)->MODER &= ~(0x3UL << (2 * pin.num)); 

    // Set new mode
    (pin.port)->MODER |= (mode << (2 * pin.num)); 
}

void digitalWrite(Pin_TypeDef pin, Output_Type output)
{
    // Set or reset pin by writing to Bit Set/Reset Register (BSSR) 
    // [pg. 241 of STM32G0x1 reference manual]
    (pin.port)->BSRR |= 1UL << (pin.num + 16*(!output));
}

void analogWrite(Pin_TypeDef pin, u8 duty_cycle)
{
    setPWMMode(pin);
    setupTimer(pin, duty_cycle);
}

// Serial Functions Definitions
void begin(i32 baud_rate)
{
    // Initialise USART2 for Serial use

    // Enable USART2 Clock
    RCC->APBENR1 |= 1UL << 17; 

    // Set Serial Pins for ALT functions
    pinMode(SERIAL_TX, ALTERNATE);   
    pinMode(SERIAL_RX, ALTERNATE);

    // Clear the Alternate Function bits for pins 2 and 3
    GPIOA->AFRL &= ~((0xFU << (2 * 4)) | (0xFU << (3*4)));

    // Set the AF bits for AF1
    GPIOA->AFRL |= ((0x1U << (2 * 4)) | (0x1U << (3*4)));   

    // Set baud rate
    USART2->BRR = 16000000UL / baud_rate;

    // Enables the Transmitter and the USART peripheral
    // [Pg. 1036 in the STM32G0x1 Reference Manual]
    USART2->CR1 |= (1UL << 3) | (1U << 0);
}

void print(char* str)
{
    // NB: Strings (char*) always end with a null terminator (a 0) in C
    
    // While we're not at the end of the string
    while(*str)
    {
        // Wait until transmit buffer is not full
        while(!(USART2->ISR & (1UL << 7)));
        
        // Write the next char of the string into the transmit data register  
        USART2->TDR = *str++;
    }
}

void println(char* str)
{
    Serial.print(str);
    Serial.print("\r\n");
}

void print_int(i32 num)
{
    char temp_string[11] = {0};
    tiny_sprintf(temp_string, "%i", num);
    Serial.print(temp_string);
}

void println_int(i32 num)
{
    print_int(num);
    Serial.print("\r\n");
}

void print_float(f32 num)
{
    char temp_string[16] = {0};
    tiny_sprintf(temp_string, "%f", num);
    Serial.print(temp_string);
}

void println_float(f32 num)
{
    print_float(num);
    Serial.print("\r\n");
}

/*
*
*   I2C Helper Functions
*
*
*/

void I2C_Init(void)
{

    I2C1->CR1 &= ~(1UL);    // Ensures peripheral is disabled

    RCC->APBENR1 |= 1UL << 21;  // Enable I2C1 Clock

    pinMode(D14, ALTERNATE);
    pinMode(D15, ALTERNATE);

    setAltFunction(D14, 6);
    setAltFunction(D15, 6);

    GPIOB->OTYPER |= (1UL << 8) | (1UL << 9);   // Set pins to Open-Drain
    GPIOB->OSPEEDR |= (3UL << 8*2) | (3UL << 9*2); // Set pins to High Speed
    GPIOB->PUPDR |= (1UL << 8*2) | (1UL << 9*2);
    

    // Sets timer up for 100kHz bus assuming a 16MHz input clock (Value from default MXCube build)
    I2C1->TIMINGR = 0x00503D5A;
    
    I2C1->CR1 |= 1UL;   // Enable the peripheral
}

void I2C_WriteByte(u8 addr, u8 data)
{
    I2C1->CR2 &= 0UL; // Clear CR2 Register
    I2C1->CR2 |= (addr) | (1UL << 16) | (1UL << 25) | (1UL << 13);
    
    while(!(I2C1->ISR & (1UL)));   // Wait for TX Register to be empty
    I2C1->TXDR = data;

    while(!(I2C1->ISR & (1UL << 5)));   // Wait for STOP Flag
    I2C1->ICR |= (1UL << 5);   // Clear STOP Flag
}

void I2C_ReadByte(u8 addr, u8* data_buffer)
{
    I2C1->CR2 &= 0UL; // Clear CR2 Register
    I2C1->CR2 |= (addr) | (1UL << 16) | (1UL << 25) | (1UL << 10) | (1UL << 13);

    while(!(I2C1->ISR & (1UL << 2)));
    *data_buffer = I2C1->RXDR;

    while(!(I2C1->ISR & (1UL << 5)));   // Wait for STOP Flag
    I2C1->ICR |= (1UL << 5);   // Clear STOP Flag
}

void I2C_WriteBytes(u8 addr, u8* data, u16 length)
{

    I2C1->CR2 &= 0UL; // Clear CR2 Register
    I2C1->CR2 |= (addr) | (length << 16) | (1UL << 25) | (1UL << 13);

    while(!(I2C1->ISR & 1UL));
    I2C1->TXDR = data[0];
    

    if(length > 1)
    {
        for(u16 i = 1; i < length; i++)
        {
            while(!(I2C1->ISR & 1UL));
            I2C1->TXDR = data[i]; 
        }
    }

    while(!(I2C1->ISR & (1UL << 5)));
    I2C1->ICR |= (1UL << 5);
}

void I2C_ReadBytes(u8 addr, u8* data_buffer, u16 length)
{
    I2C1->CR2 &= 0UL; // Clear CR2 Register
    I2C1->CR2 |= (addr) | (length << 16) | (1UL << 25) | (1UL << 10) | (1UL << 13);

    while(!(I2C1->ISR & (1UL << 2)));
    *data_buffer = I2C1->RXDR;

    if(length > 1)
    {
        for(u8 i = 1; i < length; i++)
        {
            while(!(I2C1->ISR & (1UL << 2)));
            *(data_buffer + i) = I2C1->RXDR;        
        }
    }

    while(!(I2C1->ISR & (1UL << 5)));
    I2C1->ICR |= (1UL << 5);
}

/*
*
*   Helper Function Definitions
*
*
*/
void delay(u32 milliseconds)
{    
    u32 start_time = Tick;

    while(Tick < (start_time + (milliseconds)));
}

#endif
