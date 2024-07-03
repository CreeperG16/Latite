#include "pch.h"
#include "Command.h"

#include "client/misc/ClientMessageSink.h"
#include "client/Latite.h"
#include "util/Util.h"

/*
Command::Command(std::string const& name, std::string const& description, std::string const& usage, std::vector<std::string> aliases)
	: cmdName(name), description(description), usage(usage) {
	this->aliases = { name };
	for (auto& a : aliases) {
		this->aliases.push_back(a);
	}
}*/

void Command::message(std::wstring const& str, bool error) {
	std::wstring fin = L"";
	if (!error) {
		fin = util::FormatWStringMC(L"[&9Latite&r] " + util::FormatWStringMC(str));
	}
	else {
		fin = util::FormatWStringMC(L"&c" + util::FormatWStringMC(str));
	}
	Latite::get().getClientMessageSink().display(fin);
}
