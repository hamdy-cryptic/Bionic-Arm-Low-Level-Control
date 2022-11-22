/*********************************************************/
/*Author     : youstina                                  */
/*version    : v01                                       */
/*date       : 10 DEC 2020                               */
/*********************************************************/
#ifndef SYSCFG_PRIVATE_H
#define SYSCFG_PRIVATE_H


typedef struct{
	volatile u32 MEMRMP;
	volatile u32 PMC;
	volatile u32 EXTICR[4];
	volatile u32 CMPCR;
	volatile u32 CFGR;
	
}SYSCFG_t;


#define SYSCFG ((volatile SYSCFG_t *) 0x40013800 )


/*base address 0x40013800 */


#endif