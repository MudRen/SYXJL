//Room: /u/lzd/dali/zhulin2.c
//Date: June. 29 1998 by Java
 
#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short","�����");
        set("long",
"��������ֵ����ֻ��ǰ����Զ����һ����������\n"
"��ʲô��ǰ������˵��ʲô���������߽�һ����ԭ����\n"
"��"HIR "Ĺ��" NOR "(mubei)��\n");
        set("objects", ([
           __DIR__"npc/xiaofeng": 1,
        ]));
        set("outdoors", "dali");
        set("exits",([ /* sizeof() == 1 */
            "north"      : __DIR__"hexi",
        ]));
        
        set("item_desc", ([
        "mubei" : "\n\n" 
HIW"             ��������������\n"NOR
HIW"             ��������������\n"NOR 
HIW"             ����  "HIR"��  "HIW"����\n"NOR
HIW"             ����  "HIR"��  "HIW"����\n"NOR
HIW"             ����  "HIR"��  "HIW"����\n"NOR
HIW"             ����  "HIR"��  "HIW"����\n"NOR
HIW"             ����  "HIR"֮| "HIW"����\n"NOR
HIW"             ����  "HIR"Ĺ��"HIW"����\n"NOR
HIW"             ����    "HIR"��"HIW"����\n"NOR
HIW"             ��������������\n"NOR
HIW"             ��������������\n"NOR
                 
                 ]) );

                 set("no_clean_up", 0);
                 set("coor/x",-10);
	set("coor/y",-220);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-220);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-220);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-220);
	set("coor/z",10);
	setup();
}
