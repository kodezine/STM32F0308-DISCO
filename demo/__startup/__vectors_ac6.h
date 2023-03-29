#ifndef VECTORS_AC6_H
#define VECTORS_AC6_H
#include <stdint.h>
/**
 * @brief This file needs to be REMOVED or MODIFIED in future once
 * the STMCubeMX starts generating startup in .c format
 * and there exists a "startup_STM32H743XX.c" file complying to
 * CMSIS Version >= 5.9
 * It should be noted that the future will see all startup assembly files
 * replaced with c files for portablity as part of CMSIS Readme
 *
 * The typedef is the only thing missing in the current implementation
 */
#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief This constant can be removed as well
 * once things get more clear {BSP has a similar macro }
 */
#ifdef BSP_IRQ_ID_NUM
#define VECTOR_TABLE_LENGTH (BSP_IRQ_ID_NUM)
#else
#define VECTOR_TABLE_LENGTH (64) // based on ARM Cortex M7
#endif

  /**
    \brief Exception / Interrupt Handler Function Prototype
  */
  typedef void (*VECTOR_TABLE_Type)(void);

  /**
    \brief System Clock Frequency (Core Clock)
  */
  extern uint32_t SystemCoreClock;

  /**
    \brief Setup the microcontroller system.

     Initialize the System and update the SystemCoreClock variable.
   */
  
    #ifdef __INITIAL_SP
        #undef __INITIAL_SP
        #define __INITIAL_SP              Image$$ARM_LIB_STACKHEAP$$ZI$$Limit
    #endif

    #ifdef __STACK_LIMIT
        #undef __STACK_LIMIT
        #define __STACK_LIMIT             Image$$ARM_LIB_STACKHEAP$$ZI$$Base
    #endif
  extern void SystemInit(void);
#ifndef __PROGRAM_START
#define __PROGRAM_START __main
#endif

#ifndef __INITIAL_SP
#define __INITIAL_SP Image$$ARM_LIB_STACK$$ZI$$Limit
#endif

#ifndef __STACK_LIMIT
#define __STACK_LIMIT Image$$ARM_LIB_STACK$$ZI$$Base
#endif

#ifndef __VECTOR_TABLE
#define __VECTOR_TABLE __Vectors
#endif

#ifndef __VECTOR_TABLE_ATTRIBUTE
#define __VECTOR_TABLE_ATTRIBUTE __attribute__((used, section("RESET")))
#endif

  /**
    \brief  Update SystemCoreClock variable.

     Updates the SystemCoreClock with current core Clock retrieved from cpu registers.
   */
  extern void SystemCoreClockUpdate(void);

#ifdef __cplusplus
}
#endif

#endif // VECTORS_AC6_H
