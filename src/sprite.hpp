#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class Game
{
    public:
                     Game();
      void           run();

    private:
      void           processEvents();
      void           update();
      void           render();

    private:
      sf::RenderWindow     mWindow;
      sf::Texture          mTexture;
//    sf::CircleShape  mPlayer;

};
