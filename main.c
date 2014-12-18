//////ISHAAN GROVER


#include <stdio.h>
#include "mylib.h"
#include "splashPic.h"
#include "winner.h"
#include "try.h"
int splash();
int game();
int win();
int lose();
int lives = 3;
int isValidMove();
void moveEnemy();
int isColliding();
int next();
enum {SPLASH, GAME, NEXT, LOSE, WIN};
int main(void)
{
	int state = SPLASH;
	int response = 1;
	while(1)
	{
		switch(state)
		{
			case SPLASH:
				lives = 3;
                response = splash();
                if(response == 1)
                {
                	state = SPLASH;
                }
                else
                	state = GAME;
                break;

            case GAME:
                response = game();
                if(response ==1)
                	state = SPLASH;
                else if(response == 2)   //restart game
                {
                	state = GAME; 			
                	lives--;
                }
                else if (response == 3)   //nextLevel
                {
                	state = NEXT;
                }
                if(lives == 0) 
                {
                	state = LOSE;
                }
                break;

            case NEXT:
            	response = next();
            	if(response == 1)
            		state = SPLASH;
            	else if (response == 2)
            	{
            		state = NEXT;
            		lives--;
            	}
            	else if(response ==3)
            	{
            		state = WIN;
            	}
            	if(lives ==0)
            	{
            		state = LOSE;
            	}
            	break;

            case WIN:
            	response = win();
            	if(response == 1)
            		state = SPLASH;
            	break;
            case LOSE:
            	response = lose();
            	if(response == 1)
            		state = SPLASH; 
            default: break;
		}
	}	
}

int lose()
{
	drawImage3(0, 0, 240, 160, try);
	if(KEY_DOWN_NOW(BUTTON_SELECT))
    		return 1;
    return 0;
}


int win()
{
	drawImage3(0, 0, 240, 160, winner);
	if(KEY_DOWN_NOW(BUTTON_SELECT))
    		return 1;
    return 0;

}
int splash()
{
	REG_DISPCTL = MODE3 | BG2_ENABLE;
	drawRect(0, 0, 240, 160, WHITE);
	drawImage3(0, 0, 240, 80, splashPic);
	drawString(100, 80, "Press Start", BLUE);
	drawString(140, 150, "-Ishaan Grover", BLUE);
	while(!KEY_DOWN_NOW(BUTTON_START))
	{
		if(KEY_DOWN_NOW(BUTTON_START))
    		return 0;
    	if(KEY_DOWN_NOW(BUTTON_SELECT))
    		return 1;
	}
	return 0;
    
}

