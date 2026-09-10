#include "/d/eastland/story/story.h"

inherit MONSTER ;

void create ()
{
	::create();
	set_level(19);
	set_name( "Wing Archelder Queen", "羽後" );
	add ("id", ({ "elder","archelder","queen"}) );
	set_short( "羽民族大首領 羽後");
	set_long(@CLONG
一個歲數很大的羽民族人；他滿臉皺紋縱橫，牙齒業已掉落大半，翅膀漸漸退化只
剩下兩個突起的肉瘤，彎腰駝揹走起路來一□一□的全□著手中木杖攙扶。雖然他
年紀大，頭腦相楚清楚一點也不含糊，平時果斷公正兼之閱歷豐富遂成了村中最有
權威的人，凡事悉聽他裁決。羽後同時是個可怕的施法者，即使是小小的法術一到
他手中便會變得威力無匹，厲害非常。
CLONG
	);
	set("gender","male");
        set("race","羽民");
	set_perm_stat("str", 25 );
        set_perm_stat("dex", 30 );
        set_perm_stat("kar", 25 );
        set_perm_stat("int", 30 );
	set( "alignment", -1000000 );
	set( "hit_points", 1800 );
	set( "max_hp", 1800 );
        set( "max_fp",500);
        set( "force_points",500);
        set( "weight",100);
        set_natural_weapon( 35, 25, 40 );
	set_natural_armor( 69, 48 );
        set("aim_difficulty",([ 
    	  "critical":80,"weakest":50,"vascular":40,"ganglion":50 ]) );
        set("wealth/gold",200);
        set("stun_difficulty",100);
        set_temp("bs",10);
        set_temp("be_joke",3);
        set("conditions/_heal_hp",({ 4 , 1 }) ) ;
        set_skill("concentrate",100);
        set_skill("target",100);
        set_skill("black-magic",100);
        set_skill("elemental",100);
        set_skill("dodge",100);
        set_skill("parry",80);
        set_skill("wand",90);
        set("spells/lightning",2);
        set("spells/ether-bolt",6);
        set("spells/flare",2);
        set("spells/sleet",4);
        set("spells/fireball",6);
        set("spells/heart-griping",4); 
        set("guild_levels/black-magic",50) ;
        set("guild_levels/elemental",50);
        set("guild_levels/guild",50);
        set("tactic_func","my_tactic");
        set("magic_delay",2);
        wield_weapon(SWEA"imp_wand");
        equip_armor(SARM"imp_leggings");
        equip_armor(SARM"imp_cloak");
        equip_armor(SARM"imp_ring");
        equip_armor(SARM"imp_amulet");
        equip_armor(SARM"imp_cloth");
        set("special_defense",(["all":100,"monk":30,"scholar":30,"none":40,"energy":30]));
        set( "inquiry", ([
          "forbidden_ground":"@@ask_help",
                   "history":"@@ask_history",
             "great_vampire":"@@ask_vampire",
                 "fly_flute":"@@ask_flute",
              "flute_energy":"@@ask_energy"
        ]) );
        set("chat_chance",10);
        set("att_chat_output",({
              "羽後嘲笑你的無知：哼，吾人寶刀未老尚可斬汝老賊，還不速退！\n",
        }) );
}
void init()
{
   ::init();
   add_action("do_embattle","embattle");
}
void ask_energy(object asker)
{
write(@LONG
羽後說道：「飛翔之笛」的能源？噢，「飛翔之笛」是以「天堂之水」(heaven_water)
          為發動能源的，至於「天堂之水」在那裡，我一點頭緒都沒有，你去請教高
          人吧。
LONG
   );
}
void ask_flute(object asker)
{
   asker->add_temp("flute_asked",1);
write(@LONG
羽後說道：你問「飛翔之笛」？喔，我已經把它借給「巫咸城」之主－「巫羅王」
　　　　　了，你就帶我的口信去跟他要吧。   
LONG
);
}
void ask_vampire(object asker)
{
write(@LONG
羽後說道：妖□谷辰乃修練萬年的僵□，他早在千年前被人收伏。最近
　　　　　聽人說起，它又出來為害世間，如果能收伏它，將是第一功德
　　　　　。妖□谷辰幾乎毫無弱點可言，惟一怕的是「滅魔符」(ghost
          -killed spell)，若你想收伏它，那怕是千辛萬苦，都要找出
          來，很抱歉，我不知道現在那符的下落，你還是多去打聽打聽
          。　　　　　
LONG
   );
}
void ask_help(object asker)
{
   write(@LONG
羽後說道：傳說在我們居住村落的北方有個禁地，那裡設有某種禁制，
　　　　　需要穿著天神祝福的防具通過才能確保無虞，所以一般人是
　　　　　無法輕易到那裡去的。說起天神祝福的防具，我身上就有一
　　　　　件，不過，我是不可能輕易給你的。
LONG
   );   
}
void ask_history(object asker)
{
   write(@LONG
羽後說道：千百年前，吾人本是黃帝手中一員驍將，多建功績。因感歲月
　　　　　如白駒過隙，又感手中殺伐之多，特於蚩尤戰敗之後，得準告
　　　　　老還鄉，但因家園飽受戰禍摧殘不復往昔，遂覓得此處招得鄉
　　　　　人若干準備長住於斯，順便為玉帝看守北方禁地，千百年來，
　　　　　不曾涉及塵事。由於長期住在地上，吾族飛行的能力也就消失
　　　　　了。　   
LONG
   );
}
int my_tactic()
{
    int i,k;
    object victim;
    
    string power,name;
    if ( !victim=query_attacker() ) return 0;
    set( "force_points",500);
    if ( random(8)> 1 ) return 0;
    if ( query_temp("cast_busy") ) return 0;
    k=1+random(2);
    switch ( k ) {
    case 1 :
        power="max";
        break;
    default : 
        power="minor";    
        break;
    } 
    name=victim->query("name");
    for ( i=0;i<k;i++ ) {
       switch ( random(6) ) {
         case 0:command(sprintf("cast %s fireball on %s",power,name));
                break;
         case 1:command(sprintf("cast %s sleet on %s",power,name));
                break;
     	 case 2:command(sprintf("cast %s flare on %s",power,name));
                break;
         case 3:command(sprintf("cast lightning on %s",name));
                break;
         case 4:command(sprintf("cast %s ether-bolt on %s",power,name));
                break;
         case 5:
                command(sprintf("cast %s heart-griping on %s",power,name));
                break;
         default :
                command("say 有蟲蟲:~~\n");
                break;
       }
    }
    set("stop_attack",0);
    return 1;
}
void die()
{
     set("alignment",2000);
     ::die();
}
