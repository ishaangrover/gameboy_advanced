//////ISHAAN GROVER



typedef unsigned short u16;
typedef unsigned int u32;


#define REG_DISPCTL *(u16 *)0x4000000
#define MODE3 (3)
#define BG2_ENABLE (1<<10)
#define RGB(r, g, b) ((r) | (g)<<5 | (b)<<10)
#define WHITE RGB(31,31,31)




#define RED RGB(31,0,0)
#define ORANGE RGB(31,20,0)
#define GREEN RGB(12,25,21)
#define OGREEN RGB(19, 6, 10)
#define BLUE RGB(0,0,31)
#define CYAN RGB(0, 31,31)
#define MAGENTA RGB(31,0,31)
#define YELLOW RGB(31, 31, 0)
#define BLACK 0
#define PINK RGB(31, 19, 20)
#define PURPLE RGB(0, 12, 11)

//==============================INPUT BUTTONS====================================
#define BUTTON_A            (1<<0)
#define BUTTON_B            (1<<1)
#define BUTTON_SELECT       (1<<2)
#define BUTTON_START        (1<<3)
#define BUTTON_RIGHT        (1<<4)
#define BUTTON_LEFT         (1<<5)
#define BUTTON_UP           (1<<6)
#define BUTTON_DOWN         (1<<7)
#define BUTTON_R            (1<<8)
#define BUTTON_L            (1<<9)
#define KEY_DOWN_NOW(key)   (~(BUTTONS) & key)
#define BUTTONS *(volatile unsigned int *)0x4000130


#define SCANLINECOUNTER *(volatile u16 *)0x4000006
#define OFFSET(r,c,numcols) ((r)*(numcols)+(c))

typedef struct
{
	int x;
	int y;
	int oldx;
	int oldy;
	int direction; //1 if going down, 0 if going up, 2 if going towards the right 3 if going left
} Enemy;


typedef struct 
{
	int x; 
	int y;
	int oldx;
	int oldy;
}Player;


typedef struct
{								
	 const volatile void *src;	
	 volatile void *dst;		
	 volatile u32 cnt;		
							
} DMAREC;

#define DMA ((volatile DMAREC *)0x040000B0)

#define DMA_DESTINATION_INCREMENT (0 << 21)
#define DMA_DESTINATION_DECREMENT (1 << 21)
#define DMA_DESTINATION_FIXED (2 << 21)
#define DMA_DESTINATION_RESET (3 << 21)

#define DMA_SOURCE_INCREMENT (0 << 23)
#define DMA_SOURCE_DECREMENT (1 << 23)
#define DMA_SOURCE_FIXED (2 << 23)

#define DMA_REPEAT (1 << 25)

#define DMA_16 (0 << 26)
#define DMA_32 (1 << 26)

#define DMA_NOW (0 << 28)
#define DMA_AT_VBLANK (1 << 28)
#define DMA_AT_HBLANK (2 << 28)
#define DMA_AT_REFRESH (3 << 28)

#define DMA_IRQ (1 << 30)
#define DMA_ON (1 << 31)

#define START_ON_FIFO_EMPTY 0x30000000


void setPixel(int x, int y, u16 color);
void drawRect(int x, int y, int width, int height, u16 color);
void drawHollowRect(int x, int y, int width, int height, u16 color);
void drawCharacter(int x, int y, unsigned char ch, u16 color);
void drawString(int x, int y, char *str, u16 color);
void drawImage3(int x, int y, int width, int height, const u16 *image);
void waitForVblank();


extern u16 *videoBuffer;
extern const unsigned char fontdata_6x8[12288];

