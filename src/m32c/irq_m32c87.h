#include "cpu_m32c.h"
BusDevice * M32C87IntCo_New(const char *name);

#define M32C_INT_BRK			(0)
#define M32C_INT_DMA0		(0x20 >> 2)
#define M32C_INT_DMA1		(0x24 >> 2)
#define M32C_INT_DMA2		(0x28 >> 2)
#define M32C_INT_DMA3		(0x2C >> 2)
#define M32C_INT_TIMER_A0	(0x30 >> 2)
#define M32C_INT_TIMER_A1	(0x34 >> 2)
#define M32C_INT_TIMER_A2	(0x38 >> 2)
#define M32C_INT_TIMER_A3	(0x3c >> 2)
#define M32C_INT_TIMER_A4	(0x40 >> 2)
#define M32C_INT_UART0_TX	(0x44 >> 2)
#define M32C_INT_UART0_RX	(0x48 >> 2)
#define M32C_INT_UART1_TX	(0x4C >> 2)
#define M32C_INT_UART1_RX	(0x50 >> 2)
#define M32C_INT_TIMER_B0	(0x54 >> 2)
#define M32C_INT_TIMER_B1	(0x58 >> 2)
#define M32C_INT_TIMER_B2	(0x5c >> 2)
#define M32C_INT_TIMER_B3	(0x60 >> 2)
#define M32C_INT_TIMER_B4	(0x64 >> 2)
#define	M32C_INT_INT5		(0x68 >> 2)
#define	M32C_INT_INT4		(0x6c >> 2)
#define	M32C_INT_INT3		(0x70 >> 2)
#define	M32C_INT_INT2		(0x74 >> 2)
#define	M32C_INT_INT1		(0x78 >> 2)
#define	M32C_INT_INT0		(0x7c >> 2)
#define M32C_INT_TIMER_B5	(0x80 >> 2)
#define M32C_INT_UART2_TX	(0x84 >> 2)
#define M32C_INT_UART2_RX	(0x88 >> 2)
#define M32C_INT_UART3_TX	(0x8c >> 2)
#define	M32C_INT_UART3_RX	(0x90 >> 2)
#define M32C_INT_UART4_TX	(0x94 >> 2)
#define M32C_INT_UART4_RX	(0x98 >> 2)
#define M32C_INT_BCN_UART2	(0x9c >> 2)
#define	M32C_INT_BCN_UART03	(0xa0 >> 2)
#define M32C_INT_BCN_UART14	(0xa4 >> 2)
#define M32C_INT_AD0		(0xa8 >> 2)
#define M32C_INT_KEYINPUT	(0xac >> 2)

#define M32C_INT_IIO0		(0xb0 >> 2)
#define M32C_INT_CAN10		(0xb0 >> 2)
#define M32C_INT_UART5_RX	(0xb0 >> 2)

#define M32C_INT_IIO1		(0xb4 >> 2)
#define M32C_INT_CAN11		(0xb4 >> 2)
#define M32C_INT_UART56_TX	(0xb4 >> 2)
#define M32C_INT_IIO2		(0xb8 >> 2)
#define M32C_INT_IIO3		(0xbc >> 2)
#define M32C_INT_IIO4		(0xc0 >> 2)

#define M32C_INT_IIO5		(0xc4 >> 2)
#define M32C_INT_CAN12		(0xc4 >> 2)
#define M32C_INT_CAN1WU		(0xc4 >> 2)

#define M32C_INT_IIO6		(0xc8 >> 2)
#define M32C_INT_IIO7		(0xcc >> 2)
#define M32C_INT_IIO8		(0xd0 >> 2)
#define M32C_INT_IIO9		(0xd4 >> 2)
#define M32C_INT_CAN00		(0xd4 >> 2)
#define M32C_INT_UART6_RX	(0xd4 >> 2)
#define M32C_INT_INT6		(0xd4 >> 2)

#define M32C_INT_IIO10		(0xd8 >> 2)
#define M32C_INT_CAN01		(0xd8 >> 2)
#define M32C_INT_UART6_TX	(0xd8 >> 2)
#define M32C_INT_INT7		(0xd8 >> 2)

#define M32C_INT_IIO11		(0xe4 >> 2)
#define M32C_INT_CAN02		(0xe4 >> 2)
#define M32C_INT_INT8		(0xe4 >> 2)