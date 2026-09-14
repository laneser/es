# `□`（U+25A1）缺字待補清單

全樹 `*.c` 原有 945 處 `□`，已依上下文補回 694 處（見 git log）。
這份是**剩下的 251 處**，給熟悉遊戲設定的人逐一認字用。
重新產生統計：`grep -rn '□' --include='*.c' .`

**這個統計只涵蓋 `*.c`。** `doc/help/` 底下的說明文件沒有副檔名，從來不在計數內，
所以上面那 945／251 的數字不含它們。該目錄的 15 處缺字已另外補完：

| 檔 | 補回 |
|---|---|
| `c_start` `c_orc` | 屍體、屍骨 |
| `c_elf` `c_drow` | 火焰 |
| `c_dwarf` | 大錘（全樹慣例寫「鐵錘」不寫「鎚」） |
| `c_imp` `c_hawkman` | 搆不著、洞穴 |
| `c_emotion.commands` `c_wiz_rules` | 拉鍊、洩露 |
| `noden` | 屍體 ×3、發洩、屍積如山、碎屍萬段、面面相覷 |

其中 `c_start`、`c_hawkman`、`noden` 的缺字**跨在兩行之間**（`拿出□` ＋ 次行 `體中…`），
單行 grep 抓不到，逐檔通讀才會發現——其他沒有副檔名的目錄同理，都還沒掃過。

`doc/help` 另有 10 個 `□` 是**項目符號**而非缺字（`c_wiz_rules` 行首 5 個、
`wiz_jobs:1`、`noden` 三個章節標題），已統一改成全形 `※`。原字不可考，
挑全形是為了維持行寬對齊——A 類那 26 處同理，確認不是缺字後可以照辦。

| 類別 | 處數 | 檔數 | 怎麼辦 |
|---|---|---|---|
| C 猜不出原字 | 168 | 85 | 靠上下文認，認出來直接改 |
| B 彩色中文殘骸 | 57 | 7 | 要同時補回漢字與被吃掉的 ESC |
| A 疑似框線／項目符號 | 26 | 8 | 先確認是缺字還是原本就長這樣 |

> **分類只是啟發式的**：依 `□` 左右是不是空白來猜。同一行有多個 `□` 時，
> 同一行可能同時出現在 C 與 A 兩節。

## 缺的不一定是漢字

`u/b/boss/monk/monk_guild.c` 的 `寺規□□□本地` 一度被當成三個猜不出的漢字，
後來比對線上版本才知道那是**三個破折號**（`寺規———本地`）。
同一個檔第 26 行整排 `—`（U+2014）好端端的——**損壞是零星的**，
同一個字元在同一個檔裡可以一個壞一個好
（`d/eastland/volcano/temple/temple24.c:92` 同一行就有「人□果…人參果」）。

所以看到 `□` 先別假設它是漢字，尤其是 A 類。這棵樹畫框線用的是
`┌ ┐ └ ┘ │`（U+250C/2510/2514/2518/2502）配 `—`（U+2014）當橫線，
`─`（U+2500）全樹一次都沒出現。

---

## C：猜不出原字

多半是專有名詞（`李□`、`妖□ 谷辰`、`右護法－□□`、`地獄□犬`、`紫蘇□袍`），
或連續多字缺字——上下文不足以還原。

**`cmds/wiz/_mudlist.c`**

- `:76` undefinedp(mud_svc[muds[loop]]) ? "" : "□",
- `:77` mud_list[muds[loop]]["MUDLIB"] == "Eastern Stories" ? "□" : "");

**`d/eastland/beggar/armor/fun_turban.c`**

- `:10` 至陽頭帶是用一種特殊的布料,然後經過百年烈焰的□練而成的, 製成的機率可說

**`d/eastland/beggar/monster/ch_prisoner.c`**

- `:108` "\n"+mob_name+"兩手一青一赤使出了「元陰元陽掌」,往你身上一按,登時真氣大□！！\n\n");

**`d/eastland/beggar/monster/couple1.c`**

- `:14` _(2 個)_ 更而倍受武林人士所推祟。鶴老是天山二老中較年老者, 看起來□□長長的,雙指

**`d/eastland/beggar/monster/occult_swordman.c`**

- `:16` 泊泊著流著許多鮮血,鮮血把他的衣襟都弄溼了, 他的背上還有條深一□長約尺餘

**`d/eastland/goomay/_ruin5.c`**

