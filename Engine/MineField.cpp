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
	
}

void MineField::Draw(Graphics& gfx)
{
	
	for (int i = 0; i < numberoftiles; i++)
	{
		for (int j = 0; j < numberoftiles; j++)
		{
			SpriteCodex::DrawTileButton(tiles[i][j].pos, gfx);
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
