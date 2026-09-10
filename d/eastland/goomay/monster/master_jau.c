
#include "../goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(18);
        set_name( "Master Jau", "趙堂主" );
        add ("id",({ "jau","master"}));
        set_short( "趙堂主");
        set("unit","位");
        set_long(
@C_LONG
這裡坐著一個鐵塔一般的大漢，他的面前擺著兩隻酒杯，他正捧著一隻
酒□子仔細的斟著酒，然後自己喝掉。你一路走過來，他只是用他那雙
醉眼瞄著你，還是自斟自飲，好像一點都不把你放在眼裡。
C_LONG
);
        set ("gender", "male");
        set ("race", "hawkman");
        set_natural_armor( 90, 20 );
        set_natural_weapon( -5, 5, 15 );
        set_perm_stat( "str", 30 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "dex", 30 );
        set_skill( "blunt", 100 );
        set_skill( "parry", 100 );
        set( "hit_points", 800 );
        set( "max_hp", 800 );
        set( "special_defense", ([ "all": 20 ]) );

        set( "wealth/gold", 100 );
        wield_weapon( Obj"thor_hammer" );
        equip_armor( Obj"thor_gloves" );

        set( "inquiry", ([
                "wine" : 
@WINE
「酒？你也懂酒？俺老趙這輩子喝遍了各種好酒烈酒，可以說
是老酒蟲了，還有什麼酒沒喝過？不過聽說最近有人從海外帶來一些新酒，
好像叫什麼加的，聽說烈的很 !! 嘿嘿 !! 老子就想試試 ...」
WINE
]) );

}

int accept_item(object me,object item)
{
        string name;
        object obj;
        int i;

	name = (string) item->query("name") ;
	if ( name !="vodka" ) {
	tell_object(me,
		"趙堂主搖搖頭：「謝謝 !! 老趙我不需要這東西 !!」\n");
        command("give "+(string)item->query("name")+" to "+lower_case((string)me->query("name")));
        return 1;
	}

        i = this_player()->query_temp("give_wine");
        if ( i )
                this_player()->set_temp("give_wine",i+1);
        else
                this_player()->set_temp("give_wine",1);
        if (i != 2){
                command("drink vodka");
                tell_room( environment(), 
                "趙堂主紅著臉，滿意的咂咂嘴笑道：好酒 !! 你還有嗎？\n");
	}
        else {
        command("drink vodka");
        tell_room( environment(), 
        "趙堂主醉的在地上滿地亂爬，大笑道：真過癮 !! 你也嚐嚐我老趙的好酒 !!\n" );
        me->delete_temp("wine");
        obj=new(Obj"old_wine");
        obj->move(this_object());
        command("give wine to "+(string)me->query("name"));
        me->set_explore("eastland#13");
	}
	return 1;
}
