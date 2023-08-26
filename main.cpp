#include <SFML/Graphics.hpp>
#include "normal.h"
#include "time.h"
#include "help.h"
#include <iostream>

using namespace sf;
using namespace std;


int main(){
	//Tile-Size............
	int ts = 54;
	Vector2i offset(48,24);

	//Generating by using time.............
	srand(time(0));
	RenderWindow app(VideoMode(740,480), "Menagerie");
	app.setFramerateLimit(60);
    
	//Textures for loading Images.........
	Texture t1;
    
	//Loading of images in game.............
	t1.loadFromFile("sprites/background.png");
	
	//Calling function for displaying images.......
	Sprite background(t1);
	
	
	//Count for characters...................
	int count1=0;
	int count2=0;
    	int count3=0;
    	int count4=0;
    	int count5=0;
    	int count6=0;
	
	
    	Music background_music;
    	
    	background_music.openFromFile("background.ogg");
	
	//Font for loading text style of heading...........
	Font heading;
	
	//Font for loading text style...........
	Font font;
	
	//Loading font style in game..........
	font.loadFromFile("regular.ttf");
	heading.loadFromFile("bold.ttf");
	
	//Heading
	Text text("Choose a Mode", heading , 35);
	
	//Option of Normal Mode
	Text normal("Normal Mode", font, 20);
	
	//Option of Time Trial
	Text time("Time Trial", font, 20);
	
	//Option of Sound
	Text sound("Sound", font, 20);
	
	//Option of Highest Score
	Text score("Highest score : 1000", font, 20);
	
	//Option of Help
	Text help("Help", font, 20);
	
	//Setting Position..........
	text.setPosition (40,  50);
	normal.setPosition(50, 150);
	time.setPosition(50,   200);
	sound.setPosition(50,  250);
	score.setPosition(50,  300);
    	help.setPosition(50,  350);
    	
    	
	//Clicks for menu.............
    	int click_menu=0;
    	
    	//Position vector for menu...................
    	Vector2i pos;
    	background_music.play();
    	
    	while (app.isOpen()){
		
	//Event e for controlling game..........
	Event e;
    
      	 	
      	 	if(click_menu==1){
      	 	}
      	 	
		while (app.pollEvent(e)){
			if(e.type == Event::Closed){
				app.close();
			}
			if (e.type == Event::MouseButtonPressed){
				if (e.key.code == Mouse::Left){
        			//code of action to be performed on mouse click       
        			
        				pos = Mouse::getPosition(app);   
        				click_menu++;
        				
      	 		background_music.stop();
        		       	 }
        		  }
      	 	}
      	 	
      	 	
      	 	int x1, y1;
                
                
                //Saving x and y axis of 1st click............
                if(click_menu==1){
                
                	//Saving x position..........
                	x1 = pos.x;
                	
                	//Saving y position..........
                	y1 = pos.y;
                	
                	
             	   //For normal Functioning...................
            	    if (x1>40 && y1>130 && y1<180){
            	    
            	    	//Start of time mode..................
            	    	normal_mode(count1, count2, count3, count4, count5, count6);
            	    	
            	    	//Click of menu returns to zero............
            	    	click_menu=0;
            	    	
            	    }
                
            	    //For time trial functioning....................
            	    if (x1>40 && y1>180 && y1<230){
            	    
            	    	/*if(count1>8000 && count2>7000 && count3>6000 && count4>5000 && count5>4000 && count6>3000){
            	    	
            	    		//Start of time mode..................
            	    		time_mode();
            	    	
            	    	}*/
            	    	
            	    	//Start of time mode..................
            	    		time_mode();
            	    		
            	    	//Click of menu returns to zero............
            	    	click_menu=0;
            	    }
            	    
            	    //For normal Functioning...................
            	    if (x1>40 && y1>230 && y1<280){
            	    	
      	 		background_music.stop();
            	    
            	    	//Click of menu returns to zero............
            	    	click_menu=0;
            	    	
            	    }
                
            	    //For Sound functioning....................
            	    if (x1>40 && y1>330 && y1<380){
            	    
            	    	help_window();
            	    	//Click of menu returns to zero............
            	    	click_menu=0;
            	    }
            	    	
                }
                
                
	
                
    
               
		//Displaying..........   
		app.clear();
		
		//For background.........
		app.draw(background); 
		
		app.draw(text);
		app.draw(normal);
		app.draw(time);
		app.draw(sound);
		app.draw(score);
		app.draw(help);
		app.display();
	}
    
    return 0;
}
