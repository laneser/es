#include "../saulin_temple.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(17);
        set_name( "master shu du", "達摩院首席 虛渡" );
        add ("id",({ "monk","master","shu","du"}));
        set_short("達摩院首席 虛渡");
        set("unit","位");
        set_long(@DESC
他是達摩院首席虛渡大師，雖然他擁有及胸的漆黑長髯，但是事實上他已經年近
九十了，紅紅的臉上時時帶著笑容的他號稱是少林寺數一數二的使刀名家，江湖
有言：一見修羅，群邪迴避。可見他的聲譽和武功。
DESC
        );
        set("alignment",1200);
        set("wealth/gold",50);
        set("max_hp", 950);
        set("hit_points", 950);
        set("max_fp", 2500);
        set("force_points", 2500);
        set("special_defense", ([ "all" : 40, "none" : 30 ]) );
        set("aim_difficulty", ([ "critical" : 60, "vascular" : 60, ]) );
        set_perm_stat("str",29);
        set_perm_stat("int",25);
        set_perm_stat("dex",25);
        set_natural_weapon(-12,5,8);
        set_natural_armor(67, 25);
	set_skill("longblade",100);
        set_skill("parry",100);
        set_skill("block",100);
        set ("gender", "male");
        set ("race", "human");
	set("attack_skill",CLASS"burn_blade");
	set("gonfus/burn-blade",35);
        wield_weapon(SAULIN_OBJ"blade");
        equip_armor(SAULIN_OBJ"glove3");
        equip_armor(SAULIN_OBJ"shield1"); 
        equip_armor(SAULIN_OBJ"armband1");
        set("inquiry", ([
        "燃木刀法" : "@@ask_blade" ]) );
}

int ask_blade()
{
   int gonfus,check_book_quest;
   object me;
   
   me = this_player();
   gonfus = 0;
   check_book_quest = me->query("book_quest_finish");

   if( !check_book_quest ) {
      tell_object( me, "\n虛渡喝道：身為少林武僧，不趕緊協助找回失去的楞枷經，還敢來找我學武功？\n");
      return 1;            }

   if( me->query("monk_gonfu/burn-blade") ) {
      tell_object( me, "\n虛渡說道：學過了還來？你是太閒沒事做是吧.....\n");
      return 1; }

   if( me->query("monk_gonfu/body-def") == 35 ) gonfus++;
   if( me->query("monk_gonfu/bolo-fist") == 35 ) gonfus++;
   if( me->query("monk_gonfu/dragon-claw") == 35 ) gonfus++;
   if( me->query("monk_gonfu/keep-flower") == 35 ) gonfus++;
   if( me->query("monk_gonfu/power-finger") == 35 ) gonfus++;
   
   if( wizardp(me) )
      printf("\nNumber of top 72 gonfus ： %d\n",gonfus);

   if( gonfus < 1 )
      tell_object( me, "\n虛渡厲聲說道：拳腳功夫這麼差，還想來學燃木刀法？再過一百年吧...\n");
   else {
      tell_object( me, @MSG

虛渡對你仔細地打量一番.

玄慈說道：不錯！以你的能力的確可以學得起燃木刀法。
          來！睜大眼睛，仔細看好！
          
虛渡緩緩地將修羅刀舉起，連人帶刀緩緩變得赤紅.....

忽地！虛渡連續使出燃木刀法中的招式，宛如一條火龍在空中翻騰,
炙熱的氣息在這兒瀰漫開來，令你覺得喘不過氣來....

只聽得虛渡一聲長嘯，你心頭一震，修羅刀已指住你的咽喉....

虛渡笑道：小子！燃木刀可不是普通的武功喔！沒兩下子就不要到外頭給我丟人現眼...

你向虛渡點了點頭.

虛渡收刀說道：好！小子，這就去吧....

MSG );
      me->set("monk_gonfu/burn-blade",0); }

  return 1;

}
