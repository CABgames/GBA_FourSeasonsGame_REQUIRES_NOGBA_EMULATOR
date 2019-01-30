////////////////////////////////////////////////////////////
// File: PlayerSprite1.c
// Author: Charlie Bullock
// Date Created: 14/11/2018
// Brief: Player sprites
////////////////////////////////////////////////////////////

//======================================================================
//
//	PlayerSprite1, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2018-11-29, 08:13:29
//	Exported 0y Cearn's G0A Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned short PlayerSprite1Tiles[768] __attribute__((aligned(4)))=
{
	//Player 6 0
	0x0000,0x0000,0x0000,0x9000,0x0000,0x9990,0x0000,0x9CEE,
	0x0000,0xEE9E,0x08A0,0x9909,0x08A0,0x00C0,0x7400,0x80C0,
	0x0000,0x0000,0x0003,0x0000,0x0303,0x0000,0x3000,0x0000,
	0x0E9E,0x0000,0xE0E9,0x0000,0x0C00,0x0000,0x0C08,0x0077,
	0x9700,0x0A00,0x7000,0x0004,0x0000,0x9440,0x0000,0xC400,
	0x0000,0x9700,0x0000,0x7400,0x0000,0x0470,0x0000,0x0C40,
	0x00A0,0x0074,0x4000,0x0007,0x0449,0x0000,0x004C,0x0000,
	0x0094,0x0000,0x0047,0x0000,0x0740,0x0000,0x04C0,0x0000,
	//Player 2 64
	0x0000,0x0000,0x0000,0x9000,0x0000,0x9990,0x0000,0x9CEE,
	0x0000,0xEE9E,0x0000,0x9909,0x0000,0x00C0,0x0000,0x80C0,
	0x0000,0x0000,0x0003,0x0000,0x0303,0x0000,0x3000,0x0000,
	0x0E9E,0x0000,0xE0E9,0x0000,0x0C00,0x0000,0x0C08,0x0000,
	0xE000,0x8A00,0xCE00,0x0009,0x4000,0x9447,0x8A00,0xC40A,
	0x8A00,0x970C,0x0000,0x0700,0x0000,0x0400,0x0000,0x0000,
	0x00A8,0x0000,0xE000,0x0000,0x4449,0x0007,0x004C,0x000A,
	0x0097,0x0000,0x0044,0x0000,0x00C4,0x0000,0x0047,0x0000,
	//Player 3 128
	0x0000,0x0000,0x0000,0x9000,0x0000,0x9990,0x0000,0x9CEE,
	0x0000,0xEE9E,0x0880,0x9909,0x0AA0,0x00C0,0x0470,0x80C0,
	0x0000,0x0000,0x0003,0x0000,0x0303,0x0000,0x3000,0x0000,
	0x0E9E,0x0000,0xE0E9,0x0000,0x0C00,0x0000,0x0C08,0x0000,
	0x4700,0x8A00,0x7000,0x0007,0x0000,0x9440,0x0000,0xC400,
	0x0000,0x9700,0x0000,0x0700,0x0000,0x0400,0x0000,0x0000,
	0x00A8,0x0000,0xE000,0x0000,0x4449,0x0007,0x704C,0x0007,
	0x8807,0x0007,0x8804,0x0007,0x00C4,0x0000,0x0047,0x0000,
	//Player 4 192
	0x0000,0x0000,0x0000,0xD000,0x0000,0xDDD0,0x0000,0xDCFF,
	0x0000,0xFFDF,0x0000,0xDD0D,0x0000,0x00C0,0x0000,0x80C0,
	0x0000,0x0000,0x0003,0x0000,0x0303,0x0000,0x3000,0x0000,
	0x0FDF,0x0000,0xF0FD,0x0000,0x0C00,0x0000,0x0C08,0x0000,
	0xF000,0x8A00,0xCF00,0x000D,0x7000,0x9444,0x4700,0xC404,
	0x8800,0x970A,0x8800,0x070A,0x0000,0x0400,0x0000,0x0000,
	0x00A8,0x0000,0xF000,0x0000,0x4449,0x0007,0x704C,0x0007,
	0x8807,0x0007,0x8804,0x0007,0x00C4,0x0000,0x0047,0x0000,
	//Player 5 256
	0x0000,0x0000,0x0000,0xF000,0x0000,0xF030,0x0000,0x0003,
	0x0000,0x3333,0x0000,0xFF33,0x0000,0x00F0,0x0000,0x8000,
	0x0000,0x0000,0x000D,0x0000,0x0CDF,0x0000,0xFF00,0x0000,
	0x0DDF,0x0000,0xD000,0x0000,0x000C,0x0000,0x080C,0x0000,
	0x0000,0x0DCF,0x0000,0x0747,0x0000,0x0094,0x0000,0x0847,
	0x0000,0x08A0,0x0000,0x0000,0x0000,0xC400,0x0000,0x4400,
	0x0088,0x0000,0x0000,0x0000,0x0044,0x0000,0x00C4,0x0000,
	0x0049,0x0000,0x0074,0x0000,0x0007,0x0000,0x0004,0x0000,
	//Player 6 320
	0x0000,0x0000,0x0000,0x7000,0x0000,0x7160,0x0000,0x1557,
	0x0000,0x6557,0x0000,0x6676,0x0000,0x1176,0x0000,0xA160,
	0x0000,0x0000,0x000A,0x0000,0x0A1A,0x0000,0xAA71,0x0000,
	0xAA77,0x0000,0x1A17,0x0000,0x1AA1,0x0000,0x071A,0x0000,
	0x6700,0x6600,0x1000,0x0001,0x8000,0x8802,0x9000,0x5D09,
	0x0000,0x2800,0x0000,0x8000,0x0000,0xDD00,0x0000,0x2D00,
	0x6077,0x0001,0x5600,0x0017,0x8088,0x0002,0xC0D5,0x000C,
	0x9022,0x000C,0x0020,0x0000,0x00D0,0x0000,0x0000,0x0000,
	//Player 7 384
	0x0000,0x0000,0x0000,0xFD00,0x0000,0xFFDC,0xF000,0x000F,
	0x0000,0x3FDD,0xD000,0xF000,0x0000,0x0C00,0x1000,0x8C08,
	0x0000,0x0000,0x0000,0x0000,0x0030,0x0000,0x0300,0x0000,
	0x0333,0x0000,0x033F,0x0000,0x00F0,0x0000,0x0000,0x0000,
	0x0000,0x0881,0x0000,0x0000,0x0000,0x0440,0x0000,0x14C0,
	0x0000,0x0940,0x0000,0x14E0,0x0000,0xCE00,0x0000,0x4400,
	0x0FCD,0x0000,0x0E4E,0x0000,0x0490,0x0000,0x0E48,0x0000,
	0x0098,0x0000,0x0000,0x0000,0x0004,0x0000,0x0004,0x0000,
	//Player 8 448
	0x0000,0x0000,0x0000,0xC000,0x0000,0xCCC0,0x0000,0xCAEE,
	0x0000,0xEECE,0x0000,0xCC0C,0x0000,0x00A0,0x0000,0xF0A0,
	0x0000,0x0000,0x0003,0x0000,0x0303,0x0000,0x3000,0x0000,
	0x0ECE,0x0000,0xE0EC,0x0000,0x0A00,0x0000,0x0A0F,0x0000,
	0xE000,0xF900,0xAE00,0x000C,0x5000,0x052D,0xF900,0xA209,
	0xF900,0x0D0A,0x0000,0x0D00,0x0000,0x0200,0x0000,0x0000,
	0x009F,0x0000,0xE000,0x0000,0x5250,0x000D,0x002A,0x0009,
	0x000D,0x0000,0x0055,0x0000,0x00A2,0x0000,0x002D,0x0000,
	//Player 9 512
	0x0000,0x0000,0x0000,0x8000,0x0000,0x8170,0x0000,0x1668,
	0x0000,0x7668,0x0000,0x7787,0x0000,0x1187,0x0000,0xA170,
	0x0000,0x0000,0x000A,0x0000,0x0A1A,0x0000,0xAA81,0x0000,
	0xAA88,0x0000,0x1A18,0x0000,0x1AA1,0x0000,0x081A,0x0000,
	0x8000,0x7708,0x6800,0x0017,0x9000,0x990E,0x1000,0x6C01,
	0x1000,0x4407,0x0000,0x0400,0x0000,0x0C00,0x0000,0x0000,
	0x0088,0x0011,0x1000,0x0001,0x4099,0x0004,0x40C6,0x0007,
	0x0094,0x0000,0x0019,0x0000,0x00CC,0x0000,0x00C4,0x0000,
	//Player 10 576
	0x0000,0x0000,0x0000,0xE000,0x0000,0xE030,0x0000,0x0003,
	0x0000,0x3333,0x0000,0xEE33,0x0000,0x00E0,0x0000,0xF000,
	0x0000,0x0000,0x000C,0x0000,0x0ACE,0x0000,0xEE00,0x0000,
	0x0CCE,0x0000,0xC000,0x0000,0x000A,0x0000,0x0F0A,0x0000,
	0x0000,0x0CAE,0x0300,0x0D0D,0xD000,0x20D5,0x9000,0x5D05,
	0x9000,0x500F,0x0000,0x5DD0,0x2000,0x0052,0x0000,0x0002,
	0x00FF,0x0000,0x0000,0x0000,0xD055,0x0000,0x90A2,0x0000,
	0x0050,0x0000,0x02D5,0x0000,0x022D,0x0000,0x00D0,0x0000,
	//Player 11 640
	0x0000,0x0000,0x0000,0x0000,0x0000,0xD000,0x0000,0x88DD,
	0x0000,0xD008,0x0000,0x0080,0x0000,0xA008,0x0000,0xA0EF,
	0x0000,0x0000,0x000D,0x0000,0x038D,0x0000,0x3888,0x0000,
	0x3333,0x0000,0x33DD,0x0000,0x8D00,0x0000,0x000E,0x0000,
	0x0000,0xEEF0,0x0000,0x0000,0x0000,0x5509,0x0000,0x2A01,
	0x0000,0x750F,0x0000,0x5920,0x0000,0x9220,0x0000,0x0900,
	0xD00F,0x0008,0x9890,0x0000,0x5902,0x0009,0x5095,0x0001,
	0xE075,0x0001,0x0995,0x0000,0x2500,0x0002,0x2000,0x0000,
	//Player 12 704
	0x0000,0x0000,0x0000,0x7000,0x0000,0x7770,0x0000,0x7900,
	0x0000,0x0070,0x0000,0x7707,0x0000,0x0090,0x0000,0xD090,
	0x0000,0x0000,0x0003,0x0000,0x0383,0x0000,0x3888,0x0000,
	0x8070,0x0000,0x0007,0x0000,0x0900,0x0000,0x090D,0x0000,
	0x0000,0xD400,0x0000,0x0087,0x5000,0x1525,0xD000,0x9200,
	0x0000,0xA100,0x0000,0x5500,0x0000,0x2900,0x0000,0xA200,
	0x804D,0x0008,0x9800,0x0087,0xA251,0x0005,0x4029,0x004D,
	0x90A1,0x004D,0x0050,0x0000,0x0020,0x0000,0x0000,0x0000
};

