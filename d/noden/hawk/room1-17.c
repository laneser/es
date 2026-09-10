#include "hawk.h"
#include <mudlib.h>
#include <conditions.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("光輝森林");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
你走到森林的深處，環顧四周一片鬱蒼蒼的樹海圍繞著你，你感受到一股生
生不息的活力從宇宙的各個角落傳來，頓時間，你好像領略了什麼，但又說不出
是什麼。
LONG_DESCRIPTION
        );
        set( "exits", ([
                "southwest" : HAWK"room1-16",
                        ]) );
    reset();
}//end of creat

void init()
{
        mixed *condis;
        if( !(condis = this_player()->query( "conditions/_heal_sp" ))) return 0;
        HEAL_SP->apply_effect(this_player(),condis[0]-5,condis[1]);
        add_action( "remove_sp_recover", "go" );
        add_action( "do_cast", "cast");
        add_action( "remove_sp_recover", "sneak" );
        add_action( "see_mirror","see" );
}

int see_mirror(string str)
{
        if (!str || str != "mirror") return 0;
        write ("你發現你的鏡子一片黑黝黝的，啥都看不到，大概是光被樹林給檔住了。\n");
        return 1;
}

int do_cast()
{
        write("\n\n一股神秘的力量阻止了你繼續唸咒。\n\n\n你的精神渙散了～～～～\n");
        this_player()->set("spell_points",10);
        return 1;
}

int remove_sp_recover(string str)
{
        mixed *condis;
        condis = this_player()->query( "conditions/_heal_sp" );
        if( !str || str == "southwest" )
        {
                HEAL_SP->apply_effect( this_player(), (condis[0]+5), condis[1] );
                return 0;
        }

        return 0;
}
