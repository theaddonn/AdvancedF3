#include "dllmain.hpp"
#include "F3/F3.hpp"

F3* f3;

ModFunction void Initialize(AmethystContext& ctx)
{
    // Initialize Amethyst mod backend
    Amethyst::InitializeAmethystMod(ctx);
    
    Amethyst::GetEventBus().AddListener<AfterRenderUIEvent>(onRenderUI);

    f3 = new F3;
}

void onRenderUI(AfterRenderUIEvent& event)
{
    if (f3 != nullptr) {
        f3->Render(event.ctx);
    }
}
