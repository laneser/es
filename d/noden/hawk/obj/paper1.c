
#include <mudlib.h>

inherit OBJECT;
void create()
{
        set_name("paper", "小紙片");
        add( "id", ({ "paper" }) );
        set_short( "小紙片" );
        set("long","這張紙已經被你烘乾了，你可以試試(read)上面的字。\n");
        set( "weight", 3 );
        set( "unit", "張" );
}

void init()
{
        add_action("to_read","read");
}

int to_read()
{
        tell_room(environment(),(string)this_player()->query("c_name")
                +"拿起手中的紙片聚精會神的讀著，臉上一陣青一陣白，不知道"
		+"怎麼了。\n",this_player() );
        tell_object(this_player(),@LONG
你拿起紙片聚精會神的讀了起來，上面寫著：
拾起這封信的勇者，我是鳥人族的領袖維多，希望你真是一名勇者，能
為我解決我的問題。
這封信，是我的遺書，希望當你發現的時候，我的故鄉－天空之城，依
然安然的飄浮在天空中；我的族人依然如往昔一般的生活。但是，天空
之城所面臨的危機依然存在，強大的敵人虎視耽耽的覬覦著鳥人的財富
與天空之城神秘的力量....
勇者，我懇求你，到諾頓王國找到我的墓，取得我的戒指，以此為信物
到天空之城尋找柏妮絲，我的愛妻，她將會協助你，讓你瞭解一切你所
該知道的，並請為我好好照顧柏妮絲，讓她不會受到我的敵人們的傷害

感謝你....勇者....
                                        維多
LONG
        );
        return 1;
}

