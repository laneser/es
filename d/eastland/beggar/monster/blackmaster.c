#include "/d/eastland/beggar/dony.h"
inherit MONSTER;

object ob1;

void create()
{
        ::create();
        set_level(17);
        set_name( "blackmaster Lu", "陸阿巧" );
        add("id",({"blackmaster","lu"}));
        set_short( "巧匠 陸阿巧");
        set("unit","位");
        set_long( @LONG
陸阿巧原本是『鑄劍門』的門人並且從師門處學得一身好手藝。 多年行走江湖並
廣為人鑄劍,所有的兵器只要經過他的手那怕是朽木也能斷金。近年來因受到師門
叛徒的迫害而穩居到『薪膽村』來,他最大的希望就是有一天能夠剷除所有的師門
敗類。
LONG
        );
        set("weight",750);
        set_perm_stat("str",30 );
        set_perm_stat("dex",24 );
        set_natural_weapon(50, 18, 38);
        set_natural_armor( 83, 29 );
        set_skill("parry",80);
        set_skill("block",80);
        set("max_hp",620);
        set("hit_points",620);
        set("gender", "male");
        set("race", "human");
        set("war_score",50000);
        set("alignment",1500);
        set("special_defense", ([ "all": 40,"none":30]) );
        set("aim_difficulty",
          ([ "critical":65, "vascular":60, "ganglion":80, "weakest":65 ]) );
        set( "inquiry", ([
               "master":"@@ask_master",
            ]) );
        wield_weapon(DWEAPON"sky_sword.c");
        equip_armor(DARMOR"orb_shield.c");
        equip_armor(DARMOR"fire_armband.c");
}
void ask_master(object asker)
{
     
//     if( (int)asker->query_quest_level("dony1") ) 
     if ( !asker->query("finish_dony") )
        tell_object( asker , "陸阿巧說道:請幫幫我的朋友震八方吧,他似乎遇到麻煩了。\n");  
     else {
        if ( ( asker->query("class") ) == "scholar" ){
           if ( present("spell",asker) ) 
              tell_object( asker , "陸阿巧說道:咦,你不是已經有了聚劍術嗎?\n");
           else {
              tell_object( asker, 
                "陸阿巧說道:是震八方叫你來問有關於聚劍術?\n"
                "陸阿巧說道:好吧,本來聚劍術是不隨便傳授給人的,既然你幫過我的朋友,那我就教你吧!\n"
                "忽然陸阿巧喃喃自語\n");
              call_out("recover1",2,asker);                     
           }     
        } else tell_object( asker , "陸阿巧說道:謝謝你的幫助我的朋友\n");
     }   
}

void recover1(object asker)
{
     tell_object( asker,
         "\n\n接著陸阿巧的眼睛暴出一道金光圍繞著你,你看不見所有的東西!!\n\n\n");
     asker->set_temp("block_command",1);
     call_out("recover2",10,asker);
}
void recover2(object asker)
{
   asker->set_temp("block_command",0);
   tell_object(asker,
       "那道圍繞著你身旁的金光久久才散去,並且在你的身上留下一樣東西。\n"
       "陸阿巧叫醒你說道:孩子不要睡了,快起來吧,我已經傳授給你聚劍術了。\n"
       "你看看自己,哇!聚劍術!!你高興地向陸阿巧說謝謝。\n"
       "陸阿巧向你微笑。^_^\n");
   ob1 = new( DITEM"spell" );
   ob1->move(asker);
}
void die()
{
   object killer;
   string str,name;
   if ( killer=query("last_attacker") ) {
     if ( killer->query("org_name") ) name=killer->query("org_name");
     else name=killer->query("name");
   }
   str="\n  "+ctime(time())+" 陸阿巧 killed at "+
    file_name(environment(this_player()))+" by "+name+"\n";
   write_file("/open/dony/deathlist",str);
   ::die();
 }