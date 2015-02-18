#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(1024, 682), "Garden", sf::Style::Fullscreen);
  window.setVerticalSyncEnabled(true);

  // load border textures
  sf::Texture vertical_border_4px;
  vertical_border_4px.loadFromFile("data/gfx/ui/vert-border-4-tileable.png");
  vertical_border_4px.setRepeated(true);

  // load button frame and mask textures
  sf::Texture button_frame;
  button_frame.loadFromFile("data/gfx/ui/buttons-frame-48.png");
  sf::Texture button_mask;
  button_mask.loadFromFile("data/gfx/ui/buttons-mask-48.png");

  // load header bg
  sf::Texture header_bg;
  header_bg.loadFromFile("data/gfx/ui/header-bg-32-tileable.png");
  header_bg.setRepeated(true);
  sf::Sprite header_bg_sprite;
  header_bg_sprite.setTexture(header_bg);
  header_bg_sprite.setTextureRect(sf::IntRect(0, 0, window.getSize().x, 32));

  // load header border
  sf::Texture header_border;
  header_border.loadFromFile("data/gfx/ui/header-border-6-tileable.png");
  header_border.setRepeated(true);
  sf::Sprite header_border_sprite;
  header_border_sprite.setTexture(header_border);
  header_border_sprite.setTextureRect(sf::IntRect(0, 0, window.getSize().x, 6));
  header_border_sprite.setPosition(0, 32);

  // load box bg
  sf::Texture box_bg;
  box_bg.loadFromFile("data/gfx/ui/box-122.png");
  sf::Sprite box_bg_sprite;
  box_bg_sprite.setTexture(box_bg);
  box_bg_sprite.setPosition(0, 32);

  // load buttons bg
  sf::Texture buttons_bg;
  buttons_bg.loadFromFile("data/gfx/ui/buttons-bg-48-tileable.png");
  buttons_bg.setRepeated(true);
  sf::Sprite buttons_bg_sprite;
  buttons_bg_sprite.setTexture(buttons_bg);
  buttons_bg_sprite.setTextureRect(sf::IntRect(0, 0, 48, window.getSize().y-154));
  buttons_bg_sprite.setPosition(0, 154);

  // load buttons border
  sf::Sprite buttons_border_sprite;
  buttons_border_sprite.setTexture(vertical_border_4px);
  buttons_border_sprite.setTextureRect(sf::IntRect(0, 0, 4, window.getSize().y-154));
  buttons_border_sprite.setPosition(48, 154);

  // load admin button frame
  sf::Sprite admin_button_frame_sprite;
  admin_button_frame_sprite.setTexture(button_frame);
  admin_button_frame_sprite.setPosition(0,154);

  // load admin button
  sf::Texture admin_button_unpressed;
  admin_button_unpressed.loadFromFile("data/gfx/ui/admin-button-48.png");
  sf::Texture admin_button_pressed;
  admin_button_pressed.loadFromFile("data/gfx/ui/admin-button-pressed-48.png");
  sf::Sprite admin_button_sprite;
  admin_button_sprite.setTexture(admin_button_unpressed);
  admin_button_sprite.setPosition(0, 154);

  // load admin button icon
  sf::Texture admin_button_icon;
  admin_button_icon.loadFromFile("data/gfx/ui/admin-icon-32.png");
  sf::Sprite admin_button_icon_sprite;
  admin_button_icon_sprite.setTexture(admin_button_icon);
  admin_button_icon_sprite.setPosition(0+8, 154+8);
  bool admin_button_is_pressed = false;

  // load button mask sprite
  sf::Sprite button_mask_sprite;
  button_mask_sprite.setTexture(button_mask);
  button_mask_sprite.setColor(sf::Color(255, 255, 255, 64));
  bool button_mask_sprite_drawn = false;

  // load sidebar bg
  sf::Texture sidebar_bg_admin;
  sidebar_bg_admin.loadFromFile("data/gfx/ui/sidebar-bg-admin-256-tileable.png");
  sidebar_bg_admin.setRepeated(true);
  sf::Sprite sidebar_bg_sprite;
  sidebar_bg_sprite.setTextureRect(sf::IntRect(0, 0, 256, window.getSize().y-38));
  sidebar_bg_sprite.setPosition(window.getSize().x+4,38);

  // load sidebar border
  sf::Sprite sidebar_border_sprite;
  sidebar_border_sprite.setTexture(vertical_border_4px);
  sidebar_border_sprite.setTextureRect(sf::IntRect(0, 0, 4, window.getSize().y-38));
  sidebar_border_sprite.setPosition(window.getSize().x+4,38);

  // extra sidebar stuff
  bool sidebar_is_out = false;
  sf::Clock sidebar_toggled_clock;
  const sf::Time sidebar_animation_time = sf::milliseconds(400);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
      if (event.type == sf::Event::Resized) {
        sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
        window.setView(sf::View(visibleArea));
        header_bg_sprite.setTextureRect(sf::IntRect(0, 0, event.size.width, 32));
        header_border_sprite.setTextureRect(sf::IntRect(0, 0, event.size.width, 6));
        buttons_bg_sprite.setTextureRect(sf::IntRect(0, 0, 48, event.size.height-154));
        buttons_border_sprite.setTextureRect(sf::IntRect(0, 0, 4, event.size.height-154));
      }
      if (event.type == sf::Event::MouseMoved) {
        int x = event.mouseMove.x;
        int y = event.mouseMove.y;
        if ((0 <= x && x < (0+48)) && (154 <= y && y < (154+48))) {
          button_mask_sprite_drawn = true;
          button_mask_sprite.setPosition(0, 154);
        }
        else {
          button_mask_sprite_drawn = false;
        }
      }
      if (event.type == sf::Event::MouseButtonPressed) {
        int x = event.mouseButton.x;
        int y = event.mouseButton.y;
        if (event.mouseButton.button == sf::Mouse::Left) {
          if ((0 <= x && x < (0+48)) && (154 <= y && y < (154+48))) {
            admin_button_sprite.setTexture(admin_button_pressed);
            admin_button_is_pressed = true;
          }
        }
      }
      if (event.type == sf::Event::MouseButtonReleased) {
        int x = event.mouseButton.x;
        int y = event.mouseButton.y;
        if (event.mouseButton.button == sf::Mouse::Left) {
          if (admin_button_is_pressed) {
            admin_button_sprite.setTexture(admin_button_unpressed);
            admin_button_is_pressed = false;
            if ((0 <= x && x < (0+48)) && (154 <= y && y < (154+48))) {
              sidebar_bg_sprite.setTexture(sidebar_bg_admin);
              sidebar_is_out = !sidebar_is_out;
              sidebar_toggled_clock.restart();
            }
          }
        }
      }
    }

    // take care of sidebar
    if (sidebar_is_out && \
        sidebar_border_sprite.getPosition().x > (window.getSize().x-260)) {
      sidebar_border_sprite.setPosition(window.getSize().x- \
                                        (260*sidebar_toggled_clock.getElapsedTime().asMilliseconds()/ \
                                         sidebar_animation_time.asMilliseconds()),
                                        38);
      sidebar_bg_sprite.setPosition(window.getSize().x+4- \
                                    (260*sidebar_toggled_clock.getElapsedTime().asMilliseconds()/ \
                                     sidebar_animation_time.asMilliseconds()),
                                    38);
    }
    if (!sidebar_is_out && \
        sidebar_border_sprite.getPosition().x < (window.getSize().x)) {
      sidebar_border_sprite.setPosition(window.getSize().x-260+ \
                                        (260*sidebar_toggled_clock.getElapsedTime().asMilliseconds()/ \
                                         sidebar_animation_time.asMilliseconds()),
                                        38);
      sidebar_bg_sprite.setPosition(window.getSize().x-260+4+ \
                                    (260*sidebar_toggled_clock.getElapsedTime().asMilliseconds()/ \
                                     sidebar_animation_time.asMilliseconds()),
                                    38);
    }

    window.clear();
    window.draw(header_bg_sprite);
    window.draw(header_border_sprite);
    window.draw(box_bg_sprite);
    window.draw(buttons_bg_sprite);
    window.draw(buttons_border_sprite);
    window.draw(admin_button_frame_sprite);
    window.draw(admin_button_sprite);
    window.draw(admin_button_icon_sprite);
    if (button_mask_sprite_drawn)
      window.draw(button_mask_sprite);
    window.draw(sidebar_bg_sprite);
    window.draw(sidebar_border_sprite);
    window.display();
  }

  return 0;
}