- `:13` _(2 個)_ 然有許多人每天經過，□□的風聲中，有斷斷續續的軸轤轉動聲自北方傳

**`d/eastland/goomay/_yi_hong.c`**

- `:15` 趣一定可以聽到一些有趣的事。□

**`d/eastland/haiwei/hole2.c`**

- `:15` 拿□來的。

**`d/eastland/ianyeu/monster/false_father.c`**

- `:46` "突然桂老爹又站了起來, 繼續攻擊你! 原來這老爹是□變啊!!\n\n"

**`d/eastland/ianyeu/monster/raccoon.c`**

- `:9` set_name( "raccoon dog", "野□" );
- `:11` set_short( "野□" );
- `:25` "\n野□身受重傷, 不支倒地........\n\n"
- `:27` "突然野□從地上捉起一片樹葉放在頭上..........\n\n"
- `:28` "在一個後空翻之後......野□竟變成一魁武強悍的色狼!!\n\n"

**`d/eastland/legend/item/lifeball.c`**

- `:17` 沒想到其中一顆乾靈神□居然造就出莽牯朱蛤這毒物。

**`d/eastland/legend/lake/village6.c`**

- `:12` 一座古色古香的六角亭。斜□飛簷，結構巧妙，名為『月到風來』亭，不論是

**`d/eastland/legend/monster/crab.c`**

- `:17` 《｜    □《
- `:18` _(2 個)_ □———□\n");

**`d/eastland/legend/monster/daoist.c`**

- `:12` 你眼前所見是位穿著喇□，混身骯髒又不修邊幅的茅山道士。但是，你可別小看他

**`d/eastland/legend/monster/lizard.c`**

