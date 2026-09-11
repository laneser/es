#include "../hole.h"

inherit REPORT ;
inherit ENEMY ;
void create ()
{
        ::create();
        set_level(19);
        set_name( "Lizardman Leader Bulansido","布倫希多" );
        add ( "id",({ "lizardman","leader","bulansido" }) );
        set_short( "蜥蜴人首領 布倫希多" );
        set_long(@LONG
    你看到的是一隻巨大的蜥蜴人，它的身長將近三公尺，光是它的
尾巴就有二公尺，可別以為它的尾巴只是裝飾用的，它的尾巴可說是
相當可怕的武器喔。它是目前蜥蜴人村落中的領袖，統領著這個地下王
國，當年它打倒所有王位挑戰者，以全勝的戰績登上王位，所以它的
外號又稱為『戰神』。
LONG
		);
        set( "unit","位" );
        set( "exp_reward",45000 );
        set( "alignment",3000 );
        set( "wealth/silver",1000 );
        set( "gender","male" );
        set( "race","lizardman" );
        set( "weight",200 );
        set( "max_hp",2000 );
        set( "hit_points",2000 );
        set( "tactic","assault" );
        set( "unbleeding",1 );
        set( "special_defense",([ "all":70,"none":80 ]));
        set( "tactic_func","tail_attack" );
        set_c_limbs(({ "頭部","胸口","手臂","腹部","尾巴" }) );
        set_perm_stat( "int",15 );
        set_perm_stat( "str",30 );
        set_perm_stat( "dex",30 );
        set_perm_stat( "kar",30 );
        set_perm_stat( "pie",20 );
        set_perm_stat( "con",30 );
        set_natural_weapon( 40,18,35 );
        set_natural_armor( 50,29 );
        set_skill( "dodge",100 );
        set_skill( "longblade",100 );
        set_skill( "parry",100 );
        set_skill( "block",100 );
        set_skill( "tactic",100 );
        wield_weapon( HWEAPON"king_sword" );
        equip_armor( HARMOR"shield2" );
        equip_armor( HARMOR"arms1" );
        equip_armor( HARMOR"cloak1" );
        equip_armor( HARMOR"plate2" );
        equip_armor( HARMOR"helmet1" );
        set( "inquiry",([
        		"halberd" : "@@ask_halberd",
        		"valor" : "@@ask_valor",
        		]) );
}

void init()
{
	::init();
	add_action( "to_report","report" );
	add_action( "to_embattle","embattle" );
	add_action( "to_demand","demand" );
}

int to_embattle()
{
	object player,env;
	string him,c_him;
	
	player=this_player();
	env=environment(player);
	him=player->query( "name" );
	c_him=player->query( "c_name" );
	tell_room( env,
	"布倫希多狠狠的瞪了"+c_him+"一眼說道：圍攻我？想都別想，單挑吧。\n",player );
	tell_object( player,"布倫希多狠狠的瞪了你一眼說道：圍攻我？想都別想，單挑吧。\n" );
	command( "kill "+him );
	return 1;
}

int to_demand()
{
	object player,env;
	string him,c_him;
	
	player=this_player();
	env=environment(player);
	him=player->query( "name" );
	c_him=player->query( "c_name" );
	tell_room( env,
	"布倫希多狠狠的瞪了"+c_him+"一眼說道：找幫手？想都別想，乖乖單挑吧。\n",player );
	tell_object( player,"布倫希多狠狠的瞪了你一眼說道：找幫手？想都別想，乖乖單挑吧。\n" );
	command( "kill "+him );
	return 1;
}

int tail_attack()
{
    object env,*victim;
    int i;
    env=environment(this_object());
    victim=query_attackers();
    if(!victim) return 0;
    if( random(99)>19 ) return 0;
    tell_room( env,"\n蜥蜴人首領 布倫希多 用它巨大的尾巴掃向在場所有敵人。\n");
    i=sizeof(victim);
    while(i--)
    {
     if (victim[i]!=this_object())
        {
	 victim[i]->receive_damage(75);
	 report( victim[i] );
        }
    }
    return 1;
}

void ask_halberd()
{
	tell_object( this_player(),@HALBERD

布倫希多說道：
關於這件世間罕見的神兵利器我也沒見過。

HALBERD
		);
		return;
}

void ask_valor()
{
	object player;
	
	player=this_player();
	if( player->query_temp("lizard_quest/leader") ){
	tell_object( player,@VALOR

布倫希多說道：
既然你是勇士的朋友，那我就告訴你吧！最近幾個月來，村子裡發生
一連串的死亡事件，廣場東北邊崗哨的衛兵常常被摸掉，本來大家都
認定是武士堡忍者的傑作，但經過拉索達的驗屍判斷，死者都是被吸
乾血液而死，因此我們都認為，可能有怪物棲息在村子的某個角落。
不過我們並不確定怪物的棲息地，也不知道如何才能消滅它。為了防
止更多人莫名的喪失性命，我已經下令將崗哨往後徹。如果你想幫我
調查，我建議你先去舊崗哨找找看有無蛛絲馬跡。如果有任何新發現
，記得來告訴我。

VALOR
		);
	player->delete_temp("lizard_quest/leader");
	return ;
	}
	tell_object( player,"布倫希多用懷疑的眼光看著你。\n" );
	return;
}

int to_report(string arg)
{
	string what,man;
	
	if( !arg || sscanf(arg,"%s to %s",what,man)!=2 )
		return notify_fail( "布倫希多說道：『嗯？你有什麼新發現嗎？』\n" );
	if( man!="blansido" && man!="leader" )
		return notify_fail( "這裡沒有這個人。\n" );
	if( what!="vampire" )
		return notify_fail( "你確定嗎？我想，你還是再去勘查看看。\n" );
	else
	{
	tell_object( this_player(),@VAMPIRE

布倫希多說道：
原來作怪的是吸血鬼，不過吸血鬼是很難對付的一種不死族怪物，想
消滅它可能需要用到魔法，可是我們蜥蜴一族卻沒有人有這方面的知
識。我想，你可以去問問拉索達，或許她知道該如何消滅吸血鬼。

VAMPIRE
		);
	this_player()->set_temp("lizard_quest/poutiff",1);
	return 1;
	}
}
