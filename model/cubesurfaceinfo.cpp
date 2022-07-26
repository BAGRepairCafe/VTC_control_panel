#include "cubesurfaceinfo.hpp"

CubeSurfaceInfo CubeSurfaceInfo::fromJson(json json) {
    return {
        .project_id = json["project_id"].get<int>(),
        .project_title = QString{json["project_title"].get<std::string>().c_str()},
        .phase_id = json["phase_id"].get<int>(),
        .phase_title = QString{json["phase_title"].get<std::string>().c_str()},
        .activity_id = json["activity_id"].get<int>(),
        .activity_title = QString{json["activity_title"].get<std::string>().c_str()},
        .location = QString{json["location"].get<std::string>().c_str()},
        .description = QString{json["description"].get<std::string>().c_str()},
        .duration = QTime::fromString(QString{json["project_title"].get<std::string>().c_str()},"hh:mm")
    };
}

json CubeSurfaceInfo::toJson() const {
    return json{
        {"project_id", this->project_id},
        {"project_title", this->project_title.toStdString()},
        {"phase_id", this->phase_id},
        {"phase_title", this->phase_title.toStdString()},
        {"activity_id", this->activity_id},
        {"activity_title", this->activity_title.toStdString()},
        {"location", this->location.toStdString()},
        {"description", this->description.toStdString()},
        {"duration", this->duration.toString().toStdString()}
    };
}
