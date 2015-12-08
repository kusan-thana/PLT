#include "render.h"

namespace sflib {

  /// class SFMLSurface - 
  class SFMLSurface : public Surface {
    // Attributes
  public:
    sf::VertexArray vertices;
    sf::Texture tileset;
    // Operations
  public:
    void clear ();
    void loadTexture (const char* tileset);
    void setSpriteCount (int n);
    void setSpriteLocation (int i, int x, int y);
    void setSpriteTexture (int i, const StaticTile* staticTile);
  private:
    void const draw (sf::RenderTarget& target, RenderStates states);
  };

};

