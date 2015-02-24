/* UIElement.cc
 * mszegedy, 2015
 *
 * This work is licensed under the Creative Commons Attribution 4.0
 * International License. To view a copy of this license, visit
 * http://creativecommons.org/licenses/by/4.0/ or send a letter to Creative
 * Commons, PO Box 1866, Mountain View, CA 94042, USA.
 *
 * A class to contain a sprite that makes up the UI.
 */

#include "UIElement.h"

void resize_to_window(sf::RenderWindow window) {
  if (this->expand_direction == RIGHT ||
      this->expand_direction == DOWN_RIGHT ||
      this->expand_direction == UP_RIGHT)
    this->setTextureRect(sf::IntRect(0,
                                     0,
                                     window.getSize().x-this->getPosition().x,
                                     this->extents_.y));
  if (this->expand_direction == LEFT ||
      this->expand_direction == DOWN_LEFT ||
      this->expand_direction == UP_LEFT)
    this->setTextureRect(sf::IntRect(0,
                                     0,
                                     -(window.getSize().x-this->getPosition().x),
                                     this->extents_.y));
  if (this->expand_direction == DOWN ||
      this->expand_direction == DOWN_RIGHT ||
      this->expand_direction == DOWN_LEFT)
    this->setTextureRect(sf::IntRect(0,
                                     0,
                                     this->extents_.x,
                                     window.getSize().y-this->getPosition().y));
  }
  if (this->expand_direction == UP ||
      this->expand_direction == UP_RIGHT ||
      this->expand_direction == UP_LEFT)
    this->setTextureRect(sf::IntRect(0,
                                     0,
                                     this->extents_.x,
                                     -(window.getSize().y-this->getPosition().y)));
  }
}
