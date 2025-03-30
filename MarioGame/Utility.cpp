#include "Utility.h"

bool checkCollision(const SDL_Rect& marioRect, const SDL_Rect& coinRect)
{
	// Sides of Rect
	int leftMario, leftCoin;
	int rightMario, rightCoin;
	int topMario, topCoin;
	int bottomMario, bottomCoin;

	// Calculate Mario's sides
	leftMario = marioRect.x;
	rightMario = marioRect.x + marioRect.w;
	topMario = marioRect.y;
	bottomMario = marioRect.y + marioRect.h;

	// Calculate coin's sides
	leftCoin = coinRect.x;
	rightCoin = coinRect.x + coinRect.w;
	topCoin = coinRect.y;
	bottomCoin = coinRect.y + coinRect.h;

	if (bottomMario <= topCoin) return false;
	if (topMario >= bottomCoin) return false;
	if (rightMario <= leftCoin) return false;
	if (leftMario >= rightCoin) return false;
	return true;
}

std::string convertIntToString(int num)
{
	std::string convertedString = "";
	if (num == 0) return "0";
	while (num > 0)
	{
		convertedString += (char)('0' + (num % 10));
		num /= 10;
	}
	reverse(convertedString.begin(), convertedString.end());
	return convertedString;

}