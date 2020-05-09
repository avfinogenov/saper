#pragma once
#include "Vei2.h"
#include "SpriteCodex.h"
#include "RectI.h"
#include "Graphics.h"
#include <random>
class MineField
{
	class Tile
	{
		enum class State
		{
			open,
			closed,
			flagged,
			exploded

		};
	public:
		State s;
	
		Vei2 pos;
		RectI GetRect();
		bool hasMine = false;


	};
	const static int numberoftiles = 10;
public:
	void InitTiles();
	Tile tiles[numberoftiles][numberoftiles];
	void Draw(Graphics& gfx);
	RectI r = RectI(0, numberoftiles * SpriteCodex::tileSize, 0, numberoftiles * SpriteCodex::tileSize);
	void PlaceMines();
};

