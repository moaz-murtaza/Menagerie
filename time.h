#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;
using namespace std;

int time_mode()
{
	//use as a condition for checking if there is no change then tile will return.........
	int swap=0; int move=0;
	static int seconds=20;
	//Tile-Size............
	int ts = 54;
	Vector2i offset(48,24);

	//Generating by using time.............
	srand(time(0));
	RenderWindow norm(VideoMode(740,480), "Time Trial Mode");
	norm.setFramerateLimit(60);
    
	//Textures for loading Images.........
	Texture t1,t2;
    
	//Loading of images in game.............
	t1.loadFromFile("sprites/background.jpg");
	t2.loadFromFile("sprites/animals.png");
    
	//Calling function for displaying images.......
	Sprite background(t1), gems(t2);
    
    	int x1,x2,y1,y2;
    	int clicks=0;
    	Vector2i pos;
    
    	//Creating font....................
    	Font scorehead;
    
    	//Loding font style...................
    	scorehead.loadFromFile("regular.ttf");
    
    	//Creating text for score heading.............
    	Text scoreheading("Scores", scorehead , 25);
    
    	//Setting font for text.......................
    	scoreheading.setFont(scorehead);
    
    	//Setting color of text..................
    	scoreheading.setFillColor(Color::White);
    
    	//Setting position.......................
    	scoreheading.setPosition(520, 250);
    	
    	
    	//Creating font....................
    	Font score;
    
    	//Loding font style...................
    	score.loadFromFile("regular.ttf");
    
    	//Creating text for scoring.............
    	Text scoring;
    
    	//Setting font for text.......................
    	scoring.setFont(score);
    
    	//Setting color of text..................
    	scoring.setFillColor(Color::White);
    
    	//Setting font size....................
    	scoring.setCharacterSize(25);
    
    	//Setting position.......................
    	scoring.setPosition(520, 290);
    	
    	
    	
    	//Creating text for Moves Left heading.............
    	Text movesl("Time Left", scorehead , 25);
    
    	//Setting font for text.......................
    	movesl.setFont(scorehead);
    
    	//Setting color of text..................
    	movesl.setFillColor(Color::White);
    
    	//Setting position.......................
    	movesl.setPosition(520, 340);
    	
    	
    	//Creating font....................
    	Font timefont;
    
    	//Loding font style...................
    	timefont.loadFromFile("regular.ttf");
    
    	//Creating text for time constraint.............
    	Text time;
    	
    	//Setting font for text.......................
    	time.setFont(timefont);
    
    	//Setting color of text..................
    	time.setFillColor(Color::White);
    
    	//Setting font size....................
    	time.setCharacterSize(30);
    
    	//Setting position.......................
    	time.setPosition(520, 370);
    
    	//Initializing clock.....................
    	Clock clock;
    
    	
    	//Initialization of rectangle shaped bar................
   	 RectangleShape overbar(Vector2f(300, 200));
    
   	 //Position of Bar...............
   	 overbar.setPosition(120, 50);
    
    	//Inside color of bar...............
    	overbar.setFillColor(sf::Color::Black);
    
    	//Border of bar.................
    	overbar.setOutlineThickness(2);
    
    	//Border color........................
    	overbar.setOutlineColor(sf::Color::Red);
    	
    
    	//Creating font....................
    	Font over;
    	
    	//Loding font style...................
    	over.loadFromFile("regular.ttf");
    
    
	//Heading
	Text gameover("Game Over", over , 25);
	
    	//Setting font for text.......................
    	gameover.setFont(over);
    
    	//Setting color of text..................
    	gameover.setFillColor(Color::White);
    
    	//Setting font size....................
    	gameover.setCharacterSize(30);
    
    	//Setting position.......................
    	gameover.setPosition(180, 130);
    
    
    	
    	Music swap_music;
    	
    	swap_music.openFromFile("swap.ogg");
    	
    	Music over_music;
    	
    	over_music.openFromFile("over.ogg");
    	
    	over_music.pause();
    
    	int points=0;
    	int scorecount;
    	
	//Total Moves...............
	int totmoves=20;
    
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			
			//Assigning type of img..............
			arr[i][j].kind=rand()%7;
			
			//Assigning column...........
			arr[i][j].col=j;
			
			//Assigning row.............
			arr[i][j].row=i;
			
			//Assigning tile size along x axis..............
			arr[i][j].x=j*ts;
			
			//Assigning tile size along y axis................
			arr[i][j].y=i*ts;
			
    		}
	}
    
	while (norm.isOpen()){
	
		
	//Event e for controlling game..........
	Event e;
		
		
		//For background.........
		norm.draw(background); 
    		
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
			
				//Initializing structure element
				tile p = arr[i][j];
				
				//Adjusting pixels of img
				gems.setTextureRect( IntRect(p.kind*49,0,49,49));
				
				//Adjusting position of element
				gems.setPosition(p.x+20, p.y+50);
				
				//Adjusting position
				gems.move(offset.x-ts, offset.y-ts);
				
				//Drawing img
				norm.draw(gems);
	    		}
		}
    
    
		while (norm.pollEvent(e)){
			if(e.type == Event::Closed)
			norm.close();
			if (e.type == Event::MouseButtonPressed){
				if (e.key.code == Mouse::Left){
        			//code of action to be performed on mouse click  
        			
        				
        				//Saving mouse clicks clicks.............
        				pos = Mouse::getPosition(norm);  
        			
        				if(swap==0 && move==0){
        			
        					//Increasing Clicks..............
        					clicks++;   
        					
        				}
        			 
        	       	 	}
        	  	}
       		}
                
                
                //Saving x and y axis of 1st click............
                if(clicks==1){
                
                	//Saving x position according to tile size..........
                	x1 = pos.x/ts;
                	
                	//Saving y position according to tile size..........
                	y1 = pos.y/ts;
                	
                	
                		swap_music.stop();
                	
                }
                
                //Saving x and y axis of 2nd click............
                if(clicks==2){
                
                	//Saving x position according to tile size..........
                	x2 = pos.x/ts;
                	
                	//Saving y position according to tile size..........
                	y2 = pos.y/ts;
                	
                	//Condition for checking difference between file............
                	if(abs(x1-x2)+abs(y1-y2)==1){
                	
                		//If only difference is of 1 tile then switch them...........
                		swaptile(arr[y1][x1], arr[y2][x2]);
                		
                		
                		swap_music.play();
                		
                		//Swap will be true..............
                		swap = 1;
                		
                		//Reset the clicks to zero...................
                		clicks =0;
                		
                		totmoves--;
                	}
                	
                	//Else reset click to 1 and again take another click...............
                	else{
                		clicks = 1;
                	}
                }
                
                
                //Looking for match ..............
                for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				if(arr[i][j].kind==arr[i+1][j].kind && arr[i][j].kind==arr[i-1][j].kind){
					arr[i][j].match = 1;
					arr[i+1][j].match = 1;
					arr[i-1][j].match = 1;
				}
	    		}
		}
		
		
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				if(arr[i][j].kind==arr[i][j+1].kind && arr[i][j].kind==arr[i][j-1].kind){
					arr[i][j].match = 1;
					arr[i][j+1].match = 1;
					arr[i][j-1].match = 1;
				}
	    		}
		}
		
               
                
    
    
   		//Type casting from int to string for display....................
   		scoring.setString(to_string(points));
    
               
                
                //Intergers to save directions.........
                int direc_x, direc_y;
                
                //Movement will be false during animation................
                move = 0;
                
                //Loop for changings gems inside the game board.........
                for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
			
				direc_x = 0; direc_y = 0;
				
				//Allocating the directions of tile..............
				tile &p = arr[i][j];
				
				//For increasing speed of the game............
				for(int sp=0; sp<2; sp++){
				
					//Direction if it is given to switch on x axis...........
					direc_x = p.x - p.col*ts;
				
					//Direction if it is given to switch on y axis...........
					direc_y = p.y - p.row*ts;
				
					//Changing of tiles.............
					if(direc_x!=0){
						p.x = p.x - direc_x/abs(direc_x);
					}
				
					//Changing of tiles.............
					if(direc_y!=0){
						p.y = p.y - direc_y/abs(direc_y);
					}
					
					if(direc_y!=0 || direc_x!=0){
						//Movement will be true................
						move = 1;
					}
				}
	    		}
		}
		
		
    		
               if(move==0){
               		  for(int i=7; i>=0; i--){
				for(int j=0; j<8; j++){
					if(arr[i][j].match==1){
						for(int k=i-1; k>=0; k--){
							
							if(arr[k][j].match==0){
								swaptile(arr[i][j],arr[k][j]);
								arr[k][j].match=1;
								break;
							}
							
						
						}
					}
		    		}
			}
			
			for(int i=7; i>=0; i--){
					int n=0;
				for(int j=7; j>=0; j--){
				
					//Counter of scores............
					scorecount=0;
					
					if(arr[i][j].match==1){
						
						arr[i][j].match=0;
						
						//Assigning type of img..............
						arr[i][j].kind=rand()%7;
						
						scorecount++;
						
						//Assigning tile size along y axis................
						arr[i][j].y= -ts*n;
						n++;
						
						//After cutting do not swap...........
						swap=0;
						
					}
					//Addition of scores..............
					points+=scorecount*100;
		    		}
			}
               }
               
               
    		//Getting time elapsed while app is open..................
    		Time elapsed = clock.getElapsedTime();
    		
		if(seconds<=0){	
    			norm.draw(overbar);
    			norm.draw(gameover);
    			seconds=0;
			over_music.play();
		}
		else{
    		//Seconds left is equal to total - elapsed seconds.....................
    		seconds = 120 - (int) elapsed.asSeconds();
    	}
    		//Type casting from int to string for display....................
    		time.setString(to_string(seconds));
    
		
		//Swap return if no match found...............
		if(swap == 1 && move == 0){
		
				//For swap return...............
                		swaptile(arr[y1][x1], arr[y2][x2]);
                		
                		//Swap will return to 0................
                		swap=0;
		}
		
		
		
                norm.draw(scoring);
                norm.draw(scoreheading);
                norm.draw(movesl);
                norm.draw(time);
		//Displaying..........   
		norm.display();
		
	}
    
    return 0;
}



