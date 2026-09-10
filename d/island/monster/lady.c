#include <mudlib.h>
inherit MONSTER;

void create()
{
	
	::create();
	set_level(1);
	set_name( "Assistant Rabecca","蕾貝卡" );
	add ("id", ({ "lizardman", "assistant", "rabecca", }) );
	set_short( "領事助理 蕾貝卡" );
	set_long(@LONG
她是蜥蜴人領事館中聘請的小姐，負責處理該族領域的簽證作業。
她發現你正色咪咪的瞧著她看，使了個眼色又繼續雕刻(carve)她手
中的小木刀去了！
LONG
	);

        set( "gender", "female" );
        set( "race", "lizardman" );
        set( "unit","位" );
	set_perm_stat( "dex", 1 );
	set_perm_stat( "str", 1 );
	set_perm_stat( "int", 1 );
	set_perm_stat( "con", 1 );
	set_perm_stat( "pie", 1 );
	set_perm_stat( "kar", 1 );
	set("no_attack",1);
	set("no_steal",1);
        set ("weight", 300);
        set( "inquiry", ([
         "carve" : "@@ask_carve" ,
//         "drill" : "@@ask_drill"
           ]) );
}

void ask_carve(object who)
{ 
  if( !who->query_temp("lizard_quest/get_saw"))
  {
      tell_room( environment(),@LONG
蕾貝卡瞪著你說：本大小姐今天不高興，刻了把木刀要殺人，有意見嗎？
LONG
      );
  }else{
  tell_room( environment(),@LONG
蕾貝卡含情脈脈的看著你說：嗨！我能為你做什麼呢？我除了會做秘書工作外
最拿手的就是雕刻木具了，不過要自備木具，我才肯為你刻哦！
LONG
      );
  }
  return;
}

int accept_item(object who, object ob)
{
    object obj;
    string *name;
    name=ob->query("id");
    
 if(name[0] == "mahogany branch")
  {
     if( who->query_temp("lizard_quest/get_saw") )
     {
       ob->remove();
       tell_room( environment(),@LONG
蕾貝卡對著你遞給她的桃木說:
    哇！紋路這麼美的桃木，一定能刻出精美的小木刀的，您稍等一下哦！
話剛說完，立刻把小木刀遞給你！
LONG
        );
        obj = new("/d/island/hole/obj/kirs");
        obj->move(this_object());
        command("give kirs to "+(string)who->query("name"));
     }else{
       tell_room( environment(),@LONG
蕾貝卡突然發出猙獰的笑聲:來的正好，讓我一消心頭之恨！

－－－－我削－－－－我割－－－－我砍－－－－我鋸死你這死沒良心的東西－－－－

哇～～～你辛苦鋸來的桃木都變成碎木屑了....
LONG
        );
        ob->remove();
     }
      return 1;
  }else{ 
      tell_room( environment(),@LONG
蕾貝卡奸笑道:你給我這東西練刀法嗎？謝謝羅！
說著說著，東東給她割碎了....
LONG
        );
     ob->remove();
     return 1;
  }
}
