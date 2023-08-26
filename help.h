#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;


int help_window()
{
	//Tile-Size............
	int ts = 54;
	Vector2i offset(48,24);

	//Generating by using time.............
	srand(time(0));
	RenderWindow help(VideoMode(740,480), "Help");
	help.setFramerateLimit(60);
    
	//Textures for loading Images.........
	Texture t1,t2;
    
	//Loading of images in game.............
	t1.loadFromFile("sprites/background2.png");
	t2.loadFromFile("sprites/animals.png");
    
	//Calling function for displaying images.......
	Sprite background(t1), gems(t2);
    
    	int x1,x2,y1,y2;
    	int clicks=0;
    	Vector2i pos;
    	
    	//Font for loading text style...........
	Font font;
	
	//Loading font style in game..........
	font.loadFromFile("regular.ttf");
    	
    
		//Heading
		Text help_text("Margerine is a match-three puzzle game that is played on a game board consisting of an 8x8\n grid filled with various types of Animals. The goal of the game is to match three or more\n of the same type of Animal in a row or column to remove them from the board and earn points.\n\nTo make matches, the player can swap two adjacent pieces on the board.\n\nTo complete a level, the player must reach the target score or clear the board of all candies.\n Levels can also feature special objectives, such as clearing all jelly. As players progress\n through the game, they will earn rewards and unlock new levels.", font , 16);
		
	    //Setting font for text.......................
	   help_text.setFont(font);
	    
	    //Setting color of text..................
	    help_text.setFillColor(Color::White);
	    
	    //Setting position.......................
	    help_text.setPosition(20, 100);
    
	
    	
	while (help.isOpen()){
	
		
	//Event e for controlling game..........
	Event e;
		
		
		//For background.........
		help.draw(background); 
    
    
		while (help.pollEvent(e)){
			if(e.type == Event::Closed)
			help.close();
			if (e.type == Event::MouseButtonPressed){
				if (e.key.code == Mouse::Left){
        			//code of action to be performed on mouse click  
        			
        	       	 	}
        	  	}
       		}
                
                
			help.draw(help_text);
		//Displaying..........   
		help.display();
		
	}
    
    return 0;
}



