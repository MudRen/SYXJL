inherit ROOM;

void create()
{
        set("short", "üë��");
        set("long", @LONG
����üë���������䣬�����������ľ����������Ũü���м���
һ����ҩ��̤���ļ�����������С��(xiaodao)��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"baichi",
  "southdown" : __DIR__"taohua",
]));
        set("objects", ([
                __DIR__"npc/shashou2": 2,]) );

        set("item_desc", ([
                "xiaodao" : "���˱��̷羰��.\n",
        ]));

        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
 
