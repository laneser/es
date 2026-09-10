
#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name("jojo zombie", "啾啾僵□");
	add( "id", ({ "zombie","jojo" }) );
	set_short("A jojo zombie", "啾啾僵□");
	set_long(@C_LONG
啾啾僵□是被超渡失敗的壞人,因怨恨無法消滅而變成的疆□...
它的身體都腐爛了,你可以見到許多蛆蟲從它的身上掉落下來,它全身都是□毒
它要找一個替身,才能脫離可怕的地獄... 它正輕輕的對著你噴氣呢!!!
C_LONG	);
	set( "unit", "只" );
	set( "alignment", -1600 );
	set_natural_armor( 10, 4 );
	set_natural_weapon( 4, 3, 7 );
	set_perm_stat( "int", 2 );
	set_perm_stat( "pie", 1 );
	set_perm_stat( "str", 5 );
	set_skill("dodge",20);
        set("defense_type","berserk");
	set( "pursuing", 1 );
	set( "tactic_func", "emit_poison" );
	set_c_limbs( ({ "半個腦袋", "腐爛的身體", "滿是蛆的腿", "快斷掉的眼睛" }) );
	set_c_verbs( ({ "%s伸出汙黑的爪子，抓向%s","%s伸長利齒咬向%s", }) );
        set("alt_corpse","/d/monk/monster/corpse1.c"); 
        set("c_death_msg","僵□被你殺死後化成一灘血水... \n"); 


}

int emit_poison()
{
	object victim;

	if( random(21)>3 || !(victim= query_attacker()) ) return 0;
	tell_room( environment(this_object()), 
"僵□揮動著它的雙手，一團腐爛的肉噴到你的身上 ....\n",
		this_object() );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 4, 4 );
	return 1;
}
