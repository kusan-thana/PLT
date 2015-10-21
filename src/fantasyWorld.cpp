#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "sfmlsurface.hpp"
#include "surface.hpp"
#include "statictile.hpp"
#include "layer.hpp"
#include "scene.hpp"
#include "tileset.hpp"
#include "client.hpp"
#include "sfmlclient.hpp"

using namespace std;

int main()
{

    Client* client = new SFMLClient();

	client->run();
	
    return 0;
}
