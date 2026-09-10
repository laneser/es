#include "../takeda.h"
#include <stats.h>
#include <conditions.h>

inherit MONSTER ;
void create()
{
	::create();
	set_level(8);
        set_name( "Huan Fu Duan", "皇甫端" );
        set_short( "皇甫端" );
	add( "id", ({ "doctor","healer","huan","fu","duan" }) );
	set_long(
@C_LONG
你看見一個長相奇特的中年人，有深棕色的鬍鬚，他就是聞名的獸醫皇甫端．
幽州府人，外號紫髯伯，善能騎馬相馬，知得一切頭口寒暑病症，下藥用針，
無不痊可，現為梁山泊內馬匹獸醫，開馬市是他的副業，在這逛逛，說不定
你能在這找到一匹好馬。
C_LONG
	);
        set( "race", "human" );
        set( "gender", "male" );
        set_perm_stat( "int", 26 );
        set_perm_stat( "kar", 20 );
	set_perm_stat("str",10);
        set_perm_stat( "dex", 18 );
        set_skill( "dodge", 100 );
        set_skill( "anatomlogy", 40 );
	set("defense_type","dodge");
        set( "aiming_loc", "ganglion" );
        set( "max_hp", 120 );
        set( "hit_points", 120 );
	set_natural_armor( 55, 20 );
        set( "natural_weapon_class1", 25 );
        set( "natural_min_damage1", 10 );
        set( "natural_max_damage1", 20 );
        set( "special_defense", ([ "evil": 30,"none":20]) );
        set( "alignment", 1500 );
        set( "wealth/gold", 30 );

        set( "inquiry", ([
                "heal": "@@ask_heal",
                "diet": "@@ask_diet"
	
        ]) );
        wield_weapon( TWEAPON"poblade" );
        equip_armor( TARMOR"small_cloth" );
        equip_armor( TARMOR"simple_boots");
}
    
int I_hate_killer()
{
        if ( this_player() == query_attacker())
        {
        tell_room( environment(), 
        "皇甫端怒道: 卑鄙的傢伙 !! 打我還叫我醫你 !! 看我怎麼教訓你 ! \n" ,
        this_object() );
        (CONDITION_PREFIX +"simple_poison")->apply_effect(this_player(),8,5);
        return 1;
	}
	return 0;
}

int ask_heal()
{
int num,hpmax,hp;

	if (I_hate_killer()) return 1;
      	command("look "+(string)this_player()->query("name"));
	hpmax=this_player()->query("max_hp");
	hp=this_player()->query("hit_points");
	if (hpmax==hp)
	{
	tell_room( environment(), 
	"皇甫端說道: 我是治牲口的，你是牲口嗎? \n" ,
	this_object() );
	return 1;
	}
	
	num=(hpmax-hp)*6;
       if( !this_player()->debit("gold", num) )
        return notify_fail( 
	"皇甫端搖搖頭道：「無錢免談。」\n");

	tell_room( environment(), 
	"皇甫端笑道：哈哈..看在錢的份上，就讓我看看吧．說著拿出了一些馬吃的青草強迫\n"+
	"你吃下，一陣反胃之後，你的傷好多了。皇甫端說道：人跟馬果然沒有不同。\n" ,
	this_object() );
	this_player()->set("hit_points",hpmax);
	return 1;

}
int ask_diet()
{
command("look "+(string)this_player()->query("name"));
if (!(this_player()->query_temp("fat_quest/fish")) || this_player()->query_temp("fat_quest/fish")<3)
write(
"皇甫端嘆道: 又一個不三不四的人，今天是什麼日子??\n");
else {
write(
"\n皇甫端摸摸你的頭說道: 我是有讓馬下痢的藥，可是，你覺得那能給人吃嗎?\n"
"是安道全叫你來的吧? 他最喜歡跟人開玩笑了，也因為這樣，他唯一的妹妹安小\n"
"慧，才會跟他鬧翻而跑到海威港去賣茶。說完，皇甫端好像忽然想起什麼事來\n");
command("hmm ");
call_out("ask_sister1",10,this_player());
return 1;
}
}
int ask_sister1()
{
write(
"皇甫端一拍大腿，說道: 我怎麼會忘記呢?? 我有一個客人，前一陣子來賣馬的時候\n"
"曾經提到海威港有賣一種神效減肥茶，不會就是安小慧在賣吧?不過她脾氣怪怪的，\n"
"很難應付，也許你該先去找安道全參詳參詳......\n");
return 1;
}