const unsigned short PlayerSprite1Pal[16] __attribute__((aligned(4)))=
{
	//Player 1 0
	0x0000,0x0190,0x3DEF,0x00C8,0x189A,0x5AD6,0x35AD,0x104E,
	0x3ADC,0x2A9A,0x1998,0x0150,0x6B5A,0x2198,0x01DA,0x2529

};

const unsigned short PlayerSprite2Pal[16] __attribute__((aligned(4))) =
{
	//Player 2 16
	0x0000,0x0190,0x3DEF,0x00C8,0x189A,0x5AD6,0x35AD,0x104E,
	0x3ADC,0x2A9A,0x1998,0x0150,0x6B5A,0x2198,0x01DA,0x2529
};

const unsigned short PlayerSprite3Pal[16] __attribute__((aligned(4))) =
{
	//Player 3 32
	0x0000,0x0190,0x3DEF,0x00C8,0x189A,0x5AD6,0x35AD,0x104E,
	0x3ADC,0x2A9A,0x1998,0x0150,0x6B5A,0x2198,0x01DA,0x2529
};

const unsigned short PlayerSprite4Pal[16] __attribute__((aligned(4))) =
{
	//Player 4 48
	0x0000,0x0190,0x3DEF,0x00C8,0x189A,0x5AD6,0x35AD,0x104E,
	0x3ADC,0x2198,0x1998,0x0150,0x6B5A,0x2A9A,0x2529,0x01DA
};

