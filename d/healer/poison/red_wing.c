// RedWing.c		真紅之翳
//
//	Effect: blind
//	所以只能用一次
//
//			Lilia

#include <mudlib.h>
#include <conditions.h>

inherit OBJECT;

// default value
int toxic = 1;
int diff = 50;		// 使用難度

void create()
{
    set_name("red_wing", "真紅之翳");
    add("id", ({ "red_wing" }));
    set_short("真紅之翳");
    set_long("這是一包毒藥粉，如果你要使用這包毒藥，用 poison <某人>。\n");
    set("unit", "包");
}

void init()
{
    add_action("do_poison", "poison");
}

// refer to poison.c
// 下毒失敗 , return 1 else 0
int checkfault(object me,object target )
{
        int rate,level,iq,dex,skill,kar;
        skill = (int)me->query_skill("venomlogy");
        if ( skill == 0 )
                return 1;
        level = (int)me->query_level() - (int)target->query_level();
        iq = (int)me->query_stat("int") - (int)target->query_stat("int");
        kar = (int)me->query_stat("kar") - (int)target->query_stat("kar");
        dex = (int)me->query_stat("dex") - (int)target->query_stat("dex");
// 60 % skill , 18% level, 14% dex 19%kar, total 111
        rate = skill*3/5 + dex + kar + level + iq;
        if( random(rate) > diff )
                return 0;
        else
		return 1;
}

int do_poison(string arg)
{
        object user, dest, env;
        int i, n, degree;
        user = this_player();
	env = environment(user);

        if( !arg || arg=="" || ! (dest = present(arg,env)) )
                return notify_fail( "你要對誰下毒? \n" );
        if( !living(dest) || dest == user )
                return notify_fail( "你瘋啦 ? \n" );
        if ( dest->query("no_attack") )
                return notify_fail( "你不能對這傢伙下毒。\n");
        if ( checkfault(user,dest) ) {
		tell_object(user, "你將毒煙偷偷地吹向"+dest->query("c_name")+"的眼睛.... 但是被發現了！\n\n");
		tell_room(environment(user), user->query("c_name")+"把一陣白煙吹向"+dest->query("c_name")+"....\n\n", ({user,dest}));
		tell_object(dest, user->query("c_name")+"把一陣毒煙吹向你，你迅速地避開了這煙幕！\n\n");

// 由於是失明毒藥，如果施成功還被堵住不合理。

	user->block_attack(2);

        } else {
		tell_object(user, "你將毒煙偷偷地吹向"+dest->query("c_name")+"的眼睛.... 成功了！\n\n");
                tell_room(environment(user), user->query("c_name")+"不知道用什麼方法，讓"+dest->query("c_name")+"掩著眼睛慘叫起來！\n\n", ({user,dest}));
                tell_object(dest, user->query("c_name")+"把一陣毒煙吹向你，你的眼睛忽然感到一陣巨痛！\n\n");

	degree = dest->query("blind") + 1;
    	if (degree > 10) degree = 10;
    	dest->set("blind", degree);

// 除失明外另加極輕微的毒性，不然沒有意義 (失明要到一定程度以上才有效果)
// duration 8 damage 1

	(CONDITION_PREFIX + "simple_poison")->apply_effect(dest, 8, 1);

// 施毒者陣營必須降低

	user->set("alignment",(int)user->query("alignment")-500);
        }
        //dest->kill_ob(user);
        user->kill_ob(dest);
	remove();
        return 1;
}
