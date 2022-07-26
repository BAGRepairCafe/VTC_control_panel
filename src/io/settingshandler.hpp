#ifndef SETTINGSHANDLER_HPP
#define SETTINGSHANDLER_HPP

#include "../../libs/json.hpp"
#include "../model/cubesurfaceinfo.hpp"

using json = nlohmann::json;

class SettingsHandler
{
    static SettingsHandler instance;

    json settings_json;

    SettingsHandler();
    ~SettingsHandler();
public:
    static SettingsHandler& getInstance();

    void create_new_settings_file();
    void set_default_settings();
    void write_settings_to_file();
    void set_username(std::string username);
    [[nodiscard]] std::string get_username();
    void set_save_username(bool save_username);
    [[nodiscard]] bool get_save_username();
    void set_surface_info(unsigned long num, CubeSurfaceInfo surface_infos);
    void set_surface_infos(const std::vector<CubeSurfaceInfo>& surface_infos);
    std::vector<CubeSurfaceInfo> get_surface_infos();
};

#endif // SETTINGSHANDLER_HPP
