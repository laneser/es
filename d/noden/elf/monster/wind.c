#include "/d/noden/elf/layuter.h"
inherit MONSTER;

void create()
{
        ::create();
        set_level(7);
        set_name( "icers", "艾瑟斯" );
        set_short( "艾瑟斯");
        set("unit","位");
        set_long( @LONG
艾瑟斯是一位才氣縱橫的雕刻家，在他的一生中創造了不少
不朽的傑作，例如廣場上的希納斯雕像，就是他花了五年的時光所
完成的曠世鉅作，但是他最近陷入創作的低潮，他沒有創作的靈感
與慾望，正到處走來走去，好像很無助的樣子，不知你是否可以幫
助(help)他。
LONG
        );
        set_perm_stat("str", 10);
        set_natural_weapon(10, 6, 10);
        set_natural_armor( 30, 14 );
        set ("gender", "male");
        set ("race", "elf");
        set_c_verbs(({"%s用他的雕刻刀向%s刺去","%s用他的腳向%s踢去","%s用他的拳頭向%s攻擊"}));
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        wield_weapon(LWEAPON"guard_sword");
        equip_armor(LARMOR"wind_cloak");
        equip_armor(LARMOR"wind_boots");

        set("inquiry",([
           "help": 
                   "我心愛的雕像(statue)不見了，它是我心靈的寄託，沒有了它我不知道\n"
                   "活在這世上有何意義，而我以前如泉湧般敏捷的靈感也因而消失殆盡，你是否可以幫\n"
                   "我找回它呢?\n",
           "statue": 
                   "那是高25公分石雕作品,是我為我太太□□□所刻的雕像,還記的那天是她\n"
                   "28歲生日，當我把雕像放在她的面前時，她喜悅地抱著雕像旋轉飛舞，仿如一個快樂 \n"
                   "的小天使，我永遠也忘不了那一夜的情景，希望你幫我找回來，我想一定是某人偷(steal)\n"
                   "了他。\n ",
           "steal": 
                   "最近村裡時常掉東西，我想一定有人在背後作怪，但是我們各處都找遍了\n"
                   "，就是沒有找到任何的蛛絲馬跡，本來我們想進入惡魔迷宮搜查，但是從迷宮傳出的\n"
                   "怪物嚇退了我們。唉!雕像你到底在哪裡。\n"
      ]));
}

int accept_item(object player, object ob)
{
    if( !ob || !(ob->query("get_my_statue")) ) return 0;
	if( (string)ob->query("killer") != (string)player->query("name") ) {
		tell_object(player,
			"非常感謝你為我帶回我心愛的雕像，我又有創作之心了，願神永遠保護你\n"
			"如果他日有空，請順便與那位找回雕像的英雄同來，讓我好好謝謝你們!!\n"
			 );
		tell_room(environment(player), 
			"艾塞斯把他心愛的雕像收藏起來。\n");
		ob->remove();
		return 1;
	}

    tell_object(player,
       "非常感謝你為我帶回我心愛的雕像，我又有創作之心了，願神永遠保護你。\n"
       );
    if( (int)player->query_quest_level("icers") < 1 ) {
       player->finish_quest("icers",1);
       player->gain_experience(10000);
       tell_object(player,
          set_color("[你完成雕刻家艾瑟斯的任務，得到 10000 點經驗值]\n","HIY",player));
       }
       ob->remove();
       tell_room(environment(player), 
           "艾塞斯把他心愛的雕像收藏起來。\n");
	return 1;
}
