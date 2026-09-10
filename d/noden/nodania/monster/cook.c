#include "mudlib.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name("cook", "廚師");
	set_short("忙碌的廚師");
	set_long(@CLONG
這個廚師正在替整個王宮中的人準備食物——沒錯，整個王宮，包括
國王一家人、僕役、侍從、及宮女。
CLONG
	);
	set_perm_stat( "kar", 30 );
	set_skill( "dodge", 50 );
	set( "natural_armor_class", 40 );
	set( "natural_weapon_class1", 9 );
	set( "natural_min_damage1", 5 );
	set( "natural_max_damage1", 9 );
	set( "alignment", 150 );
	set( "wealth/gold", 5 );
        set( "inquiry", ([
	        "fat": "@@ask_fat",
        ]) );
}
int ask_fat()
{
command("look "+(string)this_player()->query("name"));
if (!(this_player()->query_temp("fat_quest/fish")) || this_player()->query_temp("fat_quest/fish")<3) {
write(
"廚師疑惑的看著你，說道: 我不算很胖吧??\n");
}
else {
write(
"\n你一五一十的把肥東的困難告訴了廚師，一陣沉默之後，廚師說道: 我這個徒弟\n"
"真是不長進，一點小小的問題就灰心喪志，真是讓我失望，一個廚師如果自己都失\n"
"去信心，那客人又怎麼會有信心呢? 我十幾年前只教他一半，就是要他自己成長，\n"
"看來我是做錯了.......\n");
call_out("help_fat",10,this_player());
return 1;
}
}
int help_fat(object ob1)
{
	object ob;
      if ( present("cook note",ob1) ) return 0;
      else {
write(
"廚師繼續說道: 算了，誰叫他是我徒弟呢，再幫他一次忙好了。說完轉身從\n"
"身後的箱子中翻出了一本小小的筆記本。說道: 這是我這些年來做魚料理的\n"
"心得，應該可以幫上一點忙。不過要求得最高深的魚料理技術，我想去找賣\n"
"魚的人可能最快，你可以去找他們並且把心得抄在筆記上一起帶回去....\n");
ob1->set_temp("fat_quest/skill",1);
   ob = new("/d/eastland/liang_shan/obj/note");
   ob->move(ob1);
return 1;
}
}
