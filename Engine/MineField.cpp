#include "MineField.h"

void MineField::InitTiles()
{
	for (int i = 0; i < numberoftiles; i++) //устанавливает позицию €чейки в центр
	{
		for (int j = 0; j < numberoftiles; j++)
		{
			tiles[i][j].pos = Vei2((j * SpriteCodex::tileSize), (i * SpriteCodex::tileSize));
			
		}
	}
	PlaceMines(10);


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
					SpriteCodex::DrawTileBomb(tiles[i][j].pos, gfx);
				}
				else
				{
					SpriteCodex::DrawTile0(tiles[i][j].pos, gfx);
				}
				break;

			case (Tile::State::closed):
				SpriteCodex::DrawTileButton(tiles[i][j].pos, gfx);
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

	if (in_mouse.LeftIsPressed())
	{
		Vei2 tmp = in_mouse.GetPos();
		tmp = ScreenToGrid(tmp);
		
			if (tiles[tmp.x][tmp.y].StateEq(Tile::State::closed))
			{
				tiles[tmp.x][tmp.y].SetState(Tile::State::open);
			}
		
		
	}
}

Vei2 MineField::ScreenToGrid(Vei2 in_loc_screen)
{

	return in_loc_screen/SpriteCodex::tileSize;
}

void MineField::Tile::SetState(State in_s)
{
	s = in_s;
}

bool MineField::Tile::StateEq(State in_s)
{
	
	return s == in_s;
}
