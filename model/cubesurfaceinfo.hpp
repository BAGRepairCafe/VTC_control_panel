#ifndef CUBESURFACEINFO_HPP
#define CUBESURFACEINFO_HPP

#include <stdint.h>
#include <QString>
#include <QTime>
#include <string>
#include <json.hpp>
using json = nlohmann::json;

struct CubeSurfaceInfo
{
    int64_t project_id;
    QString project_title;
    int64_t phase_id;
    QString phase_title;
    int64_t activity_id;
    QString activity_title;
    QString location;
    QString description;
    QTime duration;

    json toJson() const;
    static CubeSurfaceInfo fromJson(json json);
};


#endif // CUBESURFACEINFO_HPP
