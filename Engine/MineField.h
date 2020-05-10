#pragma once
#include "Vei2.h"
#include "SpriteCodex.h"
#include "RectI.h"
#include "Graphics.h"
#include <random>
#include "Mouse.h"
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
			exploded,
			one,
			two,
			three,
			four,
			five,
			six,
			seven,
			eight,
			nine
			
			//State& operator+=(const Vei2& rhs);
		};
	
		State s=State::closed; //s-state
	
		Vei2 pos;
		RectI GetRect();
		bool hasMine = false;
		void SetState(State in_s);
		bool StateEq(State in_s);
		bool iscounted = false;
		int bombcountsur = 0;
	};
	const static int numberoftiles = 20;
	bool GameOver = false;
public:
	void InitTiles();
	Tile tiles[numberoftiles][numberoftiles];
	void Draw(Graphics& gfx);
	RectI r = RectI(0, numberoftiles * SpriteCodex::tileSize, 0, numberoftiles * SpriteCodex::tileSize);
	void PlaceMines(int number);
	void Update(Mouse& in_mouse);
	Vei2 ScreenToGrid(Vei2 in_loc_screen);
	void CountSurBombs(Vei2 loc);
	void OpenSurTiles(int i, int j);
};

