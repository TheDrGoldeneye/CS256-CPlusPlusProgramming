// Fadhar Jared Castillo
// CS256 C++ Programming 
// SMFL Snake Game With 2 Players

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

//Globals
int num_vertBox = 30, num_horzBox = 20;
int size = 16; // number of pixels
int w = size * num_horzBox;
int h = size * num_vertBox;
int direction, snake_length = 4;
int direction2, snake_length2 = 4;
float delay = .2;

struct Snake
{
	int x, y;
}s[100], s2[100];

struct Fruit
{
	int x, y;
} food;

void Tick()
{
	//Move remaining pieces of snake 1-99
	//Player1
	for (int i = snake_length - 1; i > 0; i--)
	{
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y;
	}
	//Player2
	for (int i = snake_length2 - 1; i > 0; i--)
	{
		s2[i].x = s2[i - 1].x;
		s2[i].y = s2[i - 1].y;
	}
	//Player1
	if (direction == 3) s[0].y -= 1;
	if (direction == 0) s[0].y += 1;
	if (direction == 1) s[0].x -= 1;
	if (direction == 2) s[0].x += 1;
	//Player2
	if (direction2 == 3) s2[0].y -= 1;
	if (direction2 == 0) s2[0].y += 1;
	if (direction2 == 1) s2[0].x -= 1;
	if (direction2 == 2) s2[0].x += 1;
	
	//Player1
	if ((s[0].x == food.x && (s[0].y) == food.y))
	{
		//Prevents array out of bounds
		if(snake_length < 100)
		{ 
			s[snake_length].x = s[snake_length-1].x;
			s[snake_length].y = s[snake_length - 1].y;
			snake_length++;
		}
		//Increase speed but cannot increase if its too fast
		if (delay>0.05) delay -= .01;
		//random food placement
		food.x = rand() % num_horzBox;
		food.y = rand() % num_vertBox;
	}
	//Player2
	if (s2[0].x == food.x && (s2[0].y) == food.y)
	{
		//Prevents array out of bounds
		if (snake_length2 < 100)
		{
			s2[snake_length2].x = s2[snake_length2 - 1].x;
			s2[snake_length2].y = s2[snake_length2 - 1].y;
			snake_length2++;
		}
		//Increase speed but cannot increase if its too fast
		if(delay>0.05) delay -= .01;
		//random food placement
		food.x = rand() % num_horzBox;
		food.y = rand() % num_vertBox;
	}
	//Player1 boundary check
	if (s[0].x > num_horzBox-1) s[0].x = 0;
	if (s[0].x < 0)				s[0].x = num_horzBox-1;
	if (s[0].y > num_vertBox-1) s[0].y = 0;
	if (s[0].y < 0)				s[0].y = num_vertBox-1;
	//Player2 boundary check
	if (s2[0].x > num_horzBox-1) s2[0].x = 0;
	if (s2[0].x < 0)			 s2[0].x = num_horzBox-1;
	if (s2[0].y > num_vertBox-1) s2[0].y = 0;
	if (s2[0].y < 0)			 s2[0].y = num_vertBox-1;
	
	//Player1 self mutilation
	for (int i = 1; i < snake_length; i++)
	{
		if (s[0].x == s[i].x && s[0].y == s[i].y)
			snake_length = i;
	}
	//Player2 self mutilation
	for (int i = 1; i < snake_length2; i++)
	{
		if (s2[0].x == s2[i].x && s2[0].y == s2[i].y)
			snake_length2 = i;
	}
}

int main()
{
	srand(time(0));

	RenderWindow window(VideoMode(w+1, h+1), "Snake Game!");
	//Textures
	Texture t1, t2, t3, t4;
	t1.loadFromFile("image/white.png");
	t2.loadFromFile("image/red.png");
	t3.loadFromFile("image/apple.png");
	t4.loadFromFile("image/green.png");
	//Sprite has physical dimensions
	Sprite sprite1(t1);
	Sprite sprite2(t2);
	Sprite sprite3(t3);
	Sprite sprite4(t4);
	//Food placement
	food.x = 10;
	food.y = 10;	

	int offset = snake_length-1, offset2 = snake_length2 - 1;;
	//Initialize player 1 at the top left corner
	for (int i = 0; i < snake_length; i++)
	{
	
		s[i].x = 0;
		s[i].y = offset;
		offset--;
 	}
	//Initialize player at the top right corner
	for (int i = 0; i < snake_length2; i++)
	{

		s2[i].x = num_horzBox-1;
		s2[i].y = offset2;
		offset2--;
	}

	//Create the clock
	Clock clock;
	float timer = 0;
	
	//GAME LOOP
	while(window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
		//Allows us to check whether the user has done something
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
		}
		//Clear the screen
		window.clear();
		//Player1 Controls
		if (Keyboard::isKeyPressed(Keyboard::W)) direction = 3;
		if (Keyboard::isKeyPressed(Keyboard::S)) direction = 0;
		if (Keyboard::isKeyPressed(Keyboard::A)) direction = 1;
		if (Keyboard::isKeyPressed(Keyboard::D)) direction = 2;
		//Player2 Controls
		if (Keyboard::isKeyPressed(Keyboard::Up)) direction2 = 3;
		if (Keyboard::isKeyPressed(Keyboard::Down)) direction2 = 0;
		if (Keyboard::isKeyPressed(Keyboard::Left)) direction2 = 1;
		if (Keyboard::isKeyPressed(Keyboard::Right)) direction2 = 2;

		//Check if it is time to move all objects
		if(timer>delay)
		{
			timer = 0;
			Tick();
		}
		//background
		for(int i = 0; i < num_horzBox; i++)
		{
			for(int j = 0; j< num_vertBox; j++)
			{
				sprite1.setPosition(i*size, j*size);
				window.draw(sprite1);
			}
		}
		//Draw snake
		for(int i = 0; i <snake_length; i++)
		{
			sprite2.setPosition(s[i].x*size, s[i].y*size);
			window.draw(sprite2);
		}
		//Draw snake 2
		for (int i = 0; i <snake_length2; i++)
		{
			sprite4.setPosition(s2[i].x*size, s2[i].y*size);
			window.draw(sprite4);
		}
		//Draw fruit
		sprite3.setPosition(food.x*size, food.y*size);
		window.draw(sprite3);
		//Display the screen
		window.display();
	}
	return 0;
}