int next()
{
	REG_DISPCTL = MODE3 | BG2_ENABLE;
	drawRect(0, 0, 240, 160, YELLOW);
	drawRect(20, 20, 200, 121, WHITE);
	drawRect(70, 0, 20, 20, WHITE);
	drawRect(70, 220, 20, 20, GREEN);
	// int speed = 3;
	// int upLimit = 20;
	// int downLimit= 130;
	int playerSpeed = 2;
	Enemy enemy1 = {.x = 50, .y = 20, .direction = 2, .oldx = 50, .oldy = 20};
	Enemy enemy2 = {.x = 90, .y = 140, .direction = 2, .oldx = 90, .oldy = 140};
	Enemy enemy3 = {.x = 20, .y = 180, .direction = 1, .oldx = 20, .oldy = 180};
	Enemy enemy4 = {.x = 20, .y = 70, .direction = 1, .oldx = 20, .oldy = 70};
	Enemy enemy5 = {.x = 50, .y = 190, .direction = 2, .oldx = 50, .oldy = 190};
	Player player= {.x = 70, .y = 0, .oldx = 70, .oldy = 0};

	drawRect(enemy1.x, enemy1.y, 10, 10, RED);
	drawRect(enemy2.x, enemy2.y, 10, 10, RED);
	drawRect(enemy3.x, enemy3.y, 10, 10, RED);
	drawRect(enemy4.x, enemy4.y, 10, 10, RED);
	drawRect(enemy5.x, enemy5.y, 10, 10, RED);
	drawRect(player.x, player.y, 10, 10, BLUE);
	drawString(150, 30, "LEVEL 2", GREEN );


	while(1){
		waitForVblank();
		enemy1.oldx = enemy1.x;
		enemy1.oldy = enemy1.y;
		enemy2.oldx = enemy2.x;
		enemy2.oldy = enemy2.y;
		enemy3.oldx = enemy3.x;
		enemy3.oldy = enemy3.y;
		enemy4.oldx = enemy4.x;
		enemy4.oldy = enemy4.y;
		enemy5.oldx = enemy5.x;
		enemy5.oldy = enemy5.y;
		player.oldx = player.x;
		player.oldy = player.y;

		if(KEY_DOWN_NOW(BUTTON_SELECT))
    		return 1;
    	///////Movement ENEMY 1
    	if((enemy1.y>=40) && (enemy1.direction == 2))
    		enemy1.direction = 1;

    	if((enemy1.x >=110) && (enemy1.direction == 1 ))
    		enemy1.direction = 3;
    	if(enemy1.y<=20 && enemy1.direction == 3)
    		enemy1.direction = 0;
    	if((enemy1.x<50) && (enemy1.direction == 0))
    		enemy1.direction = 2;
    	if(enemy1.direction == 1)
    		enemy1.x = enemy1.x+1;
    	if(enemy1.direction ==2)
    		enemy1.y = enemy1.y +1;
    	if(enemy1.direction ==3)
    		enemy1.y = enemy1.y -1;
    	if(enemy1.direction == 0)
    		enemy1.x = enemy1.x -1;

    	drawRect(enemy1.oldx, enemy1.oldy, 10, 10, WHITE);
    	drawRect(enemy1.x, enemy1.y, 10, 10, RED);


    	//////Movement ENEMY 2

    	if((enemy2.y>=140) && (enemy2.direction == 2))
    		enemy2.direction = 1;
    	if((enemy2.x >=110) && (enemy2.direction == 1 ))
    		enemy2.direction = 3;
    	if(enemy2.y<=90 && enemy2.direction == 3)
    		enemy2.direction = 0;
    	if((enemy2.x<30) && (enemy2.direction == 0))
    		enemy2.direction = 2;
    	if(enemy2.direction == 1)
    		enemy2.x = enemy2.x+5;
    	if(enemy2.direction ==2)
    		enemy2.y = enemy2.y +5;
    	if(enemy2.direction ==3)
    		enemy2.y = enemy2.y -5;
    	if(enemy2.direction == 0)
    		enemy2.x = enemy2.x -5;
    	drawRect(enemy2.oldx, enemy2.oldy, 10, 10, WHITE);
    	drawRect(enemy2.x, enemy2.y, 10, 10, RED);


    	////Movement of Enemy 3
    	if((enemy3.x >= 130) && (enemy3.direction == 1))
    		enemy3.direction = 0;

    	if((enemy3.x <= 20) && (enemy3.direction == 0))
    		enemy3.direction = 1;
   
    	if(enemy3.direction == 1)
    	{
    		enemy3.x = enemy3.x +5;	
    	}

    	if(enemy3.direction == 0)
    	{
    		enemy3.x = enemy3.x -5;
    	}

    	drawRect(enemy3.oldx, enemy3.oldy, 10, 10, WHITE);
    	drawRect(enemy3.x, enemy3.y, 10, 10, RED);


    	////Movement of Enemy4
    	if((enemy4.x >= 130) && (enemy4.direction == 1))
    		enemy4.direction = 0;

    	if((enemy4.x <= 20) && (enemy4.direction == 0))
    		enemy4.direction = 1;
   
    	if(enemy4.direction == 1)
    	{
    		enemy4.x = enemy4.x +3;	
    	}

    	if(enemy4.direction == 0)
    	{
    		enemy4.x = enemy4.x -3;
    	}
    	drawRect(enemy4.oldx, enemy4.oldy, 10, 10, WHITE);
    	drawRect(enemy4.x, enemy4.y, 10, 10, RED);


    	//Movement of enemy 5
    	if((enemy5.y>=208) && (enemy5.direction == 2))
    		enemy5.direction = 1;

    	if((enemy5.x >=110) && (enemy5.direction == 1 ))
    		enemy5.direction = 3;
    	if(enemy5.y<=190 && enemy5.direction == 3)
    		enemy5.direction = 0;
    	if((enemy5.x<50) && (enemy5.direction == 0))
    		enemy5.direction = 2;
    	if(enemy5.direction == 1)
    		enemy5.x = enemy5.x+2;
    	if(enemy5.direction ==2)
    		enemy5.y = enemy5.y +2;
    	if(enemy5.direction ==3)
    		enemy5.y = enemy5.y -2;
    	if(enemy5.direction == 0)
    		enemy5.x = enemy5.x -2;

    	drawRect(enemy5.oldx, enemy5.oldy, 10, 10, WHITE);
    	drawRect(enemy5.x, enemy5.y, 10, 10, RED);


    	//////Player Movements
    	if(KEY_DOWN_NOW(BUTTON_RIGHT)) {
    		player.y = player.y + playerSpeed;
    		int isvalid = 0;
    		isvalid = isValidMove(player.x, player.y);
    		if(isvalid == 0)
    			player.y = player.y - playerSpeed;

        } 

        if(KEY_DOWN_NOW(BUTTON_UP)) {
    		player.x = player.x - playerSpeed;
    		int isvalid = 0;
    		isvalid = isValidMove(player.x, player.y);
    		if(isvalid == 0)
    			player.x = player.x + playerSpeed;
        }

        if(KEY_DOWN_NOW(BUTTON_LEFT)) {
    		player.y = player.y - playerSpeed;
    		int isvalid = 0;
    		isvalid = isValidMove(player.x, player.y);
    		if(isvalid == 0)
    			player.y = player.y + playerSpeed;
        }

        if(KEY_DOWN_NOW(BUTTON_DOWN)) {
    		player.x = player.x + playerSpeed;
    		int isvalid = 0;
    		isvalid = isValidMove(player.x, player.y);
    		if(isvalid == 0)
    			player.x = player.x - playerSpeed;

        }

        if(KEY_DOWN_NOW(BUTTON_L))
        {
        	if(playerSpeed <=3)
        		playerSpeed = playerSpeed +1;
        }


        if(player.y + 9 >= 220 && player.x>=70 && player.x<=210)
        	return 3;

        int collide;
        collide = isColliding(player, enemy1, enemy2, enemy3, enemy4, enemy5);
        if(collide)
        	return 2; 

        char str[15];
        sprintf(str, "%d", lives);
        drawRect(player.oldx, player.oldy, 10, 10, WHITE);
    	drawRect(player.x, player.y, 10, 10, BLUE);
    	drawString(150, 100, "Lives:", GREEN);
    	drawString(150, 140, str, GREEN);


	};
	return 1;
}


