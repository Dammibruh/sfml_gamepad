#include <SFML/Graphics.hpp>
#include <vector>
class GamePad
{
  private:
	const sf::RenderWindow &win;

  public:
	float sclX = 50, sclY = 50;
	sf::RectangleShape topRect = sf::RectangleShape(sf::Vector2f(sclX, sclY)),
					   botRect = topRect,
					   leRect = topRect,
					   riRect = topRect;
	GamePad(const sf::RenderWindow &_window)
		: win(_window)
	{
	}
	void setPos(const sf::Vector2f &cord)
	{
		(*this).topRect.setPosition((*this).topRect.getPosition() + cord);
		(*this).riRect.setPosition((*this).riRect.getPosition() + cord);
		(*this).leRect.setPosition((*this).leRect.getPosition() + cord);
		(*this).botRect.setPosition((*this).botRect.getPosition() + cord);
	}
	void adjust()
	{
		auto Px = (*this).topRect.getPosition().x;
		auto Py = (*this).topRect.getPosition().y;
		auto Sx = (*this).sclX;
		auto Sy = (*this).sclY;
		(*this).riRect.setPosition(Px + Sx + 30, Py + Sy + 25);
		(*this).botRect.setPosition(Px, Py + (Sy * 3));
		(*this).leRect.setPosition(Px - Sx - 30, Py + Sy + 25);
	}
	auto topTouch()
	{
		auto pos = sf::Touch::getPosition(0, this->win);
		auto Px = pos.x, Py = pos.y;
		auto _top = sf::Rect(this->topRect.getPosition().x, this->topRect.getPosition().y, this->sclX, this->sclY);
		if (_top.contains(Px, Py))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	auto botTouch()
	{
		auto pos = sf::Touch::getPosition(0, this->win);
		auto Px = pos.x, Py = pos.y;
		auto _bot = sf::Rect(this->botRect.getPosition().x, this->botRect.getPosition().y, this->sclX, this->sclY);
		if (_bot.contains(Px, Py))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	auto leftTouch()
	{
		auto pos = sf::Touch::getPosition(0, this->win);
		auto Px = pos.x, Py = pos.y;
		auto _left = sf::Rect(this->leRect.getPosition().x, this->leRect.getPosition().y, this->sclX, this->sclY);
		if (_left.contains(Px, Py))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	auto rightTouch()
	{
		auto pos = sf::Touch::getPosition(0, this->win);
		auto Px = pos.x, Py = pos.y;
		auto _right = sf::Rect(this->riRect.getPosition().x, this->riRect.getPosition().y, this->sclX * 2, this->sclY * 2);
		if (_right.contains(Px, Py))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	auto getbtns()
	{
		std::vector<sf::RectangleShape> shapes{
			this->topRect, this->botRect, this->leRect, this->riRect};
		return shapes;
	}
};
