#include <SFML/Audio.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;
using namespace std;

struct tile
{
	//Type of tile
	int kind;
	
	//x-axis of tile size
	int x;
	
	//y-axis of file size
	int y;
	
	//column of array
	int col;
	
	//row of array
	int row;
	
	//matching
	int match=0;
	
}arr[8][8];
	
//Function for swapping of files...............
void swaptile(tile p1, tile p2){

	//For swapping columns................
	swap(p1.col,p2.col);
	
	//For swapping rows...................
	swap(p1.row,p2.row);
	
	//Assigning changed values of tile according to swapping.................
	arr[p1.row][p1.col] = p1;
	arr[p2.row][p2.col] = p2;
}

int normal_mode(int count1, int count2, int count3, int count4, int count5, int count6)
{
	//use as a condition for checking if there is no change then tile will return.........
	int swap=0; int move=0;

	//Tile-Size............
	int ts = 54;
	Vector2i offset(48,24);

	//Generating by using time.............
	srand(time(0));
	RenderWindow norm(VideoMode(740,480), "Normal Mode");
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
    
    	
    	//Setting color of text..................
    	scoreheading.setFillColor(Color::White);
    
    	//Setting position.......................
    	scoreheading.setPosition(500, 250);
    	
    	
    	Text animal1("1st Animal", scorehead , 14);
    	Text animal2("2nd Animal", scorehead , 14);
    	Text animal3("3rd Animal", scorehead , 14);
    	Text animal4("4th Animal", scorehead , 14);
    	Text animal5("5th Animal", scorehead , 14);
    	Text animal6("6th Animal", scorehead , 14);
    	
    	
    	animal1.setFillColor(Color::White);
    	animal2.setFillColor(Color::White);
    	animal3.setFillColor(Color::White);
    	animal4.setFillColor(Color::White);
    	animal5.setFillColor(Color::White);
    	animal6.setFillColor(Color::White);
    	
    	animal1.setPosition(500, 50);
    	animal2.setPosition(500, 80);
    	animal3.setPosition(500, 110);
    	animal4.setPosition(500, 140);
    	animal5.setPosition(500, 170);
    	animal6.setPosition(500, 200);
    	
    	Text animalcount1("1st Animal", scorehead , 14);
    	Text animalcount2("2nd Animal", scorehead , 14);
    	Text animalcount3("3rd Animal", scorehead , 14);
    	Text animalcount4("4th Animal", scorehead , 14);
    	Text animalcount5("5th Animal", scorehead , 14);
    	Text animalcount6("6th Animal", scorehead , 14);
    	
    	
    	animalcount1.setFillColor(Color::White);
    	animalcount2.setFillColor(Color::White);
    	animalcount3.setFillColor(Color::White);
    	animalcount4.setFillColor(Color::White);
    	animalcount5.setFillColor(Color::White);
    	animalcount6.setFillColor(Color::White);
    	
    	animalcount1.setPosition(680, 50);
    	animalcount2.setPosition(680, 80);
    	animalcount3.setPosition(680, 110);
    	animalcount4.setPosition(680, 140);
    	animalcount5.setPosition(680, 170);
    	animalcount6.setPosition(680, 200);
    	
    	//Initialization of rectangle shaped progress bar................
  	RectangleShape Bar1(Vector2f(80, 15));
    	RectangleShape Bar2(Vector2f(80, 15));
    	RectangleShape Bar3(Vector2f(80, 15));
    	RectangleShape Bar4(Vector2f(80, 15));
    	RectangleShape Bar5(Vector2f(80, 15));
    	RectangleShape Bar6(Vector2f(80, 15));
    
    	//Position of Bar...............
    	Bar1.setPosition(580, 50);
    	Bar2.setPosition(580, 80);
    	Bar3.setPosition(580, 110);
    	Bar4.setPosition(580, 140);
    	Bar5.setPosition(580, 170);
    	Bar6.setPosition(580, 200);
    
    	//Inside color of bar...............
    	Bar1.setFillColor(sf::Color::Red);
    	Bar2.setFillColor(sf::Color::Red);
    	Bar3.setFillColor(sf::Color::Red);
    	Bar4.setFillColor(sf::Color::Red);
    	Bar5.setFillColor(sf::Color::Red);
    	Bar6.setFillColor(sf::Color::Red);
    	
    	//Border of bar.................
    	Bar1.setOutlineThickness(2);
    	Bar2.setOutlineThickness(2);
    	Bar3.setOutlineThickness(2);
    	Bar4.setOutlineThickness(2);
    	Bar5.setOutlineThickness(2);
    	Bar6.setOutlineThickness(2);
    	
    	//Border color........................
    	Bar1.setOutlineColor(sf::Color::Blue);
    	Bar2.setOutlineColor(sf::Color::Blue);
    	Bar3.setOutlineColor(sf::Color::Blue);
    	Bar4.setOutlineColor(sf::Color::Blue);
    	Bar5.setOutlineColor(sf::Color::Blue);
    	Bar6.setOutlineColor(sf::Color::Blue);
    
    
    	
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
    	scoring.setPosition(500, 290);
    	
    	
    	
    	//Creating text for Moves Left heading.............
    	Text movesl("Moves Left", scorehead , 25);
    
    	//Setting font for text.......................
    	movesl.setFont(scorehead);
    
    	//Setting color of text..................
    	movesl.setFillColor(Color::White);
    
    	//Setting position.......................
    	movesl.setPosition(500, 340);
    	
    	//Creating font....................
    	Font moves;
    
    	//Loding font style...................
    	moves.loadFromFile("regular.ttf");
    
    	//Creating text for Moves Left.............
    	Text movesleft;
    
    	//Setting font for text.......................
    	movesleft.setFont(moves);
    
    	//Setting color of text..................
    	movesleft.setFillColor(Color::White);
    
    	//Setting font size....................
    	movesleft.setCharacterSize(25);
    
    	//Setting position.......................
    	movesleft.setPosition(500, 370);
    	
    	
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
			
			if(arr[i][j].kind==1){
				count1++;
			}
			if(arr[i][j].kind==2){
				count2++;
			}
			if(arr[i][j].kind==3){
				count3++;
			}
			if(arr[i][j].kind==4){
				count4++;
			}
			if(arr[i][j].kind==5){
				count5++;
			}
			if(arr[i][j].kind==6){
				count6++;
			}
			
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
                		
                		if(totmoves>0){
                			totmoves--;
                		}
                		else{
                			totmoves=0;
                		}
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
    
                //Type casting from int to string for display....................
   		movesleft.setString(to_string(totmoves));
    
      
                //Type casting from int to string for display....................
   		animalcount1.setString(to_string(count1));
   		animalcount2.setString(to_string(count2));
   		animalcount3.setString(to_string(count3));
   		animalcount4.setString(to_string(count4));
   		animalcount5.setString(to_string(count5));
   		animalcount6.setString(to_string(count6));
    
                
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
			
			for(int i=7, n=0; i>=0; i--){
				for(int j=7; j>=0; j--){
				
					//Counter of scores............
					scorecount=0;
					
					if(arr[i][j].match==1){
						
						arr[i][j].match=0;
						
						//Assigning type of img..............
						arr[i][j].kind=rand()%7;
						
						scorecount++;
						
						//Assigning tile size along y axis................
						arr[i][j].y= -ts*n++;
						
						
						//After cutting do not swap...........
						swap=0;
						
						if(arr[i][j].kind==1){
							count1++;
						}
						if(arr[i][j].kind==2){
							count2++;
						}
						if(arr[i][j].kind==3){
							count3++;
						}
						if(arr[i][j].kind==4){
							count4++;
						}
						if(arr[i][j].kind==5){
							count5++;
						}
						if(arr[i][j].kind==6){
							count6++;
						}
					}
					//Addition of scores..............
					points+=scorecount*100;
		    		}
			}
               }
               
               
               if(count1<8000){
		
			//Size of Bar...................
			Bar1.setSize(Vector2f(count1*0.01, 15)); 
		} 
		if(count2<7000){
		
			//Size of Bar...................
			Bar2.setSize(Vector2f(count2*0.0114, 15)); 
		}
		if(count3<6000){
		
			//Size of Bar...................
			Bar3.setSize(Vector2f(count3*0.0133, 15)); 
		} 
		if(count4<5000){
			
			//Size of Bar...................
			Bar4.setSize(Vector2f(count4*0.016, 15)); 
		} 
		if(count5<4000){
			
			//Size of Bar...................
			Bar5.setSize(Vector2f(count5*0.02, 15)); 
		} 
		 
		if(count6<3000){
			
			//Size of Bar...................
			Bar6.setSize(Vector2f(count6*0.0266, 15)); 
		}
               
               
		
		//Swap return if no match found...............
		if(swap == 1 && move == 0){
		
				//For swap return...............
                		swaptile(arr[y1][x1], arr[y2][x2]);
                		
                		//Swap will return to 0................
                		swap=0;
		}
		
		
		if(totmoves < 1){
    			norm.draw(overbar);
    			norm.draw(gameover);
			over_music.play();
		}
		
		
		
		
   		norm.draw(Bar1);  
   		norm.draw(Bar2); 
    		norm.draw(Bar3); 
    		norm.draw(Bar4); 
    		norm.draw(Bar5); 
    		norm.draw(Bar6); 
    		norm.draw(animal1);  
   		norm.draw(animal2); 
    		norm.draw(animal3); 
    		norm.draw(animal4); 
    		norm.draw(animal5); 
    		norm.draw(animal6);
    		norm.draw(animalcount1);  
   		norm.draw(animalcount2); 
    		norm.draw(animalcount3); 
    		norm.draw(animalcount4); 
    		norm.draw(animalcount5); 
    		norm.draw(animalcount6);
                norm.draw(scoring);
                norm.draw(scoreheading);
                norm.draw(movesl);
                norm.draw(movesleft);
		//Displaying..........   
		norm.display();
		
	}
    
    return 0;
}



