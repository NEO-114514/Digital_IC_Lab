#include <lib.h>

//int main()
//{
//    volatile int i;

//    LED_REG = 0;
//    MASK_REG = 0x00;
//    while (1)
//    {
//        LED_REG=0x55;
//        for ( i = 0; i < 0x2F; i++);
//        LED_REG=0xAA;
//        for ( i = 0; i < 0x2F; i++); 
//    }
//    
//}

int main()
{

    LED_REG = 0;
    MASK_REG = 0xF0;
    while (1)
    {
			if(KEY_REG==0x01)
        LED_REG=0x55;
			if(KEY_REG==0x00)
        LED_REG=0xAA; 
    }
    
}

