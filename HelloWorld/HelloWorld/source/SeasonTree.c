////////////////////////////////////////////////////////////
// File: SeasonTree.c
// Author: Charlie Bullock
// Date Created: 14/11/2018
// Brief: Season tree sprites
////////////////////////////////////////////////////////////

//======================================================================
//
//	SeasonTree, 32x32@4, 
//	+ palette 16 entries, not compressed
//	+ 16 tiles not compressed
//	Total size: 32 + 512 = 544
//
//	Time-stamp: 2018-12-04, 15:50:34
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

//Autumn season tree sprite tile data
const unsigned short SeasonTreeTiles[256] __attribute__((aligned(4)))=
{
	0x0000,0x0000,0x0000,0xBB00,0xB000,0xBBBB,0xBB00,0xBBBB,
	0xBBB0,0xBBBB,0xBBB0,0xBBBB,0xBBB0,0xBBBB,0xBBB0,0xBBBB,
	0x0B00,0xBBBB,0xBBBB,0xBBBB,0xBBBB,0xBBBB,0xBBBB,0xBBBB,
	0xBBBB,0xBBBB,0xBBBB,0xBBBB,0xBBBB,0xBBBB,0xBBBB,0xBBBB,
	0x000B,0x0B00,0xBBBB,0xBBBB,0xBBBB,0xBBBB,0xBBBB,0xBBBB,
	0xBBBB,0xBBBB,0xBBBB,0xBBBB,0xBBBB,0xBBBB,0xBBBB,0xBBBB,
	0x0000,0x0000,0x00BB,0x0000,0xBBBB,0x0000,0xBBBB,0x00BB,
	0xBBBB,0x0BBB,0xBBBB,0x0BBB,0xBBBB,0x0BBB,0xBBBB,0x0BBB,

	0xBBBB,0xBBBB,0xBBB0,0xBBBB,0xBB00,0xBBBB,0xB000,0xBBBB,
	0x0000,0xBBBB,0x0000,0xBBB0,0x0000,0x0000,0x0000,0x0000,
	0xBBBB,0xBBBB,0xBBBB,0xBBBB,0xBBBB,0xBBBB,0xBBBB,0xBBBB,
	0xBBBB,0xBBBB,0xBBBB,0xBBBB,0x4444,0x4444,0xCCA4,0xACA9,
	0xBBBB,0xBBBB,0xBBBB,0xBBBB,0xBBBB,0xBBBB,0xBBBB,0xBBBB,
	0xBBBB,0xBBBB,0xBBBB,0xBBBB,0x4444,0x4444,0x9C9A,0x4ACC,
	0xBBBB,0x0BBB,0xBBBB,0x00BB,0xBBBB,0x000B,0xBBBB,0x0000,
	0x0BBB,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x4000,0x0000,0x4400,
	0x0000,0xCA40,0x4000,0x9944,0xC400,0xC99C,0xC400,0xA9CC,
	0x49A4,0xC666,0x69C4,0xC2E6,0x99CC,0xCA99,0x999A,0xCC49,
	0x9999,0x6CCC,0xC999,0x6644,0x9C9A,0xAC6C,0x9C9C,0xA4AA,
	0xC66C,0x44A9,0x6E2C,0x4C96,0x999C,0x4CC9,0x99CC,0xAAC9,
	0x94C6,0x9999,0xA466,0xCC99,0x96CC,0xCC99,0xCCC4,0xA99C,
	0x0000,0x0000,0x0000,0x0000,0x0044,0x0000,0x04C4,0x0000,
	0x004A,0x0000,0x44CA,0x0000,0x9999,0x0004,0xAC4A,0x0044,

	0x4000,0xC44A,0x0000,0x9404,0x0000,0xCA40,0x0000,0x9C40,
	0x0000,0x4400,0x0000,0x0400,0x0000,0x0000,0x0000,0x0000,
	0xCC99,0xA4AC,0xCACC,0x4444,0x44AC,0x3686,0x04AA,0x8636,
	0x0044,0x3686,0x0000,0x6860,0x0000,0x6600,0x0000,0x0000,
	0xCAA4,0x99CC,0x4444,0x99C4,0x6868,0xCA40,0x6363,0xCA40,
	0x6836,0x4400,0x0683,0x0000,0x0066,0x0000,0x0000,0x0000,
	0x4404,0x0000,0x004C,0x0000,0x0004,0x0000,0x0049,0x0000,
	0x004A,0x0000,0x0004,0x0000,0x0000,0x0000,0x0000,0x0000,
};
//Autumn season tree sprite palette data
const unsigned short SeasonTreePal[16] __attribute__((aligned(4)))=
{
	0x0000,0x318C,0x7FFF,0x036D,0x01A1,0x5E8B,0x0435,0x03F5,
	0x0241,0x32D9,0x2993,0x0D3B,0x2E37,0x02FF,0x6146,0x0432,
};
//Spring season tree sprite tile data
const unsigned short SeasonTreeSpringTiles[256] __attribute__((aligned(4))) =
{
	0x0000,0x0000,0x0000,0x3300,0x0000,0x3333,0x3300,0xDD33,
	0x3330,0x7DDD,0xD330,0x777D,0xDD30,0x7777,0xDD30,0x7777,
	0x0000,0x0000,0x3333,0x3333,0xDDD3,0xDDDD,0x77DD,0x7777,
	0x7777,0x7777,0x7777,0x7777,0x7777,0x7777,0x7777,0x7777,
	0x0000,0x0000,0x3333,0x3333,0x33DD,0x3333,0x7777,0xDDD7,
	0x7777,0x7777,0x7777,0x7777,0x7777,0x7777,0x7777,0x7777,
	0x0000,0x0000,0x0033,0x0000,0x3333,0x0000,0x33DD,0x0033,
	0x3DDD,0x0333,0xDDD7,0x0333,0xDD77,0x033D,0xDD77,0x033D,

	0xD333,0x777D,0x3330,0x77DD,0x3300,0xDDDD,0x3000,0xDDD3,
	0x0000,0x3333,0x0000,0x3333,0x0000,0x0000,0x0000,0x0000,
	0x7777,0x7777,0x7777,0x7777,0x777D,0x7777,0xDDDD,0xDDDD,
	0x3333,0x3333,0x3333,0x3333,0xFFFF,0xFFFF,0x44AF,0xA4A9,
	0x7777,0x7777,0x7777,0x7777,0x7777,0xDD77,0xDDDD,0xDDDD,
	0xDD33,0x33DD,0x3333,0x3333,0xFFFF,0xFFFF,0x949A,0xFA44,
	0xDD77,0x0333,0xDDDD,0x0033,0x33DD,0x0033,0x3333,0x0000,
	0x0333,0x0000,0x0033,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0xF000,0x0000,0xFF00,
	0x0000,0x4AF0,0xF000,0x99FF,0x4F00,0x4994,0x4F00,0xA944,
	0xF9AF,0x4555,0x594F,0x4B25,0x9944,0x4A99,0x999A,0x44F9,
	0x9999,0x5444,0x4999,0x55FF,0x949A,0xA454,0x9494,0xAFAA,
	0x4554,0xFFA9,0x52B4,0xF495,0x9994,0xF449,0x9944,0xAA49,
	0x9F45,0x9999,0xAF55,0x4499,0x9544,0x4499,0x444F,0xA994,
	0x0000,0x0000,0x0000,0x0000,0x00FF,0x0000,0x0F4F,0x0000,
	0x00FA,0x0000,0xFF4A,0x0000,0x9999,0x000F,0xA4FA,0x00FF,

	0xFF00,0x4FFA,0x0000,0x9F0F,0x0000,0x4AF0,0x0000,0x94F0,
	0x0000,0xFF00,0x0000,0x0F00,0x0000,0x0000,0x0000,0x0000,
	0x4499,0xAFA4,0x4A44,0xFFFF,0xFFA4,0x6C0C,0x0FAA,0x0C6C,
	0x00FF,0x650C,0x0000,0x50C0,0x0000,0xCC00,0x0000,0x0000,
	0x4AAF,0x9944,0xFFFF,0x994F,0xC0C0,0x4AF0,0xC6C6,0x4AF0,
	0xC065,0xFF00,0x0C06,0xA000,0x00CC,0x0000,0x0000,0x0000,
	0xFF0F,0x000A,0x00F4,0x0000,0x004F,0x0000,0x00F9,0x0000,
	0x00FA,0x0000,0x00AF,0x0000,0x0000,0x0000,0x0000,0x0000,
};
//Spring season tree sprite palette data
const unsigned short SeasonTreeSpringPal[16] __attribute__((aligned(4))) =
{
	0x0000,0x01A1,0x6146,0x036D,0x2E37,0x0435,0x2807,0x03F5,
	0x0241,0x32D9,0x2993,0x7FFF,0x294A,0x03F0,0x02C2,0x250E,
};
//Winter season tree sprite tile data
const unsigned short SeasonTreeColdTiles[256] __attribute__((aligned(4))) =
{
	0x0000,0x0000,0x0000,0x2200,0x2000,0x2222,0x2200,0x2222,
	0x2220,0x2222,0x2220,0x2222,0x2220,0x2222,0x2220,0x2222,
	0x0200,0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,
	0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,
	0x0002,0x0200,0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,
	0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,
	0x0000,0x0000,0x0022,0x0000,0x2222,0x0000,0x2222,0x0022,
	0x2222,0x0222,0x2222,0x0222,0x2222,0x0222,0x2222,0x0222,

	0x2222,0x2222,0x2220,0x2222,0x22B0,0x2222,0x2B00,0x2222,
	0x0000,0x2222,0x0000,0x2220,0x0000,0x00B0,0x0000,0x0000,
	0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,
	0x2222,0x2222,0x2222,0x2222,0x1111,0x1111,0x55E1,0xE5ED,
	0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,0x2222,
	0x2222,0x2222,0x2222,0x2222,0x1111,0x1111,0xD5DE,0x1E55,
	0x2222,0x0222,0x2222,0x0022,0x2222,0x0002,0x2222,0x0000,
	0x0222,0x0000,0x0B00,0x0000,0x0B00,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x1000,0x0000,0x1100,
	0x0000,0x5E10,0x1000,0xDD11,0x5100,0x5DD5,0x5100,0xED55,
	0x1DE1,0x5888,0x8D51,0x5278,0xDD55,0x5EDD,0xDDDE,0x551D,
	0xDDDD,0x8555,0x5DDD,0x8811,0xD5DE,0xE585,0xD5D5,0xE1EE,
	0x5885,0x11ED,0x8725,0x15D8,0xDDD5,0x155D,0xDD55,0xEE5D,
	0xD158,0xDDDD,0xE188,0x55DD,0xD855,0x55DD,0x5551,0xEDD5,
	0x0000,0x0000,0x0000,0x0000,0x0011,0x0000,0x0151,0x0000,
	0x001E,0x0000,0x115E,0x0000,0xDDDD,0x0001,0xE51E,0x0011,

	0x1000,0x511E,0x0000,0xD101,0x0000,0x5E10,0x0000,0xD510,
	0x0000,0x1100,0x0000,0x0100,0x0000,0x0000,0x0000,0x0000,
	0x55DD,0xE1E5,0x5E55,0x1111,0x11E5,0x9F3F,0x01EE,0x3F9F,
	0x0011,0x983F,0x0000,0x83F0,0x0000,0xFF00,0x0000,0x0000,
	0x5EE1,0xDD55,0x1111,0xDD51,0xF3F3,0x5E10,0xF9F9,0x5E10,
	0xF398,0x1100,0x0F39,0x0000,0x00FF,0x0000,0x0000,0x0000,
	0x1101,0x0000,0x0015,0x0000,0x0001,0x0000,0x001D,0x0000,
	0x001E,0x0000,0x0001,0x0000,0x0000,0x0000,0x0000,0x0000,
};
//Winter season tree sprite palette data
const unsigned short SeasonTreeColdPal[16] __attribute__((aligned(4))) =
{
	0x0000,0x250E,0x7FFF,0x036D,0x01A1,0x2E37,0x0D3B,0x6146,
	0x0435,0x2807,0x03F5,0x5E8B,0x0241,0x32D9,0x2993,0x294A,
};
//Summer season tree sprite tile data
const unsigned short SeasonTreeSummerTiles[256] __attribute__((aligned(4))) =
{
	0x0000,0x0000,0x0000,0x4400,0x0000,0x4444,0x4400,0xAAA4,
	0x4440,0xAAAA,0x4440,0xAAAA,0xA440,0xAAAA,0xA440,0xAAAA,
	0x0000,0x0000,0x4444,0x4444,0xAA44,0x4AAA,0xAAAA,0xAAAA,
	0xAAAA,0xAAAA,0xAAAA,0xAAAA,0xAAAA,0xAAAA,0xAAAA,0xAAAA,
	0x0000,0x0000,0x4444,0x4444,0xAA44,0x444A,0xAAAA,0xAAAA,
	0xAAAA,0xAAAA,0xAAAA,0xAAAA,0xAAAA,0xAAAA,0xAAAA,0xAAAA,
	0x0000,0x0000,0x0044,0x0000,0x4444,0x0000,0x44AA,0x0044,
	0xAAAA,0x0444,0xAAAA,0x0444,0xAAAA,0x044A,0xAAAA,0x044A,

	0xA444,0xAAAA,0x444A,0xAAAA,0x4400,0xAAAA,0x4000,0xAAA4,
	0x0000,0x4444,0x0000,0x4444,0x0000,0xAAAA,0x0000,0x000A,
	0xAAAA,0xAAAA,0xAAAA,0xAAAA,0xAAAA,0xAAAA,0xAAAA,0xAAAA,
	0x4444,0x4444,0x4444,0x4444,0x1111,0x1111,0xDDC1,0xCDCB,
	0xAAAA,0xAAAA,0xAAAA,0xAAAA,0xAAAA,0xAAAA,0xAAAA,0xAAAA,
	0x44AA,0x4444,0x4444,0x4444,0x1111,0x1111,0xBDBC,0x1CDD,
	0xAAAA,0x044A,0xAAAA,0x0044,0x4AAA,0x0044,0x4444,0x0000,
	0x0444,0x0000,0x0044,0x0000,0x000A,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x1000,0x0000,0x1100,
	0x0000,0xDC10,0x1000,0xBB11,0xD100,0xDBBD,0xD100,0xCBDD,
	0x1BC1,0xD777,0x7BD1,0xD267,0xBBDD,0xDCBB,0xBBBC,0xDD1B,
	0xBBBB,0x7DDD,0xDBBB,0x7711,0xBDBC,0xCD7D,0xBDBD,0xC1CC,
	0xD77D,0x11CB,0x762D,0x1DB7,0xBBBD,0x1DDB,0xBBDD,0xCCDB,
	0xB1D7,0xBBBB,0xC177,0xDDBB,0xB7DD,0xDDBB,0xDDD1,0xCBBD,
	0x0000,0x0000,0x0000,0x0000,0x0011,0x0000,0x01D1,0x0000,
	0x001C,0x0000,0x11DC,0x0000,0xBBBB,0x0001,0xCD1C,0x0011,

	0x1100,0xD11C,0x0000,0xB101,0x0000,0xDC10,0x0000,0xBD10,
	0x0000,0x1100,0x0000,0x0100,0x0000,0x0000,0x0000,0x0000,
	0xDDBB,0xC1CD,0xDCDD,0x1111,0x11CD,0x8F1F,0x01CC,0x1F8F,
	0x0011,0x871F,0x0000,0x71F0,0x0000,0xFF00,0x0000,0x0000,
	0xDCC1,0xBBDD,0x1111,0xBBD1,0xF1F1,0xDC10,0xF8F8,0xDC10,
	0xF187,0x1100,0x0F18,0xC000,0x00FF,0x0000,0x0000,0x0000,
	0x1101,0x000C,0x001D,0x0000,0x00D1,0x0000,0x001B,0x0000,
	0x001C,0x0000,0x00C1,0x0000,0x0000,0x0000,0x0000,0x0000,
};
//Summer season tree sprite palette data
const unsigned short SeasonTreeSummerPal[16] __attribute__((aligned(4))) =
{
	0x0000,0x250E,0x7FFF,0x036D,0x01A1,0x5E8B,0x6146,0x0435,
	0x2807,0x03F5,0x0241,0x32D9,0x2993,0x2E37,0x03F0,0x294A,
};