#include <mudlib.h>

void create(object ob)
{
        if ( !ob ) return ;
	ob->set_level(4);
	ob->set_name("bandit", "強盜");
	ob->set_short("強盜");
	ob->set_long(
		"這個人滿臉橫肉，一副凶神惡煞的樣子，如果你不想打架的話\n"
		"最好離他遠一點。\n"
	);
	ob->set( "unit", "名" );
	ob->set_perm_stat("str",6);
	ob->set_perm_stat("con",8);
	ob->set_skill("shortblade", 50 );
	ob->set( "race", "orc" );
	ob->set( "gender", "male" );
	ob->set( "wealth/silver", 10 );
	ob->set( "natural_armor_class", 30 );
	ob->set( "alignment", -500 );

	ob->set( "chat_chance", 5 );
	ob->set( "chat_output", ({
		"強盜說道: 此路是我開，此樹是我栽，要想從此過，留下買路財！\n",
		"強盜伸手把你向後推了幾步。\n",
		"強盜臉露獰笑，大聲說: 把所有的錢留下來，不然老子割你脖子！\n"
	}) );
	ob->set( "att_chat_output", ({
		"強盜大叫大跳，氣得吹鬍子瞪眼睛。\n",
		"強盜大喝: 小子！你真的不要命了嗎？\n",
		"強盜欺身上前，想要掐住你的脖子。\n"
	}) );

	ob->wield_weapon("/d/noden/item/short_sword");
	ob->equip_armor("/d/noden/item/wooden_shield");
}
