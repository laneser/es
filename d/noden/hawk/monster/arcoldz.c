#include "../hawk.h"
inherit MONSTER;
void create()
{
        ::create();
        set_level(19);
        set_name( "Thief Arcold", "神偷 亞寇" );
        add ("id", ({ "arcold","thief"}) );
        set ("class","theif");
        set_short( "神偷 亞寇" );
        set_long(@C_LONG
你看到一名長得十分可愛的少女，大概十七八歲左右的年紀，全身穿著黑色
勁裝，看起來清秀與剽悍兼備，你又注意到她手上拿了一隻極為罕見的金色
扁鑽，難道是失傳以久的鑲金扁鑽嗎？
C_LONG
        );
        set( "race", "imp" );
        set( "gender", "female" );
        set_perm_stat( "str", 12 );
        set_perm_stat( "dex", 30 );
        set_perm_stat( "kar", 24 );
        set_perm_stat( "pie", 17 );
        wield_weapon("/d/island/obj/dagger01.c");
        equip_armor(ARMOR"god_3.c");
        equip_armor(ARMOR"black_suit.c");
        set_perm_stat( "int", 20 );
        set_skill( "dodge", 90 );
        set_skill( "anatomlogy", 100);
        set("aiming_loc","weakest");
        set("player_invisible", 1 );
        set( "aim_difficulty",([ "weakest":15,"vascular":30,"ganglion":50
]) );
        set( "special_defense",([ "all":30, "evil": 40 ]) );
        set_natural_armor(15,20);
        set_natural_weapon( 40, 17, 26 );
        set( "wealth/silver", 200);
        set("alt_corpse",WEAPON"dagger01.c");
        set( "moving", 1 );
        set( "speed", 30 );
        set( "patrol", ({ "west", "south", "south", "east",
                  "east", "north","north", "west", "south",
		"west", "north", "east" }) );
}

void init()
{
        object ob;
        ::init();
        if( !(ob= this_player()) || !userp(ob) ) return;
        call_out( "backstab", 0, ob );
}

void report(object holder, object victim )
{
   seteuid(getuid());
   tell_object( victim,
   sprintf("( 你%s )\n","/adm/daemons/statsd"->status_string(victim)));
}

void backstab(object ob)
{
        string *types;
        object env;
        int i, total;

        env = environment();
        if( !env || !present(ob, env) ) return;
        tell_object( ob,
"
亞寇突然從你背後冒出，雙眼殺機重重，手拿著扁鑽朝你背後沒有防備
到的地方狠狠的刺了下去，你感到一陣劇痛，似乎亞寇的背刺讓你受到了
相當大的傷害
\n");
        ob->receive_special_damage( "evil" , 30 + random(20));
        report(ob,ob);
}

void die()
{
        object killer,dagger;
        killer = query("last_attacker");
        killer->set_temp("smore_armor/arcold",1);
        dagger = present( "golden dagger", this_object() );
        dagger->remove();
        ::die(1);
        set( "death_msg","%s\n");
        tell_room(environment(),
"
你高興的從亞寇的屍體中拿出金光閃閃的鑲金扁鑽，拿在手上把玩，用手
試試它的鋒芒，咦，好像比不上傳說中的鑲金扁鑽，你仔細地瞧瞧這把扁
鑽，哇！上面的金色櫻花竟然是鍍金的....

一氣之下你又把扁鑽丟到地上\n\n");
	set("alt_corpse",WEAPON"dagger01.c");
}