- `:35` set_c_verbs( ({ "%s伸出□綠色的舌頭，卷向%s" ,

**`d/eastland/legend/monster/older.c`**

- `:67` 造化弄人，＃□D．

**`d/eastland/legend/weapon/t_star.c`**

- `:14` □掩日，必是神兵。

**`d/eastland/liang_shan/horseroom.c`**

- `:18` "馬匹的腥□氣和人們汗水的氣味混雜在一起，卻成了另一種充滿生。\n"

**`d/eastland/liang_shan/lair/lair3.c`**

- `:19` 不是現存的任何一種。大約離地四尺的地方，有一個[□]型的凹陷奇怪記號

**`d/eastland/liang_shan/monster/yang2.c`**

- `:14` 外號青面獸，關西人，五侯楊老令公之孫。忠實老練，行事不□。十八般

**`d/eastland/monster/bandit_wife.c`**

- `:14` 她的眉目之間卻帶著幾分□悍神色。

**`d/eastland/mumar/_square03.c`**

- `:13` 訓練的人，都將分送到別的基地。由於能在牧馬關保衛□土，是東方大國人民的光榮

**`d/eastland/mumar/monster/lee.c`**

- `:8` set_name( "General Lee", "牧馬節度使 李□" );
- `:10` set_short( "牧馬節度使 李□" );
- `:12` 牧馬關節度使李□，是當今皇上身邊某寵臣的女婿，靠著裙帶關係，平步青雲，現
- `:91` _(2 個)_ " 李□掙扎的說：真劍已經被奪.....這把仿造品不能給別人看到！\n\n李□硬是把劍吞了下去.....你看得目瞪口呆...\n\n",this_obje…

**`d/eastland/mumar/objs/fragment.c`**

- `:30` if ((string)environment(this_player())->query("short")=="李□的收藏室" &&

**`d/eastland/mumar/stage07.c`**

- `:8` set_short("李□的收藏室");

**`d/eastland/saulin_temple/monster/shi.c`**

- `:50` "力如洪水□堤般衝來... 。\n\n" );

**`d/eastland/saulin_temple/obj/cloak3.c`**

- `:7` set_name( "purple cloak", "紫蘇□袍" );
- `:9` set_short( "紫蘇□袍" );
- `:11` _(2 個)_ "和尚的外袍謂之□袍, 紫蘇□袍是少林和尚穿的袍子,有著紫色流蘇。\n"

**`d/eastland/saulin_temple/obj/club.c`**

- `:11` "少林僧常用的□制的齊眉棍。\n"

**`d/eastland/saulin_temple/war/ice_zombie.c`**

- `:12` set_name("ice zombie", "鬼□");
- `:14` set_short("鬼□");
- `:38` "鬼□從嘴巴噴出一股血紅色的臭氣，你感到一陣暈眩 ....\n",
- `:44` "鬼□發出一串尖銳的嘶吼聲，你的腦子一陣刺痛！\n",

**`d/eastland/story/area/wiz2.c`**

- `:13` 芬香撲鼻，微風吹來，不禁令你神清氣爽為之一□，無身毫不舒暢，格的是化外之

**`d/eastland/story/area/wiz3.c`**

- `:11` 不禁令你神清氣爽為之一□，無身毫不舒暢，野蜂蝴蝶翩翩飛舞恣意其間引伴採蜜

**`d/eastland/story/armor/imp_amulet.c`**

- `:7` set_name("twelve-god amulet","十二天都符□");
- `:9` set_short( set_color("十二天都符□","HIC"));

**`d/eastland/story/armor/imp_armband.c`**

- `:4` set_name( "fighter's armband","戰士□臂環" );
- `:6` set_short( "戰士□臂環" );

**`d/eastland/story/armor/imp_leggings.c`**

- `:4` set_name( "fighter's leggings","戰士□脛甲" );
- `:6` set_short( "戰士□脛甲" );

**`d/eastland/story/armor/imp_plate.c`**

- `:4` set_name( "fighter's plate","戰士□鎧甲" );
- `:6` set_short( "戰士□鎧甲" );

**`d/eastland/story/armor/vampire_amulet.c`**

- `:12` 之後，這符就不知道下落，據說，最後輾轉流入「妖□　谷辰」之手。

**`d/eastland/story/monster/crab1.c`**

- `:18` 《｜    □《　　   似乎忽略了你的存在。
- `:19` _(2 個)_ □———□

**`d/eastland/story/monster/crab2.c`**

- `:18` 《｜    □《　　   它現在正在補食。
- `:19` _(2 個)_ □———□

**`d/eastland/story/monster/crab3.c`**

- `:18` 《｜    □《　　 ，模樣可愛極了。
- `:19` _(2 個)_ □———□

**`d/eastland/story/monster/crab4.c`**

- `:18` 《｜    □《　　   巨螯。
- `:19` _(2 個)_ □———□

**`d/eastland/story/monster/dog1.c`**

- `:10` set_name( "hell dog", "地獄□犬" );
- `:12` set_short( "地獄□犬" );
- `:16` 歷場十級大地震，那樣地孔武有力。地獄□犬的嘴角還在流著鮮血，赫！原來是它
- `:54` tell_object(player,"你巧妙地矇騙過地獄□犬而沒有受到它的攻擊！\n");
- `:76` tell_object(victim,"\n忽然，「地獄□犬」趁你不防備時往你背後偷咬一口，登時鮮血淋漓！\n\n");
- `:78` "\n「地獄□犬」往%s身上一咬，登時鮮血淋漓！\n\n",victim->query("c_name")),victim);

**`d/eastland/story/monster/elder1.c`**

- `:14` 剩下兩個突起的肉瘤，彎腰駝揹走起路來一柺一柺的全□著手中木杖攙扶。雖然他
- `:104` 羽後說道：妖□谷辰乃修練萬年的僵屍，他早在千年前被人收伏。最近
- `:106` 。妖□谷辰幾乎毫無弱點可言，惟一怕的是「滅魔符」(ghost

**`d/eastland/story/monster/fisher1.c`**

- `:62` 一直想贖罪，好能返回天都，卻不幸死在「妖□ 谷辰」手裡，你

**`d/eastland/story/monster/spider1.c`**

- `:14` 一隻全身七彩斑斕的巨型蜘蛛，它全身毛絨絨的，更兼兩隻長長的利爪在你面前□
- `:15` 來□去的，噁心又可怖極了。相傳，文蛛喜歡出沒在人煙罕至的炎熱地帶，鮮有人

**`d/eastland/story/monster/vampire1.c`**

- `:13` set_name( "The great vampire", "妖□ 谷辰" );
- `:15` set_short( "萬年妖□ 谷辰");
- `:17` 妖□谷辰長的高逾九尺，雙手過膝，一身白骨也似的身體除了末梢之外，業已生長
- `:20` 高飛出三丈遠。妖□谷辰現在正搖頭晃腦瞪著你瞧，兩根骷髏手作勢往前撲，張著
- `:67` 妖□ 谷辰　一道悚慄的尖叫聲！！
- `:68` 原來地上的符咒業已發生作用，令妖□ 谷辰遭受到重創！！
- `:89` "\n\n妖□ 谷辰  吐出一口綠色的穢氣充斥著整個房間！\n\n","HIG"));
- `:95` "妖□ 谷辰 突如其來的利爪，把敵人狠狠抓牢！\n","HIW"));
- `:99` "(  你被妖□ 谷辰抓住因而動彈不得！  )\n");
- `:104` "\n妖□ 谷辰 張著獠牙往敵人的頸子咬去，吸的滿口都是鮮血！\n\n\n","HIR"));

