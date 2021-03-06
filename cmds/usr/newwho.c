
/// who.c
// From ES2

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

mapping party=([
        "emei":    "峨嵋派",
        "murong":  "姑苏慕容",
        "gumu":    "古墓派",
        "xueshan": "密宗",
        "mingjiao":"明教",
        "shaolin": "少林派",
        "taohua":  "桃花岛",
        "tianlong":"天龙寺",
        "xingxiu": "星宿派",
        "gaibing": "丐帮",
        "wudang":  "武当派",
        "shashou": "杀手楼",
        "kunlun":  "昆仑派",
        "huashan": "华山派",
        "baituo":  "白驼山派",
        "honghua": "红花会",
        "kunlun":  "昆仑派",
        "quanzhen":"全真教",
        "riyue":   "日月神教",
        "yunlong": "云龙门",
        "dali":    "镇南王府",
        "huanhua": "浣花剑派",
        "xiaoyao": "逍遥派",
]);

int sort_user(object,object);

void create() { seteuid(getuid()); }

string opt_party;

mixed main(object me, string arg, int remote)
{
        string str, *option, fname = "";
        object *list, *ob;
        int i, ppl_cnt, cnt, count, wcnt = 0;
        int opt_long, opt_id, opt_wiz;

        opt_party = "(null)";
        if( arg ) {
                option = explode(arg, " ");
                option -= ({ "" });
                i = sizeof(option);
                while( i-- )
                        switch(option[i]) {
                                case "-l": opt_long = 1; break;
                                case "-i": opt_id = 1; break;
                                case "-w": opt_wiz = 1; break;
                                case "-f":
                                case "-p": opt_party = me->query("family/family_name"); break;
                                default:
/*
                                        if( wizardp(me)
                                        &&      option[i][0]=='@' ) {
                                                RWHO_Q->send_rwho_q(option[i][1..sizeof(option[i])],
                                                        me, opt_long);
                                                write("网路讯息已送出，请稍候。\n");
                                                return 1;
                                        }
*/
                                        if (option[i][0] == '-' && !undefinedp(party[option[i][1..<1]]))
                                                opt_party = party[option[i][1..<1]];
                                        else return notify_fail("指令格式：who [-l|-i|-w|-p|-shaolin..wudang..mingjiao.....]\n");
                        }
        }

        if( opt_long && !wizardp(me)) {
                if( (int)me->query("jing") < 50 )
                        return notify_fail("你的精神太差了，没有办法得知所有玩家的详细资料。\n");
                me->receive_damage("jing", 50);
        }

      str = HIG "※ " + MUD_NAME + HIG " ※\n"NOR;
        str += "————————————————————————————————————————\n";
        ob = filter_array(objects(), (: userp :));
        if (opt_party != "(null)")
                ob = filter_array(ob, (: $1->query("family/family_name") ==
                        opt_party :));
        list = sort_array(ob, (: sort_user :));
        ppl_cnt = 0;
        cnt = 0;
        if( opt_long || opt_wiz ) {
                i = sizeof(list);
                while( i-- ) {
                        // Skip those users in login limbo.
                        if( !environment(list[i]) ) continue;
                        if( !me->visible(list[i]) ) continue;
            if( opt_wiz && !wiz_level(list[i]) ) continue;
                        if (interactive(list[i])) ppl_cnt++;
                        else cnt++;
                        str = sprintf("%s%12s%s%s%s\n",
                                str,
                                RANK_D->query_rank(list[i]),
                                interactive(list[i])?(query_idle(list[i]) > 120?HIM "+" NOR:" "):HIG "*" NOR,
                                list[i]->short(1),
				interactive(list[i])?(query_idle(list[i]) > 120?HIM "<发呆"+ chinese_number(query_idle(list[i])/60) + "分钟>" NOR:" "):" "                                
                        );
                }
        } else {
                i = sizeof(list);
                count = 0;
                while( i-- ) {
                        // Skip those users in login limbo.
                        if( !environment(list[i]) ) continue;
                        if( !me->visible(list[i]) ) continue;
                        if (!wiz_level(list[i]) && fname != list[i]->query("family/family_name")) {
                            fname = list[i]->query("family/family_name");
                            if (count % (opt_id?4:8)) str += "\n";
                            str += sprintf(HIY "%-10s" NOR, (fname?fname:"普通百姓") + "：");
                            count = 1;
                        }
                        if (!wcnt && wiz_level(list[i])) {
                            if (count % (opt_id?4:8)) str += "\n";
                            str += sprintf(HIY "%-10s" NOR, "巫师：");
                            wcnt = 1;
                            count = 1;
                        }
                        if (!(count % (opt_id?4:8))) {
                                count++;
                                str += "          ";
                        }
                        str = sprintf("%s%s%-"+(opt_id?19:9)+"s"NOR"%s",
                                str,
                                interactive(list[i]) ? (query_idle(list[i]) > 120 ? HIM "+" : " ") : HIG "*",
                                list[i]->name(1) + (opt_id ? "("+capitalize(list[i]->query("id"))+")" : ""),
                                ++count % (opt_id?4:8) ? "" : "\n"
                        );
                        if (interactive(list[i])) ppl_cnt++;
                        else cnt++;
                }
                if( count % (opt_id?4:8) ) str += "\n";
        }
        str += "————————————————————————————————————————\n";
        str = sprintf("%s有 %d 位玩家连线中，%d 位玩家断线中，系统负担：%s\n* 表示断线中  + 表示发呆中", str, ppl_cnt,
                cnt, query_load_average());

//      if( remote ) return str;

        me->start_more(str);
        return 1;
}

int sort_user(object ob1, object ob2)
{
        string name1, name2;

        reset_eval_cost();
        if( wiz_level(ob1) != wiz_level(ob2) )
                return wiz_level(ob2)
                        - wiz_level(ob1);
        
        name1 = ob1->query("family/family_name");
        name2 = ob2->query("family/family_name");

        if (intp(name1)) name1 = "";
        if (intp(name2)) name2 = "";
        if (name1 > name2) return -1;
        if (name1 < name2) return 1;

        return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}

int help(object me)
{
write(@HELP
指令格式 : who [-l|-i|-w|-p|-门派名]

这个指令可以列出所有在线上的玩家及其等级。

-l 选项列出较长的讯息。
-i 只列出玩家的英文代号。
-p 只列出同门的玩家。
-w 只列出线上所有的巫师。
门派名：
        emei:     峨嵋派,
        murong:   姑苏慕容,
        gumu:     古墓派,
        xueshan:  雪山派,
        mingjiao: 明教,
        shaolin:  少林派,
        taohua:   桃花岛,
        tianlong: 天龙寺,
        xingxiu:  星宿派,
        gaibing:  丐帮,
        wudang:   武当派,
        shashou:  杀手楼,
        kunlun:   昆仑派,
        huashan:  华山派,
        baituo:   白驼山派,
        honghua:  红花会,
        kunlun:   昆仑派,
        quanzhen: 全真教,
        riyue:    日月神教,
        yunlong:  云龙门,
        dali:     镇南王府,
        huanhua:  浣花剑派,
        xiaoyao:  逍遥派,
相关指令： finger
HELP
        );
        return 1;
}
