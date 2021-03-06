#include <room.h>
#include <ansi.h>
inherit ROOM;
mapping *paizi=({
    ([  "name":"北京",
        "id":"beijing",
        "file":"/d/chehang/che1",                    
        "value":500
     ]),
    ([  "name":"武当",
        "id":"wudang",
        "file":"/d/chehang/che3",                    
        "value":500
     ]),
    ([  "name":"泉州",
          "id":"quanzhou",
        "file":"/d/chehang/che5",                    
        "value":500
     ]),
    ([  "name":"华山",
          "id":"huashan",
        "file":"/d/chehang/che7",                    
        "value":500
     ]),
    ([  "name":"少林",
        "id":"shaolin",
        "file":"/d/chehang/che9",                    
        "value":500
     ]),
    ([  "name":"桃花岛",
        "id":"taohuadao",
        "file":"/d/chehang/che11",                    
        "value":500
     ]),
    ([  "name":"白驼山",
          "id":"baituo",
        "file":"/d/chehang/che13",                    
        "value":500
     ]),
    ([  "name":"星宿",
          "id":"xingxiu",
        "file":"/d/chehang/che15",                    
        "value":500
     ]),
    ([  "name":"灵鹫宫",
        "id":"lingjiu",
        "file":"/d/chehang/che17",                    
        "value":500
     ]),
    ([  "name":"明教",
        "id":"mingjiao",
        "file":"/d/chehang/che19",                    
        "value":500
     ]),
    ([  "name":"红花会",
          "id":"honghuahui",
        "file":"/d/chehang/che21",                    
        "value":500
     ]),
    ([  "name":"雪山派",
          "id":"xueshan",
        "file":"/d/chehang/che23",                    
        "value":500
     ]),
    ([  "name":"北疆小镇",
        "id":"beijiang",
        "file":"/d/chehang/che25",                    
        "value":500
     ]),
    ([  "name":"古墓派",
        "id":"gumu",
        "file":"/d/chehang/che27",                    
        "value":500
     ]),
    ([  "name":"全真教",
          "id":"quanzhen",
        "file":"/d/chehang/che29",                    
        "value":500
     ]),
/*
    ([  "name":"万梅山庄",
          "id":"wanmei",
        "file":"/d/chehang/che31",                    
        "value":500
     ]),    
*/
    ([  "name":"姑苏慕容",
          "id":"murong",
        "file":"/d/chehang/che33",                    
        "value":500
     ]),
/*
    ([  "name":"天龙帮",
        "id":"tianlongbang",
        "file":"/d/chehang/che35",                    
        "value":500
     ]),
*/
    ([  "name":"浣花剑派",
        "id":"huanhua",
        "file":"/d/chehang/che37",                    
        "value":500
     ]),
    ([  "name":"日月神教",
          "id":"riyue",
        "file":"/d/chehang/che39",                    
        "value":500
     ]),
    ([  "name":"杀手楼",
          "id":"shashou",
        "file":"/d/chehang/che41",                    
        "value":500
     ]),          
    ([  "name":"逍遥派",
          "id":"xiaoyao",
        "file":"/d/chehang/che43",                    
        "value":500
     ]),
    ([  "name":"峨嵋派",
          "id":"emei",
        "file":"/d/chehang/che45",                    
        "value":500
     ]),
    ([  "name":"大理",
          "id":"dali",
        "file":"/d/chehang/che47",                    
        "value":500
     ]),          
});
string look_paizi();
int do_go(string);
void create()
{
         set("short","车行");
         set("long", @LONG
这里是扬州车行。院子里停着几辆马车，这儿是专门负责迎送住店的客人。
旁边有一块价格表(paizi)。你可以用qu 地名代号 来乘坐马车。
LONG
   );
         set("exits",([
                  "west" : "/d/city/kedian",
]));
         set("item_desc",([
             "paizi" : (: look_paizi :)     
]));
}
void init()
{
    add_action("do_go", "qu");
}

string look_paizi()
{
    string str="";
    int i=sizeof(paizi);


    while (i--) {
        str += paizi[i]["name"];
        str += "(" + paizi[i]["id"] + ") ";
        str += MONEY_D->price_str(paizi[i]["value"]) + "\n";
    }

    return str;
}

void do_move(object ob, int i)
{
        ob->move(paizi[i]["file"]);
}

int do_go(string arg)
{
    object ob=this_player();
    int i=sizeof(paizi);

    if (!arg) return notify_fail("你要去哪里？\n");
    if(present("biao yin",ob))
              return notify_fail("车老板皱了皱眉：你身上带着林镖头的镖银，丢了我们可担单不起。\n");
    if(present("xin",ob))
              return notify_fail("车老板皱了皱眉：你好象还有任务在身吧。\n");
       
    if (ob->is_busy() || ob->is_fighting())
        return notify_fail("你正忙着呢！\n");
    
    while(i--) {
        if (arg == paizi[i]["id"]) {
                switch (MONEY_D->player_pay(ob, paizi[i]["value"]))
                {
                        case 0:
                                return notify_fail("穷光蛋，一边呆着去！\n");
                        case 2:
                                return notify_fail("有零钱吗？\n");
                }
                message_vision("$N在口袋里翻来覆去地找车钱。\n", ob);
                ob->start_busy(3);
                message_vision(YEL"\n$N把钱交给车老板，车老板热情地打开了车厢门，领着$N上了马车。\n\n"NOR,ob);
                call_out("do_move", 3, ob, i);
                return 1;
        }
    }
    return notify_fail("你要去哪里？\n");
}

