#include "../oldcat.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "wraith elder", "矮靈族長老" );
        add ("id", ({ "elder" }) );
        set_short( "矮靈族長老");
        set("unit","位");
        set_long(
           "矮靈族長老已不管族內瑣事已久，他是矮靈族中最仁慈的，他不贊成每\n"
           "年的人頭祭，反對獵殺人頭，他一直要找一個方法來有效解決火山爆發\n"
           "的問題，別看他老態龍鍾的，他可是相當可怕的對手，連族長都得讓他\n"
           "三分。\n"
        );
        set("alignment",500);
        set("wealth/gold",350);
        set_perm_stat("int", 30);
        set_perm_stat("dex", 25);
        set_perm_stat("con",30);
        set_perm_stat("kar",30);
        set_natural_weapon( 5, 5, 15 );
        set_natural_armor( 60, 25 );
        set ("gender", "male");
        set ("race", "dwarf");
        set("max_sp",700);
        set("spell_points",700);
        set_skill("concentrate",100);
        set_skill("wand",100);
        set_skill("target",100);
        set_skill("black-magic",100);
        set("guild_levels/black-magic",70) ;
        set("guild_levels/guild",70);
        set("spells/lightning",3);
        set("magic_delay",2);
        set( "tactic_func", "cast_help" ); 
        set("aim_difficulty",(["critical":100,"weakest":40,
                               "vascular":60,"ganglion":50 ])) ;
        set("special_defense",(["all":60,"none":60]));
        wield_weapon(OWEAPON"wand2");
        equip_armor(OARMOR"cloth4");
        equip_armor(OARMOR"amulet3");
        equip_armor(OARMOR"legging3");
        equip_armor(OARMOR"helmet3");
        equip_armor(OARMOR"glove1");
}

int cast_help()
{ 
    object victim;
    string name;
    int i,j,ran,vickar,vicint,refn;
    victim = query_attacker();
    vicint = victim->query_perm_stat("int") ;
    vickar = victim->query_perm_stat("kar") ;
    
    i =30-vicint ;
    j =30-vickar ;
    
    if( i+j < 1 )  refn = 1 ;
    else refn = random(i+j) ; 

    ran = random(50) ;
                            
    if ( (int)this_object()->query("spell_points")< 300 )   
         this_object()->set("spell_points",600);

    if ( ran < refn  )
       {
          name=victim->query("name");
          command("cast lightning on "+name); 
          return 1;
        }
    else 
       {
          return 0;
        }
}

int accept_item(object player, object ob)
{
    if( (string)ob->query("killer") != (string)player->query("name") ) {
      tell_object(player,
        "非常感謝你找回了黑龍的寶盒，這個寶盒的用處，我們先擺到一邊，\n"+
        "如果他日有空，請順便與那位找回寶盒的英雄同來，讓我好好謝謝你們!!\n"
             );
      tell_room(environment(player),
        "長老把寶盒收了起來。\n");
      ob->remove();
      return 1;
    }

    tell_object(player,
      "\n非常感謝你找回這寶盒，這寶盒擁有強大的力量，假如使用不當很可能會\n"
      "導至產生非常大的災難，我在懷疑，當年火山爆發就是有人亂用這盒子造成。\n\n"
       );
    if( (int)(player->query_quest_level("Dragon_box"))==1 ) {
       player->finish_quest("Dragon_box",2);
       player->delete_temp("dragon_box");
       tell_object(player,
          set_color("你已經完成黑龍寶盒的任務，你得到10000點經驗值\n","HIY"));
          player->gain_experience(10000);
     }
     ob->remove();
     tell_room(environment(player),
           "長老把寶盒收了起來。\n");
    return 1;
}
