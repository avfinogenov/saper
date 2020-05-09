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
				SpriteCodex::DrawTile0(tiles[i][j].pos, gfx);
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

void MineField::Tile::SetState(State in_s)
{
	s = in_s;
}

bool MineField::Tile::StateEq(State in_s)
{
	
	return s == in_s;
}
