//#pragma save_binary

// #include <disclaimer.h>
// The Version command.
// Brought to you by Buddha@TMI
// Updated for mudlib version by Watcher@TMI
// 4-19-92

#include <config.h>
#include <mudlib.h>

inherit DAEMON ;

int help();

int cmd_version(string str) {
	if (str) return help();
 
	write(capitalize(mud_name()) + " is running the " + MUDLIB_VERSION +
	      " mudlib on " + version() + "\n");
	return 1;
}
int
help() {
  write(@HELP

這條指令可以讓你知道這個mud是什麼版本與運轉了多久.

HELP
);
  return 1;
}