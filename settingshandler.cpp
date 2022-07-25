#include "settingshandler.hpp"
#include <fstream>
#include <iostream>
#include <filesystem>

namespace fs = std::__fs::filesystem;

constexpr auto DEFAULT_DEVELOPMENT_PATH = "/Users/timgohlisch/Documents/VTC/VTC_control_panel/assets/settings.json";

SettingsHandler::SettingsHandler()
{
    if(!fs::exists(fs::path{DEFAULT_DEVELOPMENT_PATH})){
        this->create_new_settings_json_file();
    }
    else {
        std::ifstream settings_config(DEFAULT_DEVELOPMENT_PATH);
        if (!settings_config.is_open()) {
            std::cerr << "Couldn't open file " << DEFAULT_DEVELOPMENT_PATH << std::endl;
            abort();
        }
        try {
            this->settings_json = json::parse(settings_config);
        }
        catch (json::parse_error& ex)
        {
            this->create_new_settings_json_file();
        }
    }

    std::cout << this->settings_json << std::endl;
}

void SettingsHandler::create_new_settings_json_file() {
    this->set_default_settings_json();
    this->write_settings_json_to_file();
}

void SettingsHandler::set_default_settings_json() {
    this->settings_json = {
        {"username", nullptr},
        {"save_username", false},
    };
}



void SettingsHandler::write_settings_json_to_file() {
    std::ofstream output_stream(DEFAULT_DEVELOPMENT_PATH, std::ios::binary);
    if(!output_stream.is_open()) {
        throw std::runtime_error(std::string("Couldn't create new settings file at ", DEFAULT_DEVELOPMENT_PATH));
    }

    output_stream << settings_json;
}

SettingsHandler::~SettingsHandler() {
    write_settings_json_to_file();
}
