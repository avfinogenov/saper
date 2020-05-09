#include "MineField.h"

void MineField::InitTiles()
{
	for (int i = 0; i < numberoftiles; i++) //устанавливает позицию €чейки в центр
	{
		for (int j = 0; j < numberoftiles; j++)
		{
			tiles[i][j].pos = Vei2((j * SpriteCodex::tileSize+SpriteCodex::tileSize/2), (i * SpriteCodex::tileSize+SpriteCodex::tileSize/2));
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
