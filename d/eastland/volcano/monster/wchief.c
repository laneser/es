#include "../oldcat.h"

inherit MONSTER;

void create()
{
        object ob1;

	::create();
	set_level(18);
	set_name( "Basge", "巴斯格" );
	add( "id", ({ "basge" }) );
	set_short( "矮靈族酋長 巴斯格" );
	set_long(
	 "酋長巴斯格是矮靈族中的強者，你看他全身肌肉結實，好像充滿了精力似的，雙眼\n炯炯有神，太陽穴微微隆起，全副武裝，手裡執著一隻權杖，感覺很有威嚴，為了\n族人他就算犧牲生命也在所不辭。\n"
	);
	set( "race", "dwarf" );
	set( "gender", "male" );
	set( "alignment", -900 );
	set_perm_stat( "str", 30 );
        set_perm_stat( "int", 20 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "kar", 20 );
	set_skill( "blunt", 100 );
	set_skill( "parry", 100 );
        set_skill( "block", 100 );
	set_skill( "dodge", 100 );
        set( "aim_difficulty",([ "critical":80,"weakest":80,"ganglion":80,"vascular":80 ]) );
	set( "wealth/gold", 80 );
        set( "hit_points", 750);
        set( "max_hp", 750);
        set("natural_armor_class",38);
        set("natural_defense_bonus",26);
        set_natural_weapon(8,5,15);
        ob1=new(OWEAPON"w_staff");
        ob1->move( this_object() ); 
	wield_weapon( ob1 );
        equip_armor(OARMOR"mail5");
        equip_armor(OARMOR"legging1");
        equip_armor(OARMOR"shield1");
        equip_armor(OARMOR"armband2");
        equip_armor(OARMOR"helmet1");
        set("chat_chance",15);
        set("chat_output",({
          "酋長說：為了平息火神，為了族人的安危，我們獵人頭實在是不得已的。\n",
        }) );
        set("inquiry", ([
            "volcano":"@@ask_volcano",
            "god":"@@ask_god",
            ]) );
}

void ask_volcano(object who)
{
  tell_object(who,
   "酋長說：這座火山實在是我們的最大禍害，想起50年前的爆發，真是讓人心悸猶存，不過\n我們族中最有智慧的長老已經在想辦法解決這個問題了，希望他能儘早想出來。\n"
  );
}

void ask_god(object who)
{
  tell_object(who,
   "酋長說：在我們族中，大家都相信火山爆發是因為火神發怒的關係，所以我們年年獵人頭\n來祭祀火神，在每年特定的日子，在火山頂由巫師將祭品投入火山之中。\n"
  );
}

int stop_attack()
{
	object slave, *tmp;

	slave = present( "wolf", environment() );
	if( !slave ) return 0;
	tell_room( environment(),
                "竟敢攻擊我的主人，不要命了！\n" 
		"巴斯格的寵物--暴狼 向你撲了過來。\n"
	);
	tmp = query_temp( "protectors" );
	if( !tmp || member_array( slave, tmp )==-1 ) {
		add_temp( "protectors", ({ slave }) );
		slave->add_temp( "protectees", ({ this_object() }) );
	}
	tmp = slave->query_attackers();
	if( !tmp || member_array( this_player(), tmp )==-1 )
		slave->kill_ob( this_player() );
}
