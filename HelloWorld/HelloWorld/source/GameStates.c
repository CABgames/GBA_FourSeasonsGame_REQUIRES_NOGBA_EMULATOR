////////////////////////////////////////////////////////////
// File: GameStates.c
// Author: Charlie Bullock using help from provided tutorials and exaple projects
// Date Created: 14/11/2018
// Brief: This is the most critical file in the solution responsible for the different game states and functionality of the project
////////////////////////////////////////////////////////////

//Including:
#include "GameStates.h"
#include "string.h"
s8 gamestate;

//Method responsible for short startup intro, in this method images are switched between into two images in order to show
void Intro()
{
	//Setting gba to rendering mode 4
	REG_DISPLAYCONTROL = VIDEOMODE_4 | BGMODE_2;

	//Copying the Second intro bitmap image into the front page memory
	memcpy(vid_page_front, Intro2Bitmap, Intro2BitmapLen);
	memcpy(pal_bg_mem, Intro2Pal, Intro2PalLen);
	//Copying the third intro bitmap image into the front page memory
	memcpy(vid_page_back, Intro3Bitmap, Intro3BitmapLen);

	//Starting frame and ii both 0
	u32 frame = 0;
	u8 ii = 0;

	//While in this loop frames are progressed through until ii is 10 and then will go to MainMenu method
	while (1) { 
		vsync();
		if (frame == 4)
		{
			page_flip();
			memcpy(vid_page_front, Intro3Bitmap, Intro3BitmapLen);
			memcpy(pal_bg_mem, Intro3Pal, Intro3PalLen);
		}
		else if (frame == 8)
		{
			page_flip();
			memcpy(vid_page_back, Intro4Bitmap, Intro4BitmapLen);
			memcpy(pal_bg_mem, Intro4Pal, Intro4PalLen);
		}
		else if (frame == 12)
		{
			page_flip();
			memcpy(vid_page_front, Intro5Bitmap, Intro5BitmapLen);
			memcpy(pal_bg_mem, Intro5Pal, Intro5PalLen);
		}
		else if (frame == 16)
		{
			page_flip();
			memcpy(vid_page_back, Intro1Bitmap, Intro1BitmapLen);
			memcpy(pal_bg_mem, Intro1Pal, Intro1PalLen);
			frame = 0;
			++ii;
		}

		++frame;
		if (ii == 10)
		{
			MainMenu();
		}
	}

}

u16* vid_page = vid_page_back;

