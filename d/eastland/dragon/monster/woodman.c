
#include "../../layuter.h"

inherit MONSTER ;

void create ()
{
        object boots,dagger,shield,legging,plate,cloak;

        ::create();
        set_level(11);
        set_name( "draconian woodman", "龍人樵夫" );
        add ("id", ({ "draconian", "woodman"}) );
        set_short( " 龍人樵夫");
        set("unit","位");
        set("alignment",100);
        set("weight",400);
        set("wealth/gold",50);
        set_long(
           "龍人樵夫是一各勤奮的工作者。\n"
        );
        set_perm_stat("int", 15);
        set_perm_stat("dex", 16);
        set_perm_stat("kar",10);
        set("max_hp",200);
        set("hit_points",200);
        set("natural_defense_bonus",10);
        set ("natural_weapon_class1", 20);
        set ("natural_min_damage1", 5);
        set ("natural_max_damage1", 16);
        set ("natural_armor_class", 20);
        set ("special_defense",(["all":20,"none":20]));
        set ("gender", "male");
        set_skill("axe",60);
        set_skill("parry",80);
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
      
        set("chat_chance",3);
        set("chat_output",({
          "樵夫說：唉!我的酒癮又犯了，我真想喝陳年女兒紅。\n",
           }));
       
        dagger= new(Lditem"axe");
        dagger->move(this_object());
        wield_weapon(dagger);
        
        boots=new(Lditem"chainmail");
        boots->move(this_object());
        equip_armor(boots);
}

int accept_item(object ob1,object ob2)
{
    object ob3,ob4;
    if (!ob2|| (int)(ob2->query("layuter_beer"))!=1) return 0;
    if ((int)(ob2->query("layuter_beer"))==1){
    tell_object(ob1,"非常感謝你為我帶來的酒，光是酒香就令我的酒蟲大作。\n");    
    if (ob3=(present("axe",this_object()))){
      tell_object(ob1,
         "我身上沒什麼值錢的東西，但是這把斧頭以跟了我二十年了，但依舊鋒利無比，就把它當作禮物送給你。\n"
         );        
         ob3->move(environment(this_object()));
        this_player()->set_explore("eastland#4");
       }
    ob2->remove();
    tell_room(environment(ob1), "樵夫坐在椅子上開始喝著酒.\n");       
   }
   
}

void die()
{  
  object ob3;
  
  
  if (ob3=(present("axe",this_object())))
    ob3->set("woodman_die",1); 
  ::die();  
    
}
