#include <mudlib.h>

inherit WEAPON ;

void create()
{
        set_name("The seven-blade", "七旋斬");
        add ("id", ({"seven","blade","the seven blade" }) );
   set_short("七旋斬");
        set_long(
                "『長離一梟』的絕招—七旋斬。\n"
        );
        set("type", "longblade");
        set("weapon_class",15);
        set("no_sale",1);
        set("no_second",1);
        set("min_damage", 5 );
        set("max_damage", 15);
        set("weight", 50);
        set("wield_func","wield_blade");
        set("value", ({ 10, "gold" }) );
	set_c_verbs( ({ 
		"%s一起，人如陀螺般轉動，忽然一掌打在%s",
		"%s『旋心動魄』一招使出，只見沙土齊飛，\n一十七掌已打在%s",
		"%s『風旋如嘯』，『雲舞流旋』接連使出，\n接連斬在%s",
	}) );
}
