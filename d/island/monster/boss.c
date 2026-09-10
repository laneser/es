#include "../island.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(5);
    set_name( "Boss", "店老闆" );
    set_short( "店老闆");
    set_long(@LONG
這是龍門客棧的店老闆，你可別小看他哦，他可是廚藝(cooking)一流哦！
LONG
            );
    set("unit","位");
    set("race","lizardman");      
    set("age",50);
    set("gender","male" );
    set("alignment",200);
    set("weight",300);
    set("wealth/copper",150);
    set_perm_stat("str",5);
    set_perm_stat("dex",5);
    set_perm_stat("kar",5);
    set_perm_stat("int",5);
    set_perm_stat("pie",5);
    set("hit_points",100);
    set("max_hp",100);
    set_natural_armor(25,7);
    set_natural_weapon(15,0,5);
    set("inquiry",([
        "cooking":"@@ask_cooking"]) );
    set("exp_reward",200);
}

int accept_item(object player,object ob)
{
      string *name;
      object obj;
      name = ob->query("id");
      
      if( name[0] != ("shark's fin") ){
      tell_room(environment(),@LONG
店老闆很生氣的說:拿這種五四三二一的東西叫我煮，未免太侮辱我的廚藝了吧！！
LONG
      );
      command("drop " + name[0] );
      return 1;
      }  
      tell_room( environment(),@LONG
店老闆很高興的說:哇！這樣好的魚翅還是第一次看到，你放心，看我的！
緊接著拿著開水沖泡了一下，一碗鮮美的魚翅湯就呈現在你面前了！！
LONG
      );
      ob->remove();
      obj = new(IOBJ"soup");
      obj->move(environment(player));
      return 1;
}
 
 
void ask_cooking()
{
    write(@ALONG
店老闆遙望著遠方，說道:不是我臭屁啊，任何東西交到我手中，都會變成
美味的佳餚哦！！

*******你隱隱看見他身後湧起了無數的浪花，哦！太陽出來了！！*******
ALONG
        );
	return;
}
