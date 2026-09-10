
#include "../goomay.h"
#include <stats.h>
inherit MONSTER ;

void create ()
{
        ::create();
        set_level(15);
        set_name( "Bodyguard", "賭場保鏢" );
        add ("id",({ "guard"}));
        set_short( "賭場保鏢");
        set("unit","位");
        set_long(
@C_LONG
他是一個長的極為可怕的蜥蜴人守衛，佈滿細細鱗片的身上泛著詭異的油光，
他正一邊擺動著他的尾巴一邊看人下注，好像也很想下場試試，不過看他的
樣子似乎沒什麼錢，大概都輸光了吧 !! 他發現你正盯著他看，便向你笑道
：「客人你好 !! 快來發財吧 !」
C_LONG
);
        set ("gender", "male");
        set ("race", "lizardman");
        set_natural_armor( 45, 10 );
        set_natural_weapon( 0, 5, 10 );
        set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 20 );
        set_skill( "axe", 90 );
        set_skill( "two-weapon", 90 );
        set_skill( "parry", 60 );
        set( "hit_points", 600 );
        set( "max_hp", 600 );
        set( "special_defense", ([ "all": 20 ]) );
        wield_weapon( Obj"iron_axe" );
        wield_weapon2( Obj"iron_axe" );
        equip_armor( Obj"steel_tail" );
}

void init()
{
        add_action( "pay_me", "pay");
}

int pay_me(string arg)
{
        string who, type;
        int num;
	object obj;

        if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
                return notify_fail(
                        "付誰？多少錢？\n");
        if( !id(who ) ) return 0;
       if( !this_player()->debit(type, num) ) return notify_fail(
		           "你沒有那麼多錢。\n");

         tell_room( environment(), 
          "守衛搓著手笑道：謝謝你 !! 要下場試試手氣嗎？ \n" ,
          this_object() );
                return 1;

}
