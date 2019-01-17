#include <room.h>
#include <ansi.h>
inherit ROOM;
mapping *paizi=({
    ([  "name":"����",
        "id":"beijing",
        "file":"/d/chehang/che1",                    
        "value":500
     ]),
    ([  "name":"�䵱",
        "id":"wudang",
        "file":"/d/chehang/che3",                    
        "value":500
     ]),
    ([  "name":"Ȫ��",
          "id":"quanzhou",
        "file":"/d/chehang/che5",                    
        "value":500
     ]),
    ([  "name":"��ɽ",
          "id":"huashan",
        "file":"/d/chehang/che7",                    
        "value":500
     ]),
    ([  "name":"����",
        "id":"shaolin",
        "file":"/d/chehang/che9",                    
        "value":500
     ]),
    ([  "name":"�һ���",
        "id":"taohuadao",
        "file":"/d/chehang/che11",                    
        "value":500
     ]),
    ([  "name":"����ɽ",
          "id":"baituo",
        "file":"/d/chehang/che13",                    
        "value":500
     ]),
    ([  "name":"����",
          "id":"xingxiu",
        "file":"/d/chehang/che15",                    
        "value":500
     ]),
    ([  "name":"���չ�",
        "id":"lingjiu",
        "file":"/d/chehang/che17",                    
        "value":500
     ]),
    ([  "name":"����",
        "id":"mingjiao",
        "file":"/d/chehang/che19",                    
        "value":500
     ]),
    ([  "name":"�컨��",
          "id":"honghuahui",
        "file":"/d/chehang/che21",                    
        "value":500
     ]),
    ([  "name":"ѩɽ��",
          "id":"xueshan",
        "file":"/d/chehang/che23",                    
        "value":500
     ]),
    ([  "name":"����С��",
        "id":"beijiang",
        "file":"/d/chehang/che25",                    
        "value":500
     ]),
    ([  "name":"��Ĺ��",
        "id":"gumu",
        "file":"/d/chehang/che27",                    
        "value":500
     ]),
    ([  "name":"ȫ���",
          "id":"quanzhen",
        "file":"/d/chehang/che29",                    
        "value":500
     ]),
/*
    ([  "name":"��÷ɽׯ",
          "id":"wanmei",
        "file":"/d/chehang/che31",                    
        "value":500
     ]),    
*/
    ([  "name":"����Ľ��",
          "id":"murong",
        "file":"/d/chehang/che33",                    
        "value":500
     ]),
/*
    ([  "name":"������",
        "id":"tianlongbang",
        "file":"/d/chehang/che35",                    
        "value":500
     ]),
*/
    ([  "name":"佻�����",
        "id":"huanhua",
        "file":"/d/chehang/che37",                    
        "value":500
     ]),
    ([  "name":"�������",
          "id":"riyue",
        "file":"/d/chehang/che39",                    
        "value":500
     ]),
    ([  "name":"ɱ��¥",
          "id":"shashou",
        "file":"/d/chehang/che41",                    
        "value":500
     ]),          
    ([  "name":"��ң��",
          "id":"xiaoyao",
        "file":"/d/chehang/che43",                    
        "value":500
     ]),
    ([  "name":"������",
          "id":"emei",
        "file":"/d/chehang/che45",                    
        "value":500
     ]),
    ([  "name":"����",
          "id":"dali",
        "file":"/d/chehang/che47",                    
        "value":500
     ]),          
});
string look_paizi();
int do_go(string);
void create()
{
         set("short","����");
         set("long", @LONG
���������ݳ��С�Ժ����ͣ�ż������������ר�Ÿ���ӭ��ס��Ŀ��ˡ�
�Ա���һ��۸��(paizi)���������qu �������� ����������
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

    if (!arg) return notify_fail("��Ҫȥ���\n");
    if(present("biao yin",ob))
              return notify_fail("���ϰ�������ü�������ϴ�������ͷ���������������ǿɵ�������\n");
    if(present("xin",ob))
              return notify_fail("���ϰ�������ü�����������������ɡ�\n");
       
    if (ob->is_busy() || ob->is_fighting())
        return notify_fail("����æ���أ�\n");
    
    while(i--) {
        if (arg == paizi[i]["id"]) {
                switch (MONEY_D->player_pay(ob, paizi[i]["value"]))
                {
                        case 0:
                                return notify_fail("��⵰��һ�ߴ���ȥ��\n");
                        case 2:
                                return notify_fail("����Ǯ��\n");
                }
                message_vision("$N�ڿڴ��﷭����ȥ���ҳ�Ǯ��\n", ob);
                ob->start_busy(3);
                message_vision(YEL"\n$N��Ǯ�������ϰ壬���ϰ�����ش��˳����ţ�����$N��������\n\n"NOR,ob);
                call_out("do_move", 3, ob, i);
                return 1;
        }
    }
    return notify_fail("��Ҫȥ���\n");
}

