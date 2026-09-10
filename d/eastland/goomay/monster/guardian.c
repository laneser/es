
#include "../goomay.h"
#include <stats.h>
inherit MONSTER ;

void create ()
{
        ::create();
        set_level(19);
        set_name( "Guardian", "會場守衛" );
        add ("id",({ "guardian"}));
        set_short( "會場守衛");
        set("unit","位");
        set_long(
@C_LONG
他是一個長的極為可怕的蜥蜴人守衛，佈滿細細鱗片的身上泛著詭異的油光，
他發現你正盯著他看，便向你喝道：「看什麼看？付錢啊 ! 每人黃金五十兩 !」
C_LONG
);
		set("no_attack",1);
        set ("gender", "male");
        set("exp_reward",61) ;
        set_natural_weapon(65 , 30 , 45) ;
        set_natural_armor( 80, 40 ) ;
        set ("race", "lizardman");
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
                return notify_fail("付誰？多少錢？\n");
        if( !id(who ) ) return 0;
        if( type != "gold" ) {
         tell_room( environment(), 
          "守衛叫道: 你聾了嗎？不是跟你說要金幣嗎？\n",
          this_object() );
                return 1;
	}
       if( !this_player()->debit(type, num) ) return notify_fail( 
           "你沒有那麼多金幣。\n");

        if( num < 50 ) {
         tell_room( environment(), 
          "守衛叫道: 你想騙老子嗎？錢不夠 ! 沒收 !!\n" ,
          this_object() );
                return 1;
	}

	obj = this_player();
	if (num>=50) 
	{
        tell_room( environment(), 
         "守衛向"+obj->query("c_name")+"點點頭說道: 好 !! 進去吧 ! 並且把他推進武鬥大會場。\n"
		, ({obj}) );
        tell_object( obj, 
         "守衛向你點點說道: 好 ! 進去吧 !! 並且很粗魯的把你推進武鬥大會場。\n"
                );
      obj->move_player( Goomay"coliseum2", "SNEAK" );
        tell_room( Goomay"coliseum2", 
          obj->query("c_name") + "跌跌撞撞的跑進來。\n"
	,obj );

	return 1;
	}

}
