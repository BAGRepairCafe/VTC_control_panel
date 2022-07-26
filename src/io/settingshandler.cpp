#include "settingshandler.hpp"
#include <fstream>
#include <filesystem>

namespace fs = std::__fs::filesystem;

constexpr auto DEFAULT_DEVELOPMENT_PATH = "/Users/timgohlisch/Documents/VTC/VTC_control_panel/assets/settings.json";

SettingsHandler SettingsHandler::instance{};

SettingsHandler::SettingsHandler()
{
    if(!fs::exists(fs::path{DEFAULT_DEVELOPMENT_PATH})){
        this->create_new_settings_file();
    }
    else {
        std::ifstream settings_config(DEFAULT_DEVELOPMENT_PATH);
        if (!settings_config.is_open()) {
            throw std::runtime_error(std::string("Couldn't open existing settings file at ", DEFAULT_DEVELOPMENT_PATH));
        }
        try {
            this->settings_json = json::parse(settings_config);
        }
        catch (json::parse_error& ex)
        {
            this->create_new_settings_file();
        }
    }
}

SettingsHandler& SettingsHandler::getInstance() {
    return SettingsHandler::instance;
}

void SettingsHandler::create_new_settings_file() {
    this->set_default_settings();
    this->write_settings_to_file();
}

void SettingsHandler::set_default_settings() {
    const CubeSurfaceInfo defaultCubeSurfaceInfo = CubeSurfaceInfo{};
    this->settings_json = {
        {"username", ""},
        {"save_username", false},
        {"surface_infos", json::array({
             defaultCubeSurfaceInfo.toJson(),
             defaultCubeSurfaceInfo.toJson(),
             defaultCubeSurfaceInfo.toJson(),
             defaultCubeSurfaceInfo.toJson(),
             defaultCubeSurfaceInfo.toJson(),
         })}
    };
}

void SettingsHandler::write_settings_to_file() {
    std::ofstream output_stream(DEFAULT_DEVELOPMENT_PATH, std::ios::binary);
    if(!output_stream.is_open()) {
        throw std::runtime_error(std::string("Couldn't create new settings file at ", DEFAULT_DEVELOPMENT_PATH));
    }

    output_stream << settings_json;
}

void SettingsHandler::set_username(std::string username) {
    this->settings_json["username"] = username;
}

std::string SettingsHandler::get_username() {
    return this->settings_json["username"].get<std::string>();
}

void SettingsHandler::set_save_username(bool save_username) {
    this->settings_json["save_username"] = save_username;
}

bool SettingsHandler::get_save_username() {
    return this->settings_json["save_username"].get<bool>();
}

void SettingsHandler::set_surface_info(unsigned long num, CubeSurfaceInfo surface_infos) {
    auto infos = get_surface_infos();
    if(infos.size() > num) {
        infos[num] = surface_infos;
        set_surface_infos(infos);
    }
}


void SettingsHandler::set_surface_infos(const std::vector<CubeSurfaceInfo>& surface_infos) {
    std::vector<json> json_representation{5};
    for(const CubeSurfaceInfo& surface_info: surface_infos) {
        json_representation.push_back(surface_info.toJson());
    }
    this->settings_json["surface_infos"] = json_representation;
}

std::vector<CubeSurfaceInfo> SettingsHandler::get_surface_infos() {
    std::vector<CubeSurfaceInfo> surface_infos{5};
    for(json& surface_info: this->settings_json["surface_infos"].get<std::vector<json>>()) {
        surface_infos.push_back(CubeSurfaceInfo::fromJson(surface_info));
    }
    return surface_infos;
}

SettingsHandler::~SettingsHandler() {
    write_settings_to_file();
}
