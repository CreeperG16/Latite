#pragma once
#include "client/hook/Hook.h"
#include "sdk/common/world/level/Level.h"
#include "util/util.h"

class GenericHooks : public HookGroup {
    static void Level_tick(sdk::Level* level);
    static void* ChatScreenController_sendChatMessage(void* controller, std::string const& message);

public:
    GenericHooks();
};