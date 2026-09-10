#include "../oldcat.h"

inherit MONSTER;
void create()
{
	::create();
	seteuid(getuid());
	set_level(19);
	set_name( "Dragon King of Well", "井龍王" );
	add ("id", ({ "king", "dragon", }) );
	set_short( "井龍王" );
	set_long(
    "  井龍王原是北海龍王，因為在兒子闖出大禍之後，得罪了玉帝，才被貶到凡間，\n"
    "他其實是很有智慧的人，且由於曾經過萬年的修□，膽識及統御能力皆不同凡響。\n"
	);

        set( "alignment",1600);
        set( "gender", "male" );
        set( "race", "dragon" );
        set( "unit", "位" );
        set( "likefish",1);
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "con", 30 );
	set_perm_stat( "piety", 20);
	set_perm_stat( "karma", 30);
	set_skill("longblade",100);
	set_skill("parry",100);
	set("special_defense", (["all":60,"none":60,"monk":60,"scholar":60]) );
        set ("aim_difficulty", ([ "critical":30, "vascular":30, "weakest":30, "ganglion":30 ]) );
	set ("max_hp", 1500);
	set ("hit_points", 1500);
        set ("max_sp", 2000);
        set ("spell_points",2000);
	set ("wealth", ([ "gold": 500 ]) );
	set_natural_weapon( 5, 5, 10 );
	set_natural_armor( 50, 41 );
        set ("weight", 400);
        set( "inquiry", ([
             "rose" : "@@ask_rose" ,
             "princess" : "@@ask_princess" ,
             "daughter" : "@@ask_princess",
             "box" : "@@ask_box",
             "door" : "@@ask_door",
             "crystal" : "@@ask_crystal",
             ]) );
        set ("unbleeding",1);
	set ("att_chat_output", ({
	    "龍王說：你們這些小老百姓，是不可能擊敗我的。\n"
	    }) );
	wield_weapon(OWEAPON"sword1");
        equip_armor(OARMOR"legging2");
        equip_armor(OARMOR"helmet2");
        equip_armor(OARMOR"boots3");
        equip_armor(OARMOR"mail6");
}

void ask_rose( object who )
{
        tell_object( who, 
          "\n龍王道：不錯，藍玫瑰在我的花園中有一棵，但那是我女兒最喜愛的，我不能替\n"
          "她作主，不過你必須先救我的女兒，她已經有生命危險了。\n");
      return ;        
}

void ask_princess(object who)
{
      
      tell_object(who,
      "\n龍王道：我的女兒因為一天到晚都泡在花園裡，不知道什麼原因，有一天突然看到她倒在\n"
      "花園裡，從此就長睡不起，也許是三百年一輪的劫數吧，但只要你能治好她，一定\n"
      "給你優厚的報酬。\n"
     );
      return ;
}

void ask_box(object who)
{
   tell_object(who,
    "\n龍王臉嚴肅的看著你，說道：你問這個做什麼 ? \n"
      "費了我好大的心力，才把寶盒又找了回來，我決定把它鎖進我的寶庫中，也不想\n"
      "讓我的兒子知道，以免他又犯了同樣的錯誤。\n"
   );
   return;
}

void ask_door(object who)
{
  tell_object(who,
    "\n龍王說：我的寶庫只有在某段時間才能進去。\n"
  );
  return;
}

void ask_crystal(object who)
{
  tell_object(who,
    "\n龍王說：用手去觸摸水晶會發生意想不到的事。\n"
  );
  return;
}

int accept_item(object me, object item)
{
   string name;
   object ob;
 
   name=(string)item->query("name");
   if (!name || (name!="living pill"))
     return 1;
   if (!item->query(me->query("name"))) {
     printf("\n龍王說：你是去那裡偷的藥丸，偷盜之物我們寧死不取。\n");
     item->move(me);
     return 0;
   }
   write("\n龍王說：啊、你這顆續命藥丸可能真的可以救我女兒的命，請拿給我的女兒，給她吃下，謝謝。\n");
   if (!this_object()->query("key")) {
     write("龍王說：這是我女兒寢室的鑰匙。\n");
     ob=new(OOBJ"diamond_key");
     ob->move(this_player());
     set("key",1);
   }
   else 
     write("\n龍王說：我女兒寢宮的鑰匙已被別人拿走了。\n");
   item->move(this_player());
   return 1;
}
void die()
{
   int i ;
   object *sword,*tmp, dragon_sword;
   
   tmp = children("/d/eastland/volcano/weapon/sword1");
   sword = ({ }) ;
   for(i=0 ; i<sizeof(tmp);i++ )
     {
       if(!environment(tmp[i])) continue ;
       else sword=sword+({tmp[i]}) ;
     }
   
 // 改成clone 出來的 sword 大於二就 remove
   
   if( sizeof(sword)>1 ){
     dragon_sword = present( "dragon sword", this_object() );  
     tell_room(environment(this_object()),
  " 龍王掙扎的說：寶劍一生只有一次．．．．．．\n龍王用盡最後的力量將龍劍粉碎！\n",this_object() );
   dragon_sword->remove();
   }
 ::die();
}

