#include <iostream>
#include <windows.h>
#include <conio.h>

bool gameOver; // Gamestate
const int width = 30;
const int height = 12;
int x, y; //player coordinates
int score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

//MAP OF HIPPODROMOS
char map[height][width + 1] =
{
	"##############################",
	"#............................#",
	"#............##..............#",
	"#............................#",
	"#............................#",
	"#............##..............#",
	"#............##..............#",
	"#............................#",
	"#............................#",
	"#............##..............#",
	"#............................#",
	"##############################"
};

//Movement function
bool canMoveTo(int newX, int newY)
{
	// Check that the coordinates are inside the map
	if (newX < 0 || newX >= width || newY < 0 || newY >= height)
	{
		return false;
	}

	// The player cannot move through walls
	return map[newY][newX] != '#';
}


void Setup()
{
	gameOver = false;
	dir = STOP;

	x = 2;
	y = 2;

	score = 0;
}

void Draw()
{
	system("cls");
	
	for (int row = 0; row < height; row++)
	{
		for (int column = 0;column < width; column++)
		{
			if (column == x && row == y)
				std::cout << '@';
			else std::cout << map[row][column];
		}

		std::cout << '\n';
	}
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}

}

void Logic()
{
	int newX = x;
	int newY = y;

	switch (dir)
	{
	case LEFT:
		newX--;
		break;
	case RIGHT:
		newX++;
		break;
	case UP:
		newY--;
		break;
	case DOWN:
		newY++;
		break;
	case STOP:
	default:
		break;
	}

	if (canMoveTo(newX, newY))
	{
		x = newX;
		y = newY;
	}

	dir = STOP;

}




int main()
{

	Setup();

	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(50);
	}
	
	system("cls");
	std::cout << "Game Over!\n";

	return 0;
}
