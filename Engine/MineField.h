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
	public:
		enum class State
		{
			open,
			closed,
			flagged,
			exploded
		
			//State& operator+=(const Vei2& rhs);
		};
	
		State s=State::closed; //s-state
	
		Vei2 pos;
		RectI GetRect();
		bool hasMine = false;
		void SetState(State in_s);
		bool StateEq(State in_s);

	};
	const static int numberoftiles = 20;
public:
	void InitTiles();
	Tile tiles[numberoftiles][numberoftiles];
	void Draw(Graphics& gfx);
	RectI r = RectI(0, numberoftiles * SpriteCodex::tileSize, 0, numberoftiles * SpriteCodex::tileSize);
	void PlaceMines(int number);
};

