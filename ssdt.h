#pragma once
#include <map>

#include "ssdt/ssdt_win10_20h1.h"

#define GetSSDTIndex(ntsym, buildver) GetSSDTMap(ntsym).get(buildver)

#define GetSSDTMap(ntsym) SSDTMap({             \
    { 19041, SSDT_Index::Win10_20H1::ntsym },   \
})

#define IsBuildVerSupported(buildver) (GetSSDTMap(NtOpenFile).count(buildver) != 0)


class SSDTMap : public std::map<int,int>
{
public:
    SSDTMap(std::map<int, int>&& data) : std::map<int, int>(data) {};

    /// <summary>
    /// Get SSDT index of given buildver
    /// </summary>
    /// <param name="buildver"> 19041 for example </param>
    /// <param name="default_value"> default value to return if not found </param>
    /// <returns></returns>
    int get(int buildver, int default_value = -1)
    {
        auto it = find(buildver);
        return it != end() ? it->second : default_value;
    };
};
