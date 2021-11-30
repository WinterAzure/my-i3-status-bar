#include "globals.hxx"

#pragma once

#define MODULE const g_data_st* (*) (void)

#include "modules/network.hxx"
#include "modules/disk.hxx"
#include "modules/battery.hxx"
#include "modules/temp.hxx"
#include "modules/load.hxx"
#include "modules/counter.hxx"

list<MODULE> modules{
    module_network,
    module_load,
    module_disk,
    module_battery,
    module_temperature,
    module_simple_counter,
};