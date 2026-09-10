#include "../mad.h"

inherit TEACHER;
inherit MONSTER;

void create()
{
	::create();
   set_level(17);
   set_name( "hunter Jang", "張獵戶" );
   add( "id", ({ "jang", "hunter" }) );
   set_short( "張獵戶" );
	set_long(@C_LONG
這個獵人生得濃眉大眼，一身虯結的肌肉和結實的肩膀，顯示他身懷武藝。
如果你沒事的話, 還是離他遠一點。
C_LONG
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 800 );
   set_perm_stat( "str", 25 );
   set_perm_stat( "dex", 25 );
   set_perm_stat( "kar", 15 );
   set_skill( "longblade", 100 );
   set_skill( "parry", 100 );
   set_skill( "block", 100 );
	set_skill( "dodge", 60 );
   set_skill( "anatomlogy", 80 );
	set( "aiming_loc", "ganglion" );
   set( "hit_points", 600 );
   set( "max_hp", 600 );
	set( "wealth/gold", 55 );
	set( "special_defense", (["all": 25 ]) );
   set_natural_weapon( 12, 12, 12 );
   set_natural_armor( 86, 55 );

   wield_weapon( IANOBJ"coral_blade" );
   equip_armor( IANOBJ"shield" );

   set_lessons( ([
                  "anatomlogy" : ({ 250, 50 })
   ]) );
    set( "inquiry", ([
        "skill" : "噢！小弟略通解剖學(anatomlogy)。\n",
        "wife" : "唉.......\n",
        "cut" : "大俠您要借刀啊? 我的家傳寶刀不外借噢!\n"
                "但是前天梁伯母曾向我借了另一把刀, 我還特地幫她藏在\n"
                "床底。\n",
       "trace" : @REPLY
大俠, 是郭長老要您找我的吧? ........

張獵戶續道: 是的, 為了報殺妻之仇, 這半年內我和長老
分頭找尋淫賊之下落。但遺憾的是, 沒有得到任何蛛絲馬
跡; 雖然近幾天來, 我也日夜不休地搜找村莊四周, 但..
..唉..................

曾聽岳父說, 他在我們的新婚之夜, 看過此賊。我實在無
臉去見他, 故請大俠您去問問他老人家。不過, 由於思念
女兒過深, 除了內人的名子, 岳父是不會有反應的!
REPLY
     ]) );
}

void init()
{
   teacher::init();
   npc::init();
}

int check_trainee(object who)
{
   if( (int)who->query_quest_level("iywolf")<1 )
   return notify_fail(
        "張獵戶嘆道: 抱歉！小弟我正要出門搜尋淫賊的行蹤。\n" );
   if( (string)who->query("class")=="adventurer"
     && (int)who->query_level()> 4 )
   return 1;
   else return notify_fail(
   "張獵戶說道: 抱歉！郭長老吩咐說只能教「高級冒險者」。\n" );
}
