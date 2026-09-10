#include "../moyada.h"

void to_climb_up( object player, string dest, int need )
{
    int skill;
    skill = player->query_skill("climbing");
    skill += 5;
    if( random(need) < skill ) {
      tell_object( player,"你小心翼翼的爬了上去。\n");
      tell_room( environment(player), 
        player->query("c_name")+"爬了上去。\n", player
      );
      player->move_player( dest, "SNEAK" );
      tell_room( environment(player),
        player->query("c_name")+"爬了上來。\n" , player
      );
    } else {
      tell_object( player,
        "你嘗試著爬上去，結果又滑了下來。\n");
      tell_room( environment(player), 
        player->query("c_name")+"嘗試著爬上去，結果又滑了下來。\n" , player
      );
    }
}

void to_climb_down( object player, string dest1, string dest2, int need, int damage )
{
    int skill;
    skill = player->query_skill("climbing");
    if( skill > need && (random(100) < skill) ) {
      tell_object( player,"你小心翼翼的爬了下去。\n" );
      tell_room( environment(player),
        player->query("c_name")+"爬了下去。\n", player
      );
      player->move_player( dest1, "SNEAK" );
      tell_room( environment(player), 
        player->query("c_cap_name")+"爬了下來。\n", player
      );
    } else {
      tell_object( player,"你嘗試著爬下去，結果一不小心掉了下去。碰! 好痛!\n" 
      );
      tell_room( environment(player),
        player->query("c_name")+"嘗試著爬下去，結果掉了下去。\n", player
      );
      player->move_player( dest2, "SNEAK" );
      player->receive_damage(damage);
      "/d/magic/magic"->report( this_object(), player );
      tell_room( environment(player),
        player->query("c_name")+"掉了下來。\n", player
      );
    }
}
