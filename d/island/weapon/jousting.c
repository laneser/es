/*
 * 原作者：Ishige (1995.1)
 * 修改者：Ishige (1995.12)
 */

#include <mudlib.h>

inherit WEAPON;

string C_NAME=("[36;1m□[0;36m□[36;1m□[0;36m@[36;1m□[0;36m□[36;1m□[0;36mu[37m");
void create()
{
	set_name( "Ultima Trident",C_NAME );
	add( "id",({ "jousting","trident" }) );
	set_short( C_NAME );
	set_long(@LONG
	這是把世間罕見的神兵利器，擁有這把神兵利
	器是許多騎士終生最大的願望，只可惜已經不
	知道有多少人為了這把神兵利器而喪失寶貴的
	性命。
LONG
		);
	set( "unit","把" );
	set( "type","jousting" );
	set( "weapon_class",45 );
        set( "min_damage",25 );
        set( "max_damage",52 );
	set( "weight",200 );
	set( "value",({ 5600,"silver" }) );
	set( "nosecond",1 );
	set( "prevent_insert",1 );
	set( "hit_func","hit_fun" );
}

string ex_look(){
return (set_color("$N","HIY")+"手上的"+C_NAME+"有股[31;5m開天闢地[37;0m的氣勢！\n$N看起來有如"+set_color("天神降世","HIB")+"一般。\n" );
}

void wi_fun()
{
	set("extra_look","@@ex_look");
	return;
}

void unwi_fun()
{
	delete( "extra_look");
	return;
}

int hit_fun(object victim,int dis)
{
	object holder;
	int dam,skill,point;
	string name1,name2;
	
	if( !victim ) return 0;
	if( !(holder=environment( this_object() )) || !living(holder) ) return 0;
	if( !(holder->query("justice")) ) return 0;
	point = (int)holder->query("justice");
//	if( point < random (2000) ) return 0;
	if( point <= 1000 ){ dam=5; }
	else if( point > 1000 && point <= 3000 ){ dam=10; }
	else if( point > 3000 && point <= 8000 ){ dam=20; }
	else if( point > 8000 && point <= 17000 ){ dam=30; }
	else if( point > 17000 && point <= 60000 ){ dam=40; }
	else if( point > 60000 ){ 50; }
	
	skill=(int)holder->query_skill("jousting");
	name1=holder->query("c_name");
	name2=victim->query("c_name");
	
	if( random(100) > (15+(skill-100)) ) return 0;
	
	tell_room(environment(victim),"\n"+C_NAME+"的"+set_color("神聖力量","HIW")+"，激發了"+name1+"的力量，對"+name2+"造成了[34;1;5m「難以估計」[37;0m的傷害。\n\n",holder);
	tell_object(holder,"\n"+set_color("神聖的力量","HIW")+"充滿了你的身軀，你發出了"+set_color("「超乎想像」","HIC")+"的一擊！\n\n" );
	holder->add("justice",-4);
	victim->receive_special_damage( "divine", dam );
	victim->set("last_attacker",holder);
	return dam;
}