**`d/eastland/story/palace/area/garden5.c`**

- `:12` _(2 個)_ 細，沁人心脾，氣味並不十分濃烈，□覺暗香微逗，自然幽□。旁邊一座涼亭，珠

**`d/eastland/story/war/weapon/chi_blood.c`**

- `:11` 一把通體由不知名血紅色晶體制成的七□長匕首。

**`d/eastland/story/weapon/dagger1.c`**

- `:6` set_name("fighter's dagger","戰士□匕");
- `:8` set_short("戰士□匕");
- `:10` 一把由妖精長老用千年精鐵經百年不滅□火熔鑄而成的武器，呈黑色光澤，斷石切

**`d/eastland/story/weapon/elder1.c`**

- `:14` 剩下兩個突起的肉瘤，彎腰駝揹走起路來一柺一柺的全□著手中木杖攙扶。雖然他
- `:103` 羽後說道：妖□谷辰乃修練萬年的僵屍，他早在千年前被人收伏。最近
- `:105` 。妖□谷辰幾乎毫無弱點可言，惟一怕的是「滅魔符」(ghost

**`d/eastland/story/weapon/imp_wand.c`**

- `:7` set_name("the evil wand", "天魔□杖");
- `:9` set_short("天魔□杖");
- `:11` 天魔□杖是由天魔窮盡畢生的法力研製而成的一把魔杖。杖前刻著一顆青鬱郁的骷

**`d/eastland/story/wiz/armor/wiz_amulet1.c`**

- `:6` _(2 個)_ set_name("The Archmaster's amulet","護國師□符□");
- `:8` _(2 個)_ set_short( set_color("護國師□符□","HIY"));

**`d/eastland/story/wiz/armor/wiz_ring1.c`**

- `:6` set_name("The Archmaster's ring","護國師□戒");
- `:8` set_short( "護國師□戒");

**`d/eastland/story/wiz/armor/wiz_robe1.c`**

- `:4` set_name( "The Archmaster's robe","護國師□袍" );
- `:6` set_short( "護國師□袍" );

**`d/eastland/story/wiz/monster/wiz_captain2.c`**

- `:44` "夏侯忍自語道：要不是我要負責這個城的安全，我早就殺往「妖□ 谷辰」(great_vampire)那裡去了。\n"
- `:47` "夏侯忍狂笑：哼，你就代替「妖□ 谷辰」(great_vampire)受死吧！\n"

**`d/eastland/story/wiz/weapon/wiz_wand1.c`**

- `:7` set_name("Origin wand", "混沌□杖");
- `:9` set_short("混沌□杖");

**`d/eastland/volcano/armor/cloak2.c`**

- `:12` _(4 個)_ 這是□□所穿著的鬥蓬，其實只是一塊綠色的布，但這是從□□幼年時就穿到現

**`d/eastland/volcano/armor/mail7.c`**

- `:12` 這件盔甲是在極北之地以冰雪之精加上精鋼□成，據說完全不懼寒冷或是冰雪攻擊。

**`d/eastland/volcano/armor/shield2.c`**

- `:7` set_name( "dark shield", "□盾" );
- `:9` set_short(  "□盾" );

**`d/eastland/volcano/group/warea10.c`**

- `:62` write("\n你把"+ob->query("c_name")+"丟入井中，只聽得叭□一聲，你見到"+ob->query("c_name")+"浮在水面…

**`d/eastland/volcano/monster/oregon.c`**

- `:32` 術實在是不行，矮靈族也沒有什麼人能夠鍛□，所以一直鎖在神殿裡沒用。或許你可以

**`d/eastland/volcano/monster/right_guard.c`**

- `:13` _(2 個)_ set_short( "右護法－□□" );
- `:16` _(2 個)_ 右護法－□□原本是一隻妖怪，具有可怕的魔力，原來居住在雲南大澤中，
- `:59` _(2 個)_ "\n□□說：你的小命已經在我的掌握之中，快投降吧。\n\n"
- `:81` _(2 個)_ "□□的身體再生又復原了。\n"
- `:87` _(2 個)_ "□□眼睛射出一道青光，吸取你的生命力。\n"
- `:91` _(4 個)_ "的靈魂飄至□□身上，□□的身體又復原了。\n",

**`d/eastland/volcano/weapon/ghostsword.c`**

- `:12` □鑄而成，單邊的刀鋒上嵌著一顆綠色晶石，正不斷的透射出詭異的光芒。

**`d/erosmia/ekravia/tavern.c`**

- `:61` _(2 個)_ □住宿須知□

**`d/island/hole/weapon/scale_sword.c`**

- `:27` "%s雀躍如狂，凌空一劃，□如烈日，使出「日麗中天」衝向%s",

**`d/island/samurai/obj/snow_dagger.c`**

- `:6` set_name("Snow dagger","雪□顏");
- `:8` set_short("Snow dagger","雪□顏");

**`d/martial/attack/monk/fist/drunk_fist.c`**

- `:40` "%s身形東歪西倒，一招『漢鍾離，醉步報□窩心頂』撞向%s",

**`d/martial/attack/monk/fist/long_fist.c`**

- `:19` "%s『舞花臥枕』、『□貓上樹』連續使出，抓向%s",

**`d/martial/attack/monk/general/burn_blade.c`**

- `:41` "使出『飛□滿天』，手中%s散出滿天刀氣攻向%s",

**`d/martial/attack/monk/general/dragon_claw.c`**

- `:73` "%s左手虛探，右手挾著一陣勁風，抓向%s，一招犀利的「□雲式」",

**`d/martial/attack/monk/test/k_dragon.c`**

- `:58` //                  龍影縱橫  龍騰千里  雙龍吐珠   火龍吞□
- `:62` "%s一掌『損則有□』擊向%s",

**`d/monk/cmds/_songin.c`**

- `:9` "佛言 惡人聞善 故來擾亂者 汝自禁息 當無□責 彼來惡者 而自惡之\n",

**`d/noden/drow/arm/lucky_plate.c`**

- `:11` 這是一件有刻有小刀圖紋的輕質鎧甲□黝黑而不能反光

**`d/noden/drow/obj/weapon1.c`**

- `:14` □魔法聚集冥界能量加筮成的長矛，由於箭柄是由冥界

**`d/noden/drow/r32.c`**

- `:16` 像(statue)□嚇！一陣刺耳的尖銳叫聲，從前方的引道傳來，你的勇氣

**`d/noden/drow/r67.c`**

- `:10` 一個由□木所雕刻的巨大書架佔據了整個房間，這裡就

**`d/noden/elf/monster/wind.c`**

- `:36` _(2 個)_ "那是高25公分石雕作品,是我為我太太□□□所刻的雕像,還記的那天是她\n"

**`d/noden/ruin/monster/queen.c`**

- `:17` 威嚴地坐在王座上的，想必就是傳說中的魔族真神□女王，不過她看來氣

**`d/noden/ruin/room/lib0.c`**

- `:34` "plate" : "銅牌上面寫著：「女王的微笑」□希達．尼普頓。\n"

**`d/noden/ruin/weapon/polearm.c`**

- `:14` □魔法聚集冥界能量加筮成的長矛，由於箭柄是由冥界

**`d/thief/thief.c`**

- `:50` "角頭老大的□啊 ",

**`std/armor/armor.c`**

- `:62` case "globe": verb = "□上"; break;

**`std/races/centaur.c`**

- `:37` "%s揮拳往%s猛□", "%s雙腳往%s猛踹", }) );

