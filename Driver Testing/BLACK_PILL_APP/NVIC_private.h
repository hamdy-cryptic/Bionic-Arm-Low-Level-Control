/**********************************************************/
/*Author    : youstina                                    */
/*version   : v01                                         */
/*date      : 8 DEC 2020                                  */
/**********************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H


#define NVIC_ISER0     *((u32*)(0xE000E100))     /* enable external interrupts from 0 to 31   */
#define NVIC_ISER1     *((u32*)(0xE000E104))     /* enable external interrupts from 32 to 63  */
#define NVIC_ISER2     *((u32*)(0xE000E108))     /* enable external interrupts from 64 to 95  */
#define NVIC_ISER3     *((u32*)(0xE000E10C))     /* enable external interrupts from 96 to 127 */

#define NVIC_ICER0     *((u32*)(0xE000E180))     /* disable external interrupts from 0 to 31   */
#define NVIC_ICER1     *((u32*)(0xE000E184))     /* disable external interrupts from 32 to 63  */
#define NVIC_ICER2     *((u32*)(0xE000E188))     /* disable external interrupts from 64 to 95  */
#define NVIC_ICER3     *((u32*)(0xE000E18C))     /* disable external interrupts from 96 to 127 */

#define NVIC_ISPR0     *((u32*)(0xE000E200))     /* set pending flags from 0 to 31    */ 
#define NVIC_ISPR1     *((u32*)(0xE000E204))     /* set pending flags from 32 to 63   */ 
#define NVIC_ISPR2     *((u32*)(0xE000E208))     /* set pending flags from 64 to 95   */
#define NVIC_ISPR3     *((u32*)(0xE000E20C))     /* set pending flags from 96 to 127  */ 
																			 
#define NVIC_ICPR0     *((u32*)(0xE000E280))     /* clear pending flags from 0 to 31     */ 
#define NVIC_ICPR1     *((u32*)(0xE000E284))     /* clear pending flags from 32 to 63    */
#define NVIC_ICPR2     *((u32*)(0xE000E288))     /* clear pending flags from 64 to 95    */
#define NVIC_ICPR3     *((u32*)(0xE000E28C))     /* clear pending flags from 96 to 127   */

#define NVIC_IABR0     *((volatile u32*)(0xE000E300))     /* read active bit from 0 to 31     */
#define NVIC_IABR1     *((volatile u32*)(0xE000E304))     /* read active bit from 32 to 63    */
#define NVIC_IABR2     *((volatile u32*)(0xE000E308))     /* read active bit from 64 to 95    */
#define NVIC_IABR3     *((volatile u32*)(0xE000E30C))     /* read active bit from 64 to 127   */

#define NVIC_IPR        ((volatile u8*)(0xE000E400))
#define SCB_AIRCR      *((volatile u32*)(0xE000ED0C))




#endif