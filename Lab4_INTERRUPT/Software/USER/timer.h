// 定时器基地址
#define TIMER_BASE              0x53000000

// 定时器寄存器地址定义
#define TIMER_LOAD_REG          *((volatile unsigned int*)(TIMER_BASE + 0x00))  // Load value register
#define TIMER_CURRENT_REG       *((volatile unsigned int*)(TIMER_BASE + 0x04))  // Current value register
#define TIMER_CONTROL_REG       *((volatile unsigned int*)(TIMER_BASE + 0x08))  // Control value register
#define TIMER_CLEAR_REG         *((volatile unsigned int*)(TIMER_BASE + 0x0C))  // Clear interrupt register

// 定时器控制位定义
#define TIMER_ENABLE_BIT        (1 << 0)  // Timer enable bit
#define TIMER_MODE_RELOAD_BIT   (1 << 1)  // Timer reload mode bit
#define TIMER_PRESCALE_BIT      (1 << 2)  // Timer prescale enable bit

extern void Timer_SetLoad(unsigned int value);
extern unsigned int Timer_GetCurrent(void);
extern void Timer_Enable(int enable);
extern void Timer_SetMode(int mode);
extern void Timer_ClearInterrupt(void);
