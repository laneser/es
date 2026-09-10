#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

#define Obj             "/d/eastland/goomay/obj/"
#define BOOK            "/d/healer/poison/book"

inherit MONSTER;

void create()
{
	object book;

        ::create();
        set_level(17);
        set_name("tang ying", "唐瑩");
        add( "id", ({ "ying","tang" }) );
        set_short("唐瑩");
        set_long(
"唐瑩是遠從四川來古梅鎮收帳的小姑娘，只比她妹妹唐如大五歲，\n"+
"長的十分標緻。她看起來心事重重，正一個人站在那兒怔怔地發呆...\n"
        );
        set("race","human");
        set("gender","female");
        set( "unit", "位" );
        set( "alignment", 200 );
        set_natural_armor( 70, 20 );
        set_natural_weapon( 11, 8, 17 );
	set_perm_stat( "str", 30 );
	set_perm_stat( "kar", 25 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "pie", 2 );
        set_perm_stat( "dex", 26 );
        set_skill("dodge",50);
        set( "hit_points", 500 );
        set( "max_hp", 500 );
        set( "special_defense", ([ "all": 20 ]) );
        set ("wealth", ([ "silver": 200 ]) );
        set( "pursuing", 1 );
        set( "tactic_func", "emit_poison" );
        equip_armor(Obj"tang_ring");

	book = new(BOOK);
	book->move(this_object());
}

int emit_poison()
{
        object victim;

        if( random(25)>6 || !(victim= query_attacker()) ) return 0;
        tell_room( environment(this_object()),
"唐瑩怒道：『臭小子，敢打姑奶奶的歪腦筋，讓你瞧瞧四川唐門的厲害!!!』\n"
"纖手一揚，你的眼前突然爆出一團七彩煙霧!!!\n\n"
 ,
        this_object() );
        (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 7, 7 );
	(CONDITION_PREFIX + "confused")->apply_effect( victim, 15, 5 );
	(CONDITION_PREFIX + "slow")->apply_effect( victim, 15, 2);
        return 1;
}

