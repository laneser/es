#include "../mumar.h"
inherit "/d/eastland/mumar/monster/mob_special";
 
void create()
{
        object ob;
        ::create();
        set_level( 7 );
        set_name( "cooking master", "伙伕頭" );
        add ("id", ({ "master" }) );
        set_short( "伙伕頭" );
        set_long( "一個伙伕頭，不知道正在煩些什麼事情，愁眉苦臉地坐在角落。\n"
        		);
        set( "gender", "male" );
        set( "race", "human" );
 
        set("hit_points", 200);
        set( "wealth/silver", 50 );
        set_natural_weapon( 10, 5, 14 );
        set_natural_armor( 35, 15 );
        set_c_verbs(({"%s用頭撞向%s","%s用平底鍋砸向%s","%s用腳踹向%s"}));
        wield_weapon( OBJS "pan" );
        set("special_attack",(["damage_type" : "none","main_damage" : 8,
                                "random_dam" : 4 , "hit_rate" : 10]));
        set( "tactic_func", "my_tactic" );
        set("c_enemy_msg",
            "伙伕頭抓起一袋米往你頭上用力砸下.\n\n");
        set("c_room_msg","那伙伕頭隨手抓起一袋米，砸向");
        set("c_room_msg2", "，你也覺得有點眼冒金星....\n");
 
        set( "chat_chance", 5 );
        set( "chat_output", ({
        "伙伕頭自言自語地說道 : 我到底該怎麼辦呢....\n",
        "伙伕頭嘆了口氣。\n",
        }) );
 
        set( "inquiry", ([
             "mood" : ({ "唉...最近關裡出現了一群老鼠(rat)，這兒的糧食被偷吃了不少....\n"
                         "我還不知道要怎麼向將軍交代呢!!而且也不知道要到那兒去找這群該死的畜生..\n"
                         "你能幫我這個忙嗎?把這群該死的傢伙除掉....\n " }),
             "bag" : ({ "唉...我怎麼點，就是少一包米，老鼠怎麼可能偷米呢？一定是有賊！..\n" }),
             "rat" : ({ "唉...我也不知道這群畜生會躲在那裡，我相信它們一定躲在關裡....\n"
                         "上回一個老兵說看到一隻比人還高的老鼠，不過我是不相信啦..\n"
                         "你一定要幫我這個忙，不然被將軍知道了，我就慘了！\n" })
        ]) );
}
 
void relay_message(string class1, string msg)
{
      string who, str;
      object player;
 
      if( sscanf( msg, "%s(%s)走了過來。", str,who )==2 )  {
         if( !player = find_player(lower_case(who)) ) return;
//	if( hunt_check( this_object(),player ) ) return;
    if (!query(temp("done") && ((int)player->query_quest_level("mumar")) < 1 &&
                        player->query_temp("mumar/done") ) {
                        tell_object( player, @THANKS
伙伕頭說說：謝謝你，幫我這個忙，願神祝福你。
你獲得 10000 點經驗。
   [   你完成了牧馬關伙房的任務。   ]
THANKS
);
                        player->gain_experience(10000);
                        player->finish_quest("mumar_cooker", 1);
                        set_temp("done",1);
                        set("chat_chance",0);
                        delete("inquiry");
                        return;
                 }
                   tell_room( environment(),
             "伙伕頭抬起頭來看了看你，然後又繼續低頭沉思...\n" );
       }
}
