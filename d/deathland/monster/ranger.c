
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	seteuid(getuid());
	set_name( "Moorth Ranger Cisklyph", "默爾斯流浪漢希斯克利夫" );
	add ("id", ({"ranger", "cisklyph"}) );
	set_short( "a moorth ranger Cishlyph ", "默爾斯流浪漢希斯克利夫" );
	set_long(@DESC
一個從默爾斯大陸流浪而來的流浪漢希斯克利夫, 他是一個多才多藝的人, 不僅是
個普通的流浪漢而已, 他還是個探險家, 科學家. 他的一生充滿著傳奇, 而且他的
知識更是非常的淵博.
但是他卻是一個很自閉的人, 喜歡孤獨地做研究. 孤獨一人思考問題. 他的朋友並
不多,書本應該是他最好的朋友吧.
DESC
	);

    set("alignment",800 );
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "個" );
	set_perm_stat( "dex", 28 );
	set_perm_stat( "str", 19 );
	set_perm_stat( "int", 29 );
	set_perm_stat( "con", 20 );
	set_perm_stat( "piety", 10);
	set_perm_stat( "karma", 30);
	set_skill("dodge",99);
	set ("max_hp", 890);
	set ("hit_points", 890);
	set ("wealth", ([ "gold": 30 ]) );
    set_natural_weapon( 44, 15, 45 );
	set_natural_armor( 88, 35 );
    set ("weight", 400);
    set("special_defense", (["all":30,"none":25]) );
    set("aim_difficulty",([ "critical":35,"weakest":30,"vascular":35 ]) );
    set( "inquiry", ([
         "muse" : "@@ask_muse",
         "annow": "@@ask_annow",
         "ruin" : "@@ask_ruin",
         "cart" : "@@ask_cart",
         "statue": "@@ask_statue",  
           ]) );
    
}

void ask_statue(object who)
{
     tell_object(who,@MSG1
這些以東北角的雕像最為奇怪, 那些雕像的底部都有一個很深的洞. 但
是卻無法瞭解到裡面有甚麼? 我也試著丟一些東西下去, 但是只傳來一
些奇怪的迴音, 而其他的雕像也是奇怪的很..
MSG1
     );
     return;     

}

void ask_cart( object who )
{
     tell_object(who ,@MSG2
對的, 那些運礦車是我建造的, 我和矮人的長老安洛是好朋友, 當他向我提起
他們的礦坑採礦的速度太慢, 須要改進的時候, 我就義不容辭的幫他建造了那
個系統了. 
MSG2
     );
}

void ask_ruin(object who)
{
    tell_object(who ,@MSG3
這座遺蹟我已經研究很久了, 這裡的文明本來很發達的, 但是一夜之間卻被邪
惡的大魔法師懷爾給毀滅了. 雖是如此, 還是有很多重要的文獻留了下來, 其
中最重要的就是謬思泉的證實. 這些地下人的探險技術是一流的, 他們似乎已
經找到了謬思泉, 但是我翻遍了所有的書籍卻無法找到詳細的記載..........
還有這座城的地底似乎有著一些隱藏的房間, 但是我始終無法找到正確的位置
. 只知道城市四個角落的雕像似乎是關鍵的所在..
MSG3
    );
}
void ask_muse( object who )
{
     object *items;
     int i;
     
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" ) 
           if (items[i]->query("quest_action/muse_filled")) {
           tell_object(who,@MSG4
你發現了謬思泉了, 很好, 這世上真的有謬思泉的存在.
傳說中謬思泉有著很多神奇的功能. 根據這裡的文獻記載著.
當年有一場很大的火災侵襲這個城市, 而當時萊特正好帶著紅
色的謬思泉回來. 一不小心萊特把泉水到灑在火上, 瞬間大火
熄滅掉了.
還有......
對不起我太嚕囌了.總之謝謝你證實了謬思的存在.
MSG4
           );     
           who->set_explore("deathland#28");
           return;
           }
      tell_object( who, 
          "如果你發現謬思泉的話, 希望你能帶一些泉水回來給我看.我會很感激你的.\n"
);
      return ;        
}

void ask_annow(object who)
{
      tell_object(who,"安洛長老, 一個有豐富知識的智者.我最好的朋友.\n");
      return ;
}