**`u/b/boss/polearm.c`**

- `:14` □魔法聚集冥界能量加筮成的長矛，由於箭柄是由冥界

**`u/c/creative/item/life1.c`**

- `:17` 沒想到其中一顆乾靈神□居然造就出莽牯朱蛤這毒物。

**`u/c/creative/item/lifeball.c`**

- `:17` 沒想到其中一顆乾靈神□居然造就出莽牯朱蛤這毒物。

---

## B：彩色中文殘骸

原作者用過一種「半字變色」的寫法：把一個漢字的**兩個 Big5 位元組分開上色**，

```
ESC [0;31m <位元組1> ESC [1;31m <位元組2> ESC [0;37m
```

轉碼時「位元組 + 後面那個 ESC」被當成一個無法對映的雙位元組序列吃掉，
變成一個 `□`。後果有三：

1. 漢字沒了——通常**兩個 `□` 等於一個漢字**。
2. 中間那些 ESC 也沒了，所以殘留的 `[1;31m`、`[0;37m` 少了前導 ESC，
   跑起來會把字面的 `[1;31m` 印在玩家畫面上。
3. **但線索還在**：Big5 第二個位元組有一半落在 ASCII 範圍（0x40–0x7E），
   那些位元組沒被吃掉。例如 `god_ring.c:7` 的
   `□[1;37mP<ESC>[0;37m□[1;37ms<ESC>[0;37m□[1;37m□` 是三個漢字，
   第一個字的第二位元組是 `P`(0x50)、第二個是 `s`(0x73)，第三個兩個位元組
   都 ≥0x80 所以全丟了。復原方式是拿這些尾位元組反查 Big5 碼表，
   再用英文名（`God-Dragon ring`）與上下文收斂。

