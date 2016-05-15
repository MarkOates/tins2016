


class Script : public ElementID
{
private:
  static ElementIDManager *manager;
  static bool initialized;

public:
  static Script *find_by_id(std::string id)
  {
    ElementID *element = manager->get_element_by_id(id);
    if (element) return static_cast<Script *>(element);
    return NULL;
  }
  static bool run(std::string id)
  {
    Script *script = find_by_id(id);
    if (!script)
    {
      if (Logging::at_least(L_ERRORS))
        std::cout
          << CONSOLE_COLOR_RED
          << "Could not run script: Script \"" << id << "\" not foud."
          << CONSOLE_COLOR_DEFAULT
          << std::endl;

      return false;
    }
    std::cout << "{{{ Activating script \"" << script->get_id() << "\"" << std::endl;
    script->activate();
    std::cout << "}}} Script \"" << script->get_id() << "\" finished" << std::endl;
    return true;
  }
  static void initialize()
  {
    if (initialized) return;
    manager = new ElementIDManager();
    initialized = true;
  }

  Script(std::string id) : ElementID(manager)
  {
    set_id(id);
  }
  virtual void activate() = 0;
};
ElementIDManager *Script::manager = NULL;
bool Script::initialized = false;


