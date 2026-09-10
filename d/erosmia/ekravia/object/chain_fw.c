#include <mudlib.h>
inherit OBJECT;
inherit MESSAGE;

int	busy;

void	create()
{
	set_name("chain firework", "連環煙火");
	set_short( "連環煙火");
	set( "long", "@@long_desc" );
	set( "id", ({"chain", "firework"}));
	set( "unit", "個" );
	set( "weight", 20 );
	set( "value", ({ 5000, "silver" }) );
	busy = 0;
}

void	init()
{
	add_action("do_light", "light");
	add_action("write_message", "write");
}

string	long_desc()
{
	string s;

	s = @CLONG
這是一個煙火, 不過似乎大了些。點燃 (light) 它不知道會發生什麼事...
煙火的上面有塊地方可以寫字, 上面寫著:
LONG
	;
	if (query("firework_message"))
		s = s + query("firework_message") + "\n";
	else 
		s = @CLONG1
這是一個煙火, 不過似乎大了些。點燃 (light) 它不知道會發生什麼事...
煙火的上面有塊地方可以寫字。
CLONG1
	;
	return s;
}

int		write_message( string s )
{
	string	msg, ob_name;
	object	ob;

	if (!s)	return notify_fail( "write <Your Messages> on firework\n" );
	if (sscanf( s, "%s on %s", msg, ob_name) != 2)
		return notify_fail( "你想把文字寫到哪去?\n" );
	if (!ob = present(ob_name) || ob != this_object() )
		return notify_fail( "這東西寫了也沒用\n" );
	set( "firework_message", msg );
	emote( "$NS把文字寫在煙火上\n", this_player() );
	return 1;
}

int		do_light(string s)
{
	object	ob;

	if (busy) return nnotify_fail( "這個煙火已經被點燃了\n" );
	busy = 1;
	if (!s) return notify_fail( "你想點燃什麼?\n" );
	if (!ob = present(s) || ob != this_object() )
		return notify_fail( "這裡沒有這種東西\n" );
		
	emote( "$NS將煙火點著, 然後掩住耳朵迅速地躲到一邊。\n", this_player() );
	tell_room( environment( this_player()), 
		"接著傳來一聲砰然巨響, 你看著巨大的火焰把煙火炸上半空中\n");
	call_out( "firework_effect", 10, 0, this_object() );
	return 1;
}

void	firework_effect( int life, object me )
{
	string	*cmsg, tmsg, wmsg;
	string	*s1, *s2;
	int		color;
	object	*usr;
	int		i, user_number;

	color = random (6);
	s1 = ({ "HIR", "HIM", "HIY", "HIG", "HIB", "HIC" });
	s2 = ({ "紅",  "粉紅", "黃", "綠",  "藍",  "紫" });
	
	cmsg = ({
	"「砰!」的一聲中, 一枚$C色的小火球在天空爆開, 化成無數美麗的火花。\n",
	"在天空中的火花慢慢黯淡時, 又有一顆$C色的火球飛上好高、好高的天空, 然後\n"
	"展開成為美麗的極光慢慢落下。\n",
	"在極光的背景中, 三顆火球由地面飛出, 一顆在比較低的天空中爆炸, 數以千計\n"
	"的$C色火花成拋物線飛散開來。\n",
	"第二顆火球炸開, 對稱散射的火焰形成了一朵漂亮的菊花。\n",
	"第三顆火球穿過菊花般的火焰, 高高地向上飛去, 炸開的火焰竟然形成了文字!\n"
	"上面寫著「$W」\n"
	});
	
    if(me->query("firework_message"))
    	wmsg = me->query("firework_message");
    else wmsg = "我是呆子";
    usr = users();
    user_number = sizeof(usr);
    tmsg = replace_string(cmsg[life], "$C", s2[color]);
    tmsg = replace_string(tmsg, "$W", wmsg);
    
    for ( i=0; i < user_number; i++ )
    {
    	tell_object( usr[i], set_color( tmsg, s1[color], usr[i]));
    }
    
    if (++life < sizeof(cmsg)) 
    	call_out( "firework_effect", 10, life, me);
	else me->remove();
}