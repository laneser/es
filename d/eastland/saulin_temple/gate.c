#include "saulin_temple.h"

inherit ROOM;

void create()
{
	::create();
	set_short("少林寺大門");
	set_long( @C_LONG_DESCRIPTION
在你的眼前有一座雄偉的山門，上面以龍飛鳳舞的筆跡書寫著「少林寺」
三字，聽說這是東方皇帝的真跡，以表揚少林寺對東方武術的貢獻，你的左右
兩方個是一片高聳的圍牆，它把整個少林寺環繞起來，使得少林寺更增神秘，
門前則是一條雲石階梯，那是少林寺對外主要道路。 
C_LONG_DESCRIPTION
	);
        set_outside("eastland");
	set("no_monster", 1);
	set("objects",([
	    "monk1" : SAULIN_MONSTER"greet_monk",
	    "monk2" : SAULIN_MONSTER"greet_monk",
	    "monk3" : SAULIN_MONSTER"greet_monk",
	    "monk4" : SAULIN_MONSTER"greet_monk",
	]) );
	set( "pre_exit_func", ([
		 "enter" : "check_weapon",
	]) );
	set( "exits", ([
		 "enter" : SAULIN"front_square2",
		 "down"  : SAULIN"road4",
	]) );
	reset();
}

int is_a_weapon(object item)
{
	if( item->query("weapon_class") && !item->query("prevent_drop")) 
		return 1;
	return 0;
}

int check_weapon()
{
	object *weapons;
	weapons = filter_array( all_inventory( this_player() ),
			"is_a_weapon", this_object() );
	if( wizardp(this_player()) || !weapons || !sizeof(weapons) || 
		!present("monk") ) return 0;
	tell_object( this_player(), 
		"知客僧說道: 施主, 對不起, 少林寺內戒殺, 請放下您的武器。\n" 
	);
	return 1;
}
