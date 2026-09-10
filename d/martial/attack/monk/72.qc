
            本次更動少林 72 絕技的內容, 主要是更動特攻出現機率,由
        原來的純粹數字 random 改為與各 72 的 gonfu level 相關。一
        般 72 絕技 (body-def、bolo-fist、dragon-claw、keep-flower)
        皆改為與該 gonfu level 成直線正相關, 最高出現率(when lv=35)
        1/10, 最低則為 0, 原來的機率則是 2/37; 而 power-finger 特攻
        為連續攻擊, 本來就是 random 出現的, 惟原來是單純的數字 
        random, 今改為與 lv 成直線正相關, 最高出現率(when lv=35)為 
        1/6 最低為 0, 原為14/100; 在連續攻擊中, 繼續連續攻擊的機率
        , 最高(when lv=35)為 1/3, 最低為 0, 原為 27/100 (即原機率
        的兩倍) 。


            另外, 亦期望能將各項特攻強度改成與 gonfu level 成正相關,
        其中 keep-flower & power-finger 的特攻強度較難以定義, 因此,
        keep-flower 改為 block_attack 的回合數與 gonfu level 的隨機值
        正相關; power-finger 則無更動(有這麼高的連續攻擊率應該不錯了).
        bolo-fist 原來就成正相關, 特攻強度未更動; dragon-claw 則由原來
        的與 int 正相關改為與 gonfu level 正相關。body-def 的特攻原為
        this_player()->receive_healing(); 但未開放, angel 與我都覺得
        不太適當, 因此新增特攻－－內力反震, 反震強度與玩家的內力值成
        正相關, 為模擬反震, 玩家可同時回復 hp 以抵銷原來的受創。

            以上為此次更動內容之大要, 含有檔案:
        /d/martial/attack/monk/general/b_f.c (bolo_fist)
        /d/martial/attack/monk/general/d_c.c (dragon_claw)
        /d/martial/attack/monk/general/k_f.c (keep_flower)
        /d/martial/attack/monk/general/p_f.c (power_finger)
        /d/martial/defense/monk/general/b_d.c (body_def)

            各項 gonfu 之原檔案仍在, 以供比對之用。

                                          Sincerely your Vincent..
