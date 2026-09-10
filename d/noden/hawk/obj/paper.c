
#include <mudlib.h>

inherit OBJECT;
void create()
{
        set_name("paper", "小紙片");
	add( "id", ({ "smore_paper","paper" }) );
        set_short( "小紙片" );
        set("long","這張紙放在水裡很久了，因此整張紙都溼答答的，看不清楚上面的字。\n");
        set( "weight", 10 );
        set( "unit", "張" );
}

void init()
{
        add_action("to_stare","stare");
}

int to_stare(string s)
{
        if (s != "paper") return 0;
        if ((s == "paper") && (this_player()->query_temp("drink_water")==3))
        {
                tell_object(this_player(),
                        "你仔細地看著這張潮溼的紙片，左上角的部份隱隱約約的"+
                        "寫了幾個字：\n柏妮....，倫..夫在比....會....裘..根.."+
                        "......\n    看了半天你還是不知道在寫些啥....或許把"+
                        "紙烘乾再看會是個好主意....。\n");
                return 1;
        }
        if ((s == "paper") && (this_player()->query_temp("drink_water") <3))
        {
                 tell_object(this_player(),
                     "你仔細的看著這張潮溼的紙片，啥都看不清楚，不過好像"+
                     "隱隱約約的看到一個\n女人的臉孔正對你陰惻惻的笑著。\n");
                 return 1;
        }
}