//This is the method responsible for main menu and is reached after the intro has completed, this simply displays a bitrmap image and checks for input
void MainMenu() 
{
	//Setting gba to rendering mode 4
	REG_DISPLAYCONTROL = VIDEOMODE_4 | BGMODE_2;
	memcpy(vid_page_front, MainMenuBitmap, MainMenuBitmapLen);
	memcpy(pal_bg_mem, MainMenuPal, MainMenuPalLen);
	//Keep looping through checking for when the player presses start
	while (1)
	{
		PollKeys();
		//Start to open/Close menu
		if (input_keyDown(START)) {
			Game();
		}
	}
}
//This is the method responsible for the pause state of the game which is reached inbetween returning the menu from the main game function, this simply displays a bitrmap image and checks for input
void Pause() 
{
	//set GBA rendering to MODE 3 Bitmap rendering
	REG_DISPLAYCONTROL = VIDEOMODE_4 | BGMODE_2;
	s32 t = 0;

	memcpy(vid_page_front, PauseBitmap, PauseBitmapLen);
	memcpy(pal_bg_mem, PausePal, PausePalLen);

	while (1)
	{

		t++;
		if (t > 3)
		{
			t = 0;
		}

		PollKeys();
		//Start to open/Close menu
		if (input_keyReleased(SELECT)) 
		{
			if (t == 0)
			{ 
				MainMenu();
			}
		}
		if (input_keyReleased(START)) 
		{
			if (t == 0)
			{ 
				Game();
			}
		}
	}
}
// This is the method responsible for the main state of the game and most of its aspects such as input, particles, season changing, etc
void Game()
{
	//set the position variable x & y to their inital values
	s16 playerY = SCREEN_HEIGHT * 0.75;
	s16 playerX = SCREEN_WIDTH * 0.5;
	s16 treeY = SCREEN_HEIGHT * 0.55;
	s16 treeX = SCREEN_WIDTH * 0.5;
	//Starting background parallax scrolling position on 0
	s32 xScroll = 0;	
	s32 playerFrame = 192;
	s8 currentFrameState = 0;
	s32 t = 0;

	//Initialising OAM memory with buffer
	oam_init(obj_buffer, 128);
	oam_copy(MEM_OAM, obj_buffer, 128);

	//Setting up the player sprite
	u8 playerTileIndex = 0;
	u8 playerPaletteIndex = 0;
	memcpy(palette_sp_block_address(playerPaletteIndex), PlayerSprite1Pal, PlayerSprite1PalLen);
	memcpy(sprite_tile_block_address(playerTileIndex), PlayerSprite1Tiles, PlayerSprite1TilesLen);
	//Get the player from OAM memory at location MEM_OAM[0]
	ObjectAttributes* spriteAttribs = (ObjectAttributes*)&MEM_OAM[0];
	//Setting the attributes for the player
	spriteAttribs->attr0 = SetAttrib0(96, 0, 0, 0, A0_4BPP, A0_SQUARE);
	spriteAttribs->attr1 = SetAttrib1(100, 0, A1_SIZE_1);
	spriteAttribs->attr2 = SetAttrib2(playerTileIndex, 2, 128);

	//Setting up the tree sprite
	u8 TreeTileIndex = 4;
	u8 TreePaletteIndex = 8;
	memcpy(palette_sp_block_address(TreePaletteIndex), SeasonTreeSummerPal, SeasonTreeSummerPalLen);
	memcpy(sprite_tile_block_address(TreeTileIndex), SeasonTreeSummerTiles, SeasonTreeSummerTilesLen);
	//Allocating the tree sprites Oam memory location
	ObjectAttributes* spriteAttribsTree = (ObjectAttributes*)&MEM_OAM[1];
	//Setting up the attributes for the tree
	spriteAttribsTree->attr0 = SetAttrib0(96, 0, 0, 0, A0_4BPP, A0_SQUARE);
	spriteAttribsTree->attr1 = SetAttrib1(100, 0, A1_SIZE_2);
	spriteAttribsTree->attr2 = SetAttrib2(TreeTileIndex, 1, TreePaletteIndex);

	//Setting up the particle sprites
	u8 particleEffectPaletteIndex = 1;
	u8 particleEffectTileIndex = 32;

	memcpy(palette_sp_block_address(particleEffectPaletteIndex), particlesPal3, particlesPalLen);
	memcpy(sprite_tile_block_address(particleEffectTileIndex), particlesTiles, particlesTilesLen);
	//Setting the particle emitter system set to point to appear as if emitting from the season tree
	Emitter emitter;
	emitter.x = int2fix((SCREEN_WIDTH * 0.5) - 4);
	emitter.y = int2fix((SCREEN_HEIGHT * 0.55) + 4);
	//Creating and setting up the dozens of particles
	Particle particles[32];
	gamestate = 3;
	ObjectAttributes particleOAM;
	particleOAM.attr0 = SetAttrib0(0, A0_MODE_REG, 0, 0, A0_4BPP, A0_SQUARE);
	particleOAM.attr1 = SetAttrib1(0, 0, A1_SIZE_0);
	particleOAM.attr2 = SetAttrib2(particleEffectTileIndex, 0, particleEffectPaletteIndex);
	particleOAM.pad = 0;

	ObjectAttributes* particleOAMStart = &MEM_OAM[2];
	//Loop through particles setting them up AND STARTING EMITTING THEM 
	for (u32 i = 0; i < 32; ++i) 
	{
		EmitParticle(&emitter, &(particles[i]),gamestate);
		particleOAMStart[i] = particleOAM;
	}

	//Load in the two background tile maps
	LoadMovingBackgroundGreen();
	LoadFloorBackgroundGreen();
	
	REG_DISPLAYCONTROL = VIDEOMODE_0 | ENABLE_OBJECTS | BGMODE_0 | BGMODE_1 | MAPPINGMODE_1D;
	//Adjusting the backgrounds to the correct position parameters I need for them
	REG_BG_OFS[0].y = 48;
	REG_BG_OFS[1].x = +8;
	REG_BG_OFS[1].y = 48;
	//Move direction set true
	bool bMoveDirection = true;

	//Game will stay in this while loop as long as not exited to pause menu once reached
	while (1)
	{

		//Increment timer		 
		t++;
		//Reset the timer
		if (t > 12)
		{
			t = 0;
		}
		//Every two update frames move the background in intended direction
		else if ((t == 12) | (t == 10) | (t == 8) | (t == 6) | (t == 4) | (t == 2))
		{
			if (bMoveDirection == true)
			{
				xScroll += 1;
			}
			else 
			{
				xScroll -= 1;
			}
			//Scroll the sky background depending upon different
			REG_BG_OFS[0].x = xScroll;
		}

		//Vsync display to avoid screen tearing
		vsync(); 
		//Check inputs
		PollKeys();

		//Move character up
		if (input_keyDown(UP) && playerY > 90) {
			--playerY;
			if (t == 0)
			{
				if (currentFrameState == 0) {
					playerFrame = 320;
					memcpy(palette_sp_block_address(playerPaletteIndex), PlayerSprite6Pal, PlayerSprite1PalLen);
					currentFrameState = 1;
				}
				else {
					playerFrame = 512;
					memcpy(palette_sp_block_address(playerPaletteIndex), PlayerSprite9Pal, PlayerSprite1PalLen);
					currentFrameState = 0;
				}				
			}
		}
		//Move character down
		else if (input_keyDown(DOWN) && playerY < 152) {
			++playerY;
			if (t == 0)
			{
				if (currentFrameState == 0) {
					playerFrame = 64;
					memcpy(palette_sp_block_address(playerPaletteIndex), PlayerSprite2Pal, PlayerSprite1PalLen);
					currentFrameState = 1;
				}
				else {
					playerFrame = 128;
					memcpy(palette_sp_block_address(playerPaletteIndex), PlayerSprite3Pal, PlayerSprite1PalLen);
					currentFrameState = 0;
				}
			}
		}
		//Move character left
		else if (input_keyDown(LEFT) && playerX > 16) {
			--playerX;
			if (t == 0)
			{
				if (currentFrameState == 0) {
					playerFrame = 384;
					memcpy(palette_sp_block_address(playerPaletteIndex), PlayerSprite7Pal, PlayerSprite1PalLen);
					currentFrameState = 1;
				}
				else {
					playerFrame = 640;
					memcpy(palette_sp_block_address(playerPaletteIndex), PlayerSprite11Pal, PlayerSprite1PalLen);
					currentFrameState = 0;
				}
			}
		}
		//Move character right
		else if (input_keyDown(RIGHT) && playerX < 224) {
			++playerX;
			if (t == 0)
			{
				if (currentFrameState == 0) {
					playerFrame = 256;
					memcpy(palette_sp_block_address(playerPaletteIndex), PlayerSprite5Pal, PlayerSprite1PalLen);

					currentFrameState = 1;
				}
				else {
					playerFrame = 576;
					memcpy(palette_sp_block_address(playerPaletteIndex), PlayerSprite10Pal, PlayerSprite1PalLen);
					currentFrameState = 0;
				}
			}
		}
		//When A or B are pressed animations will play
		else if (input_keyDown(A) || input_keyDown(B)) {
			if (t == 0)
			{
				if (currentFrameState == 0) {
					playerFrame = 192;
					memcpy(palette_sp_block_address(playerPaletteIndex), PlayerSprite4Pal, PlayerSprite1PalLen);
					currentFrameState = 1;
				}
				else {
					playerFrame = 0;
					memcpy(palette_sp_block_address(playerPaletteIndex), PlayerSprite1Pal, PlayerSprite1PalLen);
					currentFrameState = 0;
				}
				//Check if colliding with the tree
				if (CheckCollisionCube(playerX,playerY, 16, treeX, treeY + 10, 16))
				{
					bMoveDirection = !bMoveDirection;
					//Switch statment for the season states of the game
					switch (gamestate)
					{
					case AUTUMN:
						//Load in the two background tile maps
						LoadMovingBackgroundBlue();
						LoadFloorBackgroundBlue();
						//Set the season tree and the particles to there autumn versions
						memcpy(palette_sp_block_address(TreePaletteIndex), SeasonTreePal, SeasonTreePalLen);
						memcpy(sprite_tile_block_address(TreeTileIndex), SeasonTreeTiles, SeasonTreeTilesLen);
						memcpy(palette_sp_block_address(particleEffectPaletteIndex), particlesPal4, particlesPalLen);
						//Pre increment game state
						++gamestate;
						break;
					case WINTER:
						//Load in the two background tile maps
						LoadMovingBackgroundGreen();
						LoadFloorBackgroundGreen(); 
						//Set the season tree and the particles to there winter versions
						memcpy(palette_sp_block_address(TreePaletteIndex), SeasonTreeColdPal, SeasonTreeColdPalLen);
						memcpy(sprite_tile_block_address(TreeTileIndex), SeasonTreeColdTiles, SeasonTreeColdTilesLen);
						memcpy(palette_sp_block_address(particleEffectPaletteIndex), particlesPal2, particlesPalLen);					
						//Pre increment game state
						++gamestate;
						break;
					case SPRING:
						//Load in the two background tile maps
						LoadMovingBackgroundRed();
						LoadFloorBackgroundRed();
						//Set the season tree and the particles to there spring versions
						memcpy(palette_sp_block_address(TreePaletteIndex), SeasonTreeSpringPal, SeasonTreeSpringPalLen);
						memcpy(sprite_tile_block_address(TreeTileIndex), SeasonTreeSpringTiles, SeasonTreeSpringTilesLen);
						memcpy(palette_sp_block_address(particleEffectPaletteIndex), particlesPal, particlesPalLen);
						//Pre increment game state
						++gamestate;
						break;
					case SUMMER:
						//Load in the two background tile maps
						LoadMovingBackgroundWhite();
						LoadFloorBackgroundWhite();
						//Set the season tree and the particles to there spring versions
						memcpy(palette_sp_block_address(TreePaletteIndex), SeasonTreeSummerPal, SeasonTreeSummerPalLen);
						memcpy(sprite_tile_block_address(TreeTileIndex), SeasonTreeSummerTiles, SeasonTreeSummerTilesLen);
						memcpy(palette_sp_block_address(particleEffectPaletteIndex), particlesPal3, particlesPalLen);
						//Set gamestate to 0
						gamestate = 0;
						break;
					default:
						break;
					}
				}
			}
		}

		//Check that the player is not colliding with the tree and if so push the player away
		if (CheckCollisionCube(playerX, playerY, 16, treeX, treeY, 16))
		{
			playerY = playerY + 3;
		}	
		//Select to select something in menu or options
		if (input_keyDown(SELECT)) {
			Pause();
		}
		memcpy(sprite_tile_block_address(playerTileIndex), &PlayerSprite1Tiles[playerFrame], 128);
		//Update and move particle sprites
		for (u32 i = 0; i < 32; ++i) {
			UpdateParticle(&emitter, &(particles[i]),gamestate);
			//Set the OAM sprites position based off the updated particle
			SetObjectPosition(&particleOAMStart[i], fix2int(particles[i].x), fix2int(particles[i].y));
			u32 frameID = (1 << 9) - particles[i].life;
			frameID = frameID << 4 >> 9;
			particleOAMStart[i].attr2 = SetAttrib2(particleEffectTileIndex + frameID, 0, particleEffectPaletteIndex);
		}
		//Set position of player and trees on screen
		SetObjectPosition(spriteAttribsTree, treeX - 16, treeY - 16);
		SetObjectPosition(spriteAttribs, playerX - 8, playerY - 8);
	}	
}

