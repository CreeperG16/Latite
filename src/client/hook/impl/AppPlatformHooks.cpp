#include "pch.h"
#include "AppPlatformHooks.h"
#include "sdk/signature/storage.h"
#include "client/event/Eventing.h"
#include "client/event/impl/FocusLostEvent.h"

namespace {
	std::shared_ptr<Hook> FocusLostHook;
}

int AppPlatformHooks::_fireAppFocusLost(SDK::AppPlatform* plat) {
	FocusLostEvent ev{};
	if (Eventing::get().dispatch(ev)) return 0;
	return FocusLostHook->oFunc<decltype(&_fireAppFocusLost)>()(plat);
}

AppPlatformHooks::AppPlatformHooks() {
	// TODO: FIX ME
	//FocusLostHook = addHook(Signatures::AppPlatform__fireAppFocusLost.result, _fireAppFocusLost, "AppPlatform::_fireAppFocusLost");
}
