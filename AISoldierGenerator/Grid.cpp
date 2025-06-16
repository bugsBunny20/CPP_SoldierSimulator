#include <string>
#include "Grid.h"
#include "SoldierObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Grid::Grid(int x, int y)
{
	sizeX = x;
	sizeY = y;
	grid = new std::string * [x];

	for (int i = 0; i < x; i++)
	{
		grid[i] = new std::string[y];
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			grid[i][j] = "_";
		}
	}

	_windowSizeScale = 15;
	_battleField.create(sf::VideoMode(sizeX* _windowSizeScale, sizeY* _windowSizeScale), "Battlefield Rivals");
	_battleField.setFramerateLimit(60);

	createGrid();
}

void Grid::createGrid()
{
	_battleField.clear(sf::Color::Black);
	cellWidth = _battleField.getSize().x / sizeX;

	for (int x = 0; x <= sizeX; x++)
	{
		for (int y = sizeY; y >= 0; y--)
		{
			sf::RectangleShape* cell = new sf::RectangleShape(sf::Vector2f(cellWidth - 1.f, cellWidth - 1.f));
			cell->setFillColor(sf::Color::White);
			cell->setPosition(static_cast<float>(x * cellWidth), static_cast<float>(y * cellWidth));
			_battleField.draw(*cell);
		}
	}
	_battleField.display();
}

void Grid::moveSoldier(Soldier* soldier, Direction direction)
{

}

bool Grid::setSoldierOnGrid(int x, int y, Soldier * soldier)
{
	if (grid[x][y] == "_")
	{
		grid[x][y] = "S";
		
		soldier->SetPosition(x, y);
		
		return true;
	}
	else 
	{
		return false;
	}
}

void Grid::loopGrid()
{
	while (_battleField.isOpen())
	{
		sf::Event event;
		while (_battleField.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_battleField.close();
		}

		_battleField.clear();
		cellWidth = _battleField.getSize().x / sizeX;
		for (int x = 0; x <= sizeX; x++)
		{
			for (int y = sizeY; y >= 0; y--)
			{
				sf::RectangleShape* cell = new sf::RectangleShape(sf::Vector2f(cellWidth - 1.f, cellWidth - 1.f));
				cell->setFillColor(sf::Color::White);
				cell->setPosition(static_cast<float>(x * cellWidth), static_cast<float>(y * cellWidth));
				_battleField.draw(*cell);

				//_gridCells.insert({ Position(x,y), cell });
			}
		}
		_battleField.display();
	}
}

void Grid::setGridCellColor(sf::Color, int x, int y)
{
	//_battleField.ce
}

bool Grid::SetProps(int x, int y, Props* props)
{
	if (grid[x][y] == "_" && grid[x][y] != "S")
	{
		grid[x][y] = "P";

		props->SetPosition(x, y);

		return true;
	}
	else
	{
		return false;
	}
}

Grid::~Grid()
{
	for (int i = 0; i < sizeX; i++)
	{
		delete[] grid[i];
	}

	delete[] grid;
}

int Grid::getSizeX()
{
	return sizeX-1;
}



int Grid::getSizeY()
{
	return sizeY-1;
}


