// armsword.c
//		鎧魔劍
//
//		Lilia

#include <move.h>
#include "../lilia.h"

inherit WEAPON;

void create()
{
    seteuid(getuid());
    set_name("Magic Armored Sword", "鎧魔劍");
    set_short("鎧魔劍");
    add("id", ({"sword"}));
    set_long(@C_LONG
傳說中魔族的超級戰士斐拉尼爾的得意配劍，劍柄上刻著鑄造這把神兵的偉大
工匠亞爾羅斯的名字，這把美麗的劍，無論從任何角度欣賞，都令人由衷讚歎
鑄造者的巧思。
C_LONG
    );
    set("unit", "把");
    set("no_sale", 1);
    set("weapon_class", 35);
    set("type", "longblade");
    set("min_damage", 20);
    set("max_damage", 40);
    set("weight", 250);
    set("second", 1);
}

void wield(int silent)
{
    object p, helm, plate, arms, hands, leggings, feet;
    string s;
    p = environment(this_object());
    s = p->query("c_name");

    if( query("wielded") ) return;
    if( !p || !living(p) ) return;
    if( userp(p) && this_object()->stop_wield(p) ) return;

    if (p->query("class") != "knight" && !wizardp(p))
    {
	tell_object(p, "只有騎士才能使用鎧魔劍。\n");
	::unwield(0);
	return;
    }

    if (p->query("race") == "lizardman")
    {
        tell_object(p, "鎧魔劍發出瞭如雷鳴的聲音，你心中的恐懼使你無法使用它。\n");
	::unwield(0);
	return;
    }

    if (p->query_perm_stat("int") < 10)
    {
	tell_object(p, "這把劍的構造太複雜，你不知如何使用它。\n");
	::unwield(0);
	return;
    }

    if (wizardp(p) || p->query("npc"))
    { 
        if (p->query("armor/head") || p->query("armor/body") || p->query("armor/arms") || p->query("armor/hands") || p->query("armor/legs") || p->query("armor/feet"))
        {
            tell_object(p, "你必須卸下與鎧魔劍衝突的護具才能裝備鎧魔劍。\n");
	    ::unwield(0);
	    return;
        }
    }
    else
    {
	if (p->query("armor/body"))
	{
	    tell_object(p, "你必須卸下與鎧魔劍衝突的護具才能裝備鎧魔劍。\n");
            ::unwield(0);
            return;
        }
    }

    tell_room(environment(p), set_color(sprintf("\n%s將鎧魔劍高高舉起，大喝一聲：「鎧化！」\n\n", p->query("c_name")), "HIY"), p);
    tell_object(p, set_color("\n你將鎧魔劍高高舉起，大喝一聲：「鎧化！」\n\n", "HIY"));
    tell_object(p, set_color("鎧魔劍呼應著你的勇氣，幻化出一套盔甲。\n\n", "HIY"));

    plate = new(ARM"plate");
    plate->move(p);
    plate->equip(1);
    tell_object(p, "你順利地穿上鎧魔甲。\n");
    tell_room(environment(p), s+"順利地穿上鎧魔甲。\n", p);
    p->calc_armor_class();

    if (wizardp(p) || p->query("npc"))
    {
        helm = new(ARM"helm");
        helm->move(p);
        helm->equip(1);
        tell_object(p, "你順利地戴上鎧魔盔。\n");
	tell_room(environment(p), s+"順利地戴上鎧魔盔。\n", p);
        p->calc_armor_class();
        arms = new(ARM"arms");
        arms->move(p);
        arms->equip(1);
        tell_object(p, "你順利地戴上鎧魔臂。\n");
	tell_room(environment(p), s+"順利地戴上鎧魔臂。\n", p);
        p->calc_armor_class();
        leggings = new(ARM"leggings");
        leggings->move(p);
        leggings->equip(1);
        tell_object(p, "你順利地穿上鎧魔襠。\n");
	tell_room(environment(p), s+"順利地穿上鎧魔襠。\n", p);
        p->calc_armor_class();
        hands = new(ARM"hands");
        hands->move(p);
        hands->equip(1);
        tell_object(p, "你順利地戴上鎧魔手。\n");
	tell_room(environment(p), s+"順利地戴上鎧魔手。\n", p);
        p->calc_armor_class();
        feet = new(ARM"feet");
        feet->move(p);
        feet->equip(1);
        tell_object(p, "你順利地穿上鎧魔鞋。\n");
	tell_room(environment(p), s+"順利地穿上鎧魔鞋。\n", p);
        p->calc_armor_class();
    }

    tell_room(environment(p), set_color("鎧魔劍幻化出一套盔甲，順利地穿在"+p->query("c_name")+"的身上!\n", "HIY"), p);
    set("prevent_drop", 1);
    set("wielded", 1);
    p->calc_weapon_class();
}

void unwield(int silent)
{
    object p, firstwep, secondwep, helm, plate, arms, leggings, hands, feet;

    p = environment(this_object());

    // quit 或裝備被吃掉 (如大國師)
    if (p->query("armor/body"))
    {
    	plate = p->query("armor/body");
	plate->remove();
    }

    if (wizardp(p) || p->query("npc"))
    {
	if (p->query("armor/head"))
	{
     	    helm = p->query("armor/head");
	    helm->remove();
	}
	if (p->query("armor/arms"))
        {
            arms = p->query("armor/arms");
            arms->remove();
        }
	if (p->query("armor/feet"))
        {
            feet = p->query("armor/feet");
            feet->remove();
        }
	if (p->query("armor/legs"))
        {
            leggings = p->query("armor/legs");
            leggings->remove();
        }
	if (p->query("armor/hands"))
        {
            hands = p->query("armor/hands");
            hands->remove();
        }
    }

    set("prevent_drop", 0);

    ::unwield(0);
}

