#include "Engine.h"

void Engine::update(float& dtAsSeconds)
{
    _player.update(dtAsSeconds);
    _enemy.update(dtAsSeconds);

}
