/* UIElement.h
 * mszegedy, 2015
 *
 * This work is licensed under the Creative Commons Attribution 4.0
 * International License. To view a copy of this license, visit
 * http://creativecommons.org/licenses/by/4.0/ or send a letter to Creative
 * Commons, PO Box 1866, Mountain View, CA 94042, USA.
 *
 * A class to contain a sprite that makes up the UI.
 */

// SFML libraries (these better have include guards or something)
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#ifndef UIELEMENT_H_
#define UIELEMENT_H_
class UIElement : public sf::Sprite {
public:
  // Variables:
  enum Region {
    HEADER,
    BOX,
    BUTTONS,
    SIDEBAR
  };
  Region region;
  enum ExpandDirection {
    NONE,
    RIGHT,
    LEFT,
    DOWN,
    UP,
    DOWN_RIGHT,
    DOWN_LEFT,
    UP_RIGHT,
    UP_LEFT
  };
  ExpandDirection expand_direction;
  // Methods:
  void resize_to_window(sf::RenderWindow& window);
  // Constructors:
  UIElement(const Region region,
            sf::Texture& texture,
            const sf::Vector2<int>& region_position,
            const sf::Vector2<int>& extents,
            const ExpandDirection expand_direction) :
    region_position_(region_position), extents_(extents) {
    this->setTexture(texture);
  }
  UIElement(const Region region,
            sf::Texture& texture,
            const sf::Vector2<int>& region_position) :
    UIElement(region, texture, region_position, sf::Vector2<int>(0, 0), NONE) {}
private:
  sf::Vector2<int> region_position_;
  sf::Vector2<int> extents_;
};
#endif
