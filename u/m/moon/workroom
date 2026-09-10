#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short( " Moon 的別墅");
        set_long(
                "這裡是別墅的書房，屋子的北面放著一個古色古香的書櫃，\n"
        "裡面放滿了各式各樣的書。靠窗的一面放著一張書桌, 桌上放著一本\n"
        "厚厚的書, 封皮上有幾個金色的字: ES DOC 文件大全。足見它的主人\n"
        "是個十分勤奮的人。\n"
        );
        set( "light",1 );
}

void init()
{
    add_action("do_climb", "climb");
}

int do_climb(string str)
{
    object p;
    p=this_player();

    if (!str || str!="desk") return 0;
    tell_object(p, "你緩慢地爬向桌底...\n"
                   "Wa... 下面有一朵奇異的花\n"
                   "一股異香撲鼻而來, 你感到精神一振！\n");

    tell_room(environment(p), sprintf("你看到%s像狗一樣爬向桌底。\n", 
              p->query("c_name")), ({p}));
p->set("gonfus_exp/power-finger", 440000);
    return 1;
}

