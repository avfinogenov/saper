#pragma once
#include "Vei2.h"
#include "SpriteCodex.h"
#include "RectI.h"
#include "Graphics.h"
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



	};
	const static int numberoftiles = 10;
public:
	void InitTiles();
	Tile tiles[numberoftiles][numberoftiles];
	void Draw(Graphics& gfx);

};

