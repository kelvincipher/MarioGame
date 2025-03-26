//#include "Mario.h"
//#include "Defs.h"
//
//#include <SDL.h>
//
//#define GRAVITY_ACCEL 5.0
//
//Mario::Mario(SDL_Renderer* renderer, Vector2D pos)
//	: texture{ renderer }, isDead{ false }, pos{ pos }, radius{ 0.0 }, speedX{ 0.0 }, speedY{ 0.0 }, accelY{0.3}
//{
//	texture.loadFromFile(IMG_MARIO);
//	radius = texture.getWidth() / 2;
//}
//
//void Mario::make_jump()
//{
//	if (speedY > 0) speedY = -GRAVITY_ACCEL;
//	else speedY -= GRAVITY_ACCEL;
//}
//
//void Mario::apply_forces()
//{
//	speedY += accelY;
//	pos.y = speedY;
//}
//
//void Mario::move()
//{
//	pos.x += speedX;
//}
//
//void Mario::render()
//{
//	texture.render(static_cast<int>(pos.x - radius), static_cast<int>(pos.y - radius), nullptr, 0.0);
//}