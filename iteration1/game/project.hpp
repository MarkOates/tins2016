


class Project : public FGUIScreen
{
public:
  WorldRenderScreen *world_render;
  WorldNavigationGUIScreen *world_navigation_gui;
  InventoryGUIScreen *inventory_gui;
  StartScreenGUIScreen *start_screen_gui;

  Project(Display *display)
    : FGUIScreen(display)
    , world_render(new WorldRenderScreen(display))
    , world_navigation_gui(new WorldNavigationGUIScreen(this, display))
    , inventory_gui(new InventoryGUIScreen(display))
    , start_screen_gui(new StartScreenGUIScreen(this, display))
  {
    Script::initialize(world_render, world_navigation_gui, inventory_gui, start_screen_gui);
    load_scripts();

    Script::run("StartTitleScreen()");
  }
  void on_message(FGUIWidget *sender, std::string message)
  {
    std::string trigger_id;
    if (TargetID::extract_trigger_id(message, &trigger_id))
    {
      std::cout << "Project running script \"" << trigger_id << "\"" << std::endl;
      Script::run(trigger_id);
    }
  }
  void load_scripts()
  {
    // load the individual scripts
    new StartTitleScreen();
    new StartGame();
  }
};