const unsigned short PlayerSprite5Pal[16] __attribute__((aligned(4))) =
{
	//Player 5 64
	0x0000,0x0190,0x3DEF,0x00C8,0x189A,0x5AD6,0x35AD,0x104E,
	0x3ADC,0x2198,0x1998,0x0150,0x6B5A,0x2A9A,0x2529,0x01DA
};

const unsigned short PlayerSprite6Pal[16] __attribute__((aligned(4))) =
{
	//Player 6 80
	0x0000,0x0190,0x3DEF,0x00C8,0x189A,0x5AD6,0x35AD,0x104E,
	0x3ADC,0x2198,0x1998,0x0150,0x6B5A,0x2A9A,0x2529,0x01DA
};

const unsigned short PlayerSprite7Pal[16] __attribute__((aligned(4))) =
{
	//Player 7 96
	0x0000,0x0190,0x3DEF,0x00C8,0x189A,0x5AD6,0x35AD,0x2529,
	0x3ADC,0x1998,0x2198,0x0150,0x6B5A,0x2A9A,0x104E,0x01DA
};

const unsigned short PlayerSprite8Pal[16] __attribute__((aligned(4))) =
{
	//Player 8 112
	0x0000,0x0190,0x4A50,0x00C8,0x35AD,0x189A,0x5AD6,0x2198,
	0x2529,0x1998,0x6B5A,0x0150,0x2A9A,0x104E,0x01DA,0x3ADC
};

