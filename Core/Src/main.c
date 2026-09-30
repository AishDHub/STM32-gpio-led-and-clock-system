#include "main.h"
#include"stdint.h"

/*defining macros for base address of each port*/

#define GPIOA_BASE_ADDR   0x40010C00U
#define GPIOB_BASE_ADDR   0x40011000U
#define GPIOC_BASE_ADDR   0x40011400U
#define GPIOD_BASE_ADDR   0x40011800U
#define GPIOE_BASE_ADDR   0x40011C00U

/*defining macros for offset address of each registers*/

#define GPIOx_CRL_OFFSET   0x00U
#define GPIOx_CRH_OFFSET   0x04U
#define GPIOx_IDR_OFFSET   0x08hU
#define GPIOx_ODR_OFFSET   0x0CU
#define GPIOx_BSRR_OFFSET  0x10U
#define GPIOx_BSR_OFFSET   0x14U
#define GPIOx_LCKR_OFFSET  0x18U


/*Actual address of each pin*/

#define GPIOC_CRL_ADDR   (GPIOC_BASE_ADDR + GPIOx_CRL_OFFSET)
#define GPIOC_CRH_ADDR   (GPIOC_BASE_ADDR + GPIOx_CRH_OFFSET)
#define GPIOC_IDR_ADDR   (GPIOC_BASE_ADDR + GPIOx_IDR_OFFSET)
#define GPIOC_ODR_ADDR   (GPIOC_BASE_ADDR + GPIOx_ODR_OFFSET)
#define GPIOC_BSRR_ADDR  (GPIOC_BASE_ADDR + GPIOx_BSRR_OFFSET)
#define GPIOC_BRR_ADDR   (GPIOC_BASE_ADDR + GPIOx_BRR_OFFSET)
#define GPIOC_LCKR_ADDR  (GPIOC_BASE_ADDR + GPIOx_LCKR_OFFSET)


/*macros related to RCC*/

#define RCC_BASE_ADDR  0x40021000U

#define RCC_APB2ENR_OFFSET_ADDR  0x018U
#define RCC_APB2ENR_ADDR         (RCC_BASE_ADDR + RCC_APB2ENR_OFFSET_ADDR)

#define RCC_CFGR_OFFSET_ADDR     0x004U
#define RCC_CFGR_ADDR            (RCC_BASE_ADDR + RCC_CFGR_OFFSET_ADDR)

#define RCC_APB2RSTR_OFFSET_ADDR 0x00CU
#define RCC_APB2RSTR_ADDR        (RCC_BASE_ADDR + RCC_APB2RSTR_OFFSET_ADDR)

#define RCC_AHBENR_OFFSET_ADDR   0x014U
#define RCC_AHBENR_ADDR          (RCC_BASE_ADDR + RCC_AHBENR_OFFSET_ADDR)

#define RCC_CR_OFFSET_ADDR       0x000U
#define RCC_CR_ADDR              (RCC_BASE_ADDR + RCC_CR_OFFSET_ADDR)

#define RCC_CFGR2_OFFSET_ADDR    0x02CU
#define RCC_CFGR2_ADDR           (RCC_BASE_ADDR + RCC_CFGR2_OFFSET_ADDR)


int main(void)
{
    //volatile uint32_t *GPIOCPIN_CRH_ADDR = (volatile uint32_t*)GPIOC_CRH_ADDR;

    volatile uint32_t *GPIOCPIN_BSRR_ADDR =
        (volatile uint32_t *)GPIOC_BSRR_ADDR;

    volatile uint32_t *GPIOCPIN_CRH_ADDR =
        (volatile uint32_t *)GPIOC_CRH_ADDR;

    volatile uint32_t *RCC_APB2ENR_ADDRS =
        (volatile uint32_t *)RCC_APB2ENR_ADDR;

    *RCC_APB2ENR_ADDRS |= (1U << 4);

    *GPIOCPIN_CRH_ADDR &= ~(0xFU << 20);
    *GPIOCPIN_CRH_ADDR |= (0x2U << 20);

    while (1)
        {
            *GPIOCPIN_BSRR_ADDR = (1U << 29);

            for (volatile uint32_t i = 0; i < 500000; i++);

            *GPIOCPIN_BSRR_ADDR = (1U << 13);

            for (volatile uint32_t i = 0; i < 500000; i++);
        }

}
