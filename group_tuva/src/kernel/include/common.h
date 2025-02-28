// common.h -- Defines typedefs and some global functions.
//             From JamesM's kernel development tutorials.

#ifndef COMMON_H
#define COMMON_H

// Some nice typedefs, to standardise sizes across platforms.
// These typedefs are written for 32-bit X86.
typedef unsigned int   u32int;
typedef          int   s32int;
typedef unsigned short u16int;
typedef          short s16int;
typedef unsigned char  u8int;
typedef          char  s8int;

#ifdef __cplusplus
extern "C" {
#endif

// Declares the init_descriptor_tables function, which
// initializes the GDT.
void outb(u16int port, u8int value);
u8int inb(u16int port);
u16int inw(u16int port);
// End of the extern C declaration
#ifdef __cplusplus
}
#endif


#endif // COMMON_H