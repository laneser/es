
#include "../../layuter.h"

inherit MONSTER ;

void create ()
{
        object boots,dagger,shield,legging,plate,cloak;

        ::create();
        set_level(15);
        set_name( "draconian artisan", "龍人工匠" );
        add ("id", ({ "draconian", "artisan"}) );
        set_short(" 龍人工匠");
        set("unit","位");
        set("alignment",400);
        set("weight",400);
        set("wealth/gold",100);
        set_long(@C_LONG
龍人工匠他熟習各種器物的製造，在這個世界上還沒有任何依樣物品是
他造不出來的！
C_LONG
        );
        set( "inquiry", ([
         "drumstick" : "@@ask_drum",
           ]) );
        set_perm_stat("int", 20);
        set_perm_stat("dex", 16);
        set_perm_stat("kar",20);
        set("max_hp",300);
        set("hit_points",300);
        set("natural_defense_bonus",10);
        set ("natural_weapon_class1", 20);
        set ("natural_min_damage1", 11);
        set ("natural_max_damage1", 16);
        set ("natural_armor_class", 40);
        set ("special_defense",(["all":20,"none":20]));
        set ("gender", "male");
        set_skill("shortblade",80);
        set_skill("dodge",100);
        set("tactic_func","sleet_tactic");
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
      
       
        wield_weapon(Lditem"dagger1");
        equip_armor(Lditem"boots");
}



void ask_drum( object who )
{
        tell_object( who, @ALONG
如果你想要製造龍神鼓槌，你必須要找到一根世上最堅硬的木頭，加上
我原有的麒麟皮即可製造出龍神鼓槌，所以快去找世上最堅硬的木頭來
吧，當你找到之後再來找我，我自然會幫你的。
ALONG
                   );
      return ;        
}
int accept_item(object ob1,object ob2)
{
    object ob3,ob4;
    if (!ob2|| (int)(ob2->query("layuter_club"))!=1) return 0;
    if ((int)(ob2->query("layuter_club"))==1){
    tell_object(ob1,
         "好既然你已經得到世上最堅硬的木頭，那我就幫你造龍神鼓槌。\n");
    tell_room(environment(this_object()),"龍人工匠開始敲敲打打地努力於工作\n");  
    call_out("aaa",15,this_object());
    ob3=new(Lditem"club");
    ob3->move(environment(this_object()));
       }
    else {
       tell_room(environment(this_object()),"龍人工匠說：謝謝你的禮物。\n");  
       }
          
    ob2->remove();   
   }  

void aaa(object who)
{
  tell_room(environment(who),"龍人工匠終於完成這艱鉅的工作，此時他已累的滿頭大汗。\n");
   tell_room(environment(this_object()),"龍人工匠說：這是你要的鼓槌 ，希望你能好好的利用它\n");  
 
}
