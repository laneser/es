//#pragma save_binary

#include "../mage.h"

inherit ROOM;
void create()
{
	::create() ;
	set("light", 1) ;
	set_short( "The Energy Room", "能源室" );
	set_long( @LONG
  NEED WORK HERE!
LONG
            , @C_LONG
這是儲存魔法能源的地方，你感到一股強大的魔力。在這裡可以請專人幫
你補充(recharge)魔法武器的能源，不過切記勿自己動手，小心控制不當毀了
裝備。
C_LONG
);
	set( "exits", ([ "down" : MAGE"library", ]) );
    set( "no_monster", 1);
	set( "objects", ([
	 "cid" : MAGE"monsters/cid", 
         "wand" : MAGE"weapons/little_wand",
	]) );
	reset();
}

void init()
{
    add_action("to_recharge", "recharge");
}

int to_recharge(string str)
{
    object item, who;
    int wc, damage, times, skill, karma, cost_money, cost_exp, money, exp;
    who = this_player();
    
    if( !str ) 
      return notify_fail( 
        "使用格式: recharge <物品名稱> \n" );
    if( !(item=present(str, who)) )
      return notify_fail("你身上沒這個東西。\n" );
    if( !item->query("max_charge") )
      return notify_fail( "這不是魔法物品，無法補充魔法能源!\n" );
    wc = (int)item->query("weapon_class");
    damage = (int)item->query("special_damage");
    times = (int)(item->query("max_charge"))-(int)(item->query("charge_left"));
    if( !times ) 
      return notify_fail("這物品已充滿了魔法能源，你還要浪費錢嗎?\n");
    skill = (int)who->query_skill("recharge");
    karma = (int)who->query_stat("karma");
    money = 200;
    exp = 500;
    cost_money = wc*damage*times*(150-skill)/money;
    cost_exp = wc*damage*damage*(130-skill)/exp;
    if( (int)who->query_exp_stock() < cost_exp )
      return notify_fail(sprintf("補充這物品的能源將損失你 %d 點經驗值，你可用經驗值不足。\n",cost_exp));
    if( present("cid") && !who->debit( "silver", cost_money ) )
      return notify_fail(sprintf("補充這物品的能源需要 %d 銀幣。\n" ,cost_money));
    who->gain_experience( -cost_exp );
    if( !present( "cid" ) ) {
      tell_room( this_object(), sprintf( "%s把%s放入能源補充機裡面。\n",who->query("c_name"),item->query("c_name")), who );
      tell_object( who, sprintf("你小心翼翼的把%s放入能源補充機裡面。\n",item->query("c_name")));
      if( random(125) > skill || random(30) > karma ) {
        tell_room( this_object(), sprintf("但是一不小心%s化成灰燼消失了。\n",item->query("c_name")));
        item->remove();
      } else {
        tell_object( who, 
          sprintf("一段時間之後，你把%s拿了出來，它看起來充滿了魔法能源。\n" ,
	item->query("c_name")));
        tell_room( this_object(), 
          sprintf("一段時間之後，%s把%s拿了出來，它看起來充滿了魔法能源。\n" ,
	who->query("c_name"),item->query("c_name")), who);
        item->set("charge_left",(int)item->query("max_charge") );
      }
    } else {
      tell_object( who, 
        sprintf("你把%s交給施得，只見他把它放入能源補充機中。\n一段時間之後，他把它拿了出來並歸還給你。\n" ,item->query("c_name")));
      tell_room( this_object(), 
      sprintf("%s把%s交給施得，只見他把它放入能源補充機中。\n一段時間之後，他把它拿了出來並歸還給%s。\n" ,
	who->query("c_name"),item->query("c_name"),who->query("c_name")),who );
      item->set("charge_left",(int)item->query("max_charge") );
      tell_room( this_object(), "施得說: 充好了。\n");  
    }
    return 1;
}
