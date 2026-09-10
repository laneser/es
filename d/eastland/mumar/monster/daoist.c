#include <../mumar.h>
inherit MONSTER;
 
void create()
{
        ::create();
        seteuid( getuid() );
        set_level(5);
        set_name( "daoist", "道士" );
        set_short( "道士" );
        add( "id", ({ "groom" }) );
        set_long( "一個相貌怪異、行動神秘的道士，全身沾滿了草屑。\n" );
        set( "gender", "male" );
        set( "natural_armor_class", 26 );
        set( "natural_defense_bonus", 12 );
        set( "no_attack",1 );
        set_natural_weapon(11,4,14);
        set( "chat_chance", 25 );
        set( "chat_output", ({
                "道士自言自語道: 在這裡打個盹也會被吵醒...\n",
                "道士抬頭望著牧馬關說道: 這牧馬關怎麼妖氣(ghost)沖天啊...\n",
        }) );
        set( "inquiry", ([
        "ghost" : "@@ask_ghost" ]) );
}
 
int ask_ghost()
{ object obj;
if ( this_player()->query_temp("under") >=2 ) {
tell_object(this_player(),
@ASK
 
道士指著牧馬關的上空對你說道: 牧馬關上籠罩著團團紫色的氣體, 看到沒？
你順著道士所指看去, 似乎真的看到了許多似煙的紫氣從牧馬關內冒出......
道士說道: 我夜觀星象, 算得在這作怪的應是一頭修□千年的異獸, 此獸在此
　　　　　軍事重地, 必然為害......。我也算得今日必有福星出現, 也許這
　　　　　福星就應在你身上了。
道士從袖中取出一支釘子。
道士說道: 這隻七星追魂釘可以將那畜生的元神擊破, 它就不能再害人了, 你
          可要收好啊......貧道還有要事在身, 這裡就拜託你了......
 
ASK );
this_player()->set_temp("under",3);
obj=new(OBJS"nail");
obj->move(this_object());
command("give nail to "+lower_case((string)this_player()->query("name")));
tell_object(this_player(),
@ASK
 
道士轉了個身，消失在草叢之中。
ASK );
}
else {tell_object(this_player(),
@ASK
 
道士說道: 什麼都不懂的人不要吵我睡覺......
 
道士話一說完就轉身消失在草叢之中......
ASK
); }
this_object()->remove();
return 1;
}
