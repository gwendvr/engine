#include <tchar.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <algorithm>
#include <filesystem>
#include "ResourceManager.h"

PewPewEngine::ResourceManager::ResourceManager()
{
    init();
}

void PewPewEngine::ResourceManager::init()
{
    //get global path
    TCHAR buffer[MAX_PATH];
    _path = GetModuleFileName(NULL, buffer, sizeof(buffer));
   
    YAML::Node dataConfig = YAML::LoadFile(std::filesystem::path(buffer).parent_path().string() + "/data-config.yaml");
    YAML::Node pathList = dataConfig["res"];

    //revover links in data config
    for (YAML::const_iterator it = pathList.begin(); it != pathList.end(); ++it)
    {
        const YAML::Node& res = *it;

        std::string id = res["ID"].as<std::string>();
        std::string path = std::filesystem::path(buffer).parent_path().string() + "/" + res["path"].as<std::string>();

        _mapPath.insert({ id, path });
    }

    //show map in log
    std::cout << "KEY\tELEMENT\n";
    for (auto itr = _mapPath.begin(); itr != _mapPath.end(); ++itr) {
        std::cout << itr->first
            << '\t' << itr->second << '\n';
    }
}

std::string PewPewEngine::ResourceManager::getPathFromID(std::string id)
{
    return _mapPath[id];
}


