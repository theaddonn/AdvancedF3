#include "dllmain.hpp"
#include "F3/F3.hpp"

F3 f3;

ModFunction void Initialize(AmethystContext& ctx)
{
    // Initialize Amethyst mod backend
    Amethyst::InitializeAmethystMod(ctx);
    
    Amethyst::GetEventBus().AddListener<AfterRenderUIEvent>(onRenderUI);
}

void onRenderUI(AfterRenderUIEvent& event)
{
    f3.Render(event.ctx);
}
