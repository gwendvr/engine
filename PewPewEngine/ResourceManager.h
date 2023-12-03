#pragma once
#include <string>
#include <map>
#include <yaml-cpp/yaml.h>

namespace PewPewEngine
{
    class ResourceManager
    {
    public:
        std::string _path;
        std::map<std::string, std::string> _mapPath;

        ResourceManager();
        void init();
        std::string getPathFromID(std::string name);
    };
}

