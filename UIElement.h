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
    BOTTOM_RIGHT,
    BOTTOM_LEFT,
    TOP_RIGHT,
    TOP_LEFT
  };
  ExpandDirection expand_direction;
  // Constructors:
  UIElement(sf::Texture& texture,
            const Region region,
            const sf::Vector2u& region_position,
            const sf::Vector2u& extents,
            const ExpandDirection expand_direction = NONE) :
    region_position_(region_position), extents_(extents) {
    switch(expand_direction) {
    case RIGHT:

    }
  }
private:
  sf::Vector2u region_position_;
  sf::Vector2u extents_;
};
#endif
