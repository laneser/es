#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	seteuid(getuid());
	set_name( "Air", "艾爾" );
	add ("id", ({ "air", }) );
	set_short( "Dwarf prince Air", "矮人王子艾爾" );
	set_long(
	"矮人王子艾爾, 從小就對神秘的東西很有興趣. 他對於魔法與醫術都有很\n"
	"深的研究. 目前他是矮人莫拉德的唯一繼承人, 為了對抗矮人的死敵巨人\n"
	", 他正在研究一種特別的法術, 以求能夠封住有始以來最可怕的巨人大司\n"
	"祭哈德瑞得屈裡(hotredchili)的黑暗魔法.\n"
	);

    set("alignment",200);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "個" );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "piety", 25);
	set_perm_stat( "karma", 25);
	set_skill("dodge",100);
	set_skill("target",100);
    set_skill("elemental",100);
    set_skill("black-magic",100);
    set_skill("concentrate",100);
	set("magic_delay",1);
	set("spells/sleet",5);
    set("spells/fireball",5);
	set("special_defense", (["all":30,"none":40]) );
	set ("aim_difficulty",([ "vascular": 50, "weakest":40 ]) );
	set( "aiming_loc", "weakest" );
	set_skill( "anatomlogy", 100 );
	set ("max_hp", 440);
	set ("hit_points", 440);
	set ("wealth", ([ "gold": 35 ]) );
	set_natural_weapon( 35, 15, 20 );
	set_natural_armor( 60, 55 );
    set( "inquiry", ([
         "hotredchili" : "@@ask_chili",
           ]) );
    set( "tactic_func", "cast_spell");
    set("echo_dwarfsoldier",1);
    wield_weapon(Weapon"/dagger01");    
}

void ask_chili(object who)
{
    tell_object(who,
    "你能想像一個具有強大魔力的巨人嗎? 哈德瑞得屈裡就是這樣的一個巨人.\n"
    "他的黑暗魔法非常的可怕, 據說的他已經完全的得到邪惡之神的弟子, 暗黑\n"
    "巫妖艾思的真傳, 所以說要打敗他是非常困難的, 但是也不是沒有機會. 從\n"
    "我們派去巨人洞穴的敢死隊傳回來的消息, 一把代表著邪神YANG的神杖, 屈\n"
    "裡的法力來源, 被置放與巨人洞穴的最深處, 只要能夠衝破一道由屈裡所設\n"
    "下的禁忌, 就有機會拿到YANG的神杖, 那麼屈裡的法力就不足為懼了.\n" 
    "當然, 你必須能夠證明你是個勇者(valor),否則一切對你與我們來講, 都是\n"
    "在浪費時間而已.\n"
    );
    return ;
}

int is_a_guard( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("echo_dwarfsoldier") ) return 1;
    return 0;
}

int echo_valor(object player,object card)
{
    if (! card || ! card->query("echo_quest_card") ) return 0;
    if( (string)player->query("name") != (string) card->query("someone_id") )
          tell_object(player,
          "我想這卡片是非法得來的,而我們需要的是一個勇者,而不是賊.\n"
           );
    else {
      tell_object(player,
      "首先謝謝你肯幫助我們, 我要先告訴你一些事情,希望你能夠"
      );
      }      
    return 1; 
}

int cast_spell()
{
    object victim,*guard;
    string name;
    int i;
    
    if( !(victim = query_attacker()) ) return 0;
    
    name = victim->query("name");
   
    guard = filter_array( all_inventory(environment(this_object())),
            "is_a_guard", this_object() );
    for( i=0; i<sizeof(guard); i++ ) {
      tell_room( environment(this_object()), 
        guard[i]->query("c_name")+"為了幫助夥伴而開始攻擊你!\n", guard[i]
      );
      guard[i]->kill_ob(victim);
    }
    
    if( random(10) < 2 ) {
      command("cast sleet on "+name);
      return 1;
     }
    else if (random(10)< 2) {
      command("cast fireball on "+name);
      return 1;
      }
    else if ( random(10)<2 ) {
      tell_room( environment(this_object()), 
        "**艾爾施展群體醫療幫助他的夥伴與自己.**\n",
        this_object() );
      for( i=0; i<sizeof(guard); i++ ) 
          guard[i]->receive_heal( 25+random(20) );
      return 1;
      }  
    else return 0;   
}


