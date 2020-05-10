#include "MineField.h"
#include <algorithm>

void MineField::InitTiles()
{
	for (int i = 0; i < numberoftiles; i++) 
	{
		for (int j = 0; j < numberoftiles; j++)
		{
			tiles[i][j].pos = Vei2((j * SpriteCodex::tileSize), (i * SpriteCodex::tileSize));
			
		}
	}
	PlaceMines(10);
	for (int i = 0; i < numberoftiles; i++) 
	{
		for (int j = 0; j < numberoftiles; j++)
		{
			CountSurBombs(Vei2(i,j));
			//if (i == numberoftiles - 1)
			//{
			//	int tmp = 0;
			//	tmp++;
			//}
		}
	}

	////tmp
	//int count = 10;
	//std::random_device rd;
	//std::mt19937 rng(rd());
	//std::uniform_int_distribution<int> place(0, numberoftiles * numberoftiles);
	//
	//while (count > 0)
	//{
	//	int randomnumber = place(rng);
	//	int Xrand, Yrand;
	//	Yrand = randomnumber / numberoftiles;
	//	Xrand = randomnumber - Yrand * numberoftiles;
	//	if (tiles[Xrand][Yrand].s==Tile::State::closed)
	//	{
	//		tiles[Xrand][Yrand].s = Tile::State::open;
	//		count--;
	//	}
	//
	//}
}

void MineField::Draw(Graphics& gfx)
{
	
	for (int i = 0; i < numberoftiles; i++)
	{
		for (int j = 0; j < numberoftiles; j++)
		{
			switch (tiles[i][j].s)
			{
			case (Tile::State::open):
				if (tiles[i][j].hasMine)
				{
					//SpriteCodex::DrawTile0(tiles[i][j].pos, gfx);
					SpriteCodex::DrawTileBombRed(tiles[i][j].pos, gfx);
					GameOver = true;
				}
				else
				{
					//SpriteCodex::DrawTile0(tiles[i][j].pos, gfx);
					switch (tiles[i][j].bombcountsur)
					{
					case 0:
						SpriteCodex::DrawTile0(tiles[i][j].pos, gfx);
						break;
					case 1:
						SpriteCodex::DrawTile1(tiles[i][j].pos, gfx);
						break;
					case 2:
						SpriteCodex::DrawTile2(tiles[i][j].pos, gfx);
						break;
					case 3:
						SpriteCodex::DrawTile3(tiles[i][j].pos, gfx);
						break;
					case 4:
						SpriteCodex::DrawTile4(tiles[i][j].pos, gfx);
						break;
					case 5:
						SpriteCodex::DrawTile5(tiles[i][j].pos, gfx);
						break;
					case 6:
						SpriteCodex::DrawTile6(tiles[i][j].pos, gfx);
						break;
					case 7:
						SpriteCodex::DrawTile7(tiles[i][j].pos, gfx);
						break;
					case 8:
						SpriteCodex::DrawTile8(tiles[i][j].pos, gfx);
						break;
					
					}
				}
				break;

			case (Tile::State::closed):
				if (!GameOver)
				{
					SpriteCodex::DrawTileButton(tiles[i][j].pos, gfx);
				}
				else
				{
					if (tiles[i][j].hasMine)
					{
						SpriteCodex::DrawTileBomb(tiles[i][j].pos, gfx);
					}
					else
					{
						SpriteCodex::DrawTileButton(tiles[i][j].pos, gfx);
					}
					
				}
				break;
			case (Tile::State::flagged):
				if (!GameOver)
				{
					SpriteCodex::DrawTileButton(tiles[i][j].pos, gfx);
					SpriteCodex::DrawTileFlag(tiles[i][j].pos, gfx);
				}
				else
				{
					if (!tiles[i][j].hasMine)
					{
						SpriteCodex::DrawTileCross(tiles[i][j].pos, gfx);
					}
					else
					{
						SpriteCodex::DrawTileFlag(tiles[i][j].pos, gfx);
					}
				}
				break;
			}
			
		}

	}
}

void MineField::PlaceMines(int number)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> place(0, numberoftiles * numberoftiles);

	while (number > 0)
	{
		int randomnumber = place(rng);
		int Xrand, Yrand;
		Yrand = randomnumber / numberoftiles;
		Xrand = randomnumber - Yrand * numberoftiles;
		if (!tiles[Xrand][Yrand].hasMine)
		{
			tiles[Xrand][Yrand].hasMine = true;
			number--;
		}

	}
}

void MineField::Update(Mouse& in_mouse)
{
	Vei2 tmp = in_mouse.GetPos();
	tmp = ScreenToGrid(tmp);
	if (in_mouse.LeftIsPressed())
	{
			if (tiles[tmp.x][tmp.y].StateEq(Tile::State::closed))
			{
				if (tiles[tmp.x][tmp.y].bombcountsur == 0)
				{
					OpenSurTiles(tmp.x, tmp.y);
				}
				tiles[tmp.x][tmp.y].SetState(Tile::State::open);
			}
		
	}
	if (in_mouse.RightIsPressed())
	{
		if (tiles[tmp.x][tmp.y].StateEq(Tile::State::closed))
		{
			tiles[tmp.x][tmp.y].SetState(Tile::State::flagged);
		} else
		if (tiles[tmp.x][tmp.y].StateEq(Tile::State::flagged))
		{
			tiles[tmp.x][tmp.y].SetState(Tile::State::closed);
		}

	}
}

Vei2 MineField::ScreenToGrid(Vei2 in_loc_screen)
{

	return in_loc_screen/SpriteCodex::tileSize;
}

void MineField::CountSurBombs(Vei2 loc)
{
	int is = std::max(0, loc.x-1);
	//int js = std::max(0, loc.y-1);
	int ie = std::min(numberoftiles-1, loc.x+1);
	int je = std::min(numberoftiles-1, loc.y + 1);
	for (; is <= ie; is++)
	{
		for (int js = std::max(0, loc.y - 1); js <= je; js++)
		{
			if (tiles[is][js].hasMine)
				tiles[loc.x][loc.y].bombcountsur++;
			
		}
	}

}

void MineField::OpenSurTiles(int i, int j)
{
	int is = std::max(0, i - 1);
	//int js = std::max(0, loc.y-1);
	int ie = std::min(numberoftiles, i + 1);
	int je = std::min(numberoftiles, j + 1);
	for (; is <= ie; is++)
	{
		for (int js = std::max(0, j - 1); js <= je; js++)
		{
			if (tiles[is][js].bombcountsur == 0)
			{
			if (!tiles[is][js].iscounted)
			{
				tiles[is][js].SetState(Tile::State::open);
				tiles[is][js].iscounted = true;
					OpenSurTiles(is, js);
				}
				
			}

		}
	}
}

void MineField::Tile::SetState(State in_s)
{
	s = in_s;
}

bool MineField::Tile::StateEq(State in_s)
{
	
	return s == in_s;
}
