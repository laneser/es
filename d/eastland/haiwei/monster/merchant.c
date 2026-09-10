#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "merchant", "魚販" );
	add( "id", ({ "fish merchant" }) );
	set_short( "魚販" );
	set_long("一個長相普普通通的魚販。\n");
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 100 );
	set_skill( "dodge", 40 );
	set( "wealth/gold", 5 );
	set( "natural_weapon_class1", 4 );
	set( "natural_min_damage1", 3 );
	set( "natural_max_damage1", 5 );
        set( "inquiry", ([
	        "fish": "@@ask_fish",
                "cook": "@@ask_cook"
        ]) );
}
int ask_fish()
{
command("look "+(string)this_player()->query("name"));
if (!(this_player()->query_temp("fat_quest/skill")) || this_player()->query_temp("fat_quest/skill") < 1) {
write(
"魚販說道，我的魚很好吃的喲??\n");
}
else {
write(
"魚販笑道: 看你的樣子好像很賢慧，要不要我教你怎麼料理(cook)魚呢?\n");
return 1;
}
}
int ask_cook(int ob1)
{
      if ( present("cook note",this_player()) ) {
write(
"魚販說道: 你有沒有什麼可以抄下來的，這樣你才不會忘記。於是你把廚師的筆記\n"
"拿給魚販，只見他在筆記上塗塗寫寫之後，然後滿意的把筆記還你.....\n");
this_player()->set_temp("fat_quest/skill",2);
return 1;
}
else 
    write("魚販說道: 你有沒有筆記之類的東西啊??\n");
    return 1;
}
