//#pragma save_binary
// create by Kyoko.
#include <mudlib.h>

inherit DAEMON ;

int help() ;

int invoke_on()
{
    int skill, wc;
    object weapon;
    weapon = this_player()->query("weapon1");
    if( !weapon )
      write("你的手中並沒有裝備任何武器。\n" );

    else if( !weapon->query("max_charge") )
      write("你手上的武器沒有任何特殊攻擊的能力。\n" );
    else if( weapon->query("power_on") )
      write("你手上的武器早就開啟釋放特殊攻擊能力。\n" );

    else {
      skill = (int)this_player()->query_skill("invoke");
      wc = (int)weapon->query("weapon_class");
      if( wc > 10 && skill < wc*2 )
        write("你的技能不足以開啟釋放這武器的特殊攻擊能力。\n" );

      else {
        write("你成功地開啟釋放這武器的特殊攻擊能力了。\n" );

        weapon->set("power_on", 1);
      }
    }
    return 1;
}

int invoke_off()
{
    int skill, wc;
    object weapon;
    weapon = this_player()->query("weapon1");
    if( !weapon )
      write( "你的手中並沒有裝備任何武器。\n" );

    else if( !weapon->query("max_charge") )
      write("你手上的武器沒有任何特殊攻擊的能力。\n" );

    else if( !weapon->query("power_on") )
      write("你手上的武器早就關閉釋放特殊攻擊能力。\n" );

    else {
      skill = (int)this_player()->query_skill("invoke");
      wc = (int)weapon->query("weapon_class");
      if( wc > 10 && skill < wc*2 )
        write("你的技能不足以關閉釋放這武器的特殊攻擊能力。\n" );

      else {
        write("你成功地關閉釋放這武器的特殊攻擊能力了。\n" );

        weapon->set("power_on", 0);
      }
    }
    return 1;
}

int cmd_invoke(string str)
{
        if( !str ) return help();
		switch(str) {
			case "on"      : return invoke_on();
			case "off"     : return invoke_off();
			default : return help();
		}
}

int help()
{
		write( @C_HELP
指令格式: invoke <on|off>

這指令可以將你手上裝備的魔法武器的特殊攻擊能力釋放或是封印。

C_HELP
		);
    return 1;
}
