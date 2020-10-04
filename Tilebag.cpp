#include "iostream"
#include "Tilebag.h"
#include "Types.h"

Tilebag::Tilebag()
{
	tiles = new LinkedList<Tile>();
	Tile pre[] = { TILE_DARK_BLUE, TILE_BLACK, TILE_BLACK, TILE_LIGHT_BLUE, TILE_BLACK, TILE_RED, TILE_YELLOW, TILE_RED, TILE_YELLOW, TILE_LIGHT_BLUE, TILE_YELLOW, TILE_LIGHT_BLUE, TILE_LIGHT_BLUE, TILE_BLACK, TILE_YELLOW, TILE_BLACK, TILE_DARK_BLUE, TILE_YELLOW, TILE_YELLOW, TILE_LIGHT_BLUE, TILE_BLACK, TILE_RED, TILE_LIGHT_BLUE, TILE_DARK_BLUE, TILE_YELLOW, TILE_RED, TILE_RED, TILE_RED, TILE_BLACK, TILE_LIGHT_BLUE, TILE_LIGHT_BLUE, TILE_DARK_BLUE, TILE_RED, TILE_DARK_BLUE, TILE_YELLOW, TILE_RED, TILE_RED, TILE_BLACK, TILE_YELLOW, TILE_RED, TILE_DARK_BLUE, TILE_YELLOW, TILE_LIGHT_BLUE, TILE_DARK_BLUE, TILE_RED, TILE_BLACK, TILE_RED, TILE_RED, TILE_BLACK, TILE_YELLOW, TILE_BLACK, TILE_DARK_BLUE, TILE_DARK_BLUE, TILE_LIGHT_BLUE, TILE_RED, TILE_YELLOW, TILE_YELLOW, TILE_DARK_BLUE, TILE_YELLOW, TILE_LIGHT_BLUE, TILE_RED, TILE_YELLOW, TILE_YELLOW, TILE_DARK_BLUE, TILE_RED, TILE_LIGHT_BLUE, TILE_LIGHT_BLUE, TILE_YELLOW, TILE_BLACK, TILE_DARK_BLUE, TILE_BLACK, TILE_LIGHT_BLUE, TILE_RED, TILE_YELLOW, TILE_YELLOW, TILE_BLACK, TILE_DARK_BLUE, TILE_DARK_BLUE, TILE_LIGHT_BLUE, TILE_DARK_BLUE, TILE_YELLOW, TILE_RED, TILE_DARK_BLUE, TILE_LIGHT_BLUE, TILE_BLACK, TILE_DARK_BLUE, TILE_BLACK, TILE_LIGHT_BLUE, TILE_LIGHT_BLUE, TILE_BLACK, TILE_BLACK, TILE_LIGHT_BLUE, TILE_DARK_BLUE, TILE_LIGHT_BLUE, TILE_RED, TILE_DARK_BLUE, TILE_RED, TILE_BLACK, TILE_DARK_BLUE, TILE_BLACK };
	for (int i = 0; i < 100; i++)
	{
		initialTilebag->push_back(&pre[i]);
		addTile(pre[i]);
	}
}

Tilebag::~Tilebag()
{

}

Tile Tilebag::drawTile()
{
	Tile t = *tiles->begin().get();
	tiles->removeAt(0);
	return t;
}

Tile* Tilebag::drawTiles(int count)
{
	Tile* arr = new Tile[count];
	for (int i = 0; i < count; i++)
	{
		if (tiles->size() == 0)
			return arr;
		arr[i] = *tiles->begin().get();
		tiles->removeAt(0);
	}
	return arr;
}

void Tilebag::addTile(Tile tile)
{
	tiles->push_back(&tile);
}

LinkedList<Tile>* Tilebag::getInitailTilebag()
{
	return initialTilebag;
}

void Tilebag::replaceTilebag(LinkedList<Tile>* newTilebag)
{
	for(int i = 0; i < tiles->size(); ++i)
	{
		tiles->insert(newTilebag->at(i), i);
		initialTilebag[i] = newTilebag[i];
	}
}