int game()
{
	REG_DISPCTL = MODE3 | BG2_ENABLE;
	drawRect(0, 0, 240, 160, YELLOW);
	drawRect(20, 20, 200, 121, WHITE);
	drawRect(70, 0, 20, 20, WHITE);
	drawRect(70, 220, 20, 20, GREEN);
	int speed = 3;
	int upLimit = 20;
	int downLimit= 130;
	int playerSpeed = 2;
	Enemy enemy1 = {.x = 20, .y = 80, .direction = 1, .oldx = 20, .oldy = 80};
	Enemy enemy2 = {.x = 130, .y = 100 , .direction = 0, .oldx = 100, .oldy = 100};
	Enemy enemy3 = {.x = 20, .y = 120, .direction = 1, .oldx = 20, .oldy = 120};
	Enemy enemy4 = {.x = 130, .y = 140, .direction = 0, .oldx = 130, .oldy = 140};
	Enemy enemy5 = {.x = 20, .y = 160, .direction = 1, .oldx = 20, .oldy = 160};
	Player player= {.x = 70, .y = 0, .oldx = 70, .oldy = 0};


	drawRect(enemy1.x, enemy1.y, 10, 10, RED);
	drawRect(enemy2.x, enemy2.y, 10, 10, RED);
	drawRect(enemy3.x, enemy3.y, 10, 10, RED);
	drawRect(enemy4.x, enemy4.y, 10, 10, RED);
	drawRect(enemy5.x, enemy5.y, 10, 10, RED);
	drawRect(player.x, player.y, 10, 10, BLUE);
	drawString(150, 30, "LEVEL 1", GREEN );
	while(1){
		waitForVblank();
		enemy1.oldx = enemy1.x;
		enemy2.oldx = enemy2.x;
		enemy3.oldx = enemy3.x;
		enemy4.oldx = enemy4.x;
		enemy5.oldx = enemy5.x;
		player.oldx = player.x;
		player.oldy = player.y;

		if(KEY_DOWN_NOW(BUTTON_SELECT))
    		return 1;


    	//// MOVE ENEMIE 1 
    	if((enemy1.x >= downLimit) && (enemy1.direction == 1))
    		enemy1.direction = 0;

    	if((enemy1.x <= upLimit) && (enemy1.direction == 0))
    		enemy1.direction = 1;
   
    	if(enemy1.direction == 1)
    	{
    		enemy1.x = enemy1.x +speed;	
    	}

    	if(enemy1.direction == 0)
    	{
    		enemy1.x = enemy1.x -speed;
    	}

    	

    	////////MOVE ENEMY 2
    	if((enemy2.x >= downLimit) && (enemy2.direction == 1))
    		enemy2.direction = 0;

    	if((enemy2.x <= 22) && (enemy2.direction == 0))
    		enemy2.direction = 1;
   
    	if(enemy2.direction == 1)
    	{
    		enemy2.x = enemy2.x +4;	
    	}

    	if(enemy2.direction == 0)
    	{
    		enemy2.x = enemy2.x - 4;
    	}

		////////MOVE ENEMY 3
    	if((enemy3.x >= downLimit) && (enemy3.direction == 1))
    		enemy3.direction = 0;

    	if((enemy3.x <= upLimit) && (enemy3.direction == 0))
    		enemy3.direction = 1;
   
    	if(enemy3.direction == 1)
    	{
    		enemy3.x = enemy3.x +speed;	
    	}

    	if(enemy3.direction == 0)
    	{
    		enemy3.x = enemy3.x -speed;
    	}
    	/////MOVE ENEMY 4
    	if((enemy4.x >= downLimit) && (enemy4.direction == 1))
    		enemy4.direction = 0;

    	if((enemy4.x <= 22) && (enemy4.direction == 0))
    		enemy4.direction = 1;
   
    	if(enemy4.direction == 1)
    	{
    		enemy4.x = enemy4.x +4;	
    	}

    	if(enemy4.direction == 0)
    	{
    		enemy4.x = enemy4.x - 4;
    	}

    	////////Move enemy 5

    	if((enemy5.x >= downLimit) && (enemy5.direction == 1))
    		enemy5.direction = 0;

    	if((enemy5.x <= upLimit) && (enemy5.direction == 0))
    		enemy5.direction = 1;
   
    	if(enemy5.direction == 1)
    	{
    		enemy5.x = enemy5.x +speed;	
    	}

    	if(enemy5.direction == 0)
    	{
    		enemy5.x = enemy5.x -speed;
    	}


    	//////Player Movements
    	if(KEY_DOWN_NOW(BUTTON_RIGHT)) {
    		player.y = player.y + playerSpeed;
    		int isvalid = 0;
    		isvalid = isValidMove(player.x, player.y);
    		if(isvalid == 0)
    			player.y = player.y - playerSpeed;

        } 

        if(KEY_DOWN_NOW(BUTTON_UP)) {
    		player.x = player.x - playerSpeed;
    		int isvalid = 0;
    		isvalid = isValidMove(player.x, player.y);
    		if(isvalid == 0)
    			player.x = player.x + playerSpeed;
        }

        if(KEY_DOWN_NOW(BUTTON_LEFT)) {
    		player.y = player.y - playerSpeed;
    		int isvalid = 0;
    		isvalid = isValidMove(player.x, player.y);
    		if(isvalid == 0)
    			player.y = player.y + playerSpeed;
        }

        if(KEY_DOWN_NOW(BUTTON_DOWN)) {
    		player.x = player.x + playerSpeed;
    		int isvalid = 0;
    		isvalid = isValidMove(player.x, player.y);
    		if(isvalid == 0)
    			player.x = player.x - playerSpeed;

        }

        if(KEY_DOWN_NOW(BUTTON_L))
        {
        	if(playerSpeed <=3)
        		playerSpeed = playerSpeed +1;
        }


        if(player.y + 9 >= 220 && player.x>=70 && player.x<=210)
        	return 3;

        int collide;
        collide = isColliding(player, enemy1, enemy2, enemy3, enemy4, enemy5);
        if(collide)
        	return 2;   
        
        	
        char str[15];
        sprintf(str, "%d", lives);
    	drawRect(enemy1.oldx, enemy1.oldy, 10, 10, WHITE);
    	drawRect(enemy1.x, enemy1.y, 10, 10, RED);
    	drawRect(enemy2.oldx, enemy2.oldy, 10, 10, WHITE);
    	drawRect(enemy2.x, enemy2.y, 10, 10, RED);
    	drawRect(enemy3.oldx, enemy3.oldy, 10, 10, WHITE);
    	drawRect(enemy3.x, enemy3.y, 10, 10, RED);
    	drawRect(enemy4.oldx, enemy4.oldy, 10, 10, WHITE);
    	drawRect(enemy4.x, enemy4.y, 10, 10, RED);
    	drawRect(enemy5.oldx, enemy5.oldy, 10, 10, WHITE);
    	drawRect(enemy5.x, enemy5.y, 10, 10, RED);
    	drawRect(player.oldx, player.oldy, 10, 10, WHITE);
    	drawRect(player.x, player.y, 10, 10, BLUE);
    	drawString(150, 100, "Lives:", GREEN);
    	drawString(150, 140, str, GREEN);
    	


	}
	return 0;
}


