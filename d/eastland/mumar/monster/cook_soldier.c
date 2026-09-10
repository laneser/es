#include <../mumar.h>
inherit "/d/eastland/mumar/monster/mob_special";
 
void create()
{
        object ob;
        ::create();
        set_level( 3 );
        set_name( "cooking soldier", "伙房兵" );
        add ("id", ({ "soldier" }) );
        set_short( "伙房兵" );
        set_long( @C_LONG
他是一個典型的伙伕，看起來好像很喜歡這份工作，顯得很高興。
C_LONG
);
        set( "gender", "male" );
        set( "race", "human" );
 
        set("hit_points", 100);
        set( "wealth/silver", 20 );
        set_natural_armor( 16, 6 );
        set_c_verbs(({"%s用頭撞向%s","%s用勺子槌向%s","%s用腳踹向%s"}));
        wield_weapon(OBJS"scoop");
        set("special_attack",(["damage_type" : "none","main_damage" : 8,
                                "random_dam" : 4 , "hit_rate" : 10]));
        set( "tactic_func", "my_tactic" );
        set("c_enemy_msg",
            "伙房兵用勺子挖起一堆菜渣，往你的臉上亂扔..\n\n");
        set("c_room_msg","那伙房兵臉上浮起一陣奸笑，同時挖起一堆剩菜渣，扔向");
        set("c_room_msg2", "，哇...你覺得亂噁心一把的.....\n");
 
        set( "chat_chance", 5 );
        set( "chat_output", ({
        "伙房兵說道 : 頭頭這幾天的心情(mood)好像怪怪的,不知怎麼了...\n",
        "伙房兵用勺子攪動著鍋裡的湯...\n"
        }) );
}
