#include "../saulin_temple.h"

inherit MONSTER;

void create()
{
		object ob;
        ::create();
        set_level(16);
        set_name( "Charming woman of fox", "狐狸精" );
        add ("id", ({ "fox","woman" }) );
        set_short( "狐狸精");
        set("unit","只");
        set_long(@C_LONG
這是一隻十分飢渴的千年狐狸精，專門吸取陽氣，男性朋友請特別小心。
C_LONG
        );
	set("killer",1);
        set("max_hp", 600);
        set("hit_points",600);
        set("alignment",-1000 );
        set("wealth/silver",100);
        set("special_defense",([ "all" : 30, "none": 30 ]));
        set("aim_difficulty", ([ "critical" : 25, "vascular" : 30, ]) );
        set_perm_stat("str", 23);
        set_perm_stat("dex", 25);
        set_perm_stat("karma",25);
        set_perm_stat("int",25);
        set_natural_weapon(32, 21, 36);
        set_natural_armor(80, 36);
        set_skill("dodge",100);
        set("gender", "female");
        set_c_limbs(({ "身體", "頭部", "腳部", "手臂" }));
        set("tactic_func","special_att");
        set("chat_chance", 10 );
        set("att_chat_output", ({
            "狐狸精媚笑道： 親愛的，讓人家吸吸你的陽氣嘛!!\n",
	    }) );
        ob = new( SAULIN_OBJ"fox_tail" );
        ob->move(this_object());
}

void report( object attacker, object victim )
{
   string message;
   seteuid(getuid());
   message= "/adm/daemons/statsd"->status_string(victim);
   tell_object( victim,
     set_color(sprintf("一陣寒氣向你襲來，彷佛生命正一點一滴的離你而去!!\n( 你%s )\n",message),"HIR",victim)
   );
}

int special_att()
{
    object victim;
    int att_type ;
    string c_name;
    if( !(victim = query_attacker()) ) return 0;
    // female won't effect, added by Kyoko.
	if( (string)victim->query("gender") == "female" ) return 0;
	
    c_name= victim->query("c_name");
    att_type = random(100);
    if( att_type < 20 ) {
      tell_room( environment(this_object()), 
        sprintf("\n狐狸精把%s抱個正著，興奮地吸收他的陽氣\n",c_name),
        this_player()
      );
      tell_object( victim, 
        set_color("\n狐狸精把你抱個正著，興奮地吸收你的陽氣\n","HIY",victim ));

      victim->receive_special_damage("cold", 30+random(12));
      report(this_object(),victim);
      return 1;
    } else if( att_type >= 20 && att_type < 40 ) {
      if( victim->query("stop_attack") ) return 0;
      tell_object( victim, 
        set_color("\n狐狸精妖媚的眼神把你迷惑住了。\n","HIG",victim));

      tell_room( environment(), 
        sprintf("狐狸精用妖媚的眼神把%s迷惑住了 !\n",c_name),
        ({ victim, this_object() })
      );
      victim->block_attack(6);
      victim->set_temp("msg_stop_attack", 
        "( 你現在被迷惑住了，無法攻擊！ )\n" );
      return 1;
    } else return 0;
}
