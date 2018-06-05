/*
 * GeekOS C code entry point
 * Copyright (c) 2001,2003,2004 David H. Hovemeyer <daveho@cs.umd.edu>
 * Copyright (c) 2003, Jeffrey K. Hollingsworth <hollings@cs.umd.edu>
 * Copyright (c) 2004, Iulian Neamtiu <neamtiu@cs.umd.edu>
 * $Revision: 1.51 $
 * 
 * This is free software.  You are permitted to use,
 * redistribute, and modify it as specified in the file "COPYING".
 */

#include <geekos/bootinfo.h>
#include <geekos/string.h>
#include <geekos/screen.h>
#include <geekos/mem.h>
#include <geekos/crc32.h>
#include <geekos/tss.h>
#include <geekos/int.h>
#include <geekos/kthread.h>
#include <geekos/trap.h>
#include <geekos/timer.h>
#include <geekos/keyboard.h>


/*
 * My thread statement
 */
void keyBoard(ulong_t arg);


/*
 * Kernel C code entry point.
 * Initializes kernel subsystems, mounts filesystems,
 * and spawns init process.
 */
void Main(struct Boot_Info* bootInfo)
{
    Init_BSS();
    Init_Screen();
    Init_Mem(bootInfo);
    Init_CRC32();
    Init_TSS();
    Init_Interrupts();
    Init_Scheduler();
    Init_Traps();
    Init_Timer();
    Init_Keyboard();


    Set_Current_Attr(ATTRIB(BLACK, GREEN|BRIGHT));
    Print("Welcome to GeekOS!\n");
    Set_Current_Attr(ATTRIB(BLACK, GRAY));


    /*TODO("Start a kernel thread to echo pressed keys and print counts");*/
    Start_Kernel_Thread(keyBoard, 157, PRIORITY_NORMAL, false);



    /* Now this thread is done. */
    Exit(0);
}




/*
 * My thread implemention
 */
void keyBoard(ulong_t atg){
    Keycode key;
    Print("keyboard test\n");
    while(1)
    {         
        if( Read_Key(&key) )       
        {              
            if(!( (key & KEY_SPECIAL_FLAG) || (key & KEY_RELEASE_FLAG)) ) 
            {
                int asciiCode = key &  0xff;
                if (asciiCode == '\r')
                {
                    Print("\n");
                }
                else
                {
                    Print("%c", asciiCode);
                }
            }         
        }    
    }

}
