#include "../layuter.h"

inherit ROOM;

void create()
{
	::create();
	set_short("小徑");
	set_long( @LONG_DESCRIPTION
這是一條通往草原的小徑，路上遍佈著玫瑰花(rose)叢，使你必須小心
翼翼地通過以免被刺傷。
LONG_DESCRIPTION
	);
	set_outside("hamlet");
    set("item_desc",([
        "rose" : @ROSE
   此處的玫瑰一年四季都開著花，紅白相間構成一副美麗的圖案，
   但最奇特的是此處特有的黑玫瑰，那神秘的色彩帶給人恐怖的死
   亡氣息。
ROSE
   ]));
    set("objects",([
            "butterfly" : LMONSTER"butterfly",
            "elf guard" : LMONSTER"elf_guard", ]));
	set( "light", 1 );
	set( "pre_exit_func", ([
		"south" : "check_level" ]) );
	set( "exits", ([
		"north" : LELF"elf2.c",
		"south" : LELF"elf6.c"
	]) );
	
	reset();
}

int check_level()
{
	if( wizardp(this_player()) || !present("guard") ||
		(int)this_player()->query_level() < 7 ) return 0;
	tell_object( this_player(), 
		"精靈守衛說: 為了大草原的和平, 只准 newbie 進入。\n"
		"精靈守衛阻止你前進!\n" 
	);
	return 1;
}
