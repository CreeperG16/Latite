#include "Module.h"

void Module::loadConfig(SettingGroup& resolvedGroup) {
	resolvedGroup.forEach([&](std::shared_ptr<Setting> set) {
		this->settings->forEach([&](std::shared_ptr<Setting> modSet) {
			if (modSet->name() == set->name()) {
				switch (set->type) {
				case Setting::Type::Bool:
					*modSet->value = std::get<BoolValue>(set->resolvedValue);
					break;
				case Setting::Type::Int:
					*modSet->value = std::get<IntValue>(set->resolvedValue);
					break;
				case Setting::Type::Float:
					*modSet->value = std::get<FloatValue>(set->resolvedValue);
					break;
				case Setting::Type::Key:
					*modSet->value = std::get<KeyValue>(set->resolvedValue);
					break;
				}
			}
			});
		});
}

void Module::addSetting(std::string const& internalName, std::string const& disp, std::string const& desc, Setting::Value& val) {
	// TODO: A better system for finding out what setting it is
	//std::variant<BoolValue, FloatValue, IntValue, KeyValue>;
	Setting::Type type = Setting::Type::Bool;
	switch (val.index()) {
	case 0:
		break;
	case 1:
		type = Setting::Type::Float;
		break;
	case 2:
		type = Setting::Type::Int;
		break;
	case 3:
		type = Setting::Type::Key;
		break;
	case 4:
		type = Setting::Type::Color;
		break;
	default:
		throw std::runtime_error("Unknown key");
	}

	auto set = std::make_shared<Setting>(internalName, disp, desc, type);
	set->value = &val;
	settings->addSetting(set);
}

void Module::addSliderSetting(std::string const& internalName, std::string const& displayName, std::string const& desc, Setting::Value& val, Setting::Value min, Setting::Value max, Setting::Value interval) {
	// TODO: A better system for finding out what setting it is
	//std::variant<BoolValue, FloatValue, IntValue, KeyValue>;
	Setting::Type type = Setting::Type::Bool;
	switch (val.index()) {
	case 1:
		type = Setting::Type::Float;
		break;
	case 2:
		type = Setting::Type::Int;
		break;
	default:
		throw std::runtime_error("Unknown key");
	}

	auto set = std::make_shared<Setting>(internalName, displayName, desc, type);
	set->value = &val;
	set->min = min;
	set->max = max;
	set->interval = interval;
	settings->addSetting(set);
}
