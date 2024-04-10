/* FILE NAME: register.h
 * Description: This header file contains the declarations of global variables representing registers.
 * These registers are used for various purposes such as storing return values, temporary data,
 * or saved values during program execution.
 */

#ifndef GLOBAL_REGISTER_H
#define GLOBAL_REGISTER_H

#define MAX_ROWS 1000
#define MAX_COLS 100


/*global variable for registers 
    * Each element of the array represents a specific register
    * 0 is zero
    * 1 is v0 (return value)
    * 2~11 is t0~t9 (temporary value)
    * 12~19 is s0~s7 (saved value)
*/
extern int register_num[20];

#endif