#include <mudlib.h>
#include <ansi.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "Shan chi", "玄慈神僧" );
        add ("id", ({ "monk","shan","chi" }) );
        set_short( "Shan chi","玄慈神僧");
        set("unit","位");
        set_long("",@C_LONG
玄慈是少林寺僅存數位玄字輩的長老之一，也是前兩任的方丈。他年
輕的時候喜歡習武，所練就的九陽神功和易筋經至今仍然傲視武林。但是
他現在已經不問世事了，除了偶爾少林寺遇到重大變故的時候會出面解危
以外，平時都負責指導少林公會。
C_LONG
        );
        set("exp_reward",50000);
        set("alignment",2000);
        set("wealth/silver",100);
        set("gender","male");
        set("race","human");
        set("tactic_func","special_attack");
        set("hit_points",2000);
        set("force_points",2500);
        set("max_hp",2000);
        set("max_fp",2500);
        set_perm_stat("str",30);
        set_perm_stat("dex",26);
        set_perm_stat("pie",30);
        set_perm_stat("kar",24);
        set_perm_stat("con",29);
        set_perm_stat("int",25);
        set_natural_weapon(35, 14, 30);
        set_natural_armor(90, 30);
        set_skill("dodge",100);
        set_skill("blunt",100);
        set_skill("parry",100);
        set_skill("inner-force",100);
        set("attack_skill","monk/general/king_kong");
        set("monk_gonfu/king-kong",35);
        wield_weapon("/d/monk/guild/weapons/kingkong_staff");
        equip_armor("/d/monk/guild/armors/sandal_beads");
        equip_armor("/d/monk/guild/armors/damo_plate");
        equip_armor("/d/monk/guild/armors/god_armband");
        equip_armor("/d/monk/guild/armors/holy_ring");
        equip_armor("/d/monk/guild/armors/cloud_boots");
        set("inquiry", ([
        "brassman" : "@@ask_brassman",
        "還俗" : "@@ask_return",
        "證明" : "@@ask_proof",
        "金剛杖法" : "@@ask_staff" ]) );
}

int ask_staff()
{
   int gonfus,check_book_quest;
   object me;
   
   me = this_player();
   gonfus = 0;
   check_book_quest = me->query("book_quest_finish");

   if( !check_book_quest ) {
      tell_object( me, "\n玄慈憂心地說道：唉！失去的楞枷經尚未尋回，目前我實在是難以靜下心來好好地傳授你武功\！\n");
      return 1;            }

   if( me->query("monk_gonfu/king-kong") ) {
      tell_object( me, "\n玄慈說道：你不是已經學過了嗎？該要好好練習才是....\n");
      return 1; }

   if( me->query("monk_gonfu/body-def") == 35 ) gonfus++;
   if( me->query("monk_gonfu/bolo-fist") == 35 ) gonfus++;
   if( me->query("monk_gonfu/dragon-claw") == 35 ) gonfus++;
   if( me->query("monk_gonfu/keep-flower") == 35 ) gonfus++;
   if( me->query("monk_gonfu/power-finger") == 35 ) gonfus++;
   
   if( wizardp(me) )
      printf("\nNumber of top 72 gonfus ： %d\n",gonfus);

   if( gonfus < 2 )
      tell_object( me, "\n玄慈溫和地說道：想要學好武器, 就先把拳腳練好再來吧...\n");
   else {
      tell_object( me, @MSG

玄慈和藹地摸摸你的頭.

玄慈說道：難得！難得！如此勤練功夫，你的確是有資格練金剛杖法。
          來！就讓我演練一次給你看吧！
          
玄慈緩緩地將金剛杖舉起，雙眼流露出恢弘的氣勢......

突然！玄慈連續使出金剛杖法中的招式，只見一道灰影在空中翻騰,
時見一道道的金光透影而出, 威猛無濤......

不一時, 灰影逐漸清晰, 慢慢看出玄慈的容貌....

玄慈笑笑地對你說：好孩兒！瞭解了嗎？

你點了點頭.

玄慈和藹地摸摸你的頭說道：金剛杖法，威猛無濤，使用時要心存善念才好啊！

MSG );
      me->set("monk_gonfu/king-kong",0); }

  return 1;

}

int special_attack()
{
    object victim;
    int fp;
    
    if(random(20)>7) return 0;
    victim = query_attacker();
    if( !victim ) return 0;
    fp=(int)victim->query("force_points");
    tell_room(environment(victim),
"\n玄慈運起九陽神功，一道渾厚的內力自丹田湧向雙手，向"+
(string)victim->query("c_name")+"直衝而去。\n",victim
	);
    tell_object(victim,@C_LONG
    
玄慈運起九陽神功，霎時你被一股強大的內力籠罩著。突然這股勁力直衝
你的丹田，你覺得你的經脈似乎已經斷了。

C_LONG
    );
    victim->receive_damage(60-random(fp/10));
    return 1;
}

int ask_brassman()
{
	object obj;
	obj = this_player();
	
	if( !obj->query("18brass") ) {
		tell_object(obj,
			"玄慈 長老說道：有關銅人陣的事情，你可以去請教慧元師侄。\n" );
		return 1; }
	if( (int)obj->query("18brass") == 1) {
		tell_object(obj,
			"玄慈 長老說道：你已通過銅人陣了。那麼現在你想( 還俗 )或是得到一項\n"
			"	       ( 證明 )呢 ?\n" );
		return 1; }
}

int ask_return() 
{
	int i;
	object obj,*urs;
	string c_msg;
	
	obj = this_player();
	urs = users();
	
	if( !obj->query("18brass") ) {	
		tell_object(obj,
			"玄慈 長老說道：請先通過銅人陣再說吧。\n" );
		return 1; }
	if( (int)obj->query("18brass") == 1) {
		tell_object(obj,
			"玄慈 長老看了你一會兒.............\n\n\n"
			"突然一巴掌在你的光頭上打了一下 !!\n"
			"玄慈 長老說道：阿彌陀佛，爾今日再度墜入紅塵，受那三千煩惱之苦，\n"
			"	       罷了罷了.....\n" );
	c_msg = set_color("[少林和尚] 玄慈 神僧: ","HIC");
		c_msg += "今日 "+obj->query("c_name")+"("+obj->query("name")+") "+
		  "成為少林俗家弟子 !!\n";
	for( i=0; i<sizeof(urs); i++ )
		if( (string)urs[i]->query("class") == "monk" )
			urs[i]->quick_message(c_msg); 
	obj->add("18brass",1); 
	return 1; } 
	return 0;
}		
		
int ask_proof() 
{	
	int i;
	object obj,*urs;
	string c_msg;
	
	obj = this_player();
	urs = users();
	
	if( !obj->query("18brass") ) {	
		tell_object(obj,
			"玄慈 長老說道：請先通過銅人陣再說吧。\n" );
		return 1; }
	if( (int)obj->query("18brass") == 1) {
		tell_object(obj,
			"玄慈 長老微笑著說道：恭禧你通過了十八銅人陣，這個臂環就是你通過\n"
			"	             考驗的證明 !!\n" );
		new("/d/eastland/saulin_temple/brass/obj/armband")->move(obj);
	c_msg = set_color("[少林和尚] 玄慈 神僧: ","HIC");
		c_msg += "恭禧 "+obj->query("c_name")+"("+obj->query("name")+") "+
		  "通過十八銅人陣的考驗 !!\n";
	for( i=0; i<sizeof(urs); i++ )
		if( (string)urs[i]->query("class") == "monk" )
			urs[i]->quick_message(c_msg); 
	obj->add("18brass",2); 
	return 1; } 
	return 0;	
}	
