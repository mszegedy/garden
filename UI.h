/* UIElement.h
 * mszegedy, 2015
 *
 * This work is licensed under the Creative Commons Attribution 4.0
 * International License. To view a copy of this license, visit
 * http://creativecommons.org/licenses/by/4.0/ or send a letter to Creative
 * Commons, PO Box 1866, Mountain View, CA 94042, USA.
 *
 * A singleton that contains the entire UI, and coordinates UI actions.
 */

// SFML libraries (these better have include guards or something)
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#ifndef UI_H_
#define UI_H_
class UI {
public:
  enum SidebarState {
    NONE,
    ADMIN
  };
  SidebarState sidebar_state;
private:
  std::map<std::string, sf::Texture> textures;
  std::list<sf::Sprite> header_bgs_;
  std::list<sf::Sprite> box_bgs_;
  std::list<sf::Sprite> buttons_bgs_;
  std::list<sf::Sprite> sidebar_bgs_;
  std::list<sf::Sprite> header_buttons_;
  std::list<sf::Sprite> box_buttons_;
  std::list<sf::Sprite> buttons_buttons_;
  std::list<sf::Sprite> sidebar_buttons_admin_;
};
#endif
