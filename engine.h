#include <vector>
#include <SDL.h>
//#include "ioMod.h"
#include "renderContext.h"
//#include "clock.h"
#include "hud.h"
#include "world.h"
#include "viewport.h"
#include "player.h"
#include "multisprite.h"

class Engine {
public:
  Engine ();
  ~Engine ();
  void play();
  void switchSprite();

private:
  const RenderContext* rc;
  const IOmod& io;
  Clock& clock;
  Hud& hud;

  SDL_Renderer * const renderer;
  World mtns;
  World mid;
  World sand;
  Player player;
  MultiSprite dad;
  Viewport& viewport;

  std::vector<Drawable*> sprites;
  std::vector<Player*> playerSprites;

  int currentSprite;
  bool makeVideo;

  void draw() const;
  void update(Uint32);

  Engine(const Engine&) = delete;
  Engine& operator=(const Engine&) = delete;
};
