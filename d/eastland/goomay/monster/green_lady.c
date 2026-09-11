#include "../goomay.h"
inherit Mob_special;

void create ()
{
        ::create();
        set_level(12);
        set_name( "Lui Chu", "綠珠" );
        add ("id",({ "chu","lui"}));
        set_short( "綠珠");
        set("unit","位");
        set_long(
@C_LONG
    在你面前的是一個十分罕見的美麗女子，氣質高雅的她正微笑地看著你，
她是綠珠，一個出身貧寒卻聰慧過人的姑娘，她現在正站在花叢之中整理她的
寶貝們，你呆呆地看著她，不知道是人因為花顯得更美麗還是花因為人開的更
嬌豔。
C_LONG
);
        set("alignment",550);
        set_perm_stat("str",17);
        set_perm_stat("dex",17);
        set_perm_stat("int",17);
        set_natural_armor( 72, 21 );
        set_natural_weapon( 6, 4, 9 ); 
        set_skill("dodge",85);
        set_skill("whip",80);
        set ("gender", "female");
        set ("race", "human");
        set( "special_defense", ([ "all": 30 ]) );

        wield_weapon( Obj"ribbon" );
		equip_armor(Obj"web");
        set( "wealth/gold", 30 );

        set( "inquiry", ([
                "root": "@@ask_root",
        ]) );
        set("special_attack",(["damage_type" : "mental","main_damage" : 20,
                                "random_dam" : 10 , "hit_rate" : 15 ]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
    "綠珠的絲帶柔柔地套上你的脖子，把你箍的連氣都透不過來..\n\n");
set("c_room_msg","綠珠輕柔地揮動著絲帶，把");
set("c_room_msg2", "箍的氣也透不過來 ...\n");

}
int ask_root()
{
	object ob1;
	if (this_player()->query_temp("amaze_root"))
	{
        tell_object(this_player(),
			"綠珠說：「我不是已經把藥給你了嗎？」\n");
	return 1;
	}
        tell_object(this_player(),
"綠珠嘆了一口氣道：「老爺也真是的，怎麼可以拿人命來做生意呢？我會\n"
"勸勸他的，謝謝你的提醒。我想藥物很快就會到了 !! 」她拿出一段樹根\n"
"道：「這是奇異花樹的根，請您先拿去急用吧 !!」\n" );

        ob1 = new( Obj"amaze_root" );
        ob1->move(this_object());
		this_player()->set_temp("amaze_root",1);
        command("give "+(string)ob1->query("name")+" to "+lower_case((string)this_player()->query("name")));
        return 1;
}
