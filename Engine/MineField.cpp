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

void MineField::PlaceMines()
{

}
