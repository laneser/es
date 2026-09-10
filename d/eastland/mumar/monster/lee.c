#include <../mumar.h>
inherit MONSTER;
 
void create ()
{
        ::create();
        set_level(19);
        set_name( "General Lee", "牧馬節度使 李□" );
        add ("id", ({ "general", "lee", }) );
        set_short( "牧馬節度使 李□" );
        set_long( @C_LONG
牧馬關節度使李□，是當今皇上身邊某寵臣的女婿，靠著裙帶關係，平步青雲，現
在已經做到節度使的職位了。不過，聽說他曾是少林的俗家子弟，功夫可能還不差。
C_LONG
        );
    set( "alignment", 0 );
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "個" );
    set_perm_stat( "dex", 29 );
    set_perm_stat( "str", 20 );
    set_perm_stat( "int", 15 );
    set_perm_stat( "con", 15 );
    set_perm_stat( "karma", 25 );
    set ("max_hp", 800);
    set ("hit_points", 800);
    set ("wealth", ([ "gold": 400 ]) );
    set_natural_weapon( 35, 10, 17 );
    set_natural_armor( 52, 33 );
    set ("unbleeding", 1);
    set ("aim_difficulty", ([ "critical":55, "weakest":35, "ganglion":85,"vascular":65]));
    set ("special_defense", ([ "all":60 ]) );
    set ("weight", 400);
    set ("exp_reward",30500 );
    set_experience(1000000);
    set_skill("longblade",100);
    set_skill("parry",100);
    set_skill("concentrate",100);
    set("c_death_msg","%s 還心有不甘地說道：「你...你是不是服用類固醇...！」然後就掛了...\n");
    set( "inquiry", ([
         "plates" : ({ "不要亂動我的收藏品喔...但是若你有空，可以幫我擦(polish)一下。\n" }),
         "mirror" : ({ "喔..那面破鏡子啊..上次一個笨手笨腳的傳令打破了那面古董鏡。\n"
                     "反正我也不是很喜歡那面鏡子，破了就算了吧..如果你要找碎片，應該在垃圾堆裡吧。\n" }),
         "button" : ({ "唉..我最喜歡穿的那件上衣掉了一顆金釦子..如果你能找到，\n"
                    "請你還給我！我會重賞你的..\n" })
           ]) );
 
    wield_weapon(OBJS"king_sword");
    equip_armor(OBJS"gloves01");
    equip_armor(OBJS"cloth01");
    equip_armor(OBJS"amulet01");
}
 
int accept_item(object me,object item)
{
    string name;
    name=(string)item->query("name");
     if ( !name || (name!="golden button") ) return 1;
     else {
     tell_object(me,
@MISSION
將軍幾乎是用哭地對你說：「謝謝你幫我找回這個釦子......。」
將軍說：「為了答謝您的恩情，我的收藏室可以讓您進去參觀 。」
MISSION
        );
                item->remove();
        this_player()->set_temp("give_button",1);
        return 1;
        }
}
 
void die()
{
 // 抄龍劍的....
   int i ;
   object *sword,*tmp, empire_sword;
 
   tmp = children("/d/eastland/mumar/objs/king_sword");
   sword = ({ }) ;
   for(i=0 ; i<sizeof(tmp);i++ )
    {
       if(!environment(tmp[i])) continue ;
       else sword=sword+({tmp[i]}) ;
     }
 
 // 改成clone 出來的 sword 大於二就 remove
 
   if( sizeof(sword)>1 ){
     empire_sword = present( "empire sword", this_object() );
     tell_room(environment(this_object()),
  " 李□掙扎的說：真劍已經被奪.....這把仿造品不能給別人看到！\n\n李□硬是把劍吞了下去.....你看得目瞪口呆...\n\n",this_object() );
   empire_sword->remove();
   }
 ::die();
 }