const unsigned short PlayerSprite9Pal[16] __attribute__((aligned(4))) =
{
	//Player 9 128
	0x0000,0x0190,0x4A50,0x00C8,0x35AD,0x189A,0x5AD6,0x2198,
	0x2529,0x1998,0x6B5A,0x2A9A,0x0150,0x104E,0x01DA,0x3ADC
};

const unsigned short PlayerSprite10Pal[16] __attribute__((aligned(4))) =
{
	//Player 10 144
	0x0000,0x0190,0x4A50,0x00C8,0x35AD,0x189A,0x5AD6,0x2198,
	0x2529,0x1998,0x6B5A,0x0150,0x2A9A,0x104E,0x01DA,0x3ADC
};

const unsigned short PlayerSprite11Pal[16] __attribute__((aligned(4))) =
{
	//Player 11 160
	0x0000,0x1998,0x4A50,0x00C8,0x35AD,0x189A,0x5AD6,0x299A,
	0x0150,0x104E,0x6B5A,0x2A9A,0x2529,0x01DA,0x3ADC,0x10D0
};

const unsigned short PlayerSprite12Pal[16] __attribute__((aligned(4))) =
{
	//Player 12 176
	0x0000,0x35AD,0x4A50,0x00C8,0x1998,0x189A,0x5AD6,0x2A9A,
	0x0150,0x6B5A,0x104E,0x01DA,0x2529,0x3ADC,0x3DEF,0x739C
};