int isValidMove(int x, int y)
{
	if(y>=20 && y<=210 && x>=20 && x<=130)
		return 1;
	if(y>=0 && y<=230 && x>=70 && x<=80)
		return 1;
	if(y>=0 && y<=230 && x>=70 && x<=80)
		return 1;
	else return 0;
}


int isColliding(Player player, Enemy enemy1, Enemy enemy2, Enemy enemy3, Enemy enemy4, Enemy enemy5)
{
		if(((player.x +9 >=enemy1.x) && (player.x<= enemy1.x+10) && (player.y+9 >=enemy1.y) && (player.y<= enemy1.y+10))  ||
           ((player.x +9 >=enemy2.x) && (player.x<= enemy2.x+10) && (player.y+9 >=enemy2.y) && (player.y<= enemy2.y+10)) ||
           ((player.x +9 >=enemy3.x) && (player.x<= enemy3.x+10) && (player.y+9 >=enemy3.y) && (player.y<= enemy3.y+10)) ||
           ((player.x +9 >=enemy4.x) && (player.x<= enemy4.x+10) && (player.y+9 >=enemy4.y) && (player.y<= enemy4.y+10)) ||
           ((player.x +9 >=enemy5.x) && (player.x<= enemy5.x+10) && (player.y+9 >=enemy5.y) && (player.y<= enemy5.y+10)))
        	return 1;
        return 0;

}