/*
 * 原作者：Mercury (1995.1)
 * 修改者：Ishige (1995.12)
 */
#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("Evil Sword","妖刀村雨");
	add("id",({"sword"}) );
	set_short("Evil Sword","妖刀村雨");
	set_long(@AAA
這是一把傳說中的「妖刀村雨」，刀身上泛出一股詭異的光芒。據說
此刀隱含有無比強大的神秘力量，但是想要使用這種力量必須以自己
的生命作為交換。
AAA
);
	set("unit","把");
	set("weapon_class",45);
	set("type","longblade");
	set("min_damage",25);
	set("max_damage",47);
	set("weight",170);
	set("value",({130,"gold"}));
	set("hit_func","sword_damage");
	set("special_c_msg","開始吸取持刀者的生命力！！ \n"
        "妖刀村雨刀身上發出一道強烈的光芒，射入敵人的心臟！！！\n");
}

int sword_damage(object victim,int damage)
{
	object holder;
	int my_kar,dam;
	string c_msg,msg; 
	
	/*由於會損耗持刀者自己的 HP，因此有較高的 damage. */
	dam = 30;

	if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	
	my_kar = (int)holder->query_stat("kar");
	if( random(30) > my_kar/3 )
		return 0;
	else {
		c_msg = (string)query("special_c_msg");
		holder->receive_damage( 5+random(10) );
		victim->receive_special_damage( "none",dam );
		victim->set("last_attacker", holder );
		tell_object( holder,"\n你的"+query("c_name")+c_msg+"\n");
		tell_room( environment(holder),
		holder->query("c_name") + "的"+query("c_name")+c_msg+"\n",
		holder );
		return dam;
	}
}