**`d/eastland/story/palace/armor/god_ring.c`**

- `:7` _(4 個)_ set_name( "God-Dragon ring","□[1;37mP<ESC>[0;37m□[1;37ms<ESC>[0;37m□[1;37m□[0…
- `:10` _(4 個)_ set_short( "□[1;37mP<ESC>[0;37m□[1;37ms<ESC>[0;37m□[1;37m□[0;37m" );

**`d/eastland/story/palace/armor/northgod_shield.c`**

- `:7` _(8 個)_ set_name( "rainbow mirror","<ESC>[0;34m□[1;34m□[0;34m<ESC>[1;34m□[0;34m_<ESC>…
- `:9` _(8 個)_ set_short( "<ESC>[0;34m□[1;34m□[0;34m□[1;34m_<ESC>[0;34m□[1;34m[<ESC>[0;34m□[…

**`d/eastland/story/palace/monster/dragon1.c`**

- `:9` _(3 個)_ set_name( "Great dragon","<ESC>[1;32m□[1;36m□[0;37m<ESC>[1;32m□[1;36ms<ESC>[m…
- `:11` _(3 個)_ set_short( "<ESC>[1;32m□[1;36m□[0;37m<ESC>[1;32m□[1;36ms<ESC>[m");

**`d/eastland/story/palace/monster/king1.c`**

- `:10` _(3 個)_ set_short( "中央天帝 黃帝 [騎在一隻<ESC>[1;32m□[1;36m□[0;37m<ESC>[1;32m□[1;36ms<ESC>[m上…

**`d/eastland/story/palace/monster/northgod.c`**

- `:13` _(6 個)_ set_short( "北方天帝 顓頊 [騎在一隻<ESC>[0;31m□[1;31m□[0;37m<ESC>[0;31m□[1;31m□[0;37m<E…

**`d/eastland/story/palace/monster/phoenix.c`**

- `:9` _(6 個)_ set_name( "Red phoenix","<ESC>[0;31m□[1;31m□[0;37m<ESC>[0;31m□[1;31m□[0;37m<E…
- `:11` _(6 個)_ set_short( "<ESC>[0;31m□[1;31m□[0;37m<ESC>[0;31m□[1;31m□[0;37m<ESC>[0;31m□[1;…

**`d/island/weapon/jousting.c`**

- `:10` _(6 個)_ string C_NAME=("<ESC>[36;1m□[0;36m□[36;1m□[0;36m@<ESC>[36;1m□[0;36m□[36;1m□[0…

---

## A：疑似框線／項目符號

`□` 兩側都是空白，看起來是拿來當項目符號或 ASCII 圖的。
但 monk_guild.c 的前例說明**這一類也可能是被吃掉的 `—`**，
動手前先看整段排版是什麼形狀。

- `d/eastland/legend/monster/crab.c:15` □ ⊙  ⊙ □
- `d/eastland/story/monster/crab4.c:16` □ ⊙  ⊙ □
- `d/eastland/story/monster/crab3.c:16` □ ⊙  ⊙ □
- `d/eastland/story/monster/crab2.c:16` □ ⊙  ⊙ □
- `d/eastland/story/monster/crab1.c:16` □ ⊙  ⊙ □
- `d/noden/elf/monster/wind.c:36` "那是高25公分石雕作品,是我為我太太□□□所刻的雕像,還記的那天是她\n"
- `d/island/town/bank.c:24` □ 先確定你的確有二十五塊金幣（一定要金幣唷！ 沒有要先換）
- `d/island/town/post_office.c:59` □ 收信 ： 鍵入 mail ，你將進入讀信的狀態 。 用 ? 可在

