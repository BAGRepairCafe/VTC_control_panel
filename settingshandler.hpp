#ifndef SETTINGSHANDLER_HPP
#define SETTINGSHANDLER_HPP

#include <json.hpp>
using json = nlohmann::json;

class SettingsHandler
{
    json settings_json;


public:
    SettingsHandler();

    void create_new_settings_json_file();
    void set_default_settings_json();
    void write_settings_json_to_file();
    void set_username(std::string username);
    [[nodiscard]] std::string get_username();
    void set_save_username(bool save_username);
    [[nodiscard]] bool get_save_username();

    ~SettingsHandler();
};

#endif // SETTINGSHANDLER_